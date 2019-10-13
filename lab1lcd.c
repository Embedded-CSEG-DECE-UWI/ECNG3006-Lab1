#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void DelayFor18TCY (void)
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
     Nop(); 
     Nop();
     Nop();
     Nop();
}

void DelayXLCD (void)
{
    Delay1KTCYx(5);     //Delay of 5ms 
                        //Cycles = (5ms * 4Mhz)/4
                        //Cycles = 5000
}

void DelayPORXLCD (void)
{
    Delay1KTCYx(15);    //Delay of 15ms
                        //Cycles = (15ms * 4Mhz)/4
                        //Cycles = 15000
}

void lcdSetup (void)
{ 
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x40); 
    while(BusyXLCD()); 
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
}

void main()
{
    lcdSetup();
    putrsXLCD("KERSHAWNFRANKLYN");
    while(BusyXLCD());
    while(1);
   
}