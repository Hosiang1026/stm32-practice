#include "led.h"
#include "delay.h"
#include "lcd.h"
#include "tft.h"
#include "gui.h"
#include "key.h"

/************************************************
 TFT-1.8 LCDҺ����ʾʵ��-�⺯���汾
 STM32F103RCT6���İ�
 �����˼��haoxiang.eu.org
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
	
		key = KEY_Scan(0); //��ȡ����ֵ
		
		if(key)
		{
			switch(key)
			{
				case KEY0_PRES:
					LED0=!LED0; //����LED0��ת
					showimageAll(gImage_logo);
					
					break;
				case KEY1_PRES:
					LED1 =!LED1; //����LED1��ת
					showimageAll(gImage_Xlogo);
					break;
				case WK_UP_PRES:
					LED0 =!LED0; //����LED0��ת
					LED1 =!LED1; //����LED1��ת
					showimageAll(gImage_Hlogo);
					break;
			}
		}
	}

}

