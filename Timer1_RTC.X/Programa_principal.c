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
//#include "Timer0_Libreria.h"
#include "Timer1_Libreria.h"

extern int sec,sec_d, min_d, min, hor_d,hor;

void main(void) {
    TRISD = 0x00;
    LCD_Init();
    Timer1_Init();
    Int_Ext();
    while(1){
        if(sec > 9){
            sec = 0;
            sec_d++;
        }
        if(sec_d > 5){
            sec_d = 0;
            min++;
        }
        if(min > 9){
            min = 0;
            min_d++;
        }
        if(min_d > 5){
            min_d = 0;
            hor++;
        }
        if(hor > 3){
            hor = 0;
            hor_d++;
        }
        if(hor_d > 2){
            hor_d = 0;
        }
        LCD_XY(0,0);
        LCD_Data('0'+ hor_d);
        LCD_Data('0'+ hor);
        LCD_Data(':');
        LCD_Data('0'+ min_d);
        LCD_Data('0'+ min);
        LCD_Data(':');
        LCD_Data('0'+ sec_d);
        LCD_Data('0'+ sec);// 0X30 + 1 = 31 -> '1'
        __delay_ms(100);
    }
    return;
}

