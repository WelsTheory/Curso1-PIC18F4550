
#include <xc.h>
#include "Configuracion.h"
#include "Timer0_Libreria.h"

//TIEMPO -> 10MS
//TMR0L -> 59.68 = 60
//TMR0L -> 235.46

//16 BITS
//void Timer0_Init(void){
//    T0CONbits.T08BIT = 0; // 16bits
//    T0CONbits.T0CS = 0;
//    T0CONbits.PSA = 0; // asignando prescaler
//    T0CONbits.T0PS = 0b111;
//    TMR0 = 46004;
//    INTCONbits.TMR0IE = 1;
//    INTCONbits.TMR0IF = 0;
//    INTCON2bits.TMR0IP = 0;
//    T0CONbits.TMR0ON = 1; // TMR0 on
//}

// 8 BITS
void Timer0_Init(void){
    T0CONbits.T08BIT = 1; // 8bits
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 0; // asignando prescaler
    T0CONbits.T0PS = 0b111;
    TMR0L = 60;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    INTCON2bits.TMR0IP = 0;
    T0CONbits.TMR0ON = 0; // TMR0 on
//    T0CONbits.TMR0ON = 1; // TMR0 on
}
