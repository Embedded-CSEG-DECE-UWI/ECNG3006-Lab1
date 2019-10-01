/* Lab 1 first file - ID number 815008434 Group E  */
#include <p18f452.h>   
#include <delays.h>

 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

 void main (void)
{
     InitLCD();
     while(BusyXLCD());
     SetDDRamAddr(0x40);
     while(BusyXLCD());
     putrsXLCD("Task 2 rule?");
     while(1){}
}