#include "switch.h"

MODE DISTANCE;

MODE Distance(GPIO_TypeDef* GPIOx)
{
  MODE distance;
  switch ((~GPIOx->IDR & 0x0F00) >> 8)
  {
    case (0x1) : distance = MODE_1;
      break;
    case (0x2) : distance = MODE_2;
      break;
    case (0x3) : distance = MODE_3;
      break;
    default : distance = MODE_0;
  }
  return distance;
}

uint16_t Sense(GPIO_TypeDef* GPIOx)
{
  uint16_t factor;
  switch ((~GPIOx->IDR & 0xF000) >> 12)
  {
    case (0x1) : factor = 1200;
      break;
    case (0x2) : factor = 1000;
      break;
    case (0x3) : factor = 850;
      break;
    case (0x4) : factor = 650;
      break;
    case (0x5) : factor = 500;
      break;
    case (0x6) : factor = 350;
      break;
    case (0x7) : factor = 250;
      break;
    case (0x8) : factor = 150;
      break;	  
    default : factor = 1450;
  }
  return factor;
}