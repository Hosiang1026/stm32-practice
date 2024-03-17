#include "led.h"
#include "stm32f10x.h"


void LED_Init(void){

	RCC->APB2ENR|=1<<4;
	
	//GPIOC.4; GPIOC.5
	GPIOC->CRL&=0xFF00FFFF;
	GPIOC->CRL|=0x00330000;
	GPIOC->ODR|=(11<<4);
	
	//GPIOC->BSRR|=(1<<4|1<<5);
}
