#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor=P1^1;

unsigned char Counter,Compare;	//计数值和比较值，用于输出PWM
unsigned char KeyNum,Speed;

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0){Compare=0;}	//设置比较值，改变PWM占空比
			if(Speed==1){Compare=50;}
			if(Speed==2){Compare=75;}
			if(Speed==3){Compare=100;}
		}
		Nixie(1,Speed);
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Counter++;
	Counter%=100;	//计数值变化范围限制在0~99
	if(Counter<Compare)	//计数值小于比较值
	{
		Motor=1;		//输出1
	}
	else				//计数值大于比较值
	{
		Motor=0;		//输出0
	}
}
