/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define MOTOR_BREW4_Pin GPIO_PIN_2
#define MOTOR_BREW4_GPIO_Port GPIOE
#define MOTOR_BREW4E3_Pin GPIO_PIN_3
#define MOTOR_BREW4E3_GPIO_Port GPIOE
#define MOTOR_GRINDER1_Pin GPIO_PIN_4
#define MOTOR_GRINDER1_GPIO_Port GPIOE
#define MOTOR_GRINDER2_Pin GPIO_PIN_5
#define MOTOR_GRINDER2_GPIO_Port GPIOE
#define MOTOR_GRINDER3_Pin GPIO_PIN_6
#define MOTOR_GRINDER3_GPIO_Port GPIOE
#define MOTOR_ENCODER_Pin GPIO_PIN_0
#define MOTOR_ENCODER_GPIO_Port GPIOC
#define MOTOR_ENCODERC1_Pin GPIO_PIN_1
#define MOTOR_ENCODERC1_GPIO_Port GPIOC
#define MOTOR_ENCODERC2_Pin GPIO_PIN_2
#define MOTOR_ENCODERC2_GPIO_Port GPIOC
#define MOTOR_ENCODERC3_Pin GPIO_PIN_3
#define MOTOR_ENCODERC3_GPIO_Port GPIOC
#define ENCODER2_CHANNEL1_Pin GPIO_PIN_0
#define ENCODER2_CHANNEL1_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_1
#define LED_GPIO_Port GPIOA
#define MOTOR_GRINDER4_Pin GPIO_PIN_2
#define MOTOR_GRINDER4_GPIO_Port GPIOA
#define PWM1_CHANNEL1_Pin GPIO_PIN_9
#define PWM1_CHANNEL1_GPIO_Port GPIOE
#define PWM1_CHANNEL2_Pin GPIO_PIN_11
#define PWM1_CHANNEL2_GPIO_Port GPIOE
#define PWM1_CHANNEL3_Pin GPIO_PIN_13
#define PWM1_CHANNEL3_GPIO_Port GPIOE
#define PWM1_CHANNEL4_Pin GPIO_PIN_14
#define PWM1_CHANNEL4_GPIO_Port GPIOE
#define SELENOIDVALVE5_Pin GPIO_PIN_11
#define SELENOIDVALVE5_GPIO_Port GPIOB
#define SELENOIDVALVE4_Pin GPIO_PIN_12
#define SELENOIDVALVE4_GPIO_Port GPIOB
#define SELENOIDVALVE3_Pin GPIO_PIN_13
#define SELENOIDVALVE3_GPIO_Port GPIOB
#define SELENOIDVALVE2_Pin GPIO_PIN_14
#define SELENOIDVALVE2_GPIO_Port GPIOB
#define SELENOIDVALVE1_Pin GPIO_PIN_15
#define SELENOIDVALVE1_GPIO_Port GPIOB
#define WATER_PUMP2_Pin GPIO_PIN_9
#define WATER_PUMP2_GPIO_Port GPIOD
#define WATER_PUMP1_Pin GPIO_PIN_10
#define WATER_PUMP1_GPIO_Port GPIOD
#define BOILER_Pin GPIO_PIN_11
#define BOILER_GPIO_Port GPIOD
#define ENCODER4_CHANNEL1_Pin GPIO_PIN_12
#define ENCODER4_CHANNEL1_GPIO_Port GPIOD
#define ENCODER4_CHANNEL2_Pin GPIO_PIN_13
#define ENCODER4_CHANNEL2_GPIO_Port GPIOD
#define ENCODER8_CHANNEL1_Pin GPIO_PIN_6
#define ENCODER8_CHANNEL1_GPIO_Port GPIOC
#define ENCODER8_CHANNEL2_Pin GPIO_PIN_7
#define ENCODER8_CHANNEL2_GPIO_Port GPIOC
#define MOTOR_ENCODERD0_Pin GPIO_PIN_0
#define MOTOR_ENCODERD0_GPIO_Port GPIOD
#define MOTOR_ENCODERD1_Pin GPIO_PIN_1
#define MOTOR_ENCODERD1_GPIO_Port GPIOD
#define MOTOR_BREW1_Pin GPIO_PIN_6
#define MOTOR_BREW1_GPIO_Port GPIOD
#define MOTOR_BREW1D7_Pin GPIO_PIN_7
#define MOTOR_BREW1D7_GPIO_Port GPIOD
#define ENCODER2_CHANNEL2_Pin GPIO_PIN_3
#define ENCODER2_CHANNEL2_GPIO_Port GPIOB
#define ENCODER3_CHANNEL3_Pin GPIO_PIN_4
#define ENCODER3_CHANNEL3_GPIO_Port GPIOB
#define ENCODER3_CHANNEL2_Pin GPIO_PIN_5
#define ENCODER3_CHANNEL2_GPIO_Port GPIOB
#define MOTOR_BREW2_Pin GPIO_PIN_6
#define MOTOR_BREW2_GPIO_Port GPIOB
#define MOTOR_BREW2B7_Pin GPIO_PIN_7
#define MOTOR_BREW2B7_GPIO_Port GPIOB
#define MOTOR_ENCODERB8_Pin GPIO_PIN_8
#define MOTOR_ENCODERB8_GPIO_Port GPIOB
#define MOTOR_ENCODERB9_Pin GPIO_PIN_9
#define MOTOR_ENCODERB9_GPIO_Port GPIOB
#define MOTOR_BREW3_Pin GPIO_PIN_0
#define MOTOR_BREW3_GPIO_Port GPIOE
#define MOTOR_BREW3E1_Pin GPIO_PIN_1
#define MOTOR_BREW3E1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
