#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "iwdg.h"

/************************************************
 �������Ź�ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{
	//��ʱ������ʼ��
	delay_init();
	
	//���ڳ�ʼ��
	uart_init(115200);
	
	//LED��ʼ��
	LED_Init();
	
	//������ʼ��
	KEY_Init();
	
	//���Ź���ʼ��
	IWDG_Init(4, 625);
	
	delay_ms(200);
	
	//����LED0
	LED0 = 0;
	
	while(1)
	{
		if(KEY_Scan(0)==WK_UP_PRES)
		{
			IWDG_Feed();
			printf("ι��\r\n");
		}
		delay_ms(10);
	}
}
