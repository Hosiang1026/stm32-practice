#include "key.h"
#include "delay.h"

/************************************************
 ����ʵ��-��������
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/

void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_Initure;
	
	//����GPIOAʱ��
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//����GPIOCʱ��
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIO_Initure.Pin = GPIO_PIN_0;
	GPIO_Initure.Mode = GPIO_MODE_INPUT;
	GPIO_Initure.Pull = GPIO_PULLUP;
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_Initure);
	
	GPIO_Initure.Pin = GPIO_PIN_8;
	HAL_GPIO_Init(GPIOA, &GPIO_Initure);
	
	GPIO_Initure.Pin = GPIO_PIN_9;
	HAL_GPIO_Init(GPIOC, &GPIO_Initure);
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

