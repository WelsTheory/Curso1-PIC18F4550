
#include <xc.h>
#include "Configuracion.h"
#include "LCD_Libreria.h"

void LCD_Init(void){
    TRISD = 0x00;
    LATD = 0x00;
//    __delay_ms(15);
    //0x30 x 3
    LCD_Comando(0x30);
    __delay_ms(100);
    LCD_Comando(0x30);
    __delay_ms(100);
    LCD_Comando(0x32);// 4 BITS
    LCD_Comando(0x28);
    LCD_Comando(0x0C);
    LCD_Comando(0x01);
    LCD_Comando(0x06);
    __delay_ms(100);
}

void LCD_Comando(char cmd){
    /*
     * 0x30 -> 0b 0011 0000
     */
    LCD_PORT = LCD_PORT & 0x0f;
    /*
     * LCD_PORT = 0B00000011
     *        AND 0B00001111
     *          = 0B00000011
      */
    LCD_PORT = LCD_PORT | (cmd & 0xf0);
    /*
     * cmd = 0b 0011 0000
     *  and  0b 1111 0000
     *     = 0b 0011 0000
     * LCD_PORT = 0B00000011
     *  OR        0B00110000
     *          = 0B00110011 
     */
    RS = 0; //MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0x0f;//RD4 al RD7
    LCD_PORT |= ((cmd<<4) & 0xf0);
    /*
     * cmd = 0b 00110010
     * cmd = 0b 00000000 <<4 
     * and = 0b 11110000
     *     = 0b 00000000
     * 
     */
    RS = 0; //MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
}

void LCD_Data(char data){
    /*
     * 0x30 -> 0b 0011 0000
     */
    LCD_PORT = LCD_PORT & 0x0f;
    LCD_PORT = LCD_PORT | (data & 0xf0);
    
    RS = 1; //MODO CARACTER
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0x0f;//RD4 al RD7
    LCD_PORT |= ((data<<4) & 0xf0);

    RS = 1; //MODO CARACTER
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
}

void LCD_XY(int x, int y){
    if(x>0){
        LCD_Comando(0xC0+y);
    }
    else{
        LCD_Comando(0x80+y);
    }
}

void LCD_Cadena(const char *dato){
    while(*dato != '\0'){
        __delay_us(100);
        LCD_Data(*dato);
        dato++;
    }
}
