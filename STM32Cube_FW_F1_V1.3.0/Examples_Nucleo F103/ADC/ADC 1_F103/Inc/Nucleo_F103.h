
/*******************************************************************************
  
  * File name :  Nucleo_F103.h  
  
			* Application model : Nucleo_F103  Board  
 
			* Ver4.0
			* January 23. 2017
			* by Sang-min Kim, Jae-Il Kim  &  Dong-hyuk Cha
 
 ****************************************************************************** */

// -- <3> Nucleo_F103 보드의 사용에 필요한 내용을 정의, 선언한 헤더 파일

// -- <3-1> Nucleo_F103 보드의 LED의 포트, 핀 번호를 정의 
#define GPIONucleo					GPIOA 
#define GPIOExt									GPIOC
#define GPIO_PIN_Led1			GPIO_PIN_0
#define GPIO_PIN_Led2			GPIO_PIN_1
#define GPIO_PIN_Led3			GPIO_PIN_2
#define GPIO_PIN_Led4			GPIO_PIN_3
#define GPIO_PIN_Led5			GPIO_PIN_4
#define GPIO_PIN_Led6			GPIO_PIN_5
#define GPIO_PIN_Led7			GPIO_PIN_6
#define GPIO_PIN_Led8			GPIO_PIN_7
#define GPIO_PIN_LedAll		GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7

// -- <3-2> Nucleo_F103 보드의 Switch의  포트, 핀 번호를 정의

#define GPIOSwNucleo							GPIOC
#define GPIOSw1												GPIOA
#define GPIOSw2												GPIOB
#define GPIOSw3												GPIOB
#define GPIOSw4												GPIOB
#define GPIO_PIN_Nucleo_Sw		GPIO_PIN_13
#define GPIO_PIN_Sw1							GPIO_PIN_8
#define GPIO_PIN_Sw2							GPIO_PIN_4
#define GPIO_PIN_Sw3							GPIO_PIN_5
#define GPIO_PIN_Sw4							GPIO_PIN_10
#define TIMER2													TIM2


// -- <3-3> Nucleo_F103.c 에서 사용하는 함수의 선언
void SystemClock_Config(void);
void LED_Config(void);
void Sw_Config(void);
void SwEXTI_Config(void);
void TIM2_Config(int prescaler_value, int period_value);
void TIM3_Config(int prescaler_value, int period_value);
void TIM_OC_Config(int pulse_value);
void TIM_PWM_Poll_Config(int pwm_value);
void TIM_PWM_IT_Config(int pwm_value);
void UART2_Config(void);
void ADC1_Polling_Config(void);
void ADC1_Interrupt_Config(void);
void LED_OnOff(int, int); 

// -------------------------------------------------------------------------------- //
