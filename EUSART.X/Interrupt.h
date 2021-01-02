
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <xc.h> // include processor files - each processor file is guarded.  

void Int_Ext(void);

void __interrupt(high_priority) INT2_Ext(void);
void __interrupt(low_priority) INT1_Ext(void);

#endif	/* XC_HEADER_TEMPLATE_H */

