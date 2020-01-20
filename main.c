/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  **Initialization  MH-ET-LIVE display algorithm "Normal Display" datasheet SSD 1608-1.2 (P. 42)
  *STM32F030F4Px HAL SPI
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define RESET_TIME	200
#define WHITE	0xFF
#define BLACK	0x00
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  uint8_t data;
  //----------------RESET
  	LL_mDelay(RESET_TIME);
  	LL_GPIO_ResetOutputPin(RST_GPIO_Port, RST_Pin);
  	LL_mDelay(RESET_TIME);
  	LL_GPIO_SetOutputPin(RST_GPIO_Port, RST_Pin);
  	LL_mDelay(RESET_TIME);
  	//-------------- Driver Output control
  	LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
  	data = 0x01;
  	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		//display height
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0xc7;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		data = 0x00;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		//GD  SM  TB
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
  	//------------------
  	//--------------Gate Driving voltage Control
  	LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
  	data = 0x03;
  	HAL_SPI_Transmit(&hspi1, &data, 1, 1);

		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0xEA;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
  	//--------------
  	//--------------Source Driving	voltage Control
	data = 0x04;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);

		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x0A;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Set dummy line period
	data = 0x3A;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x02;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Set Gate line width
	data = 0x3B;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x08;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Border Waveform Control
	data = 0x3C;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x71;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Data Entry mode setting
	data = 0x11;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x03;
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Set RAM X - address Start / End position
	data = 0x44;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x00; //xDot -start
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		data = 0x18; //xDot/8 -end
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------Set RAM X - address Start / End position
	data = 0x45;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x00; //yDot/8 start
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		data = 0x00; //yDot/8 start
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		data = 0xC7; //yDot%256
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		data = 0x00; //yDot/256
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Set RAM X address counter
	data = 0x4E;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x00; //
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Set RAM X address counter
	data = 0x4F;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0x00; //
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		data = 0x00; //
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------Write RAM
	data = 0x24;
	HAL_SPI_Transmit(&hspi1, &data, 1, 1);
	LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
	data = BLACK;
	int i;
	for(i = 0; i < 2500; i++)
	{
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);

	}
	data = WHITE;
	for(i = 0; i < 2500; i++)
	{
		HAL_SPI_Transmit(&hspi1, &data, 1, 1);
	}
	LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Display Update  Control 2
	data = 0x22;
	HAL_SPI_Transmit(&hspi1, &data, 1, 10);
		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin);
		data = 0xFF; //
		HAL_SPI_Transmit(&hspi1, &data, 1, 10);
		LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin);
	//--------------
	//--------------Master Activation
	data = 0x20;
	HAL_SPI_Transmit(&hspi1, &data, 1, 10);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);

  if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_1)
  {
  Error_Handler();  
  }
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {
    
  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE_DIV_1, LL_RCC_PLL_MUL_6);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {
    
  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  
  }
  LL_Init1msTick(48000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(48000000);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
