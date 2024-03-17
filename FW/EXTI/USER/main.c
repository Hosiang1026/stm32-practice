#include "led.h"
#include "key.h"
#include "exti.h"
#include "delay.h"
#include "usart.h"
#include "stm32f10x.h"

/************************************************
 外部中断实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{
	//延时函数初始化
	delay_init();
	
	//设置NVIC中断分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//串口初始化
	uart_init(115200);
	
	//LED初始化
	LED_Init();
	
	//按键初始化
	KEY_Init();
	
	//外部中断初始化
	EXTIX_Init();
	
	//点亮LED0
	LED0 = 0;
	
	while(1)
	{
		printf("OK\r\n");
		delay_ms(1000);
	}
}
