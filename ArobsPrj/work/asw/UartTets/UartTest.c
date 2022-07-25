/*
 * UartTest.c
 *
 * Created: 7/21/2022 4:39:26 PM
 *  Author: alexei.guriev
 */ 

//#include "uart.h"
//#include "uartCnf.h"
#include "UartTypes.h"
#include "UartCnf.h"
#include "Uart.h"

#include "UartTest.h"
#include "TimerSw.h"
#include "TimerCfg/TimerCfg.h"
#include "Disp7Seg.h"

#define SENDING_PERIOD	5000
#define ALFA_SIZE		('z'-'a')
bool testRunning = true;
bool readData = false;
bool sendDataBack = false;
bool GetNewData = true;

bool startSending = true;
TimerSwHandle timer;
UartDataType rxBuff[100];
UartDataType txBuff[8];
UartConfigType uartConfig;
UartDataType alfaBuff[ALFA_SIZE];

uint8_t atCommand = 0;

void NewDataCallback(uint8_t index);

void Commands()
{
	switch(atCommand)
	{
		case 1:
		UART_SendDataBlocking(UART_BLUETOOTH_INSTANCE_ID,"AT+UART?",8,3000);
		atCommand = 0;
		break;
		case 2:
		UART_SendDataBlocking(UART_BLUETOOTH_INSTANCE_ID,"AT+UART?",9,3000);
		atCommand = 0;
		break;
		case 3:
		UART_SendDataBlocking(UART_BLUETOOTH_INSTANCE_ID,"AT+VERSION?",11,3000);
		atCommand = 0;
		break;
		case 4:
		UART_SendDataBlocking(UART_BLUETOOTH_INSTANCE_ID,"AT+VERSION?",12,3000);
		atCommand = 0;
		break;
	}
	
}
void UartTestRutine(void)
{
	StatusError err;
	
	err = UART_Init(UART_BLUETOOTH_INSTANCE_ID,&uartConfig);
	
	UART_InstallRxCallback(UART_BLUETOOTH_INSTANCE_ID,NewDataCallback,NULL);
	
	TimerSwInitParam *pTimerSwInitParam = TimerGetIntervalPointerCfg();
	
	TimerSwInit(pTimerSwInitParam,&timer);
	
	TimerSwStartup(&timer,1);
	//rxBuff[0] = 'a';
	//UART_ReceiveDataAsynchrone(UART_BLUETOOTH_INSTANCE_ID,rxBuff,100);
	while(testRunning)
	{
		//Commands();
		Disp7SegRutine();
		
		//if (startSending)
		//{
			//if (StatusErrTime == TimerSwIsExpired(&timer))
			//{
				//for(uint8_t index = 0; index < ALFA_SIZE; index++)
				//{
					//alfaBuff[index] = index + 'a';
				//}
				//UART_SendDataBlocking(UART_BLUETOOTH_INSTANCE_ID,alfaBuff,ALFA_SIZE,3000);
				//TimerSwStartup(&timer,SENDING_PERIOD);
				//
				//if (rxBuff[0] == 'z')
				//{
					//rxBuff[0] = 'a';
				//}
			//}
			//
		//}
		//if (sendDataBack)
		//{
			//for (uint8_t index = 0, j = 0; index < 8; index += 2, j++)
			//{
				//txBuff[index] = 0;
				//txBuff[index + 1] = rxBuff[j] + 30;
			//}
			//UART_SendDataBlocking(UART_BLUETOOTH_INSTANCE_ID,rxBuff,4,3000);
			//sendDataBack = false;
		//}
		//
		if (GetNewData)
		{
			UART_ReceiveDataAsynchrone(UART_BLUETOOTH_INSTANCE_ID,rxBuff,4);
			GetNewData = false;
		}
		
	}
	
}
void NewDataCallback(uint8_t index)
{
	Disp7SegSetByDigit(0,rxBuff[0],false);
	Disp7SegSetByDigit(1,rxBuff[1],false);
	Disp7SegSetByDigit(2,rxBuff[2],false);
	Disp7SegSetByDigit(3,rxBuff[3],false);
	GetNewData = true;
	//sendDataBack = true;
}