/* Lab 1 first file - ID number 815117459 Group Hello World  */
#include <p18f452.h> 
#include <delays.h>


/* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

int i = 0;
void main (void)
{
    /* Insert code from pre-lab Q14 to change vPORTB */

    
    TRISB   =   0x00;
    PORTB   =   0x00;

    
    for(i = 1; i <= 15; i++)
    {
        PORTB = i;
        Delay10KTCYx(0x32);
    }
    
}
