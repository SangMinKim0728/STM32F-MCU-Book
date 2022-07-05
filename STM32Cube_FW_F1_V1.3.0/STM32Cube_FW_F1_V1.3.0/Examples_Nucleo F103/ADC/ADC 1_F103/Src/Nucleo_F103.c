
/*******************************************************************************
  
  * File name :  Nucleo_F103.c  
  
			* Application model : Nucleo_F103  Board  
 
			* Ver4.0
			* January 23. 2017
			* by Sang-min Kim, Jae-Il Kim  &  Dong-hyuk Cha
 
 ****************************************************************************** */

// -- <4> Nucleo_F103 보드의 사용에 필요한 함수를 구현한 파일

// -- <4-1> 프로그램의 실행에 필요한 헤더파일을 인클루드
#include "main.h"
#include "Nucleo_F103.h"

// -- <4-2> 주변장치 초기화용 구조체
GPIO_InitTypeDef		    						GPIO_Init_Struct; 					    // GPIO의 초기화용 구조체 변수 
TIM_HandleTypeDef								TimHandle;											// 타이머의 초기화용 구조체 변수 
TIM_OC_InitTypeDef								TIM_OCInit;												// 타이머 Channel(OC)의 초기화용 구조체 변수
UART_HandleTypeDef						UartHandle;											// UART의 초기화용 구조체 변수 
ADC_HandleTypeDef							AdcHandler;											// ADC의 초기화용 구조체 변수
ADC_ChannelConfTypeDef   	Adc_sConfig; 									// ADC Channel의 초기화용 구조체 변수

// -------------------------------------------------------------------------------- //
// -- <5> Nucleo_F103 보드의 LED용 GPIO (PA5, PC0~PC7)의 초기설정을 함 

void LED_Config(void)
{
		// -- Nucleo Board LED GPIO (PA5)설정
		// -- <5-1> GPIOA의 클럭을 enable	
		__HAL_RCC_GPIOA_CLK_ENABLE();

		// -- <5-2> LED의 동작 조건을 설정
		GPIO_Init_Struct.Pin = GPIO_PIN_5;					// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode  = GPIO_MODE_OUTPUT_PP; 		// Output Push-Pull 모드
		GPIO_Init_Struct.Pull     = GPIO_PULLUP; 						// Pull Up 모드
		GPIO_Init_Struct.Speed = GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 	
		
		// -- <5-3> GPIO_Init_Struct에 설정된 조건으로 초기화함
		HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);
		
		// -- 확장 IO Board LED GPIO (PC0 ~ PC7)설정
		// -- <5-4> GPIOC의 클럭을 enable
		__HAL_RCC_GPIOC_CLK_ENABLE();

		// -- <5-5> LED1~8의 동작 조건을 설정
		GPIO_Init_Struct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | 
								 GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;	
																	// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode  = GPIO_MODE_OUTPUT_PP; 		// Output Push-Pull 모드
		GPIO_Init_Struct.Pull     = GPIO_PULLUP; 						// Pull Up 모드
		GPIO_Init_Struct.Speed = GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 	
		
		// -- <5-6> GPIO_Init_Struct에 설정된 조건으로 초기화함
		HAL_GPIO_Init(GPIOC, &GPIO_Init_Struct); 
}

// -------------------------------------------------------------------------------- //
// -- <6> Nucleo_F103 보드의  Switch의 GPIO (PC13, PA8, PB4, PB5, PB10)의 초기설정을 함 
//				* 이 함수는 SW를 GPIO 입력으로 받는 함수이다

