#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "iwdg.h"

/************************************************
 独立看门狗实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{
	//延时函数初始化
	delay_init();
	
	//串口初始化
	uart_init(115200);
	
	//LED初始化
	LED_Init();
	
	//按键初始化
	KEY_Init();
	
	//看门狗初始化
	IWDG_Init(4, 625);
	
	delay_ms(200);
	
	//点亮LED0
	LED0 = 0;
	
	while(1)
	{
		if(KEY_Scan(0)==WK_UP_PRES)
		{
			IWDG_Feed();
			printf("喂狗\r\n");
		}
		delay_ms(10);
	}
}
