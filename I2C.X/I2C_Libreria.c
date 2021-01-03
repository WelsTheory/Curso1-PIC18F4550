
#include <xc.h>
#include "Configuracion.h"
#include "I2C_Libreria.h"

void I2C_Init(void){
    TRIS_SCL = 1;
    TRIS_SDA = 1;
    
    SSPSTATbits.CKE = 0;
    SSPSTATbits.SMP = 1;
    
    SSPCON1bits.SSPEN = 1; //SDA y SCL
    SSPCON1bits.SSPM = 0b1000; // Modo maestro
    
    SSPCON2 = 0x00;//
            
    SSPADD = 49; //100KHz
}

void I2C_Start(void){
    SSPCON2bits.SEN = 1;// INICIA CONDICIÓN START
    while(SSPCON2bits.SEN);
}

void I2C_Stop(void){
    SSPCON2bits.PEN = 1;//  CONDICIÓN STOP
    while(SSPCON2bits.PEN);
}

void I2C_Restart(void){
    SSPCON2bits.RSEN = 1;// CONDICIÓN RESTART
    while(SSPCON2bits.RSEN);
}

void I2C_NACK(void){
    PIR1bits.SSPIF = 0;
    SSPCON2bits.ACKDT = 1;// NACK
    SSPCON2bits.ACKEN = 1; //Habilitamos ACK
    while(PIR1bits.SSPIF == 0);
    PIR1bits.SSPIF = 0;
}

void I2C_ACK(void){
    PIR1bits.SSPIF = 0;
    SSPCON2bits.ACKDT = 0;// ACK
    SSPCON2bits.ACKEN = 1; //Habilitamos ACK
    while(PIR1bits.SSPIF == 0);
    PIR1bits.SSPIF = 0;
}

void I2C_Tx(char dato){
    PIR1bits.SSPIF = 0;
    SSPBUF = dato;
    while(PIR1bits.SSPIF == 0);
    PIR1bits.SSPIF = 0;
}

char I2C_Rx(void){
    PIR1bits.SSPIF = 0;
    SSPCON2bits.RCEN = 1; //Habilitando Recepción
    while(PIR1bits.SSPIF == 0);
    PIR1bits.SSPIF = 0;
    return SSPBUF;
}
