
#include "Rtos.h"
#include "Rtos_Cfg.h"
#include "Mcu.h"
#include "Timer.h"

static uint16 rtos_tick_counter = 0;
static Rtos_BitsType rtos_flag;

#define RTOS_TASK_1MS_FALG        rtos_flag.bit0
#define RTOS_TASK_5MS_FALG        rtos_flag.bit1
#define RTOS_TASK_10MS_FALG       rtos_flag.bit2
#define RTOS_TASK_50MS_FALG       rtos_flag.bit3
#define RTOS_TASK_100MS_FALG      rtos_flag.bit4
#define RTOS_TASK_500MS_FALG      rtos_flag.bit5
#define RTOS_TASK_1S_FALG         rtos_flag.bit6
#define RTOS_TASK_100US_FALG      rtos_flag.bit7


void Rtos_ResetSystem(void)
{
    rtos_tick_counter = 0;
    
    RTOS_TASK_1MS_FALG = RTOS_FALSE;
    RTOS_TASK_5MS_FALG = RTOS_FALSE;
    RTOS_TASK_10MS_FALG = RTOS_FALSE;
    RTOS_TASK_50MS_FALG = RTOS_FALSE;
    RTOS_TASK_100MS_FALG = RTOS_FALSE;
    RTOS_TASK_500MS_FALG = RTOS_FALSE;
    RTOS_TASK_1S_FALG = RTOS_FALSE;
    RTOS_TASK_100US_FALG = RTOS_FALSE;
}


void Rtos_SystemTickRoutine(void)
{
  rtos_tick_counter++;
#ifdef RTOS_TASK_100US_ENABLE
  if(RTOS_FALSE == RTOS_TASK_100US_FALG)
  {
    RTOS_TASK_100US_FALG = RTOS_TRUE;
  } 
#endif 
#ifdef RTOS_TASK_1MS_ENABLE
  if((0 == (rtos_tick_counter%RTOS_TICK_COUNTER_1MS)) && (RTOS_FALSE == RTOS_TASK_1MS_FALG))
  {
    RTOS_TASK_1MS_FALG = RTOS_TRUE;
  }  
#endif 

#ifdef RTOS_TASK_5MS_ENABLE
  if((0 == (rtos_tick_counter%RTOS_TICK_COUNTER_5MS)) && (RTOS_FALSE == RTOS_TASK_5MS_FALG))
  {
    RTOS_TASK_5MS_FALG = RTOS_TRUE;
  }
#endif 

#ifdef RTOS_TASK_10MS_ENABLE
  if((0 == (rtos_tick_counter%RTOS_TICK_COUNTER_10MS)) && (RTOS_FALSE == RTOS_TASK_10MS_FALG))
  {
    RTOS_TASK_10MS_FALG = RTOS_TRUE;
  }
#endif 

#ifdef RTOS_TASK_50MS_ENABLE
  if((0 == (rtos_tick_counter%RTOS_TICK_COUNTER_50MS)) && (RTOS_FALSE == RTOS_TASK_50MS_FALG))
  {
    RTOS_TASK_50MS_FALG = RTOS_TRUE;
  }
#endif 

#ifdef RTOS_TASK_100MS_ENABLE
  if((0 == (rtos_tick_counter%RTOS_TICK_COUNTER_100MS)) && (RTOS_FALSE == RTOS_TASK_100MS_FALG))
  {
    RTOS_TASK_100MS_FALG = RTOS_TRUE;
  }
#endif 

#ifdef RTOS_TASK_500MS_ENABLE
  if((0 == (rtos_tick_counter%RTOS_TICK_COUNTER_500MS)) && (RTOS_FALSE == RTOS_TASK_500MS_FALG))
  {
    RTOS_TASK_500MS_FALG = RTOS_TRUE;
  }
#endif 

#ifdef RTOS_TASK_1S_ENABLE
  if((0 == (rtos_tick_counter%RTOS_TICK_COUNTER_1000MS)) && (RTOS_FALSE == RTOS_TASK_1S_FALG))
  {
    RTOS_TASK_1S_FALG = RTOS_TRUE;
    rtos_tick_counter = 0;
  }
#endif 
  
  if(rtos_tick_counter > RTOS_TICK_COUNTER_1000MS)
  {
    rtos_tick_counter = 0;
    //Rtos_Error();
  }
}

void Rtos_TaskSchedule(void)
{
  uint8 index = 0;

#ifdef RTOS_TASK_100US_ENABLE
  if(RTOS_TRUE == RTOS_TASK_100US_FALG)
  {
    for(index=0; index<RTOS_TASK_100US_NUM; index++)
    {
      rtos_task_array_100us[index]();
    }
    RTOS_TASK_100US_FALG = RTOS_FALSE;
  }
#endif 

#ifdef RTOS_TASK_1MS_ENABLE
  if(RTOS_TRUE == RTOS_TASK_1MS_FALG)
  {
    for(index=0; index<RTOS_TASK_1MS_NUM; index++)
    {
      rtos_task_array_1ms[index]();
    }
    RTOS_TASK_1MS_FALG = RTOS_FALSE;
  }
#endif 

#ifdef RTOS_TASK_5MS_ENABLE
  if(RTOS_TRUE == RTOS_TASK_5MS_FALG)
  {
    for(index=0; index<RTOS_TASK_5MS_NUM; index++)
    {
      rtos_task_array_5ms[index]();
    }
    RTOS_TASK_5MS_FALG = RTOS_FALSE;
  }
#endif 

#ifdef RTOS_TASK_10MS_ENABLE
  if(RTOS_TRUE == RTOS_TASK_10MS_FALG)
  {
    for(index=0; index<RTOS_TASK_10MS_NUM; index++)
    {
      rtos_task_array_10ms[index]();
    }
    RTOS_TASK_10MS_FALG = RTOS_FALSE;
  }
#endif 

#ifdef RTOS_TASK_50MS_ENABLE
  if(RTOS_TRUE == RTOS_TASK_50MS_FALG)
  {
    for(index=0; index<RTOS_TASK_50MS_NUM; index++)
    {
      rtos_task_array_50ms[index]();
    }
    RTOS_TASK_50MS_FALG = RTOS_FALSE;
  }
#endif 

#ifdef RTOS_TASK_100MS_ENABLE
  if(RTOS_TRUE == RTOS_TASK_100MS_FALG)
  {
    for(index=0; index<RTOS_TASK_100MS_NUM; index++)
    {
      rtos_task_array_100ms[index]();
    }
    RTOS_TASK_100MS_FALG = RTOS_FALSE;
  }
#endif 

#ifdef RTOS_TASK_500MS_ENABLE
  if(RTOS_TRUE == RTOS_TASK_500MS_FALG)
  {
    for(index=0; index<RTOS_TASK_500MS_NUM; index++)
    {
      rtos_task_array_500ms[index]();
    }
    RTOS_TASK_500MS_FALG = RTOS_FALSE;
  }
#endif 

#ifdef RTOS_TASK_1S_ENABLE
  if(RTOS_TRUE == RTOS_TASK_1S_FALG)
  {
    for(index=0; index<RTOS_TASK_1S_NUM; index++)
    {
      rtos_task_array_1s[index]();
    }
    RTOS_TASK_1S_FALG = RTOS_FALSE;
  }
#endif 
}

static void Rtos_TimeBaseInit(void)
{
  Timer5_Init();
}

static void Rtos_TimeBaseDeInit(void)
{
  Timer5_DeInit();
}

void Rtos_Init(void)
{
  uint8 index = 0;
  
  Rtos_TimeBaseInit();
  Rtos_ResetSystem();
  
  for(index=0; index<RTOS_TASK_1S_NUM; index++)
  {
    rtos_task_array_init[index]();
  }
}


void Rtos_DeInit(void)
{
  Rtos_ResetSystem();
  Rtos_TimeBaseDeInit();
}


void Rtos_Error(void)
{
  while(1)
  {
  }  
}

void main(void)
{
  disableInterrupts();
  Mcu_Init();
  Rtos_Init();
  enableInterrupts();
  
  while(1)
  {
    Rtos_TaskSchedule();
  }
}
