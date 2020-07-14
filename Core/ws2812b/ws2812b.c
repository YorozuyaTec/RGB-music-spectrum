/*
 * ws2812b.c
 *
 *  Created on: Jun 19, 2020
 *      Author: Administrator
 */


#include "ws2812b.h"
// 定义一条WS2812灯串
SW28_HandleTypeDef	hsw28;


// 用于显示缓存
static uint8_t buff_a[LED_ARR]= {BIT00};
// 用于发送缓存
static uint8_t buff_b[LED_ARR]= {BIT00};



/*
WS28 - Library for the WS281X series of RGB LED device IC.

Copyright 2018 Waiman

Supported devices:
WS2811 WS2812
*/








/****************************************************************************
* 名    称： Sw28_Init(SW28_HandleTypeDef *swObj, uint8_t pixelLen)
* 功    能：
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void Sw28_Init(SW28_HandleTypeDef *swObj, uint8_t pixelLen)
{
    swObj->PixelLen = pixelLen;
    swObj->BuffLen = pixelLen*12+1;
    swObj->BuffPoint = buff_a;
    swObj->SendPoint = buff_b;
    swObj->Brightness = 10;
    *(swObj->BuffPoint +swObj->BuffLen-1)  = 0xFE;	//

    swObj->Status = READY;
    Sw28_AllBlock(swObj);
    Sw28_Show(swObj);
}



/****************************************************************************
* 名    称：void Sw28_AllBlock(void)
* 功    能：关闭颜色
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void Sw28_AllBlock(SW28_HandleTypeDef *swObj)
{
    memset(swObj->BuffPoint,BIT00,(swObj->BuffLen-1));
    swObj->Status = READY;
}



/****************************************************************************
* 名    称：Sw28_SetPixelsColor(SW28_HandleTypeDef *swObj, uint8_t pix, uint32_t color)
* 功    能：设置指定LED的颜色
* 入口参数： pix 位置
* 出口参数：
* 说    明：
****************************************************************************/
void Sw28_SetPixelsColor(SW28_HandleTypeDef *swObj, uint8_t pix, uint32_t color)
{
    uint8_t i;
    uint8_t tmp;
    uint8_t	*pb = swObj->BuffPoint + pix*12;

    for(i=0; i<12; i++)
    {
        tmp = (uint8_t)(color &0x00000003);
        switch(tmp)
        {
        case 0x00:
            *pb = BIT00;
            break;
        case 0x01:
            *pb = BIT01;
            break;
        case 0x02:
            *pb = BIT10;
            break;
        case 0x03:
            *pb = BIT11;
            break;
        }
        color = color >>2;

        pb++;
    }
}



