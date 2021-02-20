#include "pwm.h"

void PWM_Config(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Impulse, uint32_t Counter)
{
  htim->Instance->CNT = Counter;
  switch (Channel)
  {
    case TIM_CHANNEL_1: htim->Instance->CCR1 = Impulse;
                        break;
    case TIM_CHANNEL_2: htim->Instance->CCR2 = Impulse;
                        break;
    case TIM_CHANNEL_3: htim->Instance->CCR3 = Impulse;
                        break;
    case TIM_CHANNEL_4: htim->Instance->CCR4 = Impulse;
                        break;
  }
}

void PWM_Enable(TIM_HandleTypeDef *htim)
{
  if (!(htim->Instance->CR1 & TIM_CR1_CEN))
    htim->Instance->CR1 |= TIM_CR1_CEN;
}

void PWM_Disable(TIM_HandleTypeDef *htim)
{
  if (htim->Instance->CR1 & TIM_CR1_CEN)
    htim->Instance->CR1 &= ~TIM_CR1_CEN;
}