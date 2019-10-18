#include<p18cxxx.h>

#include <delays.h>
#include <xlcd.h>



 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000
//ADRIAN ASHTON
void DelayFor18TCY( void )
{
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop() ;
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
}

void DelayXLCD( void )
{
 Delay1KTCYx(5); //Delay of 5ms
 return;
}
void DelayPORXLCD( void )
{
 Delay1KTCYx(15); //Delay of 15ms
 return;
}


void Busy (){
    OpenXLCD (FOUR_BIT & LINE_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x23);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_RIGHT);
}
void main( void )
{
    Busy();
    
    while(BusyXLCD());
    putrsXLCD("HELLO WORLD!");
    while(100);
}
