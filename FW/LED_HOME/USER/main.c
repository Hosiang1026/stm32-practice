#include "led.h"
#include "delay.h"
#include "stm32f10x.h"

/************************************************
 跑马灯实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{

	delay_init();
	LED_Init();
	
	while(1){
		
		 GPIO_SetBits(GPIOA, GPIO_Pin_12);
		 GPIO_ResetBits(GPIOC, GPIO_Pin_8);
		 delay_ms(500);
		
		 GPIO_SetBits(GPIOC, GPIO_Pin_8);
		 GPIO_ResetBits(GPIOC, GPIO_Pin_9);
		 delay_ms(500);
		
		 GPIO_SetBits(GPIOC, GPIO_Pin_9);
		 GPIO_ResetBits(GPIOA, GPIO_Pin_11);
		 delay_ms(500);
		
		 GPIO_SetBits(GPIOA, GPIO_Pin_11);
		 GPIO_ResetBits(GPIOA, GPIO_Pin_12);
		 delay_ms(500);
		
	}
	
	
}
