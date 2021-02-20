#ifndef __PWM_H
#define __PWM_H

#include "tim.h"

#define IMPULSE_0               COUNTER_0       
#define COUNTER_0               0
#define IMPULSE_1               COUNTER_1
#define COUNTER_1               1
#define IMPULSE_2               COUNTER_2
#define COUNTER_2               2
#define IMPULSE_3               COUNTER_3
#define COUNTER_3               3
#define IMPULSE_4               COUNTER_4
#define COUNTER_4               4
#define IMPULSE_5               COUNTER_5
#define COUNTER_5               5
#define IMPULSE_6               COUNTER_6
#define COUNTER_6               6
#define IMPULSE_7               COUNTER_7
#define COUNTER_7               7

void PWM_Config(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Impulse, uint32_t Counter);
void PWM_Enable(TIM_HandleTypeDef *htim);
void PWM_Disable(TIM_HandleTypeDef *htim);

#endif /* __PWM_H */