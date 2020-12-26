
#include <xc.h>
#include "Configuracion.h"
#include "EEPROM_Libreria.h"

void EEPROM_Write(uint8_t dir, uint8_t dat){
    EEADR = dir;
    EEDATA = dat;
    EECON1bits.EEPGD = 0; //MEMORIA EEPROM
    EECON1bits.CFGS = 0; // EEPROM
    EECON1bits.WREN = 1; //HABILITAR ESCRITURA
    /* SECUENCIA REQUERIDA */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    while(EECON1bits.WR == 1);
    EECON1bits.WREN = 0;
}

uint8_t EEPROM_Read(uint8_t dir){
    EEADR = dir;
    EECON1bits.EEPGD = 0; //MEMORIA EEPROM
    EECON1bits.CFGS = 0; // EEPROM
    EECON1bits.RD = 1;
    return EEDATA;
}
