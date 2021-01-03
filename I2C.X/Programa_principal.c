/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 12 de diciembre de 2020, 04:08 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "I2C_Libreria.h"
#include "Ds1307_Libreria.h"
#include "LCD_Libreria.h"

uint8_t i = 0;
extern char datos;

void main(void) {
    TRISD = 0x00;
    LCD_Init();
    ADCON1bits.PCFG = 0xF;
    I2C_Init();
    Escribir_Hora();
    LCD_XY(0,0);
    LDC_Cadena("LA HORA ES: ");
    while(1){
        Leer_Hora();
        LCD_XY(1,5);
        /*
         * horas = 0x12 -> 0x12 & 0xF0= 0x10 -> >>4 = 0x01 + '0' = 31 = '1'
         * horas = 0x12 -> 0x12 & 0x0F= 0x02 -> + '0' = 32 = '2'
         */
        LCD_Data('0'+ ((horas&0xF0)>>4));
        LCD_Data('0'+ (horas&0x0F));
        LCD_Data(':');
        LCD_Data('0'+ ((minutos&0xF0)>>4));
        LCD_Data('0'+ (minutos&0x0F));
        LCD_Data(':');
        LCD_Data('0'+ ((segundos&0xF0)>>4));
        LCD_Data('0'+ (segundos&0x0F));
        I2C_Start();
        I2C_Tx(0x40);
        I2C_Tx(i);
        I2C_Stop();
        __delay_ms(200);
        i++;
    }
    return;
}


//void main(void) {
//    ADCON1bits.PCFG = 0xF;
//    I2C_Init();
//    while(1){
//        for( i=0; i<16;i++){
//            I2C_Start();
//            I2C_Tx(0x40);// Direccion + RW
//            //I2C_ACK();
//            I2C_Tx(i);
//            //I2C_ACK();
//            I2C_Stop();
//            __delay_ms(250);
//        }
//        
//
//    }
//    return;
//}

