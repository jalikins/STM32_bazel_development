#include <atomic>

#include "stm32g4xx_hal.h"


#define HEARTBEAT_LED_GPIO_Port GPIOA
#define HEARTBEAT_LED_Pin       GPIO_PIN_1

static void MpuConfig(void);
static void SystemClockConfig(void);
static void GpioInit(void);
static void ErrorHandler(void);

static std::atomic<bool> g_flag = false;

class StaticConstructorTest {
 public:
  StaticConstructorTest() { g_flag = true; }
};

static StaticConstructorTest g_static_object;

int main(void) {
  // Enable Power Clock
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  // Initialize HAL
  HAL_Init();

  // Configure System
  MpuConfig();
  SystemClockConfig();
  GpioInit();

  while (true) {
    
    HAL_Delay(500); // Blink every 500ms
    HAL_GPIO_TogglePin(HEARTBEAT_LED_GPIO_Port, HEARTBEAT_LED_Pin);
  }

  return 0;
}

static void MpuConfig(void) { // taken directly from STM32G4 reference manual
  HAL_MPU_Disable();
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x0;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}


static void SystemClockConfig(void) { // values in this are changed but structure from stm32
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  // Enable HSE (External Crystal)
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  
  // Note: If using a Crystal (2 legs), use RCC_HSE_ON.

  RCC_OscInitStruct.HSEState = RCC_HSE_ON; 
  
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE; // Running directly off HSE for simplicity

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    ErrorHandler(); 
  }

  // 2. Select HSE as System Clock Source (16MHz)
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
    ErrorHandler();
  }
}

static void GpioInit(void) {
  __HAL_RCC_GPIOA_CLK_ENABLE(); 
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef gpio_init = {0};
  gpio_init.Pin = HEARTBEAT_LED_Pin;
  gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
  gpio_init.Pull = GPIO_NOPULL;
  gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(HEARTBEAT_LED_GPIO_Port, &gpio_init);
}

static void ErrorHandler(void) {
  __disable_irq();
  while (1) {
  }
}