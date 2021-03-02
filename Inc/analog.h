#ifndef __ANALOG_H
#define __ANALOG_H

#include "stdint.h"
#include "usart.h"
#include "stdbool.h"

#define DURATION                5                                               //длительность преобразований - 5 секунд 
#define FREQUENCY               2000                                            //частота цифровки - Герцы
#define MESSAGE                 9
#define SIZE                    FREQUENCY * DURATION                            //длина выборки
#define LEVEL_LOW               1
#define LEVEL_HIGH              4095

 /* структура буффера данных АЦП */
typedef struct
{
  bool state;
  uint16_t low;                                                                 //нижний порог
  uint16_t high;                                                                //верхний порог 
  uint16_t index;                                                               //индекс элемента буффера
  uint16_t replace;                                                             //индекс заменяемого элемента
  uint16_t buffer[SIZE];                                                        //буфер данных
} converter;

 /*объявления структур*/
extern converter Analog; 

 /*объявления буффера*/
extern uint8_t uart_buffer[MESSAGE];


                                /*объявления функций*/
void Analog_Reset(converter* analog);
void Replace_Check(converter* analog);
void Constructor_Analog(converter* analog);                                     //конструктор для структуры буфера даннных АЦП
void Analog_Up(converter* analog);

                               /*функции отправки сигнала*/
void Send_Signal(uint16_t signal, uint16_t high, uint16_t low, uint16_t average, uint8_t* uart_buff);     

#endif /* __ANALOG_H */