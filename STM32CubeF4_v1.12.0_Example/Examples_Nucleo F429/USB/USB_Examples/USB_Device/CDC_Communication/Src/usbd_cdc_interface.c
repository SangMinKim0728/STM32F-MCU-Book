/**
  ******************************************************************************
  * @file    USB_Device/CDC_Standalone/Src/usbd_cdc_interface.c
  * @author  MCD Application Team
  * @version V1.1.1
  * @date    20-November-2015
  * @brief   Source file for USBD CDC interface
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

#include "main.h"
#include "Nucleo_F429.h"
#include <stdio.h>
#include <string.h>

#define APP_RX_DATA_SIZE  	2048
#define APP_TX_DATA_SIZE  	2048

/* Private variables ---------------------------------------------------------*/

// -- <1> PC, �ٸ� MCU���� UART(COM) ����� ���� ������
USBD_CDC_LineCodingTypeDef 		LineCoding =  
  {
		115200, /* baud rate*/
		0x00,   /* stop bits-1*/
		0x00,   /* parity - none*/
		0x08    /* nb. of bits 8*/
  };

// -- <2> USB, UART�� �۽�, ���� �����Ϳ� ����
// 		-- <2-1>  Received Data over USB are stored in this buffer 
uint8_t 		UserRxBuffer[APP_RX_DATA_SIZE];	
// 		-- <2-2> Received Data over UART (CDC interface) are stored in this buffer */
uint8_t 		UserTxBuffer[APP_TX_DATA_SIZE];	
uint8_t 		UserTxBuffer2[APP_TX_DATA_SIZE];
uint8_t 		UserTxBuffer3[APP_TX_DATA_SIZE];
  
uint32_t 	BuffLength;
extern USBD_HandleTypeDef  USBD_Device;

/* Private function prototypes -----------------------------------------------*/
static int8_t 	CDC_Itf_Init (void);
static int8_t 	CDC_Itf_DeInit (void);
static int8_t 	CDC_Itf_Control (uint8_t cmd, uint8_t* pbuf, uint16_t length);
static int8_t 	CDC_Itf_Receive (uint8_t* pbuf, uint32_t *Len);

void My_Send_Data( uint8_t* UserTxBuffer2, int len );


USBD_CDC_ItfTypeDef 	USBD_CDC_fops = 
{
	  CDC_Itf_Init,
	  CDC_Itf_DeInit,
	  CDC_Itf_Control,
	  CDC_Itf_Receive
};


/*----------------------------------------------------------------------------*/
// -- <3>  CDC_Itf_Init :  Initializes the low layer CDC interface  
//				- �� �Լ��� ������ �ʿ���� �״�� ����ϸ� ��
/**
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
/*----------------------------------------------------------------------------*/

static int8_t CDC_Itf_Init(void)
{

	// -- <3-1>  ���� ��ſ� ����� Buffer (UserTxBuffer, UserRxBuffer)�� ����
			// hcdc->TxBuffer = UserTxBuffer �� ����
	USBD_CDC_SetTxBuffer(&USBD_Device, UserTxBuffer, 0);			
			// hcdc->RxBuffer = UserRxBuffer �� ����"
    USBD_CDC_SetRxBuffer(&USBD_Device, UserRxBuffer);			
  return (USBD_OK);
}

/*----------------------------------------------------------------------------*/
/**
  * @brief  CDC_Itf_DeInit
  *         DeInitializes the CDC media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Itf_DeInit(void)
{
  return (USBD_OK);
}

/*----------------------------------------------------------------------------*/
/**
  * @brief  CDC_Itf_Control
  *         Manage the CDC class requests
  * @param  Cmd: Command code            
  * @param  Buf: Buffer containing command data (request parameters)
  * @param  Len: Number of data to be sent (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Itf_Control (uint8_t cmd, uint8_t* pbuf, uint16_t length)
{ 
  switch (cmd)  {
		  case CDC_SEND_ENCAPSULATED_COMMAND:
			/* Add your code here */
			break;

		  case CDC_GET_ENCAPSULATED_RESPONSE:
			/* Add your code here */
			break;

		  case CDC_SET_COMM_FEATURE:
			/* Add your code here */
			break;

		  case CDC_GET_COMM_FEATURE:
			/* Add your code here */
			break;

		  case CDC_CLEAR_COMM_FEATURE:
			/* Add your code here */
			break;

		  case CDC_SET_LINE_CODING:
//			LineCoding.bitrate    = (uint32_t) (pbuf[0] | (pbuf[1] << 8) |\
//															(pbuf[2] << 16) | (pbuf[3] << 24) );
			LineCoding.bitrate
				= (uint32_t) (pbuf[0] | (pbuf[1] << 8) | (pbuf[2] << 16) | (pbuf[3] << 24) );
			LineCoding.format     = pbuf[4];
			LineCoding.paritytype = pbuf[5];
			LineCoding.datatype   = pbuf[6];
			
			/* Set the new configuration */
			//ComPort_Config();
			break;

		  case CDC_GET_LINE_CODING:
			pbuf[0] = (uint8_t)(LineCoding.bitrate);
			pbuf[1] = (uint8_t)(LineCoding.bitrate >> 8);
			pbuf[2] = (uint8_t)(LineCoding.bitrate >> 16);
			pbuf[3] = (uint8_t)(LineCoding.bitrate >> 24);
			pbuf[4] = LineCoding.format;
			pbuf[5] = LineCoding.paritytype;
			pbuf[6] = LineCoding.datatype;     
			break;

		  case CDC_SET_CONTROL_LINE_STATE:
			/* Add your code here */
			break;

		  case CDC_SEND_BREAK:
			 /* Add your code here */
			break;    
			
		  default:
			break;
  }
  
  return (USBD_OK);
}


