#include "edge.h"

average Average;
deviation Deviation;

void Average_Summary(converter* analog, average* average)
{
  average->summ += analog->buffer[analog->index];
}

void Moving_Average(converter* analog, average* average)
{
  average->value = average->summ / (FILTER_MODE - 1);
  average->summ -= analog->buffer[analog->replace];
}

void Standart_Deviation(converter* analog, average* average, deviation* deviation)
{
  deviation->variance += abs(analog->buffer[analog->index] - average->value) * 
    abs(analog->buffer[analog->index] - average->value);
  deviation->counter++;
  if (deviation->counter == LEVEL_MODE) 
  {
    deviation->variance /= (LEVEL_MODE - 1);
    deviation->sigma = ceil(sqrt(deviation->variance));
    Level_Setting(analog, average, deviation); 
    deviation->counter = 0;
    deviation->variance = 0;
  }
}

void Level_Setting(converter* analog, average* average, deviation* deviation)
{
  analog->low = average->value - ((uint16_t)deviation->sigma); // * factor
  analog->high = average->value + ((uint16_t)deviation->sigma);  // * factor
  analog->low > LEVEL_HIGH ? (ADC1->LTR = LEVEL_LOW) : (ADC1->LTR = analog->low);  
  analog->high > LEVEL_HIGH ? (ADC1->HTR = LEVEL_HIGH) : (ADC1->HTR = analog->high);
}

void Edge_Setting(converter* analog, average* average, uint16_t factor)
{
  analog->low = average->value - factor;
  analog->high = average->value + factor;
  analog->low < LEVEL_LOW ? (ADC1->LTR = LEVEL_LOW) : (ADC1->LTR = analog->low);  
  analog->low > LEVEL_HIGH ? (ADC1->LTR = LEVEL_LOW) : (ADC1->LTR = analog->low);
  analog->high > LEVEL_HIGH ? (ADC1->HTR = LEVEL_HIGH) : (ADC1->HTR = analog->high);
}