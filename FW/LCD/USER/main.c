#include "led.h"
#include "delay.h"
#include "lcd.h"
#include "tft.h"
#include "gui.h"
#include "key.h"

/************************************************
 TFT-1.8 LCD液晶显示实验-库函数版本
 STM32F103RCT6核心板
 狂欢马克思：haoxiang.eu.org
************************************************/


extern const unsigned char gImage_Xlogo[40960];
extern const unsigned char gImage_logo[40960];
extern const unsigned char gImage_Hlogo[40960];

int main(void)
{
	u8 key;
  SystemInit();	//System init.
  delay_init();//Delay init.
	LED_Init();
	KEY_Init();
	QDTFT_Test_Demo();
	
	while(1){
	
		key = KEY_Scan(0); //获取按键值
		
		if(key)
		{
			switch(key)
			{
				case KEY0_PRES:
					LED0=!LED0; //控制LED0翻转
					showimageAll(gImage_logo);
					
					break;
				case KEY1_PRES:
					LED1 =!LED1; //控制LED1翻转
					showimageAll(gImage_Xlogo);
					break;
				case WK_UP_PRES:
					LED0 =!LED0; //控制LED0翻转
					LED1 =!LED1; //控制LED1翻转
					showimageAll(gImage_Hlogo);
					break;
			}
		}
	}

}

