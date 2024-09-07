/*
 * File:   gear_indicator_tx.c
 * Author: Yogesh S
 *
 * Created on 25 May, 2024, 7:15 AM
 */

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void delay(unsigned int a)//delay used for synchronization and responsiveness
{
    while(--a);
}

void tx(char data)//transmitter function gets char as an input parameter
{
    TXREG=data;
    while(TXIF==0);
    TXIF=0;
}

void main(void) {
    
    PORTA=0X00;TRISA=0XFF;//enabling port a
    PORTC=0X00;TRISC=0X80;//enabling port c
    ANSEL=0X00;ANSELH=0X00;//analog selection registers
    TXSTA=0X26;RCSTA=0X90;
    SPBRG=25;
    
    while(1)
    {
        if(RA0==1)//for 1st gear
        {
        tx('1');
        while(RA0==1);//key bouncing
        }
        if(RA1==1)//for 2nd gear
        {
        tx('2');
        while(RA1==1);
        }
        if(RA2==1)//for 3rd gear
        {
        tx('3');
        while(RA2==1);
        }
        if(RA3==1)//for 4th gear
        {
        tx('4');
        while(RA3==1);
        }
        if(RA4==1)//for 5th gear
        {
        tx('5');
        while(RA4==1);
        }
        if(RA5==1)//for reverse
        {
        tx('R');
        while(RA5==1);
        }
        if(RA6==1)//to indicate neutral
        {
        tx('N');
        while(RA6==1);
        }
    }
}