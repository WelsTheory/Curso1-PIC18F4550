
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DS1307_H
#define	DS1307_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h>

uint8_t horas = 0, segundos = 0, minutos =0;

void Escribir_Hora(void);
void Leer_Hora(void);

#endif	/* XC_HEADER_TEMPLATE_H */

