
/*******************************************************************************
  
  * File name :  GPIO_2 / stm32f1xx_it.c  
  
			* Application model : Nucleo_F103 Board  
 
			* Ver4.0
			* January 23. 2017
			* by Sang-min Kim, Jae-Il Kim  &  Dong-hyuk Cha
 
 ****************************************************************************** */

#include "main.h"
#include "stm32f1xx_it.h"					// ���ͷ�Ʈ ��뿡 �ʿ��� ��� ����

// -------------------------------------------------------------------------------- //

void SysTick_Handler(void)
{	
		HAL_IncTick();
}

// -------------------------------------------------------------------------------- //

