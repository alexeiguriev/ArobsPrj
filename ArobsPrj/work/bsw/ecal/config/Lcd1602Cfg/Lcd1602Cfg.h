/*
 * Lcd1602Cfg.h
 *
 * Created: 7/6/2022 4:43:28 PM
 *  Author: alexei.guriev
 */ 


#ifndef LCD1602CFG_H_
#define LCD1602CFG_H_

#include "generalCfg/generalCfg.h"
#include <avr/io.h>

#define LCD_DATA_PORT PORTB
#define LCD_DATA_DDR DDRB


#define LCD_MODE_PORT PORTA  // RS or EN Port
#define LCD_MODE_DDR DDRA
#define RS PA0 // RS
#define EN PA2 // EN




#endif /* LCD1602CFG_H_ */