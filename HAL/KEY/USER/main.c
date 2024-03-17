#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
/************************************************
 按键实验-HAL库版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{ 
	u8 key=0;
	
  HAL_Init();                    	 	//初始化HAL库    
  Stm32_Clock_Init(RCC_PLL_MUL9);   //设置时钟,72M
	delay_init(72);               		//初始化延时函数
	LED_Init();							//初始化LED	
	KEY_Init();							//初始化按键
	LED0=0;								//点亮LED
	while(1)
	{
		key=KEY_Scan(0);				//得到键值
		switch(key)
		{				 
			case KEY0_PRES:
				LED0=!LED0;
				break;
			case KEY1_PRES:
				LED1=!LED1;
				break;
			case WK_UP_PRES:				
				LED0=!LED0;
				LED1=!LED1;
				break;
			default:
				delay_ms(10);	
		} 
	}
}

