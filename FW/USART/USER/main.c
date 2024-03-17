#include "led.h"
#include "delay.h"
#include "usart.h"

//#include "usart_demo.h"

/************************************************
 串口-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
 

/**
int main(void)
{	
	//配置中断分组级别
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
	
	//延时函数初始化
	delay_init();
	//设置中断优先级分组2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//串口初始化9600
	uart_init(9600);
	//初始化与LED连接的硬件接口
	LED_Init();
	
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{
			//得到此次接收到的数据长度
			len=USART_RX_STA&0x3fff;
			printf("\r\n您发送的消息为：\r\n");
			for(t=0; t<len; t++)
			{
				USART1->DR=USART_RX_BUF[t];
				//等待发送结束
				while((USART1->SR&0x40)==0);
			}
			//插入换行
			printf("\r\n\r\n");
			USART_RX_STA=0;
		}
		else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\nSTM32F103RCT6核心板 串口实验\r\n");
				printf("狂欢马克思：haoxiang.eu.org\r\n\r\n\r\n");
			}
			if(times%200==0)printf("请输入数据，以回车键结束\r\n");
			//闪烁LED,提示系统正在运行
			if(times%30==0)LED0=!LED0;
			delay_ms(10);
		}
	}
	
	
}
 
