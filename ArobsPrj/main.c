#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//#include <xc.h>
#include <stdio.h>
//#include "Lcd1602.h"
#include "TimerCfg/TimerCfg.h"
#include "TimerSw.h"
#include "UartTest.h"
#include "Disp7Seg.h"


#define BL_RZ_DATA_SEZE 9
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


//UartDataType bluetootherxBuff[BL_RZ_DATA_SEZE];

int main(void)
{
	//StatusError err;
	init_PWM_Timer();
	//UART_Init(0, &uartConfig);
	
	//UartTest();
	
	Disp7SegInit();
	Disp7SegSetFloatVal(0);
	sei();
	UartTestRutine();
	while(1)
	{
		//err = UART_ReceiveDataAsynchrone(UART_BLUETOOTH_INSTANCE_ID, bluetootherxBuff, BL_RZ_DATA_SEZE);
	}
}


void init_PWM_Timer(){
//	DDRD = (0x01 << LED);     //Configure the PORTD4 as output
	
	TimerInitCfg();
	TimerEnableCfg(true);
	
	sei();
}