void Sw_Config(void)
{
		// -- Nucleo Board Switch (PC13)설정
		// -- <6-1> GPIOC의 클럭을 enable		
		__HAL_RCC_GPIOC_CLK_ENABLE();	

		// -- <6-2> SW1의 동작 조건을 GPIO 입력으로 설정
		GPIO_Init_Struct.Pin 		= GPIO_PIN_13;	// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode 	= GPIO_MODE_INPUT; 				// Input Floating 모드
		GPIO_Init_Struct.Pull 		= GPIO_PULLUP; 						// Pull Up 모드
		GPIO_Init_Struct.Speed 	= GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 

		// -- <6-3> GPIOC를 GPIO_Init_Struct에 설정된 조건으로 초기화함	
		HAL_GPIO_Init(GPIOC, &GPIO_Init_Struct);    

		// -- 확장 IO Board Switch (PA8, PB4, PB5, PB10)설정
		//  SW1용 GPIO (PA8)의 초기설정
		// -- <6-4> GPIOA의 클럭을 enable		
		__HAL_RCC_GPIOA_CLK_ENABLE();	

		// -- <6-5> SW1의 동작 조건을 GPIO 입력으로 설정
		GPIO_Init_Struct.Pin 		= GPIO_PIN_8;	// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode 	= GPIO_MODE_INPUT; 				// Input Floating 모드
		GPIO_Init_Struct.Pull 		= GPIO_PULLUP; 						// Pull Up 모드
		GPIO_Init_Struct.Speed 	= GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 

		// -- <6-6> GPIOA를 GPIO_Init_Struct에 설정된 조건으로 초기화함	
		HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);    

		//  SW2, SW3, SW4용 GPIO (PB4, PB5, PB10)의 초기설정
		// -- <6-7> GPIOB의 클럭을 enable	
		__HAL_RCC_GPIOB_CLK_ENABLE();	
		
		// -- <6-8> SW의 동작 조건을 GPIO 입력으로 설정
		GPIO_Init_Struct.Pin 		= GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_10;		// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode 	= GPIO_MODE_INPUT; 				// Input Floating 모드
		GPIO_Init_Struct.Pull 		= GPIO_NOPULL; 						// Pull Up / Pull Down 비활성화
		GPIO_Init_Struct.Speed 	= GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 

		// -- <6-9> GPIOB를 GPIO_Init_Struct에 설정된 조건으로 초기화함	
		HAL_GPIO_Init(GPIOB, &GPIO_Init_Struct);   		   
		
}

// -------------------------------------------------------------------------------- //
// -- <7> Nucleo_F103 보드의  Switch의 GPIO (PC13, PA8, PB4, PB5, PB10)의 초기설정을 함  
//				* 이 함수는 SW를 누르면 EXTI가 발생하도록 설정한다.

void SwEXTI_Config(void)
{
		// -- Nucleo Board Switch (PC13)설정
		// -- <7-1> GPIOC의 클럭을 enable		
		__HAL_RCC_GPIOC_CLK_ENABLE();	

		// -- <7-2> SW1의 동작 조건을 GPIO 입력으로 설정
		GPIO_Init_Struct.Pin 		= GPIO_PIN_13;	// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode 	= GPIO_MODE_IT_FALLING; 				// Input Floating 모드
		GPIO_Init_Struct.Pull 		= GPIO_NOPULL; 						// Pull Up / Pull Down 비활성화
		GPIO_Init_Struct.Speed 	= GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 

		// -- <7-3> GPIOC를 GPIO_Init_Struct에 설정된 조건으로 초기화함	
		HAL_GPIO_Init(GPIOC, &GPIO_Init_Struct);

		// -- 확장 IO Board Switch (PA8, PB4, PB5, PB10)설정	
		//  SW1용 GPIO (PA8)의 초기설정
		// -- <7-4> GPIOA의 클럭을 enable		
		__HAL_RCC_GPIOA_CLK_ENABLE();	

		// -- <7-5> SW1의 동작 조건을 GPIO 입력으로 설정
		GPIO_Init_Struct.Pin 		= GPIO_PIN_8;	// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode 	= GPIO_MODE_IT_FALLING; 				// Input Floating 모드
		GPIO_Init_Struct.Pull 		= GPIO_NOPULL; 						// Pull Up / Pull Down 비활성화
		GPIO_Init_Struct.Speed 	= GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 

		// -- <7-6> GPIOA를 GPIO_Init_Struct에 설정된 조건으로 초기화함	
		HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);    

		//  SW2, SW3, SW4용 GPIO (PB4, PB5, PB10)의 초기설정
		// -- <7-7> GPIOB의 클럭을 enable	
		__HAL_RCC_GPIOB_CLK_ENABLE();	
		
		// -- <7-8> SW의 동작 조건을 GPIO 입력으로 설정
		GPIO_Init_Struct.Pin 		= GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_10;		// GPIO에서 사용할 PIN 설정
		GPIO_Init_Struct.Mode 	= GPIO_MODE_IT_FALLING; 				// Input Floating 모드
		GPIO_Init_Struct.Pull 		= GPIO_NOPULL; 						// Pull Up / Pull Down 비활성화
		GPIO_Init_Struct.Speed 	= GPIO_SPEED_FREQ_HIGH; 		// 동작속도를 HIGH로 

		// -- <7-9> GPIOB를 GPIO_Init_Struct에 설정된 조건으로 초기화함	
		HAL_GPIO_Init(GPIOB, &GPIO_Init_Struct);       
	
		// -- <7-10> Sw1의 EXTI에 대한 인터럽트의 우선순위를 설정하고, 인터럽트를 enable함
		HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);	 //  EXTI 의 priority를 설정
		HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);			 //  EXTI 인터럽트를 enable
	
		HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);		//  EXTI 의 priority를 설정	
		HAL_NVIC_EnableIRQ(EXTI4_IRQn);				//  EXTI 인터럽트를 enable
		
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);	//  EXTI 의 priority를 설정
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);			//  EXTI 인터럽트를 enable
		
}

