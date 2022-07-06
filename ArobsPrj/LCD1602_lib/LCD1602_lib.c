#include "LCD1602_lib.h"

#include <stdlib.h>

void lcd_com(unsigned char p)
{
	LCD_MODE_PORT &= ~(1 << RS);
	LCD_MODE_PORT |= (1 << EN);
	LCD_DATA_PORT = p;
	_delay_us(100);
	LCD_MODE_PORT &= ~(1 << EN);
	_delay_us(100);
}

// Inscrierea datelor
void lcd_dat(unsigned char p)
{
	_delay_us(100);
	LCD_MODE_PORT |= (1 << RS)|(1 << EN);
	LCD_DATA_PORT = p;
	_delay_us(100);
	LCD_MODE_PORT &= ~(1 << EN);
	_delay_us(100);
	lcd_com(0x06);
}

//Initializarea LCD
void lcd_init(void)
{
	LCD_MODE_DDR |= (1 << PC2)|(1 << PC1)|(1 << PC0);
	LCD_MODE_PORT = 0x00;
	LCD_DATA_DDR = 0xFF;
	LCD_DATA_PORT = 0x00;
	_delay_ms(150);
	lcd_com(0x08);
	_delay_us(1000);
	lcd_com(0x38);
	_delay_us(100);
	lcd_com(0x38);
	_delay_us(100);
	lcd_com(0x38);
	_delay_us(100);
	lcd_com(0x01);
	_delay_us(100);
	lcd_com(0x06);
	_delay_ms(10);
	lcd_com(0x0C);
}

void lcd_Print_str(const char lcd_str[]){
	for(int n = 0;lcd_str[n]!='\0';n++)
	{
		lcd_dat(lcd_str[n]);
	}
}
void set_pos(unsigned char x, unsigned y)
{
	char adress;
	adress=(0x40*y+x)|0b10000000;
	lcd_com(adress);
}

void lcd_clear(void)
{
	lcd_com(0x01);
	_delay_ms(3);
}
void cursor_home(void){
	lcd_com(0x02);
	_delay_ms(3);
}

void lcd_PrintVall(int vall)
{
	char buf[20];
	itoa(vall, buf, 10);
	lcd_Print_str(buf);
	
}
