#include "tim_init.h"

bool slave = false;
bool master = true;

void TIM_Reset(TIM_HandleTypeDef *htim)
{
  htim->Instance->DIER &= ~TIM_DIER_UIE;
  htim->Instance->CR1 &= ~TIM_CR1_CEN;
  htim->Instance->SR = 0;
}

void TIM_Config(TIM_HandleTypeDef *htim, uint16_t counter)
{
  htim->Instance->SR = 0;
  htim->Instance->CR1 = 0;
  htim->Instance->PSC = (30 * 1000) - 1;
  htim->Instance->ARR = counter;
  htim->Instance->DIER = TIM_DIER_UIE;
  htim->Instance->CR1 = TIM_CR1_CEN;
  htim->Instance->CNT = 0;
}