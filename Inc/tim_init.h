#ifndef __TIM_INIT_H
#define __TIM_INIT_H

#include <stdbool.h>

#include "tim.h"

extern bool slave;
extern bool master;

void TIM_Reset(TIM_HandleTypeDef *htim);
void TIM_Config(TIM_HandleTypeDef *htim, uint16_t counter);

#endif /* __TIM_INIT_H */