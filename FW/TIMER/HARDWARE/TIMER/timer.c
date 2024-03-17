#include "timer.h"
#include "led.h"

/************************************************
 ��ʱ���ж�ʵ��-��������
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/

void TIM3_Int_Init(u16 arr, u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//ʹ�ܶ�ʱ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//��ʼ����ʱ��
	TIM_TimeBaseInitStructure.TIM_Period = arr;
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	//������ʱ���ж�
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	
	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM3, ENABLE);
	
}

//�жϴ�����
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		LED1 = !LED1;
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}




