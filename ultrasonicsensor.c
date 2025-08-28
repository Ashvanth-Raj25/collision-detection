/*
 * File:   ultrasonic.c
 * Author: ashva
 *
 * Created on 12 August, 2025, 10:50 AM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000
#include "ultrasonic.h"
void main(void) 
{
    PORTD=PORTE=0X00;
    TRISD=TRISE=0X00;
    PORTA=0X00;
    TRISA=0X02;
    ANSEL=ANSELH=0X00;
    T1CON=0X00;
    int distance,time;
    command(0,0x38);
    command(0,0x0E);
    while(1)
    {
        TMR1=0;
        RA2=1;
        __delay_us(10);
        RA2=0; 
       while(RA1==0);
        TMR1ON=1;
        while(RA1==1);
        TMR1ON=0;
        time=TMR1;
        distance=time/58;
        display(distance);
    }

}
