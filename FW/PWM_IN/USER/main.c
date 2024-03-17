#include "led.h"
#include "delay.h"
#include "pwm.h"
#include "usart.h"

/************************************************
 ��ʱ��PWM���벶��ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
extern u8  TIM5CH1_CAPTURE_STA;		//���벶��״̬		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ
 int main(void)
 {	
	u32 temp=0; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	delay_init();	    	 //��ʱ������ʼ��	
	uart_init(9600);	 			//9600	 
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
 	TIM5_Cap_Init(0XFFFF,72-1);		//��1Mhz��Ƶ�ʼ��� 
   	while(1)
	{
 		delay_ms(10);
		TIM_SetCompare1(TIM1,TIM_GetCapture1(TIM1)+1);
		if(TIM_GetCapture1(TIM1)==300)TIM_SetCompare1(TIM1,0);		 
		if(TIM5CH1_CAPTURE_STA&0X80)//�ɹ�������һ�θߵ�ƽ
		{
			temp=TIM5CH1_CAPTURE_STA&0X3F;
			temp*=65536;					//���ʱ���ܺ�
			temp+=TIM5CH1_CAPTURE_VAL;		//�õ��ܵĸߵ�ƽʱ��
			printf("HIGH:%d us\r\n",temp);	//��ӡ�ܵĸߵ�ƽʱ��
 			TIM5CH1_CAPTURE_STA=0;			//������һ�β���
 		}
	}
}
