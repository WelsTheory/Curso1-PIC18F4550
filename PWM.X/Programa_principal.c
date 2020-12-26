/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de diciembre de 2020, 04:22 PM
 */


#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "PWM_Libreria.h"

uint8_t duty = 0;
/*
 * duty max = 52 = 0000110100
 */

void main(void) {
    PWM_Init();
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    while(1){
        if(PORTBbits.RB0 == 0){
            duty++;
            if(duty == 0b00110100){
                duty = 0b00110011;
            }
//            CCP1CON = (CCP1CON & 0x0F) | ((duty<<4)& 0x30); 
            /*
             *  CCP1CON = 0b00001100 modo pwm
             *       AND  0b00001111
             *          = 0b00001100 (CCP1CON & 0x0F)
             * 
             *  duty = 11110000 <<4 =>> 00 
             *     AND 00110000 = 0X30
             *       = 00110000 ((duty<<4)& 0x30); 
             * 
             *    0b00001100
             * OR 0B00110000
             *   =0B00111100
             */
//            CCPR1L = (duty>>2);
            /*
             * 00000011 
             */
            __delay_ms(50);
        }
        if(PORTBbits.RB1 == 0){
            duty--;
            if(duty == 0b00000000){
                duty = 0b00000001;
            }
//            CCP1CON = (CCP1CON & 0x0F) | ((duty<<4)& 0x30);
//            CCPR1L = (duty>>2);
            __delay_ms(50);
        }
        CCP1CON = (CCP1CON & 0x0F) | ((duty<<4)& 0x30);
        CCPR1L = (duty>>2);
    }
    return;
}