/****************************************************************************
* 名    称：Sw28_SetAllColor(SW28_HandleTypeDef *swObj, uint32_t color)
* 功    能：设置所以LED使用同一颜色
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void Sw28_SetAllColor(SW28_HandleTypeDef *swObj, uint32_t color)
{
    uint8_t i;
    uint8_t *dest = swObj->BuffPoint+12;
    Sw28_SetPixelsColor(swObj,0,color);
    for(i=1; i<swObj->PixelLen; i++)
    {
        memcpy(dest, swObj->BuffPoint, (12*sizeof(uint8_t)));
        dest+=12;
    }
    swObj->Status = READY;
}



/****************************************************************************
* 名    称：uint32_t Sw28_Color(uint8_t r, uint8_t g, uint8_t b)
* 功    能：
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
uint32_t Sw28_Color(uint8_t r, uint8_t g, uint8_t b)
{
  uint32_t temp;
  uint8_t ir,ig,ib;
  ir=HEX_inver(r);ig=HEX_inver(g);ib=HEX_inver(b);
  temp=(((uint32_t)ib << 16) | ((uint32_t)ir <<  8) | ig);
  return temp;
}



/****************************************************************************
* 名    称：void Sw28_Color2RGB(uint32_t color, uint8_t* r, uint8_t* g, uint8_t* b)
* 功    能：
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void Sw28_Color2RGB(uint32_t color, uint8_t* r, uint8_t* g, uint8_t* b)
{
    *b = (uint8_t)color;
    *r = (uint8_t)(color>>8);
    *g = (uint8_t)(color>>16);
}


uint8_t HEX_inver(uint8_t hex)
{
	uint8_t bh2h,bh2l,bl2h,bl2l,result;

//	bh4= hex>>4;
//	bl4= (hex<<4)>>4;
//	result = (bl4<<4)+bh4;
	bh2h = hex>>6;
	bh2l = (hex&0x30)>>4;

	bl2h = (hex&0x0C)>>2;
	bl2l = (hex&0x03);
    result = (bl2l<<6)+(bl2h<<4)+(bh2l<<2)+bh2h;
	return result;
}

/****************************************************************************
* 名    称：uint32_t Sw28_GetPixelColor(SW28_HandleTypeDef *swObj, uint16_t pix)
* 功    能：
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
uint32_t Sw28_GetPixelColor(SW28_HandleTypeDef *swObj, uint16_t pix)
{
    uint8_t i;
    uint8_t tmp;
    uint32_t color=0;
    uint8_t	*pb = swObj->BuffPoint + pix*12;

    for(i=0; i<12; i++)
    {
        color = color <<2;
        switch(*pb)
        {
        case BIT00:
            tmp = 0x0;
            break;
        case BIT01:
            tmp = 0x1;
            break;
        case BIT10:
            tmp = 0x2;
            break;
        case BIT11:
            tmp = 0x3;
            break;
        }
        color |= tmp;

        pb++;

    }
    return color;
}



/****************************************************************************
* 名    称：Sw28_Show(void)
* 功    能：
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void Sw28_Show(SW28_HandleTypeDef *swObj)
{
	// SPI 空闲
	if (HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_READY)
	{
		// 有缓存需要更新，更新显示缓存
		if(swObj->Status == READY) {
			memcpy(swObj->SendPoint, swObj->BuffPoint, swObj->BuffLen);
			swObj->Status = BUSY;
		}
		// 发送显示缓存
		if(HAL_SPI_Transmit_DMA(&hspi1, swObj->SendPoint, swObj->BuffLen) != HAL_OK)
		{
			Error_Handler();
		}
	}
}


/****************************************************************************
* 名    称：
* 功    能：
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
uint32_t Sw28_ScaleColor(uint8_t scale, uint32_t color)
{
    uint8_t r,g,b;

    b = (uint8_t)color;
    r = (uint8_t)(color>>8);
    g = (uint8_t)(color>>16);

    r = (r * scale) >> 8;
    g = (g * scale) >> 8;
    b = (b * scale) >> 8;

    return (((uint32_t)g << 16) | ((uint32_t)r <<  8) | b);
}


/****************************************************************************
* 名    称：Sw28_Show(void)
* 功    能：
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void Sw28_SetBrightness(SW28_HandleTypeDef *swObj, uint8_t b)
{
    uint8_t newBrightness = b + 1;
    uint8_t  oldBrightness = swObj->Brightness - 1; // De-wrap old brightness value
    uint32_t c;
    uint16_t scale,i;

    if(newBrightness != swObj->Brightness) { // Compare against prior value
        // Brightness has changed -- re-scale existing data in RAM

        if(oldBrightness == 0) scale = 0; // Avoid /0
        else if(b == 255) scale = 65535 / oldBrightness;
        else scale = (((uint16_t)newBrightness << 8) - 1) / oldBrightness;

        for(i=0; i<swObj->PixelLen; i++)
        {
            c = Sw28_GetPixelColor(swObj,i);	//获取16bit颜色
            c = Sw28_ScaleColor(scale, c);
            Sw28_SetPixelsColor(swObj,i,c);//设置颜色
        }
        swObj->Brightness = newBrightness;
    }
}





/****************************************************************************
* 名    称：
* 功    能：输入值0到255以获取颜色值。返回一个过渡颜色 r-g-b。
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
uint32_t Wheel(uint8_t WheelPos)
{
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85)
    {
        return Sw28_Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if(WheelPos < 170) {
        WheelPos -= 85;
        return Sw28_Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return Sw28_Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



void ShowFft12(SW28_HandleTypeDef *swObj,uint32_t *val, uint8_t color)
{
	uint32_t c;
	uint8_t i, j;
	c = GREEN / 15;
	for (i = 0; i < 12; i++)
	{
//		for (i = 0; i < 10; i++)
//		{
//			if (val[i] > 0)
//			{
//				for (j = 0; j < val[i]; j++)
//				{
//					Sw28_SetPixelsColor(&hsw28, j, c);
//				}
//			}
//		}
	Sw28_SetPixelsColor(swObj, i, 255);
	}


	Sw28_SetPixelsColor(swObj, 12, 255);
	swObj->Status == READY;
	Sw28_Show(swObj);
	HAL_Delay (100);
}

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//					效果函数
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/



/****************************************************************************
* 名    称：
* 功    能：彩虹
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void rainbow(SW28_HandleTypeDef *swObj, uint16_t wait)
{
    uint16_t i, j;
    for(j=0; j<256; j++)
    {
        for(i=0; i<swObj->PixelLen; i++)
        {
            Sw28_SetPixelsColor(swObj,i, Wheel((i+j) & 255));
        }
        swObj->Status = READY;
        Sw28_Show(swObj);
        HAL_Delay (wait);
    }
}



/****************************************************************************
* 名    称：
* 功    能：略有不同, 这使得彩虹均匀分布在整个
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void rainbowCycle(SW28_HandleTypeDef *swObj, uint16_t wait)
{
    uint16_t i, j;
    for(j=0; j<256*5; j++)
    {   // 5 cycles of all colors on wheel
        for(i=0; i< swObj->PixelLen; i++)
        {
            Sw28_SetPixelsColor(swObj,i, Wheel(((i * 256 / swObj->PixelLen) + j) & 255));
        }
        swObj->Status = READY;
        Sw28_Show(swObj);
        HAL_Delay (wait);
    }
}


/****************************************************************************
* 名    称：
* 功    能：剧场式的爬行灯。
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void theaterChase(SW28_HandleTypeDef *swObj, uint32_t c, uint16_t wait)
{
    for (int j=0; j<10; j++)
    {   //do 10 cycles of chasing
        for (int q=0; q < 3; q++)
        {
            for (uint16_t i=0; i < swObj->PixelLen; i=i+3)
            {
                Sw28_SetPixelsColor(swObj,i+q, c);    //turn every third pixel on
            }
            swObj->Status = READY;
            Sw28_Show(swObj);
            HAL_Delay(wait);

            for (uint16_t i=0; i < swObj->PixelLen; i=i+3)
            {
                Sw28_SetPixelsColor(swObj,i+q, 0);        //turn every third pixel off
            }
            swObj->Status = READY;
            Sw28_Show(swObj);
            HAL_Delay(2);
        }
    }
}


/****************************************************************************
* 名    称：
* 功    能：具有彩虹效果的剧场式爬行灯
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void theaterChaseRainbow(SW28_HandleTypeDef *swObj, uint16_t wait)
{
    uint16_t j,q,i;
    for (j=0; j < 256; j++)
    {   // cycle all 256 colors in the wheel
        for (q=0; q < 3; q++)
        {
            for (i=0; i < swObj->PixelLen; i=i+3)
            {
                Sw28_SetPixelsColor(swObj,i+q, Wheel( (i+j) % 255));    //turn every third pixel on
            }
            swObj->Status = READY;
            Sw28_Show(swObj);
            HAL_Delay(wait);

            for (i=0; i < swObj->PixelLen; i=i+3)
            {
                Sw28_SetPixelsColor(swObj,i+q, 0);        //turn every third pixel off
            }
            swObj->Status = READY;
            Sw28_Show(swObj);
            HAL_Delay(wait);
        }
    }
}

/****************************************************************************
* 名    称：
* 功    能：颜色填充一个后的点
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void colorWipe(SW28_HandleTypeDef *swObj, uint32_t color, uint16_t wait)
{
    uint16_t i=0;
//    uint8_t temp_val;
//    uint8_t temp[3];
//    uint32_t col;
//    temp_val=10-brightness;
//
//    temp[0] = color;
//    temp[1]= color >>8;
//    temp[2] = color >>16;
//    for(i=0;i<3;i++)
//    {
//      temp[i]=temp[i]/(0x10*temp_val);
//    }
  //  col = (((uint32_t)temp[2])<<16)+(((uint32_t)temp[1])<<8)+temp[0];
    for( i=0; i<swObj->PixelLen; i++)
    {
        Sw28_SetPixelsColor(swObj,i,color);
        swObj->Status = READY;
        Sw28_Show(swObj);
        HAL_Delay(wait);
    }
}





/****************************************************************************
* 名    称：
* 功    能：指定颜色闪动
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void blink_all(SW28_HandleTypeDef *swObj, uint32_t color, uint8_t times, uint16_t delay_time)
{
    uint8_t i;
    for (i = 0; i < times; i++) {
        Sw28_SetAllColor(swObj, color);
        swObj->Status = READY;
        Sw28_Show(swObj);
        HAL_Delay(delay_time);

        Sw28_AllBlock(swObj);	// off
        swObj->Status = READY;
        Sw28_Show(swObj);
        HAL_Delay(delay_time);
    }
}
/****************************************************************************
* 名    称：
* 功    能：呼吸
* 入口参数：
* 出口参数：
* 说    明：
****************************************************************************/
void breath_all(SW28_HandleTypeDef *swObj, uint32_t color)
{
	static int16_t i=0;
	static uint8_t flag=0;
	if(flag==0)
	{
	  i++;
	  if(i>20)
		  flag=1;
	}
	else
	{
		i--;
		if(i<2)
		{
			flag=0;
		   HAL_Delay(1);
		}
	}
    if(color == RED)
	  Sw28_SetAllColor(swObj, Sw28_Color(i, 0, 0));
    else if(color == GREEN)
    {
      Sw28_SetAllColor(swObj, Sw28_Color(0, i, 0));
	}
    else if(color == BLUE)
    {
      Sw28_SetAllColor(swObj, Sw28_Color(0, 0, i));
	}
    else if(color == PURPLE)
    {
      Sw28_SetAllColor(swObj, Sw28_Color(i, 0, i));
    }
    else if(color == YELLOW )
    {
      Sw28_SetAllColor(swObj, Sw28_Color(i, i, 0));
    }
    else if(color == TURQUOISE)
    {
      Sw28_SetAllColor(swObj, Sw28_Color(0, i, i));
    }
	swObj->Status = READY;
	Sw28_Show(swObj);
	HAL_Delay(20);
}



/**
  * @brief  Function called from DMA1 IRQ Handler when Tx transfer is completed
  * @param  None
  * @retval None
  */
void DMA1_TransmitComplete_Callback(void)
{

}



/**
  * @brief  Function called from DMA1 IRQ Handler when Rx transfer is completed
  * @param  None
  * @retval None
  */
void DMA1_ReceiveComplete_Callback(void)
{

}






/**
  * @brief  Function called in case of error detected in SPI IT Handler
  * @param  None
  * @retval None
  */
void SPI_TransferError_Callback(void)
{


}

