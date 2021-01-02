/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 12 de diciembre de 2020, 04:08 PM
 */

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "Interrupt.h"
#include "Configuracion.h"
#include "ADC_Libreria.h"
#include "LCD_Libreria.h"
#include "EUSART.h"

char valor = 0;
extern char datos[5];
extern int i;
extern int a;

void main(void) {
    EUSART_Init(31); //9600 baudios
    LCD_Init();
    Int_Ext();
    while(1){
        switch(valor){
            case '1':
                EUSART_Tx('1');
                LCD_Comando(0x01);
                LCD_XY(0,0);
                LDC_Cadena("Hola");
                LATDbits.LATD0 = ~LATDbits.LATD0;
                __delay_ms(100);
                break;
                
            case '2':
                LATDbits.LATD0 = ~LATDbits.LATD0;
                __delay_ms(100);
                break;
        }
        if(a == 5){
            LCD_XY(0,0);
            LDC_Cadena(datos);
            __delay_ms(100);
        }
    }
    return;
}

//void main(void) {
//    EUSART_Init(31); //9600 baudios
//    LCD_Init();
//    Int_Ext();
//    while(1){
//        valor = EUSART_Rx();
//        switch(valor){
//            case 'a':
//                EUSART_Tx('1');
//                LCD_Comando(0x01);
//                __delay_ms(100);
//                break;
//                
//            case 'b':
//                LCD_XY(0,0);
//                LCD_Comando(0x01);
//                LDC_Cadena("Hola");
//                __delay_ms(100);
//                break;
//                
//            case 'c':
//                EUSART_Tx('0');
//                LCD_Comando(0x01);
//                LCD_XY(0,0);
//                LDC_Cadena("DENEGADO");
//                __delay_ms(100);
//                break;
//                
//            default:
//                EUSART_Tx('-');
//                LCD_Comando(0x01);//Limpiar LCD
//                break;
//        }
//    }
//    return;
//}
