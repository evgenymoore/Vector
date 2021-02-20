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
  enum mode { reset, remote, fault, delay };
  //bool reset;
  //bool remote;
  //bool fault;
  //bool delay;
} alarm;

 /* объявление структуры */                                                        
extern alarm Alarm;

                                /* объявления функций */
void Alarm_Reset(alarm* alarm);                                                 //сброс тревоги 
bool Alarm_Check(uint16_t counter);
void Alarm_Cross(converter* conv, alarm* alarm);                                //сброс флага пересечений                           
void Alarm_Update(converter* conv, alarm* alarm);                               //увеличение счетчика тревоги
void Alarm_Launch(uint16_t counter, bool reset);                                //запуск тревоги


#endif /* __ALARM_H */