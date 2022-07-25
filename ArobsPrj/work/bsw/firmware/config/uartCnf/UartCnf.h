/*
 * UartCnf.h
 *
 * Created: 7/21/2022 4:47:31 PM
 *  Author: alexei.guriev
 */ 


#ifndef UARTCNF_H_
#define UARTCNF_H_

#include "System.h"
#include "uartTypes.h"

#define UART_INSTANCE_COUNT 1

typedef void (*UartConfigCallbackType)(uint8_t,UartDataType);

#define UART_BLUETOOTH_INSTANCE_ID	0

#define USART_BAUDRATE 115200UL
//#define USART_BAUDRATE 9600UL
//#define USART_BAUDRATE 19200UL
//#define USART_BAUDRATE 38400UL
//#define USART_BAUDRATE 57600UL

#define UART_MAX_BAUD_RATE	1000000UL

StatusError UartCfgInit(const UartInstanceIndexType instance, UartConfigType * uartConfig);

StatusError UartCfgSetBaudRate(const UartInstanceIndexType instance,UartBaudRateType baudRate);

void UartCfgRxInterruptEnable(const UartInstanceIndexType instance,bool state);

void UartCfgTxInterruptEnable(const UartInstanceIndexType instance,bool state);

bool UartCfgCheckIsTxBuffIsEmpty(const UartInstanceIndexType instance);

bool UartCfgCheckIsRxDataIsReceived(const UartInstanceIndexType instance);

void UartCfgSendOneByte(const UartInstanceIndexType instance,UartDataType data);

UartDataType UartCfgGetOneByte(const UartInstanceIndexType instance);

void UartCfgSetRxBuffer(const UartInstanceIndexType instance,UartConfigCallbackType callBack);


#endif /* UARTCNF_H_ */