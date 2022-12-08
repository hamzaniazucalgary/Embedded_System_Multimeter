/*
 * File:   TimeDelay.c
 * Author: Hamza N, Yousef H, Rumaisa T
 *
 * Created on November 28, 2022, 8:41 PM
 */
#include "TimeDelay.h"
void TMR2config(void)
{
    IFS0bits.T2IF = 0;//clear Timer2 interrupt flag
    IEC0bits.T2IE = 1;//enable interrupt for Timer2
    IPC1bits.T2IP = 0b001;//set priority level - only one interrupt so 111 is fine
    T2CONbits.TSIDL = 0;//continue operation in Idle mode
    T2CONbits.T32 = 0;//use Timer2 as standalone 16 bit timer
    T2CONbits.TCS = 0;//use internal clock
    T2CONbits.TCKPS = 0b01;//set pre-scaler to 1:8 for fun/to test
}
void delay_ms(uint16_t time_ms)
{   
    TMR2config();//Configure Timer2
    PR2 = time_ms * 2;//Time_ms * 32000 Hz /1000 / 2 / pre-scaler(1:8)    
    T2CONbits.TON = 1;//Turn on Timer2   
    Idle();//Go to idle mode until Timer2 interrupt occurs  
    return;
}
void __attribute__((interrupt, no_auto_psv))_T2Interrupt(void)
{
    IFS0bits.T2IF = 0;//Clear Timer2 interrupt flag
    T2CONbits.TON = 0;//Turn off Timer2
    TMR2 = 0;//Reset TMR2 register
    return;
}