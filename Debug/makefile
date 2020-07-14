################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/ws2812b/subdir.mk
-include Core/peripheral/subdir.mk
-include Core/main/subdir.mk
-include Core/fft/subdir.mk
-include Core/Startup/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
RGB_FSC.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
RGB_FSC.list \

OBJCOPY_BIN += \
RGB_FSC.bin \


# All Target
all: RGB_FSC.elf secondary-outputs

# Tool invocations
RGB_FSC.elf: $(OBJS) $(USER_OBJS) D:\VdioProject\RGB_FSC_CODE\STM32F401CEUX_FLASH.ld
	arm-none-eabi-gcc -o "RGB_FSC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\VdioProject\RGB_FSC_CODE\STM32F401CEUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="RGB_FSC.map" -Wl,--gc-sections -static "D:\VdioProject\RGB_FSC_CODE\Core\fft\libarm_cortexM4lf_math.a" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

RGB_FSC.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "RGB_FSC.list"
	@echo 'Finished building: $@'
	@echo ' '

RGB_FSC.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "RGB_FSC.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
