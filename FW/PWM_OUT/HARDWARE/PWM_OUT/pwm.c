#include "pwm.h"

/************************************************
 定时器PWM输出实验-驱动代码
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/

//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM3_PWM_Init(u16 arr, u16 psc){

	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitTypeStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	
	//使能定时器3时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//使能GPIO外设和AFIO复用功能模块时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//部分重映射
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	
	//初始化定时器
	TIM_TimeBaseInitStructure.TIM_Period = arr;
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	//初始化TIM3 Channel2 PWM模式
	TIM_OCInitTypeStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitTypeStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitTypeStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM3, &TIM_OCInitTypeStructure);
	
	//使能输出比较预装载
	TIM_OC2PolarityConfig(TIM3, TIM_OCPreload_Enable);
	
	//使能定时器3
	TIM_Cmd(TIM3, ENABLE);
	
}