// -------------------------------------------------------------------------------- //
// -- <8> Timer의 초기설정을 위한 함수
//			  * TIM2를 Up couting 모드로 동작시켜 1초에 1번씩 발생하도록 주파수를 1 Hz로 설정한다.

void TIM2_Config(int prescaler_value, int period_value)
{

		// -- <8-1> TIM2의 clock을 enable
		__HAL_RCC_TIM2_CLK_ENABLE();
		
		// -- <8-2> TIM의 동작 조건 설정 (인터럽트가 1초에 1번씩 발생하도록 주파수를 1 Hz로 설정)
		TimHandle.Instance = TIM2;								// TIM2 사용
		TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;	//	Up Counter 모드 설정
		TimHandle.Init.Prescaler = prescaler_value;					// Prescaler =6399로 설정
		TimHandle.Init.Period = period_value;							// 업데이트 이벤트 발생시 Auto-Reload 레지스터 = 9999로 설정
		TimHandle.Init.ClockDivision = 0;					// Clock Division 설정
		//TimHandle.Init.RepetitionCounter = 0;		// Repetition Counter 값을  설정 (TIM1만 해당)

		// -- <8-3> TIM2를 TimHandle에 설정된 값으로 초기화하고 TIM를 동작
		HAL_TIM_Base_Init(&TimHandle);	
		HAL_TIM_Base_Start_IT(&TimHandle);	
		
		// -- <8-4> 타이머 인터럽트 우선순위 설정 및 ENABLE
		HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);		// 별도로 설정하지 않으면 디폴트로 설정됨
		HAL_NVIC_EnableIRQ(TIM2_IRQn);		
}

// -------------------------------------------------------------------------------- //
// -- <9> Timer의 초기설정을 위한 함수
//			  * TIM3를 Down couting 모드로 동작시켜 1초에 1번씩 발생하도록 주파수를 1 Hz로 설정한다.

void TIM3_Config(int prescaler_value, int period_value)
{

		// -- <9-1> TIM2의 clock을 enable
		__HAL_RCC_TIM3_CLK_ENABLE();
		
		// -- <9-2> TIM의 동작 조건 설정 (인터럽트가 1초에 1번씩 발생하도록 주파수를 1 Hz로 설정)
		TimHandle.Instance = TIM3;								// TIM3 사용
		TimHandle.Init.CounterMode = TIM_COUNTERMODE_DOWN;	//	Down Counter 모드 설정
		TimHandle.Init.Prescaler = prescaler_value;					// Prescaler =6399로 설정
		TimHandle.Init.Period = period_value;							// 업데이트 이벤트 발생시 Auto-Reload 레지스터 = 9999로 설정
		TimHandle.Init.ClockDivision = 0;					// Clock Division 설정
		//TimHandle.Init.RepetitionCounter = 0;		// Repetition Counter 값을  설정 (TIM1만 해당)

		// -- <9-3> TIM3를 TimHandle에 설정된 값으로 초기화하고 TIM를 동작
		HAL_TIM_Base_Init(&TimHandle);	
		HAL_TIM_Base_Start_IT(&TimHandle);	
		
		// -- <9-4> 타이머 인터럽트 우선순위 설정 및 ENABLE
		HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);		// 별도로 설정하지 않으면 디폴트로 설정됨
		HAL_NVIC_EnableIRQ(TIM3_IRQn);		
}

