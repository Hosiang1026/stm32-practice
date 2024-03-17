#include "exti.h"
#include "key.h"
#include "led.h"
#include "delay.h"

/************************************************
 �ⲿ�ж�-��������
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/

void EXTIX_Init(void)
{
	
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//IO������ӳ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//����PA0ӳ���ж���0
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	
	//����PA8ӳ���ж���8
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
	
	//����PC9ӳ���ж���9
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource9);
	
	//�ⲿ�жϳ�ʼ��
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Line = EXTI_Line0|EXTI_Line8|EXTI_Line9;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	//�жϳ�ʼ��
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
