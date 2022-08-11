/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   adc.h
 * Author: Andrea Isaza Lopez, Alejandro Ceballos  <deceballos@unicauca.edu.co> <aisaza@unicauca.edu.co>
 * Comments: aqui se hace el llamado de los puertos 
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#define SBIT_ADON     0
#define SBIT_CHS0     2
#define SBIT_ADFM     7

#define AN0     0x01
#define AN1     0x02
#define AN2     0x04
#define AN3     0x08
#define AN4     0x10
#define AN5     0x20
#define AN6     0x40
#define AN7     0x80
    
void delay_adc(int cnt);
void ADC_Pin(unsigned char pines);
void ADC_Init(void);
int ADC_Read(int adcChannel);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */