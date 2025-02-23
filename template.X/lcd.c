/* ########################################################################

   PICsim - PIC simulator http://sourceforge.net/projects/picsim/

   ########################################################################

   Copyright (c) : 2015-2017  Luis Claudio Gamb�a Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#include <xc.h>
#include "lcd.h"
#include "config.h"

void lcd_wr(unsigned char val)
{
  LPORT=val;
}

void lcd_cmd(unsigned char val)
{
	LENA=1;
        lcd_wr(val);
        LDAT=0;
        __delay_us(100);
        LENA=0;
        delay(2);
	LENA=1;
}
 
void lcd_dat(unsigned char val)
{
	LENA=1;
        lcd_wr(val);
        LDAT=1;
        __delay_us(100);
        LENA=0;
        __delay_us(100);
	LENA=1;
}

void lcd_init(void)
{
    	TPORT = 0x00;
    	TLENA = 0;
    	TLDAT = 0;
    
	LENA=0;
	LDAT=0;
	delay(20);
	LENA=1;
	
	lcd_cmd(L_CFG);
	delay(5);
	lcd_cmd(L_CFG);
        delay(1);
	lcd_cmd(L_CFG); //configura
	lcd_cmd(L_OFF);
	lcd_cmd(L_ON); //liga
	lcd_cmd(L_CLR); //limpa
        lcd_cmd(L_L1);
}

void lcd_str(const char* str)
{
 unsigned char i=0;
  
 while(str[i] != 0 )
 {
   lcd_dat(str[i]);
   i++;
 }  
}

void lcd_custom(char num, const char d1,const char d2,const char d3,const char d4,const char d5,const char d6,const char d7,const char d8)
{ 
  unsigned char i;

  if(num < 8)
  {
    lcd_cmd((unsigned char)(0x40+num*8));
    lcd_dat(d1);
    lcd_dat(d2);
    lcd_dat(d3);
    lcd_dat(d4);
    lcd_dat(d5);
    lcd_dat(d6);
    lcd_dat(d7);
    lcd_dat(d8);
    lcd_cmd(L_L1);
  }
}






 
