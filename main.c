/*
 * main.c
 *
 *  Created on: 05-04-2013
 *      Author: michal.dobrzanski
 */

#include <avr/io.h>
#include "main.h"
#include "lcd.h"
#include <avr/delay.h>
#include <stdlib.h>

static const PROGMEM unsigned char znaczki[] =
	{
	   0b00010,
	   0b00101,
	   0b00010,
	   0b00000,
	   0b00000,
	   0b00000,
	   0b00000,
	   0b00000,

	   0b00110,
	   0b01111,
	   0b11111,
	   0b11111,
	   0b01111,
	   0b00111,
	   0b00011,
	   0b00001,

	   0b01100,
	   0b11110,
	   0b11111,
	   0b11111,
	   0b11110,
	   0b11100,
	   0b11000,
	   0b10000
	};

void lcd_put_serce(uint8_t x,uint8_t y){
	lcd_gotoxy(x,y);
	lcd_putc(1);
	lcd_putc(2);
}


int main (void) {
	lcd_init(LCD_DISP_ON);
	lcd_clrscr();

	       /*
	        * load two userdefined characters from program memory
	        * into LCD controller CG RAM location 0 and 1
	        */
	       lcd_command(1<<LCD_CGRAM);  /* set CG RAM start address 0 */
	       for(uint8_t i=0; i<24; i++)
	       {
	           lcd_data(pgm_read_byte_near(&znaczki[i]));
	       }

	       /* move cursor to position 0 on line 2 */
	       /* Note: this switched back to DD RAM adresses */

	       /* display user defined (c), built using two user defined chars */
	       for (uint8_t j=105;;j--){
	    	   char buffer [3];
	    	   lcd_gotoxy(5,0);
	    	   lcd_puts("   ");
	    	   lcd_gotoxy(5,0);
	    	   lcd_puts(itoa(j,buffer,10));
	    	   _delay_ms(100);
	       }

	return 0;
}
