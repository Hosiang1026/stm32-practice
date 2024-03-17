#ifndef __LED_H
#define __LED_H

#include "sys.h"

#define LED0 PCout(4) //LED0
#define LED1 PCout(5) //LED1

void LED_Init(void);

#endif
