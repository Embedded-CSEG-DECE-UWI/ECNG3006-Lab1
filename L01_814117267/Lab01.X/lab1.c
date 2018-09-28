/* Lab 1 first file - ID number 814117267 Group H  */
#include <p18f452.h>
#include <delays.h>
 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000
int x =1;

 void main (void)
{
    /* Insert code from pre-lab Q14 to change values on PORTB */
     
     /*output on the pins of portb in bin a variable that counts 1 to 15*/
     
     /*initialise portb*/
     
     TRISB = 0;
     for (x; x <=15; x++){
         PORTB = x;
        
         //sadsdas
     }
}