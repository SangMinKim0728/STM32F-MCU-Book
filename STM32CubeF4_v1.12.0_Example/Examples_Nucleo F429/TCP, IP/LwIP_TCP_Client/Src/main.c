
/*******************************************************************************
  
  * File name :  TCP_IP_Client / main.c  
  
			* Application model : Nucleo_F429 Board  
  
			* Ver2.0
			* January 23. 2017
			* by Sang-min Kim, Jae-Il Kim  &  Dong-hyuk Cha
 
 ****************************************************************************** */
 
// -- <1> 필요한 헤더 파일을 인클루드 --
#include "main.h"
#include "Nucleo_F429.h"
#include "lwip/opt.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/lwip_timers.h"
#include "netif/etharp.h"
#include "ethernetif.h"
#include "app_ethernet.h"
#include "tcp_echoclient.h"

// -- <2> 변수, 함수의 선언
struct netif gnetif;

static void Netif_Config(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
		// -- <3> 시스템 초기화를 위한 함수 
		HAL_Init();  
		SystemClock_Config();	
		LED_Config();
		SwEXTI_Config();
		
		// -- <4> Initilaize the LwIP stack 
		lwip_init();
		
		// -- <5> Network interface를 설정하는 함수 
		Netif_Config();
		
		// -- <6> Notify user about the network interface status
		User_notification(&gnetif);
		
		// -- <7> server(PC)에 접속함 
		tcp_echoclient_connect();
			
		// -- <8> 무한 루프를 시작함
		while (1)
		{  
				// -- <9> Read a received packet from the Ethernet buffers
				//				 and send it to the lwIP for handling --
				ethernetif_input(&gnetif);

				// -- <10> timeouts을 처리하는 함수 --
				sys_check_timeouts();
		}
}

// ------------------------------------------------------------------------- //
//
//  -- <11>  Network interface를 설정하는 함수 
//
// ------------------------------------------------------------------------- //  

static void Netif_Config(void)
{
		 // -- <11> IP를 핸들링하기 위한 변수 --
		struct ip4_addr ipaddr;					// ip 주소
		struct ip4_addr netmask;				// netmask 주소
		struct ip4_addr gw;						// gate way 주소
		
		// -- <11-2> 주어진 값으로 ip, netmask, gate way 주소를 format에 맞게 만드는 함수 --
		IP4_ADDR(&ipaddr, IP_ADDR0, IP_ADDR1, IP_ADDR2, IP_ADDR3);
		IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
		IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);

		// -- <11-3> 네트워크 인터페이스를 구현하는 부분 --  
		/* add the network interface */    
		netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &ethernet_input);  
		/*  Registers the default network interface */
		netif_set_default(&gnetif);
		
		if (netif_is_link_up(&gnetif))  {
			/* When the netif is fully configured this function must be called */
			netif_set_up(&gnetif);
		}
		else  {
			/* When the netif link is down this function must be called */
			netif_set_down(&gnetif);
		}
}

// ------------------------------------------------------------------------- //  
//
//   --<12> Network interface의 설정 결과를 LED로 표시하는 함수
//
// 		param  netif	: the network interface
//
// ------------------------------------------------------------------------- //  

void User_notification(struct netif *netif) 
{
		// -- <12-1> 이더넷과 LwIP의 초기화에 성공하면 : LED7을 ON함
		if (netif_is_up(netif))  {
			/* Turn On LED 7 to indicate ETH and LwIP init success*/
			HAL_GPIO_WritePin(GPIONucleo, GPIO_PIN_0, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOExt, GPIO_PIN_Led7, GPIO_PIN_SET);
		}

	 // -- <12-2> 초기화에 실패하면  : LED8을 ON함
		else  {     
			/* Turn On LED 8 to indicate ETH and LwIP init error */
			HAL_GPIO_WritePin(GPIONucleo, GPIO_PIN_7, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOExt, GPIO_PIN_Led8, GPIO_PIN_SET);
		} 
}

