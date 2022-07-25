/*
 * UartCnf.c
 *
 * Created: 7/21/2022 4:47:51 PM
 *  Author: alexei.guriev
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "UartCnf.h"
#include "stddef.h"
/* Local variables */

//static UartConfigType UART_ConfigurationCfg;
static UartConfigCallbackType s_rxCallback;

#define BAUD_PRESCALE(value) (((F_CPU / (value * 16UL))) - 1)

ISR(USART_RXC_vect)
{
	if (NULL != s_rxCallback)
	{
		s_rxCallback(UART_BLUETOOTH_INSTANCE_ID,UDR);
	}
}
StatusError UartCfgInit(const UartInstanceIndexType instance, UartConfigType * uartConfig)
{
	UCSRB |= (1 << RXEN);
	UCSRB |= (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

	UBRRL = BAUD_PRESCALE(USART_BAUDRATE);		/* Load lower 8-bits of the baud rate */
	UBRRH = (BAUD_PRESCALE(USART_BAUDRATE) >> 8);	/* Load upper 8-bits */
	
	return StatusErrNone;
}

bool UartCfgCheckIsTxBuffIsEmpty(const UartInstanceIndexType instance)
{
	if (!(UCSRA & (1<<UDRE)))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool UartCfgCheckIsRxDataIsReceived(const UartInstanceIndexType instance)
{
	if ((UCSRA & (1 << RXC)) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void UartCfgSendOneByte(const UartInstanceIndexType instance,UartDataType data)
{
	UDR = data;
}

UartDataType UartCfgGetOneByte(const UartInstanceIndexType instance)
{
	return UDR;
}

StatusError UartCfgSetBaudRate(const UartInstanceIndexType instance,UartBaudRateType baudRate)
{
	if (baudRate > UART_MAX_BAUD_RATE)
	{
		return StatusErrRange;
	}
	
	UBRRL = BAUD_PRESCALE(baudRate);		/* Load lower 8-bits of the baud rate */
	UBRRH = (BAUD_PRESCALE(baudRate) >> 8);	/* Load upper 8-bits */
	
	return StatusErrNone;
}

void UartCfgRxInterruptEnable(const UartInstanceIndexType instance,bool state)
{
	if (state)
	{
		UCSRB |= (1 << RXCIE);
	}
	else
	{
		UCSRB &= ~(1 << RXCIE);
	}
}

void UartCfgTxInterruptEnable(const UartInstanceIndexType instance,bool state)
{
	if (state)
	{
		UCSRB |= (1 << TXCIE);
	}
	else
	{
		UCSRB &= ~(1 << TXCIE);
	}
}

void UartCfgSetRxBuffer(const UartInstanceIndexType instance,UartConfigCallbackType callBack)
{
	s_rxCallback = callBack;
}
