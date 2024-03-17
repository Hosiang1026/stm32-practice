#ifndef _KEY_H
#define _KEY_H

#include "sys.h"

//����ķ�ʽ��ͨ��λ��������ʽ��ȡIO
//#define KEY0        PAin(8) 	//KEY0����PA8
//#define KEY1        PCin(9) 	//KEY1����PC9
//#define WK_UP       PAin(0)	    //WKUP����PA0

//����ķ�ʽ��ͨ��ֱ�Ӳ���HAL�⺯����ʽ��ȡIO
#define KEY0 		HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) //KEY1����PA8
#define KEY1 		HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9) //KEY2����PC9
#define WK_UP 	HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) //WKUP����PA0

#define KEY0_PRES  1
#define KEY1_PRES  2
#define WK_UP_PRES 3

void KEY_Init(void);

u8 KEY_Scan(u8 mode);

#endif