/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 12 de diciembre de 2020, 04:08 PM
 */

#include <xc.h>
#include "Configuracion.h"

void main(void) {
    TRISDbits.RD0 = 0; //ENABLE
    TRISDbits.RD1 = 0; //SENTIDO
    TRISDbits.RD2 = 0;
    LATDbits.LATD0 = 1; // Habilitando L293D 
    TRISBbits.RB0 = 1; // Entradas 
    TRISBbits.RB1 = 1;
    while(1){
        if(PORTBbits.RB0 == 0 && PORTBbits.RB1 == 1){
            LATDbits.LATD1 = 1;
            LATDbits.LATD2 = 0;
        }
        
        if(PORTBbits.RB1 == 0 && PORTBbits.RB0 == 1){
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 1;
        }
        
        else if(PORTBbits.RB1 == 1 && PORTBbits.RB0 == 1){
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0; 
        }
        
        else if(PORTBbits.RB1 == 0 && PORTBbits.RB0 == 0){
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0; 
        }
    }
    return;
}
