/* 
 * File:   ADC.c
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:21
 */

#define ADC_C
#include "../Sources/Main.h"

//------------------------------------------------------------------------------
// Interruption de l'ADC1
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _ADC1Interrupt(void)
{
    
    
    AD1CON1bits.ASAM        = 0;            // Stop auto conversion
    IFS0bits.AD1IF          = 0;
}
//------------------------------------------------------------------------------


void ADC_Init(void){
    ADC_CONFIG Adc; // define an ADC_CONFIG variable
    // Configure values of the ADC_CONFIG variable
    Adc.Bit_Voie_de_Conversion_ADC_ANx = ADC_AN0_RA0_BORNE_2;
    Adc.Bit_Alimentation_Capteur_Temperature = BIT_RA1;
    Adc.Autorise_Interruption = 0;
    Adc.Niveau_Priorite = 0;

    Lib_Temp_ADC_Config_ANx(Adc); // Configure l'ADC pour convertir 16 �esure sur la voie ADC_ANx
    Lib_Temp_ADC_Activation_Interruption(ON, 7); // enable interrup for ADC
}