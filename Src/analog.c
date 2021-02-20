#include "analog.h"

converter Analog;

uint8_t uart_buffer[3] = {0xAA};

void Constructor_Analog(converter* analog) 
{
  ADC1->CR2 |= ADC_CR2_DDS;                                                     //активация кругового режима для DMA при работе с АЦП
  ADC1->HTR = analog->high = LEVEL_HIGH;
  ADC1->LTR = analog->low = LEVEL_LOW;
  analog->size = sizeof(analog->buffer) / sizeof(uint16_t);
  analog->index = 0;
}

void Analog_Up(converter* analog)
{
  analog->dma_value = (uint16_t)(DMA2_Stream0->NDTR);
  if (analog->dma_value <= (analog->size - 1))
    analog->index++;
}

void Analog_Reset(converter* analog)
{
  if (DMA2->LISR & DMA_LISR_TCIF0)
    analog->index = 0;
}

void Replace_Check(converter* analog)
{
  analog->replace++;
  if (analog->replace == analog->size)
    analog->replace = 0;
}

void Send_Value(uint16_t value, uint8_t* uart_buff)
{
  uart_buff[1] = value >> 8;
  uart_buff[2] = value;
  HAL_UART_Transmit(&huart4, uart_buff, 3, 1);
}