/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 12 de diciembre de 2020, 04:08 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "LCD_Libreria.h"
#include "Interrupt.h"
#include "Timer0_Libreria.h"

int x = 0;

void main(void) {
    TRISD = 0x00;
    Timer0_Init();
    LCD_Init();
    Int_Ext();
    while(1){
        if (x == 1){
            LCD_XY(1,5);
            LCD_Cadena("Hola :D");
        }
        if( x == 2){
            LCD_XY(0,9);
            LCD_Cadena("WELS");
        }
        if(x == 0){
            LCD_Comando(0x01);// Limpiar LCD
        }
    }
    return;
}

