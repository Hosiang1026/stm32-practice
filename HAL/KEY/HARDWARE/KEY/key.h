#ifndef _KEY_H
#define _KEY_H

#include "sys.h"

//下面的方式是通过位带操作方式读取IO
//#define KEY0        PAin(8) 	//KEY0按键PA8
//#define KEY1        PCin(9) 	//KEY1按键PC9
//#define WK_UP       PAin(0)	    //WKUP按键PA0

//下面的方式是通过直接操作HAL库函数方式读取IO
#define KEY0 		HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) //KEY1按键PA8
#define KEY1 		HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9) //KEY2按键PC9
#define WK_UP 	HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) //WKUP按键PA0

#define KEY0_PRES  1
#define KEY1_PRES  2
#define WK_UP_PRES 3

void KEY_Init(void);

u8 KEY_Scan(u8 mode);

#endif
