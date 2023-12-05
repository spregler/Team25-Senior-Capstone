################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F469/stm32469i_discovery_ts.c 

C_DEPS += \
./STM32F469/stm32469i_discovery_ts.d 

OBJS += \
./STM32F469/stm32469i_discovery_ts.o 


# Each subdirectory must supply rules for building sources it contributes
STM32F469/%.o STM32F469/%.su STM32F469/%.cyclo: ../STM32F469/%.c STM32F469/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"/Users/spregler/STM32CubeIDE/workspace_1.13.1/LCD/Components/Common" -I"/Users/spregler/STM32CubeIDE/workspace_1.13.1/LCD/Components/ft6x06" -I"/Users/spregler/STM32CubeIDE/workspace_1.13.1/LCD/STM32F469" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-STM32F469

clean-STM32F469:
	-$(RM) ./STM32F469/stm32469i_discovery_ts.cyclo ./STM32F469/stm32469i_discovery_ts.d ./STM32F469/stm32469i_discovery_ts.o ./STM32F469/stm32469i_discovery_ts.su

.PHONY: clean-STM32F469

