#ifndef __EDGE_H
#define __EDGE_H

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "analog.h"

#define LEVEL_MODE              5000                                            //частота расчёта порога (половина буффера АЦП)

typedef struct
{
  uint32_t summ;
  uint16_t value;
  uint16_t factor;
} average;

                                /* объявления структур */ 
extern average Average;

                                /* объявления функций */
void Average_Summary(converter* analog, average* average);
void Moving_Average(converter* analog, average* average);
void Edge_Setting(converter* analog, average* average);

#endif /* __EDGE_H */