/* Lab 1 first file - ID number 816003022 Group CRYTEK  */
#include <p18f452.h>   

#define NUMBER_OF_LEDS 4
/* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

static unsigned char s_count = 0;

#pragma code
#pragma interrruptlow timer_isr save=PROD

void timer_isr(void)
{
    static unsigned char led_display = 0;
    INTCONbits.TMR0IF = 0;
    
    s_count = s_count % (NUMBER_OF_LEDS + 1);
    led_display = (1 << s_count++) - 1;
    PORTB = led_display;
    if (s_count >= 4)
    {
        s_count = 0;
    }
}
void main (void)
{
    /* Insert code from pre-lab Q14 to change values on PORTB */
    TRISAbits.TRISA1  =   0;
    LATAbits.LATA3    =   0;
    
    TRISB   =   0;
    PORTB   =   0;
    
    T0CONbits.TMR0ON    =   1;
    T0CONbits.T0CS      =   0;
    T0CONbits.T08BIT    =   0;
    
    INTCONbits.GIE      =   1;
    
    while(1) {}
    
    
}
