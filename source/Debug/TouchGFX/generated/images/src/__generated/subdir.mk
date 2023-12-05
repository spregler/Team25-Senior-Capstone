################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_power_settings_new_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_pause_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_play_arrow_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_next_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_previous_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_add_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_remove_50_50_000000.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_light_theme_images_widgets_lineprogress_backgrounds_line_normal_small_0.cpp 

OBJS += \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_power_settings_new_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_pause_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_play_arrow_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_next_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_previous_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_add_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_remove_50_50_000000.svg.o \
./TouchGFX/generated/images/src/__generated/image_light_theme_images_widgets_lineprogress_backgrounds_line_normal_small_0.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_power_settings_new_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_pause_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_play_arrow_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_next_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_previous_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_add_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_remove_50_50_000000.svg.d \
./TouchGFX/generated/images/src/__generated/image_light_theme_images_widgets_lineprogress_backgrounds_line_normal_small_0.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__generated/%.o TouchGFX/generated/images/src/__generated/%.su TouchGFX/generated/images/src/__generated/%.cyclo: ../TouchGFX/generated/images/src/__generated/%.cpp TouchGFX/generated/images/src/__generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"/Users/spregler/STM32CubeIDE/workspace_1.13.1/LCD/STM32F469" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated:
	-$(RM) ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_power_settings_new_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_power_settings_new_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_power_settings_new_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_power_settings_new_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_pause_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_pause_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_pause_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_pause_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_play_arrow_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_play_arrow_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_play_arrow_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_play_arrow_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_next_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_next_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_next_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_next_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_previous_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_previous_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_previous_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_av_skip_previous_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_add_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_add_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_add_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_add_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_remove_50_50_000000.svg.cyclo ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_remove_50_50_000000.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_remove_50_50_000000.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_content_remove_50_50_000000.svg.su ./TouchGFX/generated/images/src/__generated/image_light_theme_images_widgets_lineprogress_backgrounds_line_normal_small_0.cyclo ./TouchGFX/generated/images/src/__generated/image_light_theme_images_widgets_lineprogress_backgrounds_line_normal_small_0.d ./TouchGFX/generated/images/src/__generated/image_light_theme_images_widgets_lineprogress_backgrounds_line_normal_small_0.o ./TouchGFX/generated/images/src/__generated/image_light_theme_images_widgets_lineprogress_backgrounds_line_normal_small_0.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

