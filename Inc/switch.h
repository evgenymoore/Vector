#ifndef __SWITCH_H
#define __SWITCH_H

#include "gpio.h"

typedef enum { MODE_0, MODE_1, MODE_2, MODE_3 } MODE;

extern MODE DISTANCE;

MODE Distance(GPIO_TypeDef* GPIOx);
uint16_t Sense(GPIO_TypeDef* GPIOx);

#endif /* __SWITCH_H */