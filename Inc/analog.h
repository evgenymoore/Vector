#ifndef __ANALOG_H
#define __ANALOG_H

#include "stdint.h"
#include "usart.h"

#define FREQUENCY               2000                                            //частота цифровки - Герцы
#define DURATION                5                                               //длительность преобразований - 5 секунд 
#define FILTER_MODE             FREQUENCY * DURATION                            //длина выборки
#define LEVEL_HIGH              4095
#define LEVEL_LOW               1

 /* структура буффера данных АЦП */
typedef struct
{
  uint16_t low;                                                                 //нижний порог
  uint16_t high;                                                                //верхний порог 
  uint16_t size;                                                                //размер буфера
  uint16_t index;                                                               //индекс элемента буффера
  uint16_t replace;                                                             //индекс заменяемого элемента
  uint16_t buffer[DURATION * FREQUENCY];                                        //буфер данных
  uint16_t dma_value;
} converter;

 /*объявления структур*/
extern converter Analog; 

 /*объявления буффера*/
extern uint8_t uart_buffer[3];

                                /*объявления функций*/
void Constructor_Analog(converter* analog);                                     //конструктор для структуры буфера даннных АЦП
void Analog_Up(converter* analog);
void Analog_Reset(converter* analog);
void Replace_Check(converter* analog);

                               /*функции отправки сигнала*/
void Send_Value(uint16_t value, uint8_t* uart_buff);      

#endif /* __ANALOG_H */