// -------------------------------------------------------------------------------- //
// -- <10> Timer의 Output Compare 동작 초기설정을 위한 함수

void TIM_OC_Config(int pulse_value)
{

		// -- <10-1> TIM의 OC 동작조건 설정
		TIM_OCInit.OCMode = TIM_OCMODE_TIMING;					// Output Compare 동작모드 설정
		TIM_OCInit.Pulse = pulse_value;											// Capture/Compare Register(CCR)의 설정값
		TIM_OCInit.OCPolarity = TIM_OCPOLARITY_HIGH;			// OC 출력을 High로 설정
		TIM_OCInit.OCFastMode = TIM_OCFAST_DISABLE; 		// TIM Output Compare Fast를 Disable

		// -- <10-2> TIM OC를 TimHandle에 설정된 값으로 초기화함  	
		HAL_TIM_OC_Init(&TimHandle);
		// -- <10-3> TIM OC의 Channel을 TIM_OCInit에 설정된 값으로 초기화함 
		HAL_TIM_OC_ConfigChannel(&TimHandle, &TIM_OCInit, TIM_CHANNEL_1);
		HAL_TIM_OC_ConfigChannel(&TimHandle, &TIM_OCInit, TIM_CHANNEL_2);
		// -- <10-4> TIM OC를 동작함
		HAL_TIM_OC_Start_IT(&TimHandle,TIM_CHANNEL_1);
		HAL_TIM_OC_Start_IT(&TimHandle,TIM_CHANNEL_2);
}

// -------------------------------------------------------------------------------- //
// -- <11> Timer의 PWM 동작 초기설정을 위한 함수

void TIM_PWM_IT_Config(int pwm_value)
{

		// -- <11-1> TIM의 OC 동작조건설정
		TIM_OCInit.OCMode = TIM_OCMODE_PWM1;					
		TIM_OCInit.Pulse = pwm_value;											
		TIM_OCInit.OCPolarity = TIM_OCPOLARITY_HIGH;						

		// -- <11-2> TIM PWM를 TimHandle에 설정된 값으로 초기화 함 	
		HAL_TIM_PWM_Init(&TimHandle);

		// -- <11-3> TIM PWM의 Channel을 TIM_OCInit에 설정된 값으로 초기화 함
 		HAL_TIM_PWM_ConfigChannel(&TimHandle, &TIM_OCInit, TIM_CHANNEL_1);

		// -- <11-4> TIM PWM를 동작함
		HAL_TIM_PWM_Start_IT(&TimHandle,TIM_CHANNEL_1);
}

// -------------------------------------------------------------------------------- //
// -- <12> Timer의 PWM 동작 초기설정을 위한 함수

void TIM_PWM_Poll_Config(int pwm_value)
{

		// -- <12-1> TIM의 OC 동작조건설정
		TIM_OCInit.OCMode = TIM_OCMODE_PWM1;					
		TIM_OCInit.Pulse = pwm_value;											
		TIM_OCInit.OCPolarity = TIM_OCPOLARITY_HIGH;						

		// -- <12-2> TIM PWM를 TimHandle에 설정된 값으로 초기화 함 	
		HAL_TIM_PWM_Init(&TimHandle);

		// -- <12-3> TIM PWM의 Channel을 TIM_OCInit에 설정된 값으로 초기화 함
 		HAL_TIM_PWM_ConfigChannel(&TimHandle, &TIM_OCInit, TIM_CHANNEL_1);

		// -- <12-4> TIM PWM를 동작함
		HAL_TIM_PWM_Start(&TimHandle,TIM_CHANNEL_1);
}

