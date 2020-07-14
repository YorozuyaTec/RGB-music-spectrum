################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/fft/fft.c 

OBJS += \
./Core/fft/fft.o 

C_DEPS += \
./Core/fft/fft.d 


# Each subdirectory must supply rules for building sources it contributes
Core/fft/fft.o: ../Core/fft/fft.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/fft/fft.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

