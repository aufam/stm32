/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#ifdef F103_USE_CAN
#undef HAL_PCD_MODULE_ENABLED
#endif
#ifdef F103_USE_USB
#undef HAL_CAN_MODULE_ENABLED
#endif
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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define button_right_Pin GPIO_PIN_14
#define button_right_GPIO_Port GPIOC
#define button_right_EXTI_IRQn EXTI15_10_IRQn
#define button_up_Pin GPIO_PIN_15
#define button_up_GPIO_Port GPIOC
#define button_up_EXTI_IRQn EXTI15_10_IRQn
#define CS_Pin GPIO_PIN_4
#define CS_GPIO_Port GPIOA
#define RESET_Pin GPIO_PIN_0
#define RESET_GPIO_Port GPIOB
#define button_down_Pin GPIO_PIN_12
#define button_down_GPIO_Port GPIOB
#define button_down_EXTI_IRQn EXTI15_10_IRQn
#define button_rot_Pin GPIO_PIN_13
#define button_rot_GPIO_Port GPIOB
#define button_rot_EXTI_IRQn EXTI15_10_IRQn
#define button_left_Pin GPIO_PIN_5
#define button_left_GPIO_Port GPIOB
#define button_left_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
