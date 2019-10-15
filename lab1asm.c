/* Lab 1 first file - ID number 815008434 Group E  */
#include <p18f452.h>   
#include <delays.h>
#include "xlcd_GpE.h"

 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

unsigned int MapIndex =  0;
extern char getMapChar (void);
extern void MapName (void);
char string[10];
int i = 0;

void InitLCD (void)
{
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
}

 void main (void)
{
     MapName();
     InitLCD();
     for(i; i<10; i++){
         string[i] = getMapChar();
         MapIndex++;
     }
     
     while(BusyXLCD());
     SetDDRamAddr(0x40);
     while(BusyXLCD());
     putsXLCD(string);
     while(1){}
}