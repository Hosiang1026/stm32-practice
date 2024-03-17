#include "iwdg.h"

/************************************************
 �������Ź�ʵ��-��������
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/

void IWDG_Init(u8 prer, u16 rlr)
{
	//ȡ���Ĵ���д����
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	//����Ԥ��Ƶϵ��
	IWDG_SetPrescaler(prer);
	
	//������װ��ֵ
	IWDG_SetReload(rlr);
	
	//Ӧ�ó���ι��
	IWDG_ReloadCounter();
	
	//ʹ�ܿ��Ź�
	IWDG_Enable();
}

void IWDG_Feed(void)
{
	IWDG_ReloadCounter();
}
