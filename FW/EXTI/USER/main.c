#include "led.h"
#include "key.h"
#include "exti.h"
#include "delay.h"
#include "usart.h"
#include "stm32f10x.h"

/************************************************
 �ⲿ�ж�ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{
	//��ʱ������ʼ��
	delay_init();
	
	//����NVIC�жϷ���
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//���ڳ�ʼ��
	uart_init(115200);
	
	//LED��ʼ��
	LED_Init();
	
	//������ʼ��
	KEY_Init();
	
	//�ⲿ�жϳ�ʼ��
	EXTIX_Init();
	
	//����LED0
	LED0 = 0;
	
	while(1)
	{
		printf("OK\r\n");
		delay_ms(1000);
	}
}
