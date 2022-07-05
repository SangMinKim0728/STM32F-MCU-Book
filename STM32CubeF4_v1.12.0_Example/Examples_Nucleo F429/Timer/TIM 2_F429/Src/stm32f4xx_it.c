
/*******************************************************************************
  
  * File name :  TIM_2 / stm32f4xx_it.c  
  
			* Application model : Nucleo_F429 Board  
 
			* Ver2.0
			* January 23. 2017
			* by Sang-min Kim, Jae-Il Kim  &  Dong-hyuk Cha
 
 ****************************************************************************** */

#include "main.h"
#include "stm32f4xx_it.h"					// ���ͷ�Ʈ ��뿡 �ʿ��� ��� ����

// -------------------------------------------------------------------------------- //

void SysTick_Handler(void)
{	
		HAL_IncTick();
}

// -------------------------------------------------------------------------------- //

void EXTI0_IRQHandler(void)
{	
		HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);	
}

// -------------------------------------------------------------------------------- //

void EXTI1_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);	
}

// -------------------------------------------------------------------------------- //

void EXTI2_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);	
}

// -------------------------------------------------------------------------------- //

void EXTI3_IRQHandler(void)
{	
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);	
}

// -------------------------------------------------------------------------------- //

void EXTI15_10_IRQHandler(void)
{	
	  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}

// -------------------------------------------------------------------------------- //

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
