
#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "EUSART.h"

void EUSART_Init(uint8_t baud){ 
    TRISCbits.RC6 = 0;// TX
    TRISCbits.RC7 = 1;// RX
    SPBRG = baud; //9600 
    TXSTAbits.SYNC = 0;// Asincrono
    TXSTAbits.BRGH = 0;
    BAUDCONbits.BRG16 = 0;
    RCSTAbits.SPEN = 1; // TX y RX
    //Transmisión
    TXSTAbits.TX9 = 0;// 8 bits
    TXSTAbits.TXEN = 1; // Transmisión habilitada
    //Recepción
    RCSTAbits.RX9 = 0; // 8 bits
    RCSTAbits.CREN = 1;// Habilitar Recepción
    PIR1bits.RCIF = 0;// Limpiando la bandera
    PIE1bits.RCIE = 1;// Habilitar la int recpecion
    IPR1bits.RCIP = 0;
}

void EUSART_Tx(char dato_tx){
    while(TXSTAbits.TRMT == 0);
    TXREG = dato_tx;
}

void EUSART_Cadena(char *datas){
    while(*datas != '\0'){
        __delay_us(100);
        EUSART_Tx(*datas);
        datas++;
    }
}

char EUSART_Rx(void){
    return RCREG;
}
