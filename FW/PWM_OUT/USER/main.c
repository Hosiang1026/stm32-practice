#include "led.h"
#include "delay.h"
#include "pwm.h"

/************************************************
 定时器PWM输出实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{
	u8 dir = 1;
	u16 led0pwmval = 0;
	
	//延时函数初始化
	delay_init();
	
	//设置中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//定时器PWM初始化
	TIM3_PWM_Init(899,0); //不分频 PWM频率=72000000/900=80KHz
	
	while(1)
	{
		delay_ms(100);
		if(dir) led0pwmval++;
		else led0pwmval--;
		
		if(led0pwmval > 300)dir = 0;
		if(led0pwmval==0) dir = 1;
		TIM_SetCompare2(TIM3, led0pwmval);
	}
}
