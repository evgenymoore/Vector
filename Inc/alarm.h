#ifndef __ALARM_H
#define __ALARM_H

#include <stdbool.h>
#include <stdint.h>

#include "analog.h"
#include "tim_init.h"
            
#define ALARM_MODE              60                                              //режим тревоги

 /* определение структуры "тревоги" */
typedef struct
{
  uint16_t counter;                                                             //счётчик пересечений
  bool cross;                                                                   //флаг перехода мгновенного значения АЦП за допустимую границу
  enum { reset, setup, remote, fault, delay } state;
} alarm;

 /* объявление структуры */                                                        
extern alarm Alarm;

                                /* объявления функций */
void Alarm_Reset(alarm* alarm);                                                 //сброс тревоги 
void Alarm_Check(alarm* alarm);
void Alarm_Cross(converter* analog, alarm* alarm);                              //сброс флага пересечений                           
void Alarm_Update(converter* analog, alarm* alarm);                             //увеличение счетчика тревоги
void Alarm_Launch(uint16_t counter);                                            //запуск тревоги


#endif /* __ALARM_H */