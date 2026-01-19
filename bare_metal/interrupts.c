#include "stm32g4xx_hal.h"

// Standard C function (no name mangling issues)
void SysTick_Handler(void) {
  HAL_IncTick();
}