// -------------------------------------------------------------------------------- //
// -- <13> UART의 초기설정을 위한 함수 
void UART2_Config(void)
{
	// -- <13-1> UART의 클럭을 활성화 
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();

	// -- <13-2> GPIO D포트 8번 핀을 UART Tx로 설정
	GPIO_Init_Struct.Pin	= GPIO_PIN_2;
	GPIO_Init_Struct.Mode	= GPIO_MODE_AF_PP;
	GPIO_Init_Struct.Pull	= GPIO_PULLUP;
	GPIO_Init_Struct.Speed	= GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);

	// -- <13-3> GPIO D포트 3번 핀을 UART Rx로 설정
	GPIO_Init_Struct.Pin	= GPIO_PIN_3;
	GPIO_Init_Struct.Mode	= GPIO_MODE_INPUT;
	GPIO_Init_Struct.Pull	= GPIO_NOPULL;
	GPIO_Init_Struct.Speed	= GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);	

	// -- <13-4> UART의 동작 조건 설정 
	UartHandle.Instance	= USART2;  
	UartHandle.Init.BaudRate	= 9600;
	UartHandle.Init.WordLength	= UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits	= UART_STOPBITS_1;
	UartHandle.Init.Parity	= UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl	= UART_HWCONTROL_NONE;
	UartHandle.Init.Mode	= UART_MODE_TX_RX;
	
	// -- <13-5> UART 구성정보를 UartHandle에 설정된 값으로 초기화 함 
	HAL_UART_Init(&UartHandle);
	
	// -- <13-6> UART 인터럽트 우선순위 설정 및 활성화
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);	
	HAL_NVIC_EnableIRQ(USART2_IRQn); 
}

// -------------------------------------------------------------------------------- //
// -- <14> ADC의 초기설정을 위한 함수 
void ADC1_Polling_Config(void)
{	  
    // -- <14-1> ADC의 clock을 활성화 
    __HAL_RCC_GPIOA_CLK_ENABLE();	
    __HAL_RCC_ADC1_CLK_ENABLE();
	
    GPIO_Init_Struct.Mode  = GPIO_MODE_ANALOG;
    GPIO_Init_Struct.Pin 	= GPIO_PIN_1;
		//GPIO_Init_Struct.Pull = GPIO_NOPULL;	
    HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);	

    // -- <14-2> ADC의 동작 조건 설정
		AdcHandler.Instance = ADC1;
		AdcHandler.Init.ScanConvMode = DISABLE;
		AdcHandler.Init.ContinuousConvMode = ENABLE;
		AdcHandler.Init.ExternalTrigConv = ADC_SOFTWARE_START;
		AdcHandler.Init.DataAlign = ADC_DATAALIGN_RIGHT;
		AdcHandler.Init.NbrOfConversion = 1;
	
    // -- <14-3> ADC를 AdcHandler에 설정된 값으로 초기화 함 	
    HAL_ADC_Init(&AdcHandler);

	// -- <14-4> ADC Calibration을 시작
    HAL_ADCEx_Calibration_Start(&AdcHandler);

    // -- <14-5> ADC Channel동작조건 설정	
    Adc_sConfig.Channel	= ADC_CHANNEL_1;
    Adc_sConfig.Rank         	= 1;
    Adc_sConfig.SamplingTime 	= ADC_SAMPLETIME_13CYCLES_5;

		// -- <14-6> 설정된 sConfig와 AdcHandler를 연관지어 초기화 함
		HAL_ADC_ConfigChannel(&AdcHandler, &Adc_sConfig);

		// -- <14-7> ADC를 동작시킴
		HAL_ADC_Start(&AdcHandler);
						
		// -- <14-8> 변환이 완료될 때까지 대기
		HAL_ADC_PollForConversion(&AdcHandler, 10);	

}

