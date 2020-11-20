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
    Date.Mois = 11;
    Date.Jour = 20;
    Date.JourSemaine = 5;
    Date.Heure = 16;
    Date.Minute = 35;
    Date.Second = 25;
    
    unsigned long sec;
    char date_string[50];

    Lib_Temp_RTCC_Activation_Clock_Out(ON); // power on date module
    Lib_Temp_RTCC_Activation_Interruption(ON, 6);

    Lib_Temp_RTCC_Ecriture_Date_Dans_Module_RTCC_du_Microcontroleur(Date);
    Lib_Temp_RTCC_Lecture_Date(&Date);
    Lib_Temp_RTCC_Conversion_Date_En_Seconde(Date, &sec);
    Lib_Temp_RTCC_Conversion_Seconde_en_Date_String(sec, date_string);
    printf("%s", date_string);
}

void RTCC_print(void){
    
}