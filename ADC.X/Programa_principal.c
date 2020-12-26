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

extern int i;
uint16_t valor_adc = 0;
float vin = 0.0;
char dato[10];

void Led(void);
void Toggle(void);

void main(void) {
    ADC_Init();
    LCD_Init();
    Int_Ext();
    TRISD = 0x00;
    TRISC = 0x00;
    LATCbits.LATC7 = 1;
    while(1){
        if(i == 2){
            Toggle();
            valor_adc = ADC_Read(1);
            vin = valor_adc*(5.0/1023);
            sprintf(dato,"es = %.2f",vin);
            LCD_XY(0,0);
            LDC_Cadena(dato);
            __delay_ms(100);
        }
        if(i == 3){
            valor_adc = ADC_Read(0);
            vin = valor_adc*(5.0/1023);
            sprintf(dato,"IS = %.2f",vin);
            LCD_XY(0,0);
            LDC_Cadena(dato);
            __delay_ms(100);
        }
        if(i == 1){
            Led();
            valor_adc = ADC_Read(0);
            vin = valor_adc*(5.0/1023);
            sprintf(dato,"IS = %.2f",vin);
            LCD_XY(0,0);
            LDC_Cadena(dato);
            __delay_ms(100);
        }
        if(i == 0){
            valor_adc = ADC_Read(1);
            vin = valor_adc*(5.0/1023);
            sprintf(dato,"IS = %.2f",vin);
            LCD_XY(0,0);
            LDC_Cadena(dato);
            __delay_ms(100);
        }
    }
    return;
}

void Led(void){
    LATCbits.LATC6 = 1;
}
void Toggle(void){
    LATCbits.LATC6 = ~LATCbits.LATC6;
    __delay_ms(100);
}

