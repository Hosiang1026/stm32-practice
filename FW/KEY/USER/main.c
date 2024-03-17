#include "led.h"
#include "key.h"
#include "delay.h"

/************************************************
 按键实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{
	u8 key;
	
	delay_init();//延时函数初始化
	
	LED_Init(); //LED端口初始化
	
	KEY_Init(); //KEY端口初始化
	
	LED0 = 0; //先点亮LED0
	
	while(1){
	
		key = KEY_Scan(0); //获取按键值
		
		if(key)
		{
			switch(key)
			{
				case KEY0_PRES:
					LED0=!LED0; //控制LED0翻转
					break;
				case KEY1_PRES:
					LED1 =!LED1; //控制LED1翻转
					break;
				case WK_UP_PRES:
					LED0 =!LED0; //控制LED0翻转
					LED1 =!LED1; //控制LED1翻转
					break;
			}
		}
	}
}
