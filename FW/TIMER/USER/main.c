#include "led.h"
#include "delay.h"
#include "timer.h"

/************************************************
 ��ʱ���ж�ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{
	//��ʱ������ʼ��
	delay_init();
	
	//�����ж����ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//LED��ʼ��
	LED_Init();
	
	//��ʱ����ʼ��
	TIM3_Int_Init(4999,7199);
	
	delay_ms(200);
	
	//����LED0
	LED0 = 0;
	
	while(1)
	{
		LED0 = !LED0;
		delay_ms(100);
	}
}
