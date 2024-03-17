#include "led.h"
#include "delay.h"
#include "stm32f10x.h"

/************************************************
 �����ʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/
int main(void)
{

	delay_init();
	LED_Init();
	
	while(1){
	
		GPIO_SetBits(GPIOC, GPIO_Pin_4);
		GPIO_SetBits(GPIOC, GPIO_Pin_5);
		delay_ms(500);
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_4);
		GPIO_ResetBits(GPIOC, GPIO_Pin_5);
		delay_ms(500);
	}
	
	
}
