/*
 * fft.c
 *
 *  Created on: Jun 23, 2020
 *      Author: Sunny
 */

#include "fft.h"
#include "stdio.h"

#include "arm_math.h"

#define NPT  1024  //1024点FFT
#define Fs 65625  //采样频率 5120Hz 频率分辨率 64Hz
#define PI2 6.28318530717959


float  testInput_f32[NPT];
float  testOutput_f32[NPT];
float  testOutput[NPT];

uint8_t fftshow[12]={1,2,3,4,5,6,25,40,50,60  ,70,80};
uint32_t fft_val[12]; //12段FFT的值

void fft_1024() //FFT 1024点
{
  uint16_t i;
  arm_rfft_fast_instance_f32 S;

  /* 实数序列FFT长度 */
  uint16_t fftSize = NPT;
  /* 正变换 */
    uint8_t ifftFlag = 0;

  /* 初始化结构体S中的参数 */
   arm_rfft_fast_init_f32(&S, fftSize);

    /* 按照实部，虚部，实部，虚部..... 的顺序存储数据 */
//  for(i=0; i<1024; i++)
//  {
//    /*3种频率 50Hz 2500Hz 2550Hz */
//    testInput_f32[i] = 1000*arm_sin_f32(PI2*i*50.0/Fs) +
//               2000*arm_sin_f32(PI2*i*2500.0/Fs)  +
//               3000*arm_sin_f32(PI2*i*2550.0/Fs);
//  }
//	for(i=0; i<1024; i++)
//	{
//			printf("%f\n", testInput_f32[i]);
//		  HAL_Delay(10);
//  }

  /* 1024点实序列快速FFT */
  arm_rfft_fast_f32(&S, hfsc.fft_input, testOutput_f32, ifftFlag);

  /* 为了方便跟函数arm_cfft_f32计算的结果做对比，这里求解了1024组模值，实际函数arm_rfft_fast_f32
     只求解出了512组
  */
  arm_cmplx_mag_f32(testOutput_f32, testOutput, fftSize);

  /* 串口打印求解的模值 */
 // for(i=0; i<fftSize/2; i++)
  for(i=1; i<100; i+=2)
  {
//		if(testOutput[i]>100)
//		{
//			__NOP();
//		}
   // DebugLog("f[%d]=%f\n",i, testOutput[i]);
   //DebugLog("%f\n", testOutput[fftshow[i]]);
   DebugLog("%f\n", testOutput[i]);

  }
}
