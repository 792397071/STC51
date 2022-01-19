#include <REGX51.H>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"



unsigned char KeyN;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Matrix Key");
	while(1)
	{
		KeyN=MatrixKey();
		
		if(KeyN)
		{
		LCD_ShowNum(2,1,KeyN,2);
		}

	}

}