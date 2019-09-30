#include <stdio.h>
#include <stdlib.h>
#include <p18f452.h> 
#include <delays.h>
#include "xlcd_A.h"


/* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

unsigned int MapIndex;
extern char getMapChar(void);
extern void MapNamee(void);
extern char MapName;
char groupName[8];


//PreLab Q16a
void DelayFor18TCY(void)
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
}
 
//PreLab Q16b
void DelayXLCD (void)
{
    Delay1KTCYx(5);    
    return;
}

//PreLab Q16c
void DelayPORXLCD (void)
{
    Delay1KTCYx(15);    
    return;
}
 
void setup (void)
{
    DelayPORXLCD();
    while(BusyXLCD());
    OpenXLCD(FOUR_BIT & LINES_5X7); 
    DelayPORXLCD();
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    DelayPORXLCD();    
}

void main (void)
{
    Nop();
    MapNamee();    
    setup();
    DelayPORXLCD(); 
    while(BusyXLCD());
    //SetDDRamAddr(0x40);
    //while(BusyXLCD());
    putsXLCD(groupName);
    DelayPORXLCD();
    while (1) {}
}

