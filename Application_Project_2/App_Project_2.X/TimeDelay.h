// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TIMEDELAY_H
#define	TIMEDELAY_H
#include <xc.h> // include processor files - each processor file is guarded.  
void delay_ms(uint16_t time_ms);
void __attribute__((interrupt, no_auto_psv))_T2Interrupt(void);
void TMR2config(void);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
#ifdef	__cplusplus
}
#endif /* __cplusplus */
#endif	/* TIMEDELAY_H */

