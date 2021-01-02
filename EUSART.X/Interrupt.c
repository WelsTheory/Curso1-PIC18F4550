
#include <xc.h>
#include "Interrupt.h"

int i = 0;
int a = 0;
char datos[5];

void Int_Ext(void){
    //TRISBbits.RB0 = 1; //Entrada
    //TRISBbits.RB1 = 1; //INT1
    //TRISBbits.RB2 = 1; //INT2
//    INTCONbits.INT0E = 1; // Habilitar la Int0
//    INTCONbits.INT0F = 0;
//    INTCON3bits.INT1E = 1;
    //INTCON3bits.INT2E = 1;
//    INTCON3bits.INT1F = 0;
//    //INTCON3bits.INT2F = 0;
//    INTCON3bits.INT1IP = 0;  //BAJA PRIORIDAD INT1
//    //INTCON3bits.INT2IP = 1; // ALTA PRIORIDAD INT2
//    INTCON2bits.INTEDG0 = 0; // 1 a 0
//    INTCON2bits.INTEDG1 = 0; // 1 A 0
    //INTCON2bits.INTEDG2 = 0; 
    RCONbits.IPEN = 1; // Habilitando PRioridades
    INTCONbits.GIEH = 1; // Globales prioridad altas
    INTCONbits.GIEL = 1;// prioridades bajas
}

void __interrupt(high_priority) INT0_Ext(void){
  
    INTCONbits.INT0F = 0;
}

void __interrupt(low_priority) Recepcion_Ext(void){
    datos[1] = RCREG;
    i++;
    a++;
    PIR1bits.RCIF = 0;
}
//
//void __interrupt() INT0_Ext(void){
//    LATDbits.LATD0 = ~LATDbits.LATD0;
//    INTCONbits.INT0F = 0;
//}