// -------------------------------------------------------------------------------- //
// -- <15> ADC의 초기설정을 위한 함수 
void ADC1_Interrupt_Config(void)
{	  
    // -- <15-1> ADC의 clock을 활성화 
    __HAL_RCC_GPIOA_CLK_ENABLE();	
    __HAL_RCC_ADC1_CLK_ENABLE();
	
    GPIO_Init_Struct.Mode  = GPIO_MODE_ANALOG;
    GPIO_Init_Struct.Pin 	= GPIO_PIN_1;
		GPIO_Init_Struct.Pull = GPIO_NOPULL;	
    HAL_GPIO_Init(GPIOA, &GPIO_Init_Struct);	

    // -- <15-2> ADC의 동작 조건 설정
		AdcHandler.Instance = ADC1;
		AdcHandler.Init.ScanConvMode = DISABLE;
		AdcHandler.Init.ContinuousConvMode = ENABLE;
		AdcHandler.Init.ExternalTrigConv = ADC_SOFTWARE_START;
		AdcHandler.Init.DataAlign = ADC_DATAALIGN_RIGHT;
		AdcHandler.Init.NbrOfConversion = 1;
	
    // -- <15-3> ADC를 AdcHandler에 설정된 값으로 초기화 함 	
    HAL_ADC_Init(&AdcHandler);

	// -- <15-4> ADC Calibration을 시작
    HAL_ADCEx_Calibration_Start(&AdcHandler);

    // -- <15-5> ADC Channel동작조건 설정	
    Adc_sConfig.Channel	= ADC_CHANNEL_1;
    Adc_sConfig.Rank         	= 1;
    Adc_sConfig.SamplingTime 	= ADC_SAMPLETIME_13CYCLES_5;

		// -- <15-6> 설정된 sConfig와 AdcHandler를 연관지어 초기화 함
		HAL_ADC_ConfigChannel(&AdcHandler, &Adc_sConfig);

		// -- <15-7> ADC를 동작시킴
		HAL_ADC_Start_IT(&AdcHandler);
	
    // -- <15-7> ADC 인터럽트 우선순위 설정 및 활성화 
    HAL_NVIC_SetPriority(ADC1_IRQn, 0, 0); 
    HAL_NVIC_EnableIRQ(ADC1_IRQn);

}

// -------------------------------------------------------------------------------- //
// -- <16> 실습보드의  LED를 ON시키고 일정 시간후에 다시 OFF 시키는 함수

void LED_OnOff(int led, int interval) 
{
		// -- <16-1> GPIOLed 포트에 있는 led를 ON 함
		HAL_GPIO_WritePin(GPIONucleo, led, GPIO_PIN_SET );
		HAL_GPIO_WritePin(GPIOExt, led, GPIO_PIN_SET );		
		// -- <16-2> interval (msec) 시간만큼 시간 지연을 함
		HAL_Delay(interval);
		// -- <16-3> GPIOLed 포트에 있는 led를 OFF 함
		HAL_GPIO_WritePin(GPIONucleo, led, GPIO_PIN_RESET );	
		HAL_GPIO_WritePin(GPIOExt, led, GPIO_PIN_RESET );	
}

// -------------------------------------------------------------------------------- //
//   --  <17>  System Clock 을 설정해주는 함수
/*				- 클럭은 다음과 같이 설정된다.

  *            System Clock source   = PLL (HSI)
  *            SYSCLK(Hz)                = 64,000,000
  *            HCLK(Hz)                    = 64,000,000
  *            AHB Prescaler              = 1
  *            APB1 Prescaler            = 2
  *            APB2 Prescaler            = 1
  *            PLLMUL                      = 16
  *            Flash Latency(WS)       = 2
  */
// -------------------------------------------------------------------------------- //

void  SystemClock_Config(void)
{
		  RCC_ClkInitTypeDef clkinitstruct = {0};
		  RCC_OscInitTypeDef oscinitstruct = {0};
		  
		  /* Configure PLL ------------------------------------------------------*/
		  /* PLL configuration: PLLCLK = (HSI / 2) * PLLMUL = (8 / 2) * 16 = 64 MHz */
		  /* PREDIV1 configuration: PREDIV1CLK = PLLCLK / HSEPredivValue = 64 / 1 = 64 MHz */
		  /* Enable HSI and activate PLL with HSi_DIV2 as source */
		  oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSI;
		  oscinitstruct.HSEState        = RCC_HSE_OFF;
		  oscinitstruct.LSEState        = RCC_LSE_OFF;
		  oscinitstruct.HSIState        = RCC_HSI_ON;
		  oscinitstruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
		  oscinitstruct.HSEPredivValue    = RCC_HSE_PREDIV_DIV1;
		  oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
		  oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSI_DIV2;
		  oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL16;
  
		  if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)   {
					/* Initialization Error */
					while(1); 
		  }

		  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
			 clocks dividers */
		  clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
		  clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		  clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
		  clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
		  clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;  
		  
		  if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)   {
					/* Initialization Error */
					while(1); 
		  }
}

// -------------------------------------------------------------------------------- //
//   --  <18>  Clock 설정시 에러가 발생하면 처리해주는 함수
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

		  /* Infinite loop */
		  while (1) 
		  {
		  }
}
#endif

// -------------------------------------------------------------------------------- //
