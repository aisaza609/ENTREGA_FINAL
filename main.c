/*!
\file   main.c
\date   2022-08-10
\author Andrea Isaza Lopez, Alejandro Ceballos  <deceballos@unicauca.edu.co> <aisaza@unicauca.edu.co>
\brief  LCD 16x2 mode 4 bits.
\par Copyright
Information contained herein is proprietary to and constitutes valuable
confidential trade secrets of unicauca, and
is subject to restrictions on use and disclosure.
\par
Copyright (c) unicauca 2022. All rights reserved.
\par
The copyright notices above do not evidence any actual or
intended publication of this material.
******************************************************************************
*/
#include    <xc.h>
#include  <pic16f887.h>
#include  "config.h"
#include "adc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LCD.h"
unsigned int value_adc = 0;//16 bits
unsigned char counter_digito = 0;
double temp = 0.0;
unsigned char lm35 = 0;


#define BETA 4090
#define resistance 10
//#define RL_VALUE (10) 
//#define RO_VALUE_CLEAN_AIR ( 9.83)
//#define RL_VALUE (10)//define the load resistance on the board, in kilo-ohms


void main(void) {
    //OSCCON = 0b01110001;
    OSCCON = 0x71;
    LCD_Init();
    TRISD=0x00;
    TRISE=0x00; // salida puerto D
    TRISA0 = 1;// CONFIGU
    ANSEL = 0x01; //  Configura el Puerto como Entrada Analógica.
    TRISC1=1; //CONFIGURACION ENTRADA GAS
    TRISC0=1; //CONFIGURACION ENTRADA SHOCK
    TRISC3=1; //configuracion entrada vibracion Lesson 16 Mercury Switch
    
//ADC CONFIGURACION SENSOR 1
    
    ADCON1bits.ADFM = 1; //  Justificación Derecha (modo-8bits).
    ADCON1bits.VCFG0 = 0; //  Selecciona Voltajes de Referencia (5v-0v).
    ADCON1bits.VCFG1 = 0; 
    
    ADCON0bits.CHS = 0b0000; //  Selecciona el Canal Analógico AN0.
    ADCON0bits.ADCS = 0b01; //  Tiempo de Co nversión Fosc/8.
    
    ADCON0bits.ADON = 1;//  Habilita el Módulo AD.
    
  
    __delay_ms(3000);
    LCD_String_xy(1,0,"DETECTANDO...");
    __delay_ms(2000);
        LCD_Clear();
        PORTE=0;
        PORTD=0;
        
           
        
        
    while (1) {
        
        //camptura temperatura
        ADCON0bits.GO_DONE = 1; //  Inicia la COnversió AD.
        while (ADCON0bits.GO_DONE); //  Espera a que termine la conversión AD.
        value_adc = ADRESH; //  Lectura de valor AD.
        value_adc = (value_adc << 8) + ADRESL;
        temp = value_adc;
        
        //convertir temperatura
        long a = (long)(1023 - temp);
        float tempC = (float)(BETA /(log((1025.0 * 10/ a - 10) / 10) + BETA / 298.0) - 273.0);
        
         
       //imprime la temperatura
        char Temperature [10];
        sprintf(Temperature, "%d%cC", (int)tempC,0xdf );
        LCD_String_xy(1,0,"T:");
        LCD_String(Temperature);
        LCD_String("  ");
         
        
        // SENSOR DE GAS
        if(PORTCbits.RC1==1) //CONFIGRUACION COMO SALIDA sensor de gas
        {
            
            LCD_String_xy(1,9,"HG");
            PORTE=0x02;
            __delay_ms(200);
            
        }
        
        else if(PORTCbits.RC1==0){
            
           LCD_String_xy(1,9,"NHG");
         
            
        }
        
 
        //SENSOR SHOCK 
         if(PORTCbits.RC0 == 0) //CONFIGRUACION COMO SALIDA)
        {
            
            LCD_String_xy(2,0,"SHOCK");
            PORTE=0x01;
            __delay_ms(200);
        }
        
        else if(PORTCbits.RC0 == 1){
            LCD_String_xy(2,0,"NO SHOCK");
           
        }
          
         //SENSOR Lesson 16 Mercury Switch
         
            if(PORTCbits.RC3==1) //CONFIGRUACION COMO SALIDA)
        {
            
            LCD_String_xy(2,9,"MOV");
            PORTE=0x04;
            __delay_ms(200);
        }
        
        else if(PORTCbits.RC3==0){
            
           LCD_String_xy(2,9,"NO MOV");
            
        }
        
        //configuracion de los leds
        if ( tempC < 30){
            PORTD=0x04;
            __delay_ms(2000);
        }
        else if (tempC >= 30) {
       
                PORTE=0x01;
                __delay_ms(200);
                PORTE=0x02;
                __delay_ms(200);
                 PORTE=0x04;
                __delay_ms(200);
                PORTD=0x04;
                __delay_ms(200);
           
            }
         __delay_ms(2000);
    LCD_String("  ");
        
    }
    
        
}
       

     