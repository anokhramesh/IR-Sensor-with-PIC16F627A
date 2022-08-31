/*https://github.com/anokhramesh/Button-Toggle-PIC16F627A
 * File:   ButtonInterfacing.c
 * Author:Anokhramesh
 *
 * Created on August 31, 2022, 7:28 AM
 */
#include <xc.h>
__CONFIG(FOSC_INTOSCIO & WDTE_OFF & PWRTE_ON & MCLRE_ON & BOREN_ON & LVP_OFF & CPD_OFF & CP_OFF);//PIC configuration Bit setting
#define _XTAL_FREQ 4000000// defined crystal frequency
int state=1;// initial value of global variable of state is = 1
// connect Push button to pin  PORT B0  pull down to ground with 10K resister
// connect LED to pin  PORT RB3
//Connect High Active relay to PORT RB2 
void main(void) 
{
    TRISBbits.TRISB0=1;//Set the PORTB Pin RB0 as an INPUT
    TRISBbits.TRISB2=0;//Set the PORTB PIn RB2 as an OUTPUT
    TRISBbits.TRISB3=0;//Set the PORTB PIn RB3 as an OUTPUT
    RB2=0;// set the initial value of RB2 to LOW(RElay OFF)
    RB3=1;// set the initial value of RB3 to HIGH(green LED ON)
    while(1)
        
    { if ((RB0 ==1)&&(state==1))//if button is Pressed and the value of variable state is equal to 1 then 
    {while(RB0==1){RB2=1;RB3=0;// Turn ON the Relay connected to PIN RB2 and Turn OFF the LED COnnected to PIN RB3
        state=0;}// store the value to variable state = 0
    }
    if((RB0==1)&&(state==0))//if button is Pressed and the value of variable state is equal to 0 then 
    {while(RB0==1){RB2=0;RB3=1;// Turn OFF the Relay connected to PIN RB2and Turn ON the LED COnnected to PIN RB3
        state=1;}// restore the value of variable state = 1
    }
    }
     return;
}
