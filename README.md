<img src="https://user-images.githubusercontent.com/108709679/177264238-e643c2c3-17a4-4821-8c2f-77f1cc67e7b5.jpg" width=240 align=left></img>
# 《STM32F 시리즈를 이용한 ARM Cortex-M3/M4 구조와 응용》
## I/O 입출력부터 USB, TCP/IP 통신까지 개정판
&nbsp; * 차동혁 , 김재일 , 김상민 지음 | 홍릉과학출판사 <br>
&nbsp; * 39,000원 <br>
&nbsp; * 구매처 : <a href="http://www.kyobobook.co.kr/product/detailViewKor.laf?ejkGb=KOR&mallGb=KOR&barcode=9791156005353&orderClick=LIZ&Kc=">교보문고</a>




<pre>
</pre>
 
 
 

### __★ 머리말 ★__ 
가장 기본적이며, 가장 많이 사용되고 있는 ST(STMicroElectronics)사의 MCU인 STM32F103과 STM32F429을 대상으로 하여 GPIO, 인터럽트, 타이머, ADC, DAC, UART 등의 주변장치는 물론, USB와 이더넷 포트를 이용한 통신에 대한 내용을 다룬다. 특히, USB 및 이더넷 포트의 내장이 타 MCU에 비해 Cortex-M의 뛰어난
장점임을 감안할 때, 이를 이용한 통신에 대한 예제는 독자들에게 아주 유용할 것으로 생각된다.

__1. Cortex-M4용 실습 보드 및 예제 프로그램 추가__

__2. ST사의 Nucleo Board를 이용한 실습 보드__ 

__3. 하드웨어 대한 깊은 지식이 없어도 이해 가능한 소스 코드__




* * *

## 예제 다운로드 및 실행 안내
본 교재를 이용한 학습에 조금이라도 도움이 되고자 네이버 카페 (카페명 : CortexWorld,http://cafe.naver.com/CortexWorld)에 학습에 필요한 여러 가지 자료를 실어두었다. 여기에 가면 바로 실행이 가능한 예제 소스파일도 다운받을 수 있으며, 예제 실행과 관련된 동영상
등도 볼 수 있다.

이 책에서 소개하는 모든 예제 프로그램은 인터넷을 통해 다운받을 수 있습니다. 아래의 사이트를 방문하시면 모든 예제 프로그램에 대한 소스코드가 포함된 파일이 제공됩니다. 이 사이트에서는 실습보드 설정방법 및 예제 실행방법에 대한 참고 동영상도 함께 제공됩니다.
예제 프로그램의 설치 및 실행에 관한 내용은 이 책의 <4장, 실습보드를 이용한 프로그램 작성 방법>의 [4.1절-4.3절]에 자세히 나와있으니 참고하시기 바랍니다.
이 책의 모든 예제는 PC의 OS가 Windows 7에서 작성되고 실행되었습니다. 그리고 Windows 10에서도 예제 실행이 정상적으로 되는 것을 확인하였습니다. 그러나 이 교재에 사용한 모든 소프트웨어는 Windows 7용입니다. 따라서 Windows 7의 사용을 권장합니다.
 * [네이버 카페] (https://cafe.naver.com/cortexworld)

## 목차

* **1부. ARM Cortex-M3 프로세서**
  * **1장. ARM Cortex-M3 프로세서의 개요**
    * 1.1 ARM Cortex-M3 기반의 마이크로컨트롤러
    * 1.2 ARM Cortex-M3 프로세서
  * **2장. STM32F1 마이크로컨트롤러의 구조**
    * 2.1 ST사의 Cortex-M 기반 마이크로컨트롤러
    * 2.2 STM32F103의 개요 및 구성
    * 2.3 STM32F107의 개요 및 구성
    * 2.4 메모리 및 버스의 구조
    * 2.5 전원 제어
    * 2.6 리셋 및 클럭 제어
    * 2.7 인터럽트 및 예외
* **2부. STM32F1 실습 보드**
  * **3장. Cortex-M3 STM32F1 실습 보드의 소개**
    * 3.1 실습 보드의 구성
    * 3.2 Nucleo-F103 보드
    * 3.3 STM32F107 보드
  * **4장. 실습 보드를 이용한 프로그램 작성 방법**
    * 4.1 개발환경 구축
    * 4.2 예제 프로그램의 실행 : Nucleo-F103 보드 이용
    * 4.3 예제 프로그램의 실행 : STM32F107 보드 이용
    * 4.4 [심화학습] Keil MDK의 사용 방법 및 mbed 소개
  * **5장. HAL 드라이버**
    * 5.1 STM32Cube 펌웨어
    * 5.2 HAL 드라이버
    * 5.3 HAL 시스템 드라이버 및 제어용 함수
    * 5.4 HAL RCC 드라이버
    * 5.5 HAL CORTEX 드라이버
* **3부. 프로그래밍 실습 : 주변장치 응용 제어**
  * **6장. GPIO를 이용한 입출력**
    * 6.1 GPIO의 구조 및 기능
    * 6.2 GPIO 구동용 HAL 드라이버
    * 6.3 GPIO 응용 예제
  * **7장. 외부 인터럽트(EXTI)를 이용한 입출력 제어**
    * 7.1 외부 인터럽트의 구조 및 기능
    * 7.2 외부 인터럽트 관련 HAL 드라이버
    * 7.3 외부 인터럽트 응용 예제
  * **8장. 타이머를 이용한 입출력 제어**
    * 8.1 범용 타이머의 구조 및 기능
    * 8.2 고급제어 타이머의 구조 및 기능
    * 8.3 기본 타이머의 구성 및 기능
    * 8.4 타이머 관련 HAL 드라이버
    * 8.5 타이머 응용 예제
  * **9장. AD 변환기를 이용한 가변 저항값 읽어오기**
    * 9.1 AD 변환기의 구조 및 기능
    * 9.2 AD 변환기 관련 HAL 드라이버
    * 9.3 ADC 응용 예제
  * **10장. DA 변환기를 이용한 LED의 밝기 제어**
    * 10.1 DA 변환기의 구조 및 기능
    * 10.2 DA 변환기 관련 HAL 드라이버
    * 10.3 DAC 응용 예제
* **4부. 프로그래밍 실습 : UART, USB, TCP/IP 통신**	
  * **11장. UART를 이용한 PC와의 통신**
    * 11.1 직렬 통신 및 UART
    * 11.2 USART의 구조 및 기능
    * 11.3 UART 관련 HAL 드라이버
    * 11.4 UART 응용 예제	
  * **12장. USB를 이용한 PC와의 통신**
    * 12.1 USB 통신의 개요
    * 12.2 USB의 구성 및 기능
    * 12.3 STM32Cube USB 디바이스 라이브러리
	* 12.4 USB 응용 예제
  * **13장. 이더넷 포트를 이용한 TCP/IP 통신**
    * 13.1 TCP/IP 통신의 개요
    * 13.2 STM32F107의 이더넷 구성 및 기능
    * 13.3 LwIP : 임베디드 시스템용 TCP/IP 스택
	* 13.4 Ethernet 응용 예제


