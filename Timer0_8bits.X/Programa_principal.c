/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 12 de diciembre de 2020, 04:08 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
//#include "LCD_Libreria.h"
#include "Interrupt.h"
#include "Timer0_Libreria.h"

void main(void) {
    TRISD = 0x00;
    Timer0_Init();
    Int_Ext();
    while(1){
        
    }
    return;
}

