#include "alarm.h"

alarm Alarm;

void Alarm_Reset(alarm* alarm)
{
  alarm->cross = alarm->reset = alarm->remote = alarm->delay = false;
  alarm->counter = 0;
}

bool Alarm_Check(uint16_t counter)
{
  return (counter == ALARM_MODE) ? true : false;
}

void Alarm_Cross(converter* analog, alarm* alarm)
{
  if (analog->buffer[analog->index] <= analog->high && 
      analog->buffer[analog->index] >= analog->low)
    alarm->cross = false;
}

void Alarm_Update(converter* analog, alarm* alarm)
{
  if ((analog->buffer[analog->index] > analog->high || 
       analog->buffer[analog->index] < analog->low) && 
       alarm->cross == 0) {
    alarm->counter++;
    alarm->cross = true;
    Alarm_Launch(alarm->counter, alarm->reset);
  }
}

void Alarm_Launch(uint16_t counter, bool reset)
{
  if (!reset) 
    switch(counter) 
    {
      case 1 : TIM_Reset(&htim11);
               TIM_Config(&htim10, (5 * 1000) - 1); 
             break;
      case 2 : TIM_Reset(&htim10);
               TIM_Config(&htim7, (3 * 1000) - 1);
             break;
    }
}