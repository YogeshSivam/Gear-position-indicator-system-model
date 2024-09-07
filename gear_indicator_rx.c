/*
 * File:   gear_indicator.c
 * Author: Tyler Durden
 *
 * Created on 25 May, 2024, 7:02 AM
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


//gear indicator receiver function
#include <xc.h>

char gear_data;

void delay(unsigned int a)//delay used for synchronization and responsiveness
{
    while(--a);
}

void pulse()//clock pulse for LCD  to synchronize address and data
{
    RE1=0;//enable pin - low
    delay(1000);
    RE1=1;//enable pin - high
    delay(1000);
}

void buffer(int cmd,char data)//function which gets command and data as an input parameter for LCD
{
    RE0=cmd;//RS(register selection) pin - high for data transmission
    PORTD=data;//sending data to port d
    pulse();//calling pulse function
}

void rx()//receiver function
{
    while(RCIF==0);
    gear_data=RCREG;
    RCIF=0;
    buffer(0,0x80);//force cursor to beginning of first row
    buffer(1,gear_data);//to print data on lcd
}

void main(void) {
    
    PORTA=0X00;TRISA=0XFF;//enabling port a
    PORTC=0X00;TRISC=0X80;//enabling port c
    PORTD=0X00;TRISD=0X00;//enabling port d
    PORTE=0X00;TRISE=0X00;//enabling port e
    ANSEL=0X00;ANSELH=0X00;//analog selection pins
    TXSTA=0X26;RCSTA=0X90;// configuring Transmission and receiving status and control
    SPBRG=25;
    
    buffer(0,0x38);//8 bit, 2 line, 5x7 dots
    buffer(0,0x0c);//display on, cursor off
   
    while(1)
    {
        rx();calling rx function
    }
}
