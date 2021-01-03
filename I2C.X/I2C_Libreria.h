

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef I2C_H
#define	I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define TRIS_SCL    TRISBbits.RB1
#define TRIS_SDA    TRISBbits.RB0

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_NACK(void);
void I2C_ACK(void);
void I2C_Tx(char dato);
char I2C_Rx(void);

#endif	/* XC_HEADER_TEMPLATE_H */

