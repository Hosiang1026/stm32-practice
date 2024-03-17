#include "led.h"
#include "delay.h"
#include "usart.h"

//#include "usart_demo.h"

/************************************************
 ����-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
 

/**
int main(void)
{	
	//�����жϷ��鼶��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART1_init();
	while(1);
}
**/

int main(void)
{
	u8 t;
	u8 len;
	u16 times=0;
	
	//��ʱ������ʼ��
	delay_init();
	//�����ж����ȼ�����2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//���ڳ�ʼ��9600
	uart_init(9600);
	//��ʼ����LED���ӵ�Ӳ���ӿ�
	LED_Init();
	
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{
			//�õ��˴ν��յ������ݳ���
			len=USART_RX_STA&0x3fff;
			printf("\r\n�����͵���ϢΪ��\r\n");
			for(t=0; t<len; t++)
			{
				USART1->DR=USART_RX_BUF[t];
				//�ȴ����ͽ���
				while((USART1->SR&0x40)==0);
			}
			//���뻻��
			printf("\r\n\r\n");
			USART_RX_STA=0;
		}
		else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\nSTM32F103RCT6���İ� ����ʵ��\r\n");
				printf("�����˼��haoxiang.eu.org\r\n\r\n\r\n");
			}
			if(times%200==0)printf("���������ݣ��Իس�������\r\n");
			//��˸LED,��ʾϵͳ��������
			if(times%30==0)LED0=!LED0;
			delay_ms(10);
		}
	}
	
	
}
 
