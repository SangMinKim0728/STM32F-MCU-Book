
/*******************************************************************************
  
  * File name :  TIM_1 / stm32f4xx_it.c  
  
			* Application model : Nucleo_F429 Board  
 
			* Ver2.0
			* January 23. 2017
			* by Sang-min Kim, Jae-Il Kim  &  Dong-hyuk Cha
 
 ****************************************************************************** */

#include "main.h"
#include "stm32f4xx_it.h"					// 인터럽트 사용에 필요한 헤더 파일

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
// -- <1> TIM 인터럽트  IRQ handler 함수를 위한 TimHandler 변수를 외부정의 변수로 선언
extern TIM_HandleTypeDef    TimHandle;

// -------------------------------------------------------------------------------- //
// -- <2> TIM 인터럽트 IRQ handler 함수

void TIM2_IRQHandler(void)
{	
		// -- <2-1> TIM 인터럽트 Callback 함수
		HAL_TIM_IRQHandler(&TimHandle);	
}

// -------------------------------------------------------------------------------- //

// -- <3> TIM 인터럽트 IRQ handler 함수
void TIM3_IRQHandler(void)
{	
		// -- <3-1> TIM 인터럽트 Callback 함수
		HAL_TIM_IRQHandler(&TimHandle);	
}
// -------------------------------------------------------------------------------- //

