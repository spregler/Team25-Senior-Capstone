################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/ft6x06/ft6x06.c 

C_DEPS += \
./Components/ft6x06/ft6x06.d 

OBJS += \
./Components/ft6x06/ft6x06.o 


# Each subdirectory must supply rules for building sources it contributes
Components/ft6x06/%.o Components/ft6x06/%.su Components/ft6x06/%.cyclo: ../Components/ft6x06/%.c Components/ft6x06/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"/Users/spregler/STM32CubeIDE/workspace_1.13.1/LCD/Components/Common" -I"/Users/spregler/STM32CubeIDE/workspace_1.13.1/LCD/Components/ft6x06" -I"/Users/spregler/STM32CubeIDE/workspace_1.13.1/LCD/STM32F469" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-ft6x06

clean-Components-2f-ft6x06:
	-$(RM) ./Components/ft6x06/ft6x06.cyclo ./Components/ft6x06/ft6x06.d ./Components/ft6x06/ft6x06.o ./Components/ft6x06/ft6x06.su

.PHONY: clean-Components-2f-ft6x06

