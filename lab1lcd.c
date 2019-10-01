#include<p18cxxx.h>
#include <delays.h>
#include "xlcd_lab1.h"


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

        
void DelayFor18TCY(void)
{
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();
}

void DelayXLCD (void)
{
    Delay1KTCYx(5); // Delay of 5ms
    // Cycles = (TimeDelay * Fosc) / 4
    // Cycles = (5ms * 4MHz) / 4
    // Cycles = 5,000
    return;
}

void DelayPORXLCD (void)
{
    Delay1KTCYx(15); // Delay of 15ms
    // Cycles = (TimeDelay * Fosc) / 4
    // Cycles = (15ms * 4MHz) / 4
    // Cycles = 15,000
    return;
}


void main(void)
{  
    Delay10KTCYx(10);
    Delay10KTCYx(10);
    OpenXLCD( FOUR_BIT & LINES_5X7 );
    
    while( BusyXLCD());
    WriteCmdXLCD(0x01);
    while( BusyXLCD());
    SetDDRamAddr( 0x13 );   // sets it to the second line and fourth character
    
    while( BusyXLCD());
    putrsXLCD("Hello World!");     //prints the string to the screen
    
    while(1);
    
}