/* Lab 1 first file - ID number 815117459 Group Hello World  */
//#include <p18f452.h> 

#include <pic18f452.h>
//#include <delays.h>
#include <delay.h>
#include "xlcd2.h"




/* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000
extern void delay10tcy(unsigned char);
extern void delay1ktcy(unsigned char);

void DelayFor18TCY(void)
{
    
    delay10tcy(0x02);

}


void DelayXLCD(void)
{
    //Delay1KTCYx(5);
    delay1ktcy(0x05); 
}

void DelayPORXLCD(void)
{
    //Delay1KTCYx(15);
    delay1ktcy(0x0F); 
}
void initLCD (void)
{
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    WriteCmdXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD()); 
}


int count = 0;
char countchar[8];

void main(void)
{
    initLCD();
    while( BusyXLCD() );
    SetDDRamAddr(0x43);
    putrsXLCD("Hello World");
    
    /*while( BusyXLCD() );
    SetDDRamAddr(0x01);
    while( BusyXLCD() )
    putrsXLCD("PRAYER");
    
    
    while( BusyXLCD() );
    SetDDRamAddr(0x40);
    while( BusyXLCD() )
    putrsXLCD("PERSISTENCE");
    
    
    while( BusyXLCD() );
    SetDDRamAddr(0x10);
    while( BusyXLCD() )
    putrsXLCD("POWER!!!");*/
    
    /*while(1)
    {
        SetDDRamAddr(0x17);
        itoa(count, countchar);
        putsXLCD(countchar);
       // Delay10KTCYx(0x32);
        delay10ktcy(0x32)
        count++;
    }*/
}