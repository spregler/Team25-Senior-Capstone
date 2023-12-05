/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define SPI4_NSS_Pin GPIO_PIN_14
#define SPI4_NSS_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_8
#define DC_GPIO_Port GPIOD
#define AD1_Pin GPIO_PIN_9
#define AD1_GPIO_Port GPIOD
#define AD0_Pin GPIO_PIN_10
#define AD0_GPIO_Port GPIOD
#define NRST_DAC_Pin GPIO_PIN_11
#define NRST_DAC_GPIO_Port GPIOD
#define PLAY_BUTTON_Pin GPIO_PIN_9
#define PLAY_BUTTON_GPIO_Port GPIOC
#define PLAY_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define PAUSE_BUTTON_Pin GPIO_PIN_10
#define PAUSE_BUTTON_GPIO_Port GPIOC
#define PAUSE_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define SKIPF_BUTTON_Pin GPIO_PIN_11
#define SKIPF_BUTTON_GPIO_Port GPIOC
#define SKIPF_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define VOL_UP_BUTTON_Pin GPIO_PIN_12
#define VOL_UP_BUTTON_GPIO_Port GPIOC
#define VOL_UP_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define VOL_DOWN_BUTTON_Pin GPIO_PIN_0
#define VOL_DOWN_BUTTON_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
