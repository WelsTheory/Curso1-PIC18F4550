
#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "I2C_Libreria.h"
#include "Ds1307_Libreria.h"

char datos = 0;
char set[6] ={"174001"};

/*
 * '1' = 0x31  '2' = 0x32 -- 0x39 = '9' 
 * and = 0x0F      = 0x0F
 *     = 0x01 -> 00010000
 *     = <<4       = 0x02     
 *     = 0x10      + 0x02 = 0x12
 */

void Escribir_Hora(void){
    horas = ((set[0] & 0x0F)<<4) + (set[1]&0x0F);
    minutos = ((set[2] & 0x0F)<<4) + (set[3]&0x0F);
    segundos = ((set[4] & 0x0F)<<4) + (set[5]&0x0F);
    I2C_Start();
    I2C_Tx(0b11010000);// DIR + RW
    I2C_Tx(0b00000000);//Registro Segundos
    I2C_Tx(segundos);
    I2C_Tx(minutos);
    I2C_Tx(horas);
    I2C_Stop();
    
}

void Leer_Hora(void){
    I2C_Start();
    I2C_Tx(0b11010000);// DIR + RW
    I2C_Tx(0b00000000);//Registro Segundos
    I2C_Restart();
    I2C_Tx(0b11010001);// DIR + RW
    segundos = I2C_Rx();
    I2C_ACK();
    minutos = I2C_Rx();
    I2C_ACK();
    horas = I2C_Rx();
    I2C_NACK();
    I2C_Stop();
}
