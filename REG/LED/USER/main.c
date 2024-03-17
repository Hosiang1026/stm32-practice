#include "stm32f10x.h"
#include "delay.h"
#include "led.h"

/************************************************
 跑马灯实验-寄存器版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{				 
	delay_init(72);
	
	LED_Init();

   while(1)
	{
		//LED一亮一灭
    GPIOC->ODR|=(1<<4);
		GPIOC->ODR=~(1<<5);
		
		//LED同时亮
		//GPIOC->ODR|=(11<<4);
		//GPIOC->BSRR|=(1<<4|1<<5);
		delay_ms(100);
		
		//LED一亮一灭
		GPIOC->ODR=~(1<<4);
		GPIOC->ODR|=(1<<5);
		
		//LED同时灭
	  //GPIOC->ODR=~(11<<4);
		//GPIOC->BSRR=~(1<<4|1<<5);
		delay_ms(100);
	}	 
}


