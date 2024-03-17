#include "key.h"
#include "delay.h"
#include "stm32f10x.h"

//������ʼ������
void KEY_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	
	//ʹ��GPIOA,GPIOCʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_8;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

//����������
u8 KEY_Scan(u8 mode)
{
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY0==0||KEY1==0||WK_UP==0))
	{
		delay_ms(10);//ȥ����
		key_up=0;
		if(KEY0 == 0) return KEY0_PRES;
		else if(KEY1 == 0) return KEY1_PRES;
		else if(WK_UP == 0) return WK_UP_PRES;
	}
	else if(KEY0 == 1&&KEY1 == 1&&WK_UP == 1)
	{
		key_up = 1;
	}
	return 0;
}

