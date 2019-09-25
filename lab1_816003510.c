/*Lab 1 first file - 816003510 Group B*/
#include <p18f452.h>
	/* Set configuration bits for use with ICD2 */
	#pragma config OSC = HS
	#pragma config WDT = OFF
	#pragma config LVP = OFF
	

	void main (void)
	{ 
	    /*Code from Question 14 in Prelab*/ 
	    int i = 1;               //Declare and initialize variables 
	    TRISB = 0;                      //Set PORTB as an output
	    while (i < 16)
	    {
	        PORTB = i;           //Assign count to PORTB
	        i++;                 //Increment count
	                
	    }
	}
//working

