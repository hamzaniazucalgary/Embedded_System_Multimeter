#ifndef ADC_H
#define	ADC_H
#include <xc.h> // include processor files - each processor file is guarded.  
uint16_t do_ADC(uint8_t inputSelect);
void PrintADCToScreen(uint16_t ADCValue);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* ADC_H */

