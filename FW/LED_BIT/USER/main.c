#include "led.h"
#include "delay.h"
#include "stm32f10x.h"

/************************************************
 跑马灯位操作实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{

	delay_init();
	
	LED_Init();
	
	while(1){
	
		PCout(4) = 1;
		PCout(5) = 1;
		delay_ms(500);
		
		PCout(4) = 0;
		PCout(5) = 0;
		delay_ms(500);
	}
	
}
