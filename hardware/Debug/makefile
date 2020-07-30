################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/uart_data_transfer/subdir.mk
-include src/system_info/subdir.mk
-include src/system_config/subdir.mk
-include src/static_malloc/subdir.mk
-include src/parser/subdir.mk
-include src/menu/subdir.mk
-include src/measurements/subdir.mk
-include src/find/subdir.mk
-include src/dl_list/subdir.mk
-include src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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
dcdc.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
dcdc.list \

OBJCOPY_BIN += \
dcdc.bin \


# All Target
all: dcdc.elf secondary-outputs

# Tool invocations
dcdc.elf: $(OBJS) $(USER_OBJS) C:\dcdc\hardware\STM32F334R8TX_FLASH.ld
	arm-none-eabi-gcc -o "dcdc.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\dcdc\hardware\STM32F334R8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="dcdc.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

dcdc.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "dcdc.list"
	@echo 'Finished building: $@'
	@echo ' '

dcdc.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "dcdc.bin"
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
