#include "loop.h"

int loop(void)
{
  Constructor_Analog(&Analog);
  
  GPIOE->ODR |= RELAY_Pin;
  
  HAL_TIM_Base_Start_IT(&htim6);

         /* ведомые таймеры */
  PWM_Config(&htim1, TIM_CHANNEL_2, IMPULSE_4, COUNTER_7);
  PWM_Config(&htim1, TIM_CHANNEL_1, IMPULSE_1, COUNTER_7);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  
  PWM_Config(&htim4, TIM_CHANNEL_4, IMPULSE_1, COUNTER_4);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
  
         /* set the distance */  
  DISTANCE = Distance(GPIOE);

         /* Super-master TIM */
  HAL_TIM_Base_Start_IT(&htim5);
  
  while(1) {
    DISTANCE = Distance(GPIOE);
  }
}