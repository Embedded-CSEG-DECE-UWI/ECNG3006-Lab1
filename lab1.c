/* Lab 1 first file - ID number 816004407 Group G  */
#include <p18f452.h>   
#include <delays.h>
 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

void delay(void){
    int count;
    for (count =0; count <50; count++){
       ;
    }
}

 void main (void)
{
    /* Insert code from pre-lab Q14 to change values on PORTB */
     int i = 0b0000;
     TRISB = 0b0000;
     PORTB = 0b0000;
     for (i =0; i<15;i++)
     {
         PORTB = i;
         delay();
     }
}
 