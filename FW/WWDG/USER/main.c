#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "wwdg.h"

/************************************************
 窗口看门狗实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{
	//延时函数初始化
	delay_init();
	
	//设置中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//串口初始化
	uart_init(115200);
	
	//LED初始化
	LED_Init();
	
	//按键初始化
	KEY_Init();
	
	delay_ms(200);
	
	//点亮LED0
	LED0 = 0;
	
	//看门狗初始化
	WWDG_Init(0x7f, 0x5f, WWDG_Prescaler_8);
	
	while(1)
	{
		LED0 = 1;
	}
}
