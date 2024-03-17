#include "delay.h"
#include "usart.h"

/************************************************
 Template����ģ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
 int main(void)
 {	
	 u8 t=0;
	 //�����ж����ȼ�����Ϊ��2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 delay_init();
	 uart_init(115200);
	 while(1)
	 {
		 printf("t:%d\r\n",t);
		 delay_ms(500);
		 t++;
	 }
 }
 
