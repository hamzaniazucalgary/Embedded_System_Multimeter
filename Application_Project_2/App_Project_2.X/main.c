/*
 * File:   main.c
 * Author: Hamza N, Yousef H, Rumaisa T
 *
 * Created on November 28, 2022, 8:39 PM
 */
// MPLAB header libraries
#include <xc.h>
#include <p24fxxxx.h>
#include <p24F16KA101.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
// User header files
#include "IOs.h"
#include "ChangeClk.h"
#include "TimeDelay.h"
#include "UART2.h"
#include "ADC.h"
//Preprocessor directives - Configuration bits for MCU start up
#pragma config FCKSM = CSECMD // Clock switching is enabled, clock monitor disabled
#pragma config OSCIOFNC = ON //CLKO output disabled on pin 8, use as IO.
// MACROS for Idle, Sleep modes
#define Nop() {__asm__ volatile ("nop");}
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep() {__asm__ volatile ("pwrsav #0");}   //Sleep() - put MCU in sleep mode - CPU and some peripherals off
#define Idle() {__asm__ volatile ("pwrsav #1");}    //Idle() - put MCU in idle mode - only CPU off
#define dsen() {__asm__ volatile ("BSET DSCON, #15");} //
//Global Variables
uint8_t state = 3;//This is the default state of the UART2 (idle)
//MAIN
int main(void) {
    // Change Clock
    NewClk(32);//Change clock to 32kHz for lowest power consumption
    IOinit();//Initialize IOs
    while(1)
    {
        if(state == 3)  //If in state 3, go to idle
        {
            /* Clear screen and go to Idle */
            Disp2String("Idle...                                                             \r");//Display idle
            Idle();//Idle
        }
        else//If in state 1 or 2, go to IOCheck()
        {
            IOCheck();//Calls the IOCheck() function
        }
    }
    return 0;
}
