#include "iwdg.h"

/************************************************
 独立看门狗实验-驱动代码
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/

void IWDG_Init(u8 prer, u16 rlr)
{
	//取消寄存器写保护
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	//设置预分频系数
	IWDG_SetPrescaler(prer);
	
	//设置重装载值
	IWDG_SetReload(rlr);
	
	//应用程序喂狗
	IWDG_ReloadCounter();
	
	//使能看门狗
	IWDG_Enable();
}

void IWDG_Feed(void)
{
	IWDG_ReloadCounter();
}