/*----------------------------------------------------------------------------*/
//  -- <4>  CDC_Itf_Receive() 
//				- USB host(PC)�� ���� ���� �����͸� ó���ϴ� �Լ�
//                USB host�� ���� �����Ͱ� ���ŵǸ� USBD_CDC_DataOut() �Լ������� �� �Լ��� ȣ����
//
//				- �� �Լ��� �ʿ�� �����Ͽ� ����ϸ� ��
/**
  *  CDC_Itf_DataRx
  *         Data received over USB OUT endpoint are sent over CDC interface 
  *         through this function.
  *   Buf		: Buffer of data to be transmitted
  *   Len	: Number of data received (in bytes)
  *   retval 	: Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */

static int8_t CDC_Itf_Receive(uint8_t* Buf, uint32_t *Len)
{
	char cp;		// �ϴ�, 1���ڸ� ���� !!, ���߿� ���ڿ��� ������ �ֵ��� �������� ! 
	// -- <4-1> ���� �������� ù��° ���ڸ� cp�� ����
	cp = Buf[0];
	
	
	// -- <4-2> ���� �����Ͱ� 1~4�̸� �ش�Ǵ� LED�� Toggle��
	if (cp == '1') {
			HAL_GPIO_TogglePin(GPIONucleo, GPIO_PIN_Led1);
			HAL_GPIO_TogglePin(GPIOExt, GPIO_PIN_Led1);
	}
	if (cp == '2') {
			HAL_GPIO_TogglePin(GPIOExt, GPIO_PIN_Led2);
	}
	if (cp == '3') {
			HAL_GPIO_TogglePin(GPIOExt, GPIO_PIN_Led3);
	}
	if (cp == '4') {
			HAL_GPIO_TogglePin(GPIOExt, GPIO_PIN_Led4);
	}

	// -- <4-3> ���� �����͸� UserTxBuffer3�� ������ �Ŀ� My_Send_Data() �Լ��� ȣ����
	*UserTxBuffer3 = *Buf;
	My_Send_Data( UserTxBuffer3, strlen(UserTxBuffer3)); 
	//USBD_CDC_SetTxBuffer(&USBD_Device, UserTxBuffer3, strlen(UserTxBuffer3) );   
	//USBD_CDC_TransmitPacket(&USBD_Device) ;
	
	// --  <4-4> �������� �۽��� ������ USBD_CDC_ReceivePacket() �Լ��� ȣ���Ѵ�.
	//         �� �Լ��� host�� ���ŵ� ������ ó���� �������� �뺸�ϰ� ���� ������ �۽��� �غ��Ѵ�.
	/* Initiate next USB packet transfer  */
	// prepare OUT Endpoint for reception
	USBD_CDC_ReceivePacket(&USBD_Device);	
	return (USBD_OK);
}


// ------------------------------------------------------------------------
// -- <5> GPIO�� EXTI �� �߻��ϸ� (��, Key�� ��������) ȣ��Ǵ� �Լ�
//
// ------------------------------------------------------------------------

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  // -- <5-1> �������� Key ���� ����  �����ϴ� ���ڸ� UserTxBuffer2�� ����		
	 if (GPIO_Pin == GPIO_PIN_Nucleo_Sw)  {
		sprintf( (char*) UserTxBuffer2,  "\n\r SW1 is pressed !!  \n\r ");
  }
  if (GPIO_Pin == GPIO_PIN_Sw1)  {
		sprintf( (char*) UserTxBuffer2,  "\n\r SW1 is pressed !!  \n\r ");
  }
  if (GPIO_Pin == GPIO_PIN_Sw2)  {
		sprintf( (char*) UserTxBuffer2,  "\n\r SW2 is pressed !!  \n\r ");	  
  }
  if (GPIO_Pin == GPIO_PIN_Sw3)  {
		sprintf( (char*) UserTxBuffer2,  "\n\r SW3 is pressed !!  \n\r ");	  
  }
  if (GPIO_Pin == GPIO_PIN_Sw4)  {
		sprintf( (char*) UserTxBuffer2,  "\n\r SW4 is pressed !!  \n\r ");	  
  }

  // -- <5-2>  My_Send_Data() �Լ��� ȣ����
  My_Send_Data( UserTxBuffer2, strlen(UserTxBuffer2));  
 
  // -- <5-3> Key�� chattering ������ �����ϱ� ���� �ð������� �ش�   
  for (int i=0; i<=100000; i++) ;
 
}

// ------------------------------------------------------------------------
// -- <6> USB host(PC)�� �����͸� �����ϴ� �Լ�
//
//		UserTxBuffer2	: Buffer of data to be transmitted
//		len					: ������ �������� ����
// ------------------------------------------------------------------------

void My_Send_Data(uint8_t* UserTxBuffer2, int len )
{

	// -- <6-1> TxBuffer�� ������ data�� ������
	USBD_CDC_SetTxBuffer(&USBD_Device, UserTxBuffer2, len);  
	// -- <6-2> data�� ������
	USBD_CDC_TransmitPacket(&USBD_Device); 
}