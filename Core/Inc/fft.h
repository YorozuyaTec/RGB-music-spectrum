/*
 * fft.h
 *
 *  Created on: Jun 23, 2020
 *      Author: Sunny
 */

#ifndef INC_FFT_H_
#define INC_FFT_H_

#include "math.h"
#include "adc.h"
#include "usart.h"

extern uint32_t fft_val[12]; //12段FFT的值

void fft_1024(void); //FFT 测试

#endif /* INC_FFT_H_ */
