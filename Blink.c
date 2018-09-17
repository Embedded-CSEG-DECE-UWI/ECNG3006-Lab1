#include <p18cxxx.h>
#include <delays.h>
//testing change
//Set configuration Bits
#pragma config WDT = OFF
#pragma config OSC = HS

void main(void)
{

      TRISDbits.TRISD7 = 0; // Set Pin RD7 as an output
  
  while(1)
  {  
        LATDbits.LATD7 = 1;// Set RD7 High
   
        Delay10KTCYx(200); //Wait for some time (two seconds)
    
         LATDbits.LATD7= 0;// Set RD7 Low
    
         Delay10KTCYx(200); //Wait for some time (two seconds) 
   
 
  }
}