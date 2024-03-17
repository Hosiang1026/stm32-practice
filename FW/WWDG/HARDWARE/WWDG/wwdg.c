#include "wwdg.h"
#include "led.h"

/************************************************
 窗口看门狗实验-驱动代码
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/

//保存WWDG计数器的设置值，默认为最大
u8 WWDG_CNT = 0x7f;

//初始化窗口看门狗
void WWDG_Init(u8 tr, u8 wr, u32 fprer)
{
	//WWDG时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	//初始化WWDG_CNT
	WWDG_CNT = tr&WWDG_CNT;
	
	//设置预设分频值
	WWDG_SetPrescaler(fprer);
	
	//设置窗口值
	WWDG_SetWindowValue(wr);
	
	//使能看门狗
	WWDG_Enable(WWDG_CNT);
	
	//清除提前唤醒中断标志位
	WWDG_ClearFlag();
	
	//初始化窗口看门狗NVIC
	WWDG_NVIC_Init();
	
	//开启窗口看门狗中断
	WWDG_EnableIT();
	
}

//重置WWDG计数器的值
void WWDG_Set_Counter(u8 cnt)
{
	WWDG_Enable(cnt);
}

//窗口看门狗中断服务程序
void WWDG_NVIC_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
}

//窗口看门狗中断处理
void WWDG_IRQHandler(void)
{
	//喂狗
	WWDG_SetCounter(WWDG_CNT);
	
	WWDG_ClearFlag();
	
	LED1 = !LED1;
}
