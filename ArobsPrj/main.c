#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//#include <xc.h>
#include <stdio.h>
#include "Lcd1602.h"
#include "TimerCfg/TimerCfg.h"
#include "TimerSw.h"

void init_PWM_Timer();
int PWMstate = 0;
int PWMstateIntermadiar = 0;

TimerSwHandle timerSwHandle;

#define LED PD4

int main(void)
{
	StatusError err;
	
	TimerSwInitParam *pTimerSwInitParam = TimerGetIntervalPointerCfg();
	
	err = TimerSwInit(pTimerSwInitParam,&timerSwHandle);
	
	if (err == StatusErrNone)
	{		
		TimerSwStartup(&timerSwHandle,1000);
	}
	
	Lcd1602_Init(); // Initializare LCD
	Lcd1602_Clear();
	init_PWM_Timer();
	while(1)
	{
		//StateMachineIterate();
		err = TimerSwIsExpired(&timerSwHandle);
		if (err == StatusErrTime)
		{
			PORTD ^= (1 << LED);
			PWMstate++;
			TimerSwStartup(&timerSwHandle,1000);
		}
		Lcd1602_SetPosition(0,0);
		Lcd1602_PrintString("Hello World!");
		Lcd1602_SetPosition(0,1);
		Lcd1602_PrintIntVall(PWMstate);
	}
}


void init_PWM_Timer(){
	DDRD = (0x01 << LED);     //Configure the PORTD4 as output
	
	TimerInitCfg();
	TimerEnableCfg(true);
	
	sei();
}
