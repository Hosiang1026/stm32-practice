#include "pwm.h"

/************************************************
 ��ʱ��PWM���ʵ��-��������
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/

//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM3_PWM_Init(u16 arr, u16 psc){

	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitTypeStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	
	//ʹ�ܶ�ʱ��3ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//������ӳ��
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	
	//��ʼ����ʱ��
	TIM_TimeBaseInitStructure.TIM_Period = arr;
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	//��ʼ��TIM3 Channel2 PWMģʽ
	TIM_OCInitTypeStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitTypeStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitTypeStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM3, &TIM_OCInitTypeStructure);
	
	//ʹ������Ƚ�Ԥװ��
	TIM_OC2PolarityConfig(TIM3, TIM_OCPreload_Enable);
	
	//ʹ�ܶ�ʱ��3
	TIM_Cmd(TIM3, ENABLE);
	
}
