#include "analog.h"

converter Analog;

uint8_t uart_buffer[MESSAGE] = {0xAA};

void Constructor_Analog(converter* analog) 
{
  ADC1->CR2 |= ADC_CR2_DDS;                                                     //активация кругового режима для DMA при работе с АЦП
  ADC1->HTR = analog->high = LEVEL_HIGH;
  ADC1->LTR = analog->low = LEVEL_LOW;
  analog->index = 0;
}

void Analog_Up(converter* analog)
{
  if (DMA2_Stream0->NDTR <= (SIZE - 1))
    analog->index++;
}

void Analog_Reset(converter* analog) {
  if (DMA2->LISR & DMA_LISR_TCIF0) 
    analog->index = 0; 
}

void Replace_Check(converter* analog)
{
  analog->replace++;
  if (analog->replace == SIZE)
    analog->replace = 0;
}

void Send_Signal(uint16_t signal, uint16_t high, uint16_t low, uint16_t average, uint8_t* uart_buff)
{
  uart_buff[1] = (uint8_t)(signal >> 8);
  uart_buff[2] = (uint8_t)(signal);

  uart_buff[3] = (uint8_t)(high >> 8);
  uart_buff[4] = (uint8_t)(high);
 
  uart_buff[5] = (uint8_t)(low >> 8);
  uart_buff[6] = (uint8_t)(low);
  
  uart_buff[7] = (uint8_t)(average >> 8);
  uart_buff[8] = (uint8_t)(average);
  
  HAL_UART_Transmit(&huart4, uart_buff, MESSAGE, 10);    
}