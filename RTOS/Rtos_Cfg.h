#ifndef __RTOS_CFG_H
#define __RTOS_CFG_H

#include "Task.h"

#define RTOS_FALSE              (0)
#define RTOS_TRUE               (!RTOS_FALSE)

/* Config System Task Enable */
#define RTOS_TASK_100US_ENABLE
#define RTOS_TASK_1MS_ENABLE
#define RTOS_TASK_5MS_ENABLE
#define RTOS_TASK_100MS_ENABLE
#define RTOS_TASK_500MS_ENABLE
#define RTOS_TASK_1S_ENABLE

#define RTOS_TICK_COUNTER_1MS           (10u)    /* 1ms */
#define RTOS_TICK_COUNTER_5MS           (50u)    /* 5ms */
#define RTOS_TICK_COUNTER_10MS          (100u)   /* 10ms */
#define RTOS_TICK_COUNTER_50MS          (500u)   /* 50ms */
#define RTOS_TICK_COUNTER_100MS         (1000u)    /* 100ms */
#define RTOS_TICK_COUNTER_500MS         (5000u)    /* 500ms */
#define RTOS_TICK_COUNTER_1000MS        (10000u)   /* 1000ms */

#define RTOS_TASK_INIT_NUM       (1U)
#define RTOS_TASK_100US_NUM      (1U)
#define RTOS_TASK_1MS_NUM        (1U)
#define RTOS_TASK_5MS_NUM        (1U)
#define RTOS_TASK_10MS_NUM       (1U)
#define RTOS_TASK_50MS_NUM       (1U)
#define RTOS_TASK_100MS_NUM      (1U)
#define RTOS_TASK_500MS_NUM      (1U)
#define RTOS_TASK_1S_NUM         (1U)

typedef void (*FUNC_PTR)(void);

static const FUNC_PTR rtos_task_array_init[RTOS_TASK_INIT_NUM] =
{
    &Task_Init,
};

#ifdef RTOS_TASK_100US_ENABLE
static const FUNC_PTR rtos_task_array_100us[RTOS_TASK_100US_NUM] =
{
    &Task_Normal_100us,
};
#endif 


#ifdef RTOS_TASK_1MS_ENABLE
static const FUNC_PTR rtos_task_array_1ms[RTOS_TASK_1MS_NUM] =
{
    &Task_Normal_1ms,
};
#endif 

#ifdef RTOS_TASK_5MS_ENABLE
static const FUNC_PTR rtos_task_array_5ms[RTOS_TASK_5MS_NUM] =
{
    &Task_Normal_5ms,
};
#endif 

#ifdef RTOS_TASK_10MS_ENABLE
static const FUNC_PTR rtos_task_array_10ms[RTOS_TASK_10MS_NUM] =
{
    &Task_Normal_10ms,
};
#endif 

#ifdef RTOS_TASK_50MS_ENABLE
static const FUNC_PTR rtos_task_array_50ms[RTOS_TASK_50MS_NUM] =
{
    &Task_Normal_50ms,
};
#endif 

#ifdef RTOS_TASK_100MS_ENABLE
static const FUNC_PTR rtos_task_array_100ms[RTOS_TASK_100MS_NUM] =
{
    &Task_Normal_100ms,
};
#endif 

#ifdef RTOS_TASK_500MS_ENABLE
static const FUNC_PTR rtos_task_array_500ms[RTOS_TASK_500MS_NUM] =
{
    &Task_Normal_500ms,
};
#endif 

#ifdef RTOS_TASK_1S_ENABLE
static const FUNC_PTR rtos_task_array_1s[RTOS_TASK_1S_NUM] =
{
    &Task_Normal_1s,
};
#endif 




#endif 
