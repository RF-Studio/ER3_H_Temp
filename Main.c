/* 
 * File:   Main.c
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:15
 */

#define MAIN_C
#include "../Sources/Config.h"
#include "../Sources/Main.h"

/*------------------------------------------------------------------------------
 *  FONCTION PRINCIPALE
 *----------------------------------------------------------------------------*/
int main(void){
    Main_Init();
    printf("test");
    Lib_Temp_ADC_Start_Conversion_Automatique();
    
    while(1){
    }
    return 0;
}

void Main_Init(void){
    HORLOGE_Init();
    UART_Init();
    ADC_Init();
    RTCC_Init();
    /*
     * CPU Init
     */
    Lib_Temp_CPU_Alimentation_Tous_Les_Modules(ON);
    Lib_Temp_CPU_Gestion_Low_Power_Sleep_Mode(CPU_LOW_POWER_MODE_RETENTION_SLEEP);
    Lib_Temp_CPU_Activation_Interruption(ON, 2);
    
}