
/*******************************************************************************
  
  * File name :  TIM_7 / stm32f1xx_it.c  
  
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

void EXTI15_10_IRQHandler(void)
{	
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}

// -------------------------------------------------------------------------------- //

void EXTI4_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);	
}

// -------------------------------------------------------------------------------- //

void EXTI9_5_IRQHandler(void)
{
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);		
}

// -------------------------------------------------------------------------------- //
// -- <1> TIM ���ͷ�Ʈ  IRQ handler �Լ��� ���� TimHandler ������ �ܺ����� ������ ����
extern TIM_HandleTypeDef    TimHandle;

// -------------------------------------------------------------------------------- //
// -- <2> TIM ���ͷ�Ʈ IRQ handler �Լ�

void TIM2_IRQHandler(void)
{	
		// -- <2-1> TIM ���ͷ�Ʈ Callback �Լ�
		HAL_TIM_IRQHandler(&TimHandle);	
}

// -------------------------------------------------------------------------------- //

// -- <3> TIM ���ͷ�Ʈ IRQ handler �Լ�
void TIM3_IRQHandler(void)
{	
		// -- <3-1> TIM ���ͷ�Ʈ Callback �Լ�
		HAL_TIM_IRQHandler(&TimHandle);	
}
// -------------------------------------------------------------------------------- //
