#include "sys.h"
#include "delay.h"
#include "usart.h"

/************************************************
 Template����ģ��-HAL��汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
************************************************/

void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;
     
    HAL_Init();                    	 			//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//����ʱ��,72M

    __HAL_RCC_GPIOA_CLK_ENABLE();           	//����GPIOAʱ��
	__HAL_RCC_GPIOD_CLK_ENABLE();           	//����GPIODʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_8; 				//PA8
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//�������
    GPIO_Initure.Pull=GPIO_PULLUP;          	//����
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    //����
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);

	GPIO_Initure.Pin=GPIO_PIN_2; 				//PD2
	HAL_GPIO_Init(GPIOD,&GPIO_Initure);
	
	while(1)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);		//PA8��1 
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);		//PD2��1  			
		Delay(0x7FFFFF);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);		//PA8��0
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);		//PD2��0  
		Delay(0x7FFFFF);
	}
}
