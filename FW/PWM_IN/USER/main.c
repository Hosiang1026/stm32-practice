#include "led.h"
#include "delay.h"
#include "pwm.h"
#include "usart.h"

/************************************************
 定时器PWM输入捕获实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
extern u8  TIM5CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//输入捕获值
 int main(void)
 {	
	u32 temp=0; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	delay_init();	    	 //延时函数初始化	
	uart_init(9600);	 			//9600	 
	LED_Init();		  	//初始化与LED连接的硬件接口
 	TIM5_Cap_Init(0XFFFF,72-1);		//以1Mhz的频率计数 
   	while(1)
	{
 		delay_ms(10);
		TIM_SetCompare1(TIM1,TIM_GetCapture1(TIM1)+1);
		if(TIM_GetCapture1(TIM1)==300)TIM_SetCompare1(TIM1,0);		 
		if(TIM5CH1_CAPTURE_STA&0X80)//成功捕获到了一次高电平
		{
			temp=TIM5CH1_CAPTURE_STA&0X3F;
			temp*=65536;					//溢出时间总和
			temp+=TIM5CH1_CAPTURE_VAL;		//得到总的高电平时间
			printf("HIGH:%d us\r\n",temp);	//打印总的高点平时间
 			TIM5CH1_CAPTURE_STA=0;			//开启下一次捕获
 		}
	}
}
