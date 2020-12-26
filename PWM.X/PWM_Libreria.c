
#include <xc.h>
#include "Configuracion.h"
#include "PWM_Libreria.h"

void PWM_Init(void){
    PR2 = 12;// Set Period
    CCPR1L = 0b00000000;
    CCP1CONbits.DC1B = 0b01;
    //40%
//    CCPR1L = 0b00000101;
//    CCP1CONbits.DC1B = 0b01;
    TRISCbits.RC2 = 0;// Salida
    T2CONbits.TMR2ON = 1;
    T2CONbits.T2CKPS = 0b10;// Prescaler 16
    CCP1CONbits.CCP1M = 0b1100; //MODO PWM
    //00000101 01
}
