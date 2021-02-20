#include "filter.h"

double denominator[3] = { 1, -1.8450684615682118, 0.93906250581749262 };		//denominator
double numerator[3] = { 1, -1.9030520739096508, 1 };					//numerator
double gain = 0.96953125290874631;

filter Filter;

uint16_t filtration(filter* filter, uint16_t data, double* denominator, double* numerator, double gain)
{
  filter->temp = ((double)data) * gain;
  filter->out = filter->temp * numerator[0] + filter->z[0];

  filter->z[0] = filter->z[1] + (filter->temp * numerator[1]) - (filter->out * denominator[1]);
  filter->z[1] = filter->temp * numerator[2] - (filter->out * denominator[2]);
  
  return ((uint16_t)(round(filter->out)) < LEVEL_HIGH) ? (uint16_t)(round(filter->out)) : data;
}