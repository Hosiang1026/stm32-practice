#include "stm32f10x.h"
#include "delay.h"
#include "led.h"

/************************************************
 �����ʵ��-�Ĵ����汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{				 
	delay_init(72);
	
	LED_Init();

   while(1)
	{
		//LEDһ��һ��
    GPIOC->ODR|=(1<<4);
		GPIOC->ODR=~(1<<5);
		
		//LEDͬʱ��
		//GPIOC->ODR|=(11<<4);
		//GPIOC->BSRR|=(1<<4|1<<5);
		delay_ms(100);
		
		//LEDһ��һ��
		GPIOC->ODR=~(1<<4);
		GPIOC->ODR|=(1<<5);
		
		//LEDͬʱ��
	  //GPIOC->ODR=~(11<<4);
		//GPIOC->BSRR=~(1<<4|1<<5);
		delay_ms(100);
	}	 
}


