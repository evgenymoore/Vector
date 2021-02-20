#ifndef __EDGE_H
#define __EDGE_H

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "analog.h"

#define LEVEL_MODE              5000                                            //частота расчёта порога (половина буффера АЦП)

typedef struct
{
  bool state;
  uint32_t summ;
  uint16_t value;
} average;

typedef struct
{
  uint32_t counter;
  uint16_t factor;
  double variance;
  double sigma;
} deviation;

                                /* объявления структур */ 
extern average Average;
extern deviation Deviation;

                                /* объявления функций */
void Average_Summary(converter* analog, average* average);
void Moving_Average(converter* analog, average* average);
void Level_Setting(converter* analog, average* average, deviation* deviation);
void Edge_Setting(converter* analog, average* average, uint16_t factor);
void Standart_Deviation(converter* analog, average* average, deviation* deviation);

#endif /* __EDGE_H */