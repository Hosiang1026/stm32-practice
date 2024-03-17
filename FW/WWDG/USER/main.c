#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "wwdg.h"

/************************************************
 ���ڿ��Ź�ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{
	//��ʱ������ʼ��
	delay_init();
	
	//�����ж����ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//���ڳ�ʼ��
	uart_init(115200);
	
	//LED��ʼ��
	LED_Init();
	
	//������ʼ��
	KEY_Init();
	
	delay_ms(200);
	
	//����LED0
	LED0 = 0;
	
	//���Ź���ʼ��
	WWDG_Init(0x7f, 0x5f, WWDG_Prescaler_8);
	
	while(1)
	{
		LED0 = 1;
	}
}
