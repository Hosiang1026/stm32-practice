#include "delay.h"
#include "usart.h"

/************************************************
 Template工程模板-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/
 int main(void)
 {	
	 u8 t=0;
	 //设置中断优先级分组为组2:2位抢占优先级，2位响应优先级
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 delay_init();
	 uart_init(115200);
	 while(1)
	 {
		 printf("t:%d\r\n",t);
		 delay_ms(500);
		 t++;
	 }
 }
 
