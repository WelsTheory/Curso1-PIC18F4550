/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 12 de diciembre de 2020, 04:08 PM
 */

#include <xc.h>
#include "Configuracion.h"
#include "Interrupt.h"

extern int i;

void main(void) {
    TRISDbits.RD0 = 0; 
    TRISDbits.RD1 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD0 = 0; 
    Int_Ext();
    while(1){
        if(i == 2){
            LATDbits.LATD0 = 1;
        }
        if(i == 1){
            LATDbits.LATD0 = 0;
        }
    }
    return;
}

//void Int0_Ext(void){
//    TRISBbits.RB0 = 1; //Entrada
//    INTCONbits.INT0E = 1; // Habilitar la Int0
//    INTCONbits.INT0F = 0;
//    INTCON2bits.INTEDG0 = 0; // 1 a 0
//    INTCONbits.GIE = 1; // Globales
//    INTCONbits.PEIE = 1;// Periféricos
//}
//
//void __interrupt() INT0_Ext(void){
//    LATDbits.LATD0 = ~LATDbits.LATD0;
//    INTCONbits.INT0F = 0;
//}
