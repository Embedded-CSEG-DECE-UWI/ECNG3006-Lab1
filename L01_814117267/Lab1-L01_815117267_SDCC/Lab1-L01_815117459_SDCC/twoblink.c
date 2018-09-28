/* 
 * File:   twoblink.c
 * Author: Luther Jn. Baptiste
 *
 * Created on September 12, 2018, 11:31 AM
 */
#include <delays.h>
#include <timers.h>
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000
void toggle_LED(void);

#pragma code HIGH_INTERRUPT_VECTOR = 0x8
void high_isr (void)
{
    _asm 
         goto toggle_LED
    _endasm
}
#pragma code

#pragma interrupt toggle_LED
int x = 0;
void toggle_LED(void)
{
    INTCONbits.TMR0IF = 0;
    WriteTimer0(0x00);
    if (x != 1){
        PORTBbits.RB4 = !(PORTBbits.RB4);
    }
        
    return;
}

void main(void) {

    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_8 );
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    WriteTimer0(0x00);
    TRISC = 0x02;
    TRISB = 0x00;
    PORTB = 0x00;
    
    while (1)
    {
       /* PORTB = 0x01;
        Delay10KTCYx(0x0C);*/
        PORTBbits.RB3 = !(PORTBbits.RB3);
        x = PORTCbits.RC2;
        Delay10KTCYx(0x0C);
    }
    
}
