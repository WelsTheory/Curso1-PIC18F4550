
#include <xc.h>
#include "Interrupt.h"

extern int x;
int i = 0;

void Int_Ext(void){
    TRISBbits.RB0 = 1; //Entrada
//    TRISBbits.RB1 = 1; //INT1
//    TRISBbits.RB2 = 1; //INT2
    INTCONbits.INT0E = 1; // Habilitar la Int0
    INTCONbits.INT0F = 0;
//    INTCON3bits.INT1E = 1;
//    INTCON3bits.INT2E = 1;
//    INTCON3bits.INT1F = 0;
//    INTCON3bits.INT2F = 0;
//    INTCON3bits.INT1IP = 0;  //BAJA PRIORIDAD INT1
//    INTCON3bits.INT2IP = 1; // ALTA PRIORIDAD INT2
    INTCON2bits.INTEDG0 = 0; // 1 a 0
//    INTCON2bits.INTEDG1 = 0; // 1 A 0
//    INTCON2bits.INTEDG2 = 0; 
    RCONbits.IPEN = 1; // Habilitando PRioridades
    INTCONbits.GIEH = 1; // Globales prioridad altas
    INTCONbits.GIEL = 1;// prioridades bajas
}

void __interrupt(high_priority) INT0_Ext(void){
    x++;
    if(x > 2){
        T0CONbits.TMR0ON = 0; // TMR0 off
        LATDbits.LATD0 = 0;
        x = 0;
    }
    if(x == 0){
        T0CONbits.TMR0ON = 1; // TMR0 on
    }  
    INTCONbits.INT0F = 0;
}

void __interrupt(low_priority) TMR0_Ext(void){
    TMR0L = 60;
    i++;
    if(i == 10){
        i = 0;
        LATDbits.LATD0 = ~LATDbits.LATD0;
    }
    INTCONbits.TMR0IF = 0;
}
//
//void __interrupt() INT0_Ext(void){
//    LATDbits.LATD0 = ~LATDbits.LATD0;
//    INTCONbits.INT0F = 0;
//}