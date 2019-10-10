#include <p18f452.h>   
#include <delays.h>
#include <xlcd.h>

 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

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
 Nop();
 Nop();
 Nop();
 Nop();
}
void DelayPORXLCD( void )
{
 Delay1KTCYx(60); //Delay of 15ms
 return;
}
void DelayXLCD( void )
{
 Delay1KTCYx(20); //Delay of 5ms
 return;
}

void lcdconfig (){
    OpenXLCD (FOUR_BIT & LINE_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x23);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_RIGHT);
}
void main( void )
{
    lcdconfig();
    while(BusyXLCD());
    putrsXLCD("HELLO WORLD!");
    while(1);
}
