# NINY RTOS

[TOC]

## 介绍

- 这是一款基于定时器的RTOS，满足时序性要求中等偏高的单片机应用。
- 简单，小巧

## 如何使用

- niny rtos 包括三个文件：
  - rtos.c ：rtos实现代码；
  - rtos.h ：rtos内部所使用的数据类型定义，函数申明；
  - rtos_cfg.h：rtos配置，时序任务列表的添加。

### 实现你的定时计数器

```
static void Rtos_TimeBaseInit(void)
{
  Timer5_Init();
}

static void Rtos_TimeBaseDeInit(void)
{
  Timer5_DeInit();
}
```

- 在如上位置添加你的初始化代码，以及反初始化代码，**在rtos.c文件中**。

### 定时器中断调用

```
void Rtos_SystemTickRoutine(void)
```

- 通常来说，进入定时器更新中断函数后，需要清空中断标志位，然后调用上述函数；
- Rtos_SystemTickRoutine函数不占用过多的时间，放心。

### 配置你所需要的时序任务

```
/* Config System Task Enable */
#define RTOS_TASK_100US_ENABLE
#define RTOS_TASK_1MS_ENABLE
#define RTOS_TASK_5MS_ENABLE
#define RTOS_TASK_100MS_ENABLE
//#define RTOS_TASK_500MS_ENABLE
#define RTOS_TASK_1S_ENABLE
```

- 分别为使能100us的任务，使能1ms的任务......以此类推；**在rtos_cfg.c文件中**。
- 根据你的应用需要来使能时序任务，当然全部打开也影响不大。

### 添加时序任务

```
//如：
#define RTOS_TASK_100US_NUM      (1U)

static const FUNC_PTR rtos_task_array_100us[RTOS_TASK_100US_NUM] =
{
    &Task_Normal_100us,
};
```

- RTOS_TASK_100US_NUM 表示该时序下任务的个数。
- Task_Normal_100us为自己实现的任务函数。

### 在你的main中添加

```
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
```

- 添加Rtos_Init();和Rtos_TaskSchedule();

