#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//#include <xc.h>
#include <stdio.h>
#include "LCD1602_lib.h"

void init_PWM_Timer();
int PWMstate = 0;
int PWMstateIntermadiar = 0;

#define LED PD4

ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	PORTD ^= (1 << LED);
	PWMstateIntermadiar++;
	if(PWMstateIntermadiar >= 1000)
	{
		PWMstate++;
		PWMstateIntermadiar = 0;
	}
	TCNT1 = 49535;   // for 1 sec at 16 MHz  63974
}

int main(void)
{
	lcd_init(); // Initializare LCD
	lcd_clear();
	init_PWM_Timer();
	while(1)
	{

		set_pos(0,0);
		lcd_Print_str("Hello World!");
		set_pos(0,1);
		lcd_PrintVall(PWMstate);
	}
}


void init_PWM_Timer(){
	DDRD = (0x01 << LED);     //Configure the PORTD4 as output
	
	TCNT1 = 49535;   // for 1 sec at 16 MHz

	TCCR1A = 0x00;
	TCCR1B = (1<<CS10);  // Timer mode with 1 prescler
	TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();
}
