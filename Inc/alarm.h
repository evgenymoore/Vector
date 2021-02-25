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
  bool cross;                                                                   //флаг перехода мгновенного значения АЦП за допустимую границу
  enum { reset, ready, remote, fault, delay } state;                            //режим работы тревоги
  uint16_t counter;                                                             //счётчик пересечений
} alarm;

 /* объявление структуры */                                                        
extern alarm Alarm;

                                /* объявления функций */
void Alarm_Check(alarm* alarm);                                                 //проверка счетчика тревоги
void Alarm_Cross(converter* analog, alarm* alarm);                              //сброс флага пересечений                           
void Alarm_Update(converter* analog, alarm* alarm);                             //увеличение счетчика тревоги
void Alarm_Launch(uint16_t counter);                                            //запуск тревоги


#endif /* __ALARM_H */