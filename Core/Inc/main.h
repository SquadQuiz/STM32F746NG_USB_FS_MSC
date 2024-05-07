/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************

\* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_MAIN_H_
#define INC_MAIN_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_msc.h"
#include "usbd_msc_storage.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_sd.h"

/* Exported types ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void Error_Handler(void);

#endif /* INC_MAIN_H_ */
