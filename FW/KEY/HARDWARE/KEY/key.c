#include "key.h"
#include "delay.h"
#include "stm32f10x.h"

//按键初始化函数
void KEY_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使能GPIOA,GPIOC时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_8;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

//按键处理函数
u8 KEY_Scan(u8 mode)
{
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY0==0||KEY1==0||WK_UP==0))
	{
		delay_ms(10);//去抖动
		key_up=0;
		if(KEY0 == 0) return KEY0_PRES;
		else if(KEY1 == 0) return KEY1_PRES;
		else if(WK_UP == 0) return WK_UP_PRES;
	}
	else if(KEY0 == 1&&KEY1 == 1&&WK_UP == 1)
	{
		key_up = 1;
	}
	return 0;
}

