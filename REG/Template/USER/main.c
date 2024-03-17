#include "sys.h"
#include "usart.h"		
#include "delay.h"	

/************************************************
 Template工程模板-寄存器版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
int main(void)
{				 
	u8 t=0; 
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);	  		//延时初始化
	uart_init(72,9600); 	//串口初始化为9600
  	while(1)
	{
		printf("t:%d\r\n",t);
		delay_ms(500);
		t++;
	}	 
}
