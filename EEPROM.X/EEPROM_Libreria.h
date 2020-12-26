 
#ifndef EEPROM_H
#define	EEPROM_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void EEPROM_Write(uint8_t dir, uint8_t dat);
uint8_t EEPROM_Read(uint8_t dir);

#endif	/* XC_HEADER_TEMPLATE_H */

