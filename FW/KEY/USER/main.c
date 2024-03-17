#include "led.h"
#include "key.h"
#include "delay.h"

/************************************************
 ����ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{
	u8 key;
	
	delay_init();//��ʱ������ʼ��
	
	LED_Init(); //LED�˿ڳ�ʼ��
	
	KEY_Init(); //KEY�˿ڳ�ʼ��
	
	LED0 = 0; //�ȵ���LED0
	
	while(1){
	
		key = KEY_Scan(0); //��ȡ����ֵ
		
		if(key)
		{
			switch(key)
			{
				case KEY0_PRES:
					LED0=!LED0; //����LED0��ת
					break;
				case KEY1_PRES:
					LED1 =!LED1; //����LED1��ת
					break;
				case WK_UP_PRES:
					LED0 =!LED0; //����LED0��ת
					LED1 =!LED1; //����LED1��ת
					break;
			}
		}
	}
}
