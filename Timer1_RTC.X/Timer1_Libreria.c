
#include <xc.h>
#include "Configuracion.h"
#include "Timer1_Libreria.h"

int sec = 8, sec_d = 5, min = 9, min_d = 5, hor = 3, hor_d = 2;

void Timer1_Init(void){
    TMR1H = 0x80;//TMR1 = 8000 -> FFFF
    TMR1L = 0x00;
    T1CON = 0x0F;
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    IPR1bits.TMR1IP = 1;
}
