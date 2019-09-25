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
     int i = 0;
    //test
    /* Insert code from pre-lab Q14 to change values on PORTB */
     TRISB = 0b00000000;
     PORTB = 0b00000000;
     for ( i = 0; i < 16; i++){
         PORTB = i;
     }
}