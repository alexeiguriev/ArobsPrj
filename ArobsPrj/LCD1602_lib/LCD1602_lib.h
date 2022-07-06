/*
 * LCD1602_lib.h
 *
 * Created: 27.06.2022 10:22:07
 *  Author: Sergo
 */ 

#ifndef LCD1602_LIB_H_
#define LCD1602_LIB_H_

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define LCD_DATA_PORT PORTB
#define LCD_DATA_DDR DDRB


#define LCD_MODE_PORT PORTA  // RS or EN Port
#define LCD_MODE_DDR DDRA
#define RS PA0 // RS 
#define EN PA2 // EN 

void lcd_com(unsigned char p);
void lcd_dat(unsigned char p);
void lcd_init(void);
void lcd_Print_str(const char LCD_str[]);
void set_pos(unsigned char x, unsigned y);
void lcd_clear(void);
void cursor_home(void);
void lcd_PrintVall(int vall);



#endif /* LCD1602_LIB_H_ */