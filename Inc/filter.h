#ifndef __FILTER_H
#define __FILTER_H

#include <stdint.h>
#include <math.h>

#include "analog.h"

extern double denominator[3]; 
extern double numerator[3];
extern double gain;  
 
typedef struct
{
  double z[2];
  double temp, out;
}filter;

extern filter Filter;

uint16_t filtration(filter* filter, uint16_t data, double* denominator, double* numerator, double gain);

#endif /* __FILTER_H */