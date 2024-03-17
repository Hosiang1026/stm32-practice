#include "exti.h"
#include "key.h"
#include "led.h"
#include "delay.h"

/************************************************
 外部中断-驱动代码
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/

void EXTIX_Init(void)
{
	
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//IO复用重映射使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//配置PA0映射中断线0
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	
	//配置PA8映射中断线8
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
	
	//配置PC9映射中断线9
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource9);
	
	//外部中断初始化
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Line = EXTI_Line0|EXTI_Line8|EXTI_Line9;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	//中断初始化
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_Init(&NVIC_InitStructure);
	
}

void EXTI0_IRQHandler(void)
{
	delay_ms(10);
	
	if(WK_UP == 0)
	{
		LED0 = !LED0;
		LED1 = !LED1;
	}
	
	EXTI_ClearITPendingBit(EXTI_Line0);
}


void EXTI9_5_IRQHandler(void)
{
	delay_ms(10);
	
	if(KEY0 == 0)
	{
		LED0 = !LED0;
	}
	
	if(KEY1 == 0)
	{
		LED1 = !LED1;
	}
	
	EXTI_ClearITPendingBit(EXTI_Line8);
	EXTI_ClearITPendingBit(EXTI_Line9);
}
