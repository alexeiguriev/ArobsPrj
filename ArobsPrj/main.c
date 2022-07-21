#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//#include <xc.h>
#include <stdio.h>
#include "Lcd1602.h"
#include "TimerCfg/TimerCfg.h"
#include "TimerSw.h"
#include "Disp7Seg.h"

void init_PWM_Timer();
int PWMstate = 0;
int PWMstateIntermadiar = 0;

float testValue = 12.34;
float oldtestValue = 0;
TimerSwHandle timerSwHandle;
StatusError err;
#define LED PD4

uint8_t digit1 = 1;
uint8_t digit2 = 2;
uint8_t digit3 = 3;
uint8_t digit4 = 4;

bool changeValue = true;

int main(void)
{
	//StatusError err;
	//
	//TimerSwInitParam *pTimerSwInitParam = TimerGetIntervalPointerCfg();
	//
	//err = TimerSwInit(pTimerSwInitParam,&timerSwHandle);
	//
	//if (err == StatusErrNone)
	//{
		//TimerSwStartup(&timerSwHandle,15);
	//}
	//
	//Lcd1602_Init(); // Initializare LCD
	//Lcd1602_Clear();
	init_PWM_Timer();
	Disp7SegInit();
	while(1)
	{
		if(changeValue)
		{
			Disp7SegSetByDigitCostum(0,0b00000010);
			//Disp7SegSetByDigit(0, digit1, false);
			Disp7SegSetByDigit(1, digit2, true);
			Disp7SegSetByDigit(2, digit3, false);
			Disp7SegSetByDigit(3, digit4, false);		
			changeValue = false;	
		}
		
		//if (oldtestValue != testValue)
		//{
			//err = Disp7SegSetFloatVal(testValue);
			//oldtestValue = testValue;
		//}
		Disp7SegRutine();
		////StateMachineIterate();
		//err = TimerSwIsExpired(&timerSwHandle);
		//if (err == StatusErrTime)
		//{
			//PORTD ^= (1 << LED);
			//PWMstate++;
			//TimerSwStartup(&timerSwHandle,1000);
		//}
		//Lcd1602_SetPosition(0,0);
		//Lcd1602_PrintString("Hello World!");
		//Lcd1602_SetPosition(0,1);
		//Lcd1602_PrintIntVall(PWMstate);
	}
}


void init_PWM_Timer(){
//	DDRD = (0x01 << LED);     //Configure the PORTD4 as output
	
	TimerInitCfg();
	TimerEnableCfg(true);
	
	sei();
}
