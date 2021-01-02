
#include <xc.h>
#include "ADC_Libreria.h"
#include "Configuracion.h"

void ADC_Init(void){
    ADCON1bits.PCFG = 0b0111; //AN7 ANALOGO
    ADCON1bits.VCFG = 0b00; // Vref VDD y VSS
    //ADCON0bits.CHS = 0b0000;
    ADCON2bits.ADCS = 0b101; // TAD = 16*(1/20MHz) = 0.8us = 0.8us Minimo 
    ADCON2bits.ACQT = 0b010; // TAQ = 4TAD = 4*0.8 = 3.2us > 2.45us Minimo
    ADCON2bits.ADFM = 1; // Justificacion izq
    //ADCON0bits.ADON = 1; // ADC ON
}

unsigned int ADC_Read(unsigned char ch){
    if(ch > 13){
        ch = 0;
    }
    ADCON0bits.CHS = ch;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO == 1);
    ADCON0bits.ADON = 0;
    return ADRES; 
}
