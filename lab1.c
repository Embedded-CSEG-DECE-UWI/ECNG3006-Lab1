
/* Lab 1 first file - ID number 814005504 Group A */
#include <p18f452.h>   
#include <delays.h>
 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

int counter;

 void main (void)
{
     TRISAbits.TRISA3 = 0;
     
     LATAbits.LATA3 = 0;
     
     TRISB = 0;
     
    /* Insert code from pre-lab Q14 to change values on PORTB */
     for( counter = 1; counter <=15; counter++ )
     {
         PORTB = counter;
         
         Delay10KTCYx(200);
         
         
     }
}
