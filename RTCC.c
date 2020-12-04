/* 
 * File:   RTCC.c
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:21
 */

#define RTCC_C
#include "../Sources/Main.h"
    
void RTCC_Init(void){
    RTCC_DATE Date;
    Date.An = 20;
    Date.Mois = 12;
    Date.Jour = 04;
    Date.JourSemaine = 5;
    Date.Heure = 13;
    Date.Minute = 26;
    Date.Second = 00;

    Lib_Temp_RTCC_Config(); // power ON date module
    Lib_Temp_RTCC_Activation_Interruption(ON, 6); // enable interupt

    Lib_Temp_RTCC_Ecriture_Date_Dans_Module_RTCC_du_Microcontroleur(Date); // change date
}

void RTCC_print(void){
    
}



//------------------------------------------------------------------------------
// Interruption RTCC
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _RTCCInterrupt(void)
{
    
    RTCCON1Hbits.ALRMEN         = 1;
    IFS3bits.RTCIF              = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------





