/* Lab 1 first file - ID number 816008623 Group B */
#include <p18f452.h>
/* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
void main (void)
{
/* Insert code from pre-lab Q14 to change values on PORTB */
    int q = 1;
    TRISB =0x00;
    while (q<16) {
        PORTB = q;
        q++;
    }
}
