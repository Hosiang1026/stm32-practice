#include "led.h"
#include "delay.h"
#include "pwm.h"

/************************************************
 ��ʱ��PWM���ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{
	u8 dir = 1;
	u16 led0pwmval = 0;
	
	//��ʱ������ʼ��
	delay_init();
	
	//�����ж����ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//��ʱ��PWM��ʼ��
	TIM3_PWM_Init(899,0); //����Ƶ PWMƵ��=72000000/900=80KHz
	
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
