/* Lab 1 L01_816007689 -  816007689 Group c  */
#include <p18f452.h>   
#include <delays.h>
 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000





     //test
void main(void)
{
unsigned int number=0; 
TRISB= 0x00;
while(number<=15)
{
PORTB = number;
number++; 
}
}

   