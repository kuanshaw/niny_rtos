
#ifndef __RTOS_H
#define __RTOS_H

#include "Std_types.h"

typedef struct
{
    uint8 bit0 : 1;
    uint8 bit1 : 1;
    uint8 bit2 : 1;
    uint8 bit3 : 1;
    uint8 bit4 : 1;
    uint8 bit5 : 1;
    uint8 bit6 : 1;
    uint8 bit7 : 1;
}Rtos_BitsType;


extern void Rtos_Init(void);
extern void Rtos_DeInit(void);
extern void Rtos_ResetSystem(void);
extern void Rtos_SystemTickRoutine(void);
extern void Rtos_TaskSchedule(void);
extern void Rtos_Error(void);

#endif 