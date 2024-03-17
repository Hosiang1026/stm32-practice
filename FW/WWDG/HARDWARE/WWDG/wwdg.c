#include "wwdg.h"
#include "led.h"

/************************************************
 ���ڿ��Ź�ʵ��-��������
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/

//����WWDG������������ֵ��Ĭ��Ϊ���
u8 WWDG_CNT = 0x7f;

//��ʼ�����ڿ��Ź�
void WWDG_Init(u8 tr, u8 wr, u32 fprer)
{
	//WWDGʱ��ʹ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	//��ʼ��WWDG_CNT
	WWDG_CNT = tr&WWDG_CNT;
	
	//����Ԥ���Ƶֵ
	WWDG_SetPrescaler(fprer);
	
	//���ô���ֵ
	WWDG_SetWindowValue(wr);
	
	//ʹ�ܿ��Ź�
	WWDG_Enable(WWDG_CNT);
	
	//�����ǰ�����жϱ�־λ
	WWDG_ClearFlag();
	
	//��ʼ�����ڿ��Ź�NVIC
	WWDG_NVIC_Init();
	
	//�������ڿ��Ź��ж�
	WWDG_EnableIT();
	
}

//����WWDG��������ֵ
void WWDG_Set_Counter(u8 cnt)
{
	WWDG_Enable(cnt);
}

//���ڿ��Ź��жϷ������
void WWDG_NVIC_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
}

//���ڿ��Ź��жϴ���
void WWDG_IRQHandler(void)
{
	//ι��
	WWDG_SetCounter(WWDG_CNT);
	
	WWDG_ClearFlag();
	
	LED1 = !LED1;
}
