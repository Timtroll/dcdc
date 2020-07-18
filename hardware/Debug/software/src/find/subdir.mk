################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/dcdc/software/src/find/find.c \
C:/dcdc/software/src/find/find_internal.c 

OBJS += \
./software/src/find/find.o \
./software/src/find/find_internal.o 

C_DEPS += \
./software/src/find/find.d \
./software/src/find/find_internal.d 


# Each subdirectory must supply rules for building sources it contributes
software/src/find/find.o: C:/dcdc/software/src/find/find.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F334x8 -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"C:/dcdc/software/inc/static_malloc" -I"C:/dcdc/software/inc/find" -I"C:/dcdc/software/inc/parser" -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I"C:/dcdc/software/inc" -I"C:/dcdc/software/inc/menu" -I"C:/dcdc/software/inc/system_info" -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Core/Inc -I"C:/dcdc/software/inc/measurements" -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I"C:/dcdc/software/inc/system_config" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"software/src/find/find.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
software/src/find/find_internal.o: C:/dcdc/software/src/find/find_internal.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F334x8 -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"C:/dcdc/software/inc/static_malloc" -I"C:/dcdc/software/inc/find" -I"C:/dcdc/software/inc/parser" -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I"C:/dcdc/software/inc" -I"C:/dcdc/software/inc/menu" -I"C:/dcdc/software/inc/system_info" -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Core/Inc -I"C:/dcdc/software/inc/measurements" -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I"C:/dcdc/software/inc/system_config" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"software/src/find/find_internal.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

