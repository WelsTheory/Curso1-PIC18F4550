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
//#include "Interrupt.h"

void main(void) {
    LCD_Init();
    LCD_XY(0,11);
    LCD_Data('e');
    LCD_XY(1,3);
    LDC_Cadena("hola");
    while(1){
        
    }
    return;
}

