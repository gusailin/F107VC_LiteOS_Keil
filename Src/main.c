/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "mcu_init.h"
#include "ethernetif.h"
#include "los_defered.h"

#include "los_base.h"
#include "los_sys.h"
#include "los_task.h"
#include "los_typedef.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
UINT32 g_uwMainTaskID;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
extern void LwIP_init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void mainTask(void)
{
  LwIP_init();

  for (;;)
  {
    LOS_TaskDelay(100);
  }
}

UINT32 createMainTask(void)
{
  UINT32 uwRet = LOS_OK;
  TSK_INIT_PARAM_S task;

  task.usTaskPrio = 1;
  task.pcName = "main_task";
  task.pfnTaskEntry = (TSK_ENTRY_FUNC)mainTask;
  task.uwStackSize = 1024;

  uwRet = LOS_TaskCreate(&g_uwMainTaskID, &task);
  if (LOS_OK != uwRet)
  {
    return uwRet;
  }
  return uwRet;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  UINT32 uwRet = LOS_OK;

  HardWare_Init();

  /* USER CODE BEGIN 2 */
  uwRet = LOS_KernelInit();
  if (LOS_OK != uwRet)
  {
    return LOS_NOK;
  }

  (void)osDeferedTaskInit();
  (void)createMainTask();
  (void)LOS_Start();
  /* USER CODE END 2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
