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
	
		GPIO_SetBits(GPIOC, GPIO_Pin_4);
		GPIO_SetBits(GPIOC, GPIO_Pin_5);
		delay_ms(500);
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_4);
		GPIO_ResetBits(GPIOC, GPIO_Pin_5);
		delay_ms(500);
	}
	
	
}
