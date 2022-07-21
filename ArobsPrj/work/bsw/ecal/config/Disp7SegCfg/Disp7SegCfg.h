/*
 * Disp7SegCfg.h
 *
 * Created: 7/13/2022 2:44:44 PM
 *  Author: alexei.guriev
 */ 

#include <avr/io.h>

#ifndef DISP7SEGCFG_H_
#define DISP7SEGCFG_H_

#define COMUN_POWER_SUPPLY	0xAA
#define COMUN_GROUND		0x55

#define DISPLAY_7_SEGMENT_MODE	COMUN_POWER_SUPPLY
//#define DISPLAY_7_SEGMENT_MODE	COMUN_GROUND

#define DISPLAY_7_SEGMENT_TIMER_MS	4

#define DISPLAY_7_SEGMENT_PORT_DIR DDRA
#define DISPLAY_7_SEGMENT_DIGIT_PORT_DIR DDRB

#define DISPLAY_7_SEGMENT_PORT PORTA
#define DISPLAY_7_SEGMENT_DIGIT_PORT PORTB

#define DISPLAY_7_SEGMENT_DIGIT_1_PIN PB4
#define DISPLAY_7_SEGMENT_DIGIT_2_PIN PB5
#define DISPLAY_7_SEGMENT_DIGIT_3_PIN PB6
#define DISPLAY_7_SEGMENT_DIGIT_4_PIN PB7

#define DISPLAY_7_SEGMENT_DIGITS_COUNT 4

typedef struct
{
	uint8_t port;
	uint8_t portDig;
	uint8_t digitsCount;
	uint8_t digitsPinValue[DISPLAY_7_SEGMENT_DIGITS_COUNT];
}Disp7SegHandleConfig;

Disp7SegHandleConfig* Disp7SegCfgInitAndGet(void);

void Disp7SegCfgAllDigitsOff(void);

void Disp7SegCfgSetDigitValue(uint8_t value);

void Disp7SegCfgDigitOn(uint8_t digit);


#endif /* DISP7SEGCFG_H_ */