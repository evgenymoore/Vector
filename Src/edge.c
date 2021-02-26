#include "edge.h"

average Average; 

void Average_Summary(converter* analog, average* average)
{
  average->summ += analog->buffer[analog->index];
}

void Moving_Average(converter* analog, average* average)
{
  average->value = average->summ / (SIZE);
  average->summ -= analog->buffer[analog->replace];
}

void Edge_Setting(converter* analog, average* average)
{
  analog->high = average->value + average->factor;
  (analog->high > LEVEL_HIGH) ? (ADC1->HTR = LEVEL_HIGH) : (ADC1->HTR = analog->high);
  
  analog->low = average->value - average->factor;
  if ((analog->low < LEVEL_LOW) || (analog->low > LEVEL_HIGH))
    ADC1->LTR = LEVEL_LOW;
  else 
    ADC1->LTR = analog->low;
}