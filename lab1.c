/* Lab 1 first file - ID number 816002558 Group d  */
#include <p18f452.h>   
#include <delays.h>
 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

int a;

 void main (void)
{
     //test
    /* Insert code from pre-lab Q14 to change values on PORTB */
     PORTAbits.RA3 = 0;
     
     for (a =0; a<16; a ++)
     {
         
         PORTB = a;
         //void Delay10KTCYx (0x32);
         
     }
     //Riyaad Mohammed 
}
