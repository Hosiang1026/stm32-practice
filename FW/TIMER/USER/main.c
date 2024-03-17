#include "led.h"
#include "delay.h"
#include "timer.h"

/************************************************
 定时器中断实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{
	//延时函数初始化
	delay_init();
	
	//设置中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//LED初始化
	LED_Init();
	
	//定时器初始化
	TIM3_Int_Init(4999,7199);
	
	delay_ms(200);
	
	//点亮LED0
	LED0 = 0;
	
	while(1)
	{
		LED0 = !LED0;
		delay_ms(100);
	}
}
