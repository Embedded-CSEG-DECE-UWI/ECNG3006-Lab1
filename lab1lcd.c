#include <p18cxxx.h>
#include <xc.h>
#include "xc8lcd_lab1.h"


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF


#define _XTAL_FREQ 4000000

void DelayFor18TCY(void)
{
    __delay_us(18);
}
 
void DelayXLCD(void)     // minimum 5ms
{
    __delay_ms(5); 		// Delay of 5ms
}

void DelayPORXLCD(void)   // minimum 15ms
{
    __delay_ms(15);		// Delay of 15ms
}
 
 

void main (void)
{ 
  
    OpenXLCD(FOUR_BIT & LINES_5X7);
    
    
    while( BusyXLCD() );
    WriteCmdXLCD( 0x01 );
    
    while( BusyXLCD() );
    SetDDRamAddr(0x13);
     
    while( BusyXLCD() );
    putrsXLCD("Hello World!");
    
    while(1);
       
    Sleep();
}