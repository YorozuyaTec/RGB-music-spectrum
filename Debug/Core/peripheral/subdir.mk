################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/peripheral/adc.c \
../Core/peripheral/dma.c \
../Core/peripheral/gpio.c \
../Core/peripheral/spi.c \
../Core/peripheral/stm32f4xx_hal_msp.c \
../Core/peripheral/stm32f4xx_it.c \
../Core/peripheral/syscalls.c \
../Core/peripheral/sysmem.c \
../Core/peripheral/system_stm32f4xx.c \
../Core/peripheral/tim.c \
../Core/peripheral/usart.c 

OBJS += \
./Core/peripheral/adc.o \
./Core/peripheral/dma.o \
./Core/peripheral/gpio.o \
./Core/peripheral/spi.o \
./Core/peripheral/stm32f4xx_hal_msp.o \
./Core/peripheral/stm32f4xx_it.o \
./Core/peripheral/syscalls.o \
./Core/peripheral/sysmem.o \
./Core/peripheral/system_stm32f4xx.o \
./Core/peripheral/tim.o \
./Core/peripheral/usart.o 

C_DEPS += \
./Core/peripheral/adc.d \
./Core/peripheral/dma.d \
./Core/peripheral/gpio.d \
./Core/peripheral/spi.d \
./Core/peripheral/stm32f4xx_hal_msp.d \
./Core/peripheral/stm32f4xx_it.d \
./Core/peripheral/syscalls.d \
./Core/peripheral/sysmem.d \
./Core/peripheral/system_stm32f4xx.d \
./Core/peripheral/tim.d \
./Core/peripheral/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/peripheral/adc.o: ../Core/peripheral/adc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/adc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/dma.o: ../Core/peripheral/dma.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/dma.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/gpio.o: ../Core/peripheral/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/spi.o: ../Core/peripheral/spi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/stm32f4xx_hal_msp.o: ../Core/peripheral/stm32f4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/stm32f4xx_it.o: ../Core/peripheral/stm32f4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/syscalls.o: ../Core/peripheral/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/sysmem.o: ../Core/peripheral/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/system_stm32f4xx.o: ../Core/peripheral/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/tim.o: ../Core/peripheral/tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/peripheral/usart.o: ../Core/peripheral/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -D__TARGET_FPU_VFP -DUSE_HAL_DRIVER -DATM_MATH_CM4 -DSTM32F401xE -DDEBUG -c -I"../Drivers/CMSIS/DSP_Lib" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/peripheral/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

