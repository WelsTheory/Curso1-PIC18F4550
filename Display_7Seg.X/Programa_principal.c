/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 12 de diciembre de 2020, 04:08 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "Interrupt.h"

unsigned char display[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};// CATODO
// char -> 8 bits
// int -> 16 bits
//unsigned char display[10]={0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10}; ANODO
uint16_t uni = 0, dec = 0, cen = 0;
int x = 0;

void main(void) {
    uint16_t i;
    TRISD = 0x00;
    TRISA = 0x00;
    TRISB = 0x00;
    Int_Ext();
    while(1){
        if(x == 1){
            for(i = 0;i<999;i++){
                cen = i/100;
                LATAbits.LA0 = 1;
                LATD =  display[cen];
                __delay_ms(50);
                LATAbits.LA0 = 0;
                dec = i/10;
                if(dec >= 10){
                    dec = dec%10;
                }
                LATAbits.LA1 = 1;
                LATD =  display[dec];
                __delay_ms(50);
                LATAbits.LA1 = 0;
                uni = i%10;
                LATAbits.LA2 = 1;
                LATD =  display[uni];
                __delay_ms(50);
                LATAbits.LA2 = 0;
            }
        }     
        if(x == 2){
            LATAbits.LA0 = 1;
            for(i=0;i<10;i++){
                LATD = display[i];
                __delay_ms(500);
            }
        }
    }
    return;
}

//void main(void) {
//    uint16_t i;
//    TRISD = 0x00;
//    TRISA = 0x00;
//    while(1){
//        for(i = 0;i<999;i++){
//            cen = i/100;
//            LATAbits.LA0 = 1;
//            LATD =  display[cen];
//            __delay_ms(50);
//            LATAbits.LA0 = 0;
//            dec = i/10;
//            if(dec >= 10){
//                dec = dec%10;
//            }
//            LATAbits.LA1 = 1;
//            LATD =  display[dec];
//            __delay_ms(50);
//            LATAbits.LA1 = 0;
//            uni = i%10;
//            LATAbits.LA2 = 1;
//            LATD =  display[uni];
//            __delay_ms(50);
//            LATAbits.LA2 = 0;
//        }
//    }
//    return;
//}
