#include "edge.h"

average Average; 

void Average_Summary(converter* analog, average* average)
{
  average->summ += analog->buffer[analog->index];
}

void Moving_Average(converter* analog, average* average)
{
  average->value = average->summ / (FILTER_MODE - 1);
  average->summ -= analog->buffer[analog->replace];
}

void Edge_Setting(converter* analog, average* average)
{
  analog->low = average->value - average->factor;
  analog->high = average->value + average->factor;
  analog->low < LEVEL_LOW ? (ADC1->LTR = LEVEL_LOW) : (ADC1->LTR = analog->low);  
  analog->low > LEVEL_HIGH ? (ADC1->LTR = LEVEL_LOW) : (ADC1->LTR = analog->low);
  analog->high > LEVEL_HIGH ? (ADC1->HTR = LEVEL_HIGH) : (ADC1->HTR = analog->high);
}