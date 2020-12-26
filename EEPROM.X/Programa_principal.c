/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de diciembre de 2020, 04:22 PM
 */


#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "EEPROM_Libreria.h"

uint8_t dato = 0;

void main(void) {
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    TRISD = 0x00;
    while(1){
        if(PORTBbits.RB0 == 0){
            EEPROM_Write(100,'H');
//            __delay_ms(100);
        }
        if(PORTBbits.RB1 == 0){
            dato = EEPROM_Read(100);
//            __delay_ms(100);
        }
        LATD = dato;
    }
    return;
}
