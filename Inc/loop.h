#ifndef __LOOP_H
#define __LOOP_H

#include "pwm.h"
#include "edge.h"
#include "alarm.h"
#include "filter.h"
#include "switch.h"
#include "tim_init.h"

extern uint8_t rxbuff[5];

int loop(void);

#endif /* __LOOP_H */