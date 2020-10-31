
#include "Task.h"
#include "Iwdg.h"
#include "Adc.h"
#include "Port.h"
#include "Pwm.h"
#include "Uart.h"
#include "Vdb_Controller.h"


//#define DEBUG_USING_UART

void Task_Init(void)
{
  Port_Init();
  ADC_Init();
  Pwm_Init();
#ifdef DEBUG_USING_UART
  Uart_Init();
#endif 
  Iwdg_Init();

  Vdb_Init();
}

void Task_DeInit(void)
{
  Port_DeInit();
  ADC_DeInit();
  Pwm_DeInit();
#ifdef DEBUG_USING_UART
  Uart_DeInit();
#endif 
  Iwdg_DeInit();

  Vdb_DeInit();
}

void Task_Normal_100us(void)
{
  Vdb_MainFunction_100us();
}


void Task_Normal_1ms(void)
{
  Iwdg_Reload();
  Vdb_MainFunction_1ms();
  ADC_MainFunction_1ms();
}

void Task_Normal_5ms(void)
{
  Vdb_MainFunction_5ms();
}

void Task_Normal_10ms(void)
{
  
}

void Task_Normal_50ms(void)
{
  
}

void Task_Normal_100ms(void)
{
  Vdb_MainFunction_100ms();
}

void Task_Normal_500ms(void)
{

}

void Task_Normal_1s(void)
{
  Vdb_MainFunction_1s();  
}

