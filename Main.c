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
    printf("\n\n\rEnter 1 to see date and temp :\n\r");
    while(1){
        
    }
    return 0;
}

void Main_Init(void){
    HORLOGE_Init();
    UART_Init();
    printf("UART UP\n\r");
    ADC_Init();
    printf("ADC up\n\r");
    RTCC_Init();
    printf("RTCC up\n\r");
    /*
     * CPU Init
     */
    Lib_Temp_CPU_Activation_Horloge_Tous_Les_Modules(ON);
    Lib_Temp_CPU_Gestion_Low_Power_Sleep_Mode(CPU_LOW_POWER_MODE_RETENTION_SLEEP);
    Lib_Temp_CPU_Activation_Interruption(ON, 2);
    printf("CPU up\n\r");
}

