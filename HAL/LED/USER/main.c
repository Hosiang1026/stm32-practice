#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
/************************************************
 �����ʵ��-HAL��汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
/*����������ʹ��λ������ʵ�֣�*/
int main(void)
{ 
  HAL_Init();                    	//��ʼ��HAL��    
  Stm32_Clock_Init(RCC_PLL_MUL9); //����ʱ��,72M
	delay_init(72);               	//��ʼ����ʱ����
	LED_Init();						//��ʼ��LED	

	while(1)
	{
     LED0=0;			     //LED0��
	   LED1=1;				 	//LED1��
		 delay_ms(500);
		 LED0=1;					//LED0��
		 LED1=0;					//LED1��
		 delay_ms(500);
	 }
}

