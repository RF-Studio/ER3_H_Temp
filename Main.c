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
    SPI_Init();
    printf("SPI up \n\r");
    MRF89_Init();
    printf("MRF89 up\n\r");
    /*
     * CPU Init
     */
    Lib_Temp_CPU_Activation_Horloge_Tous_Les_Modules(ON);
    Lib_Temp_CPU_Gestion_Low_Power_Sleep_Mode(CPU_LOW_POWER_MODE_RETENTION_SLEEP);
    Lib_Temp_CPU_Activation_Interruption(ON, 2);
    printf("CPU up\n\r");
}

int Mesure(void){
    unsigned long sec;
    char date_string[50], r, str[100];
    RTCC_DATE Date;
    /*------------------------------------
    *   Printing temp and date
    * -----------------------------------*/
    if(U1RXREG == '1'){
        /*Start emitter*/
        Lib_Temp_MRF89_Change_Mode(MRF89_MODE_TRANSMIT);
        /*Start ADC*/
        Lib_Temp_ADC_Alimente_Capteur_Temperature(ON); // power ON Temp cpt
        Lib_Temp_ADC_Start_Conversion_Automatique();
        /*---------------
        *   Get date
        * -------------*/
        Lib_Temp_RTCC_Lecture_Date(&Date); // read date
        Lib_Temp_RTCC_Conversion_Date_En_Seconde(Date, &sec); // convert date to sec
        Lib_Temp_RTCC_Conversion_Seconde_en_Date_String(sec, date_string); // convert date_sec to str

        /*---------------
        *   Get temp
        * -------------*/
        if(Lib_Temp_ADC_Attend_Fin_Conversion() == -1)
            {
                printf("ADC error\n\r");
                return -1;
            }
        Lib_Temp_ADC_Alimente_Capteur_Temperature(OFF); // power OFF temp cpt
        sprintf(str,"%s | %.2f %cC \n\r", date_string, (double)Lib_Temp_ADC_Temperature_en_Centieme_de_degre(2500)/100, 0xF8);
        printf(str);
        /*------------------
        *   Transmition
        * ----------------*/
        Lib_Temp_MRF89_Ecriture_SPI_FIFO(10,(unsigned char *)str);
        r = Lib_Temp_MRF89_Attend_Fin_Transmission_Hertzienne();
        if(r == -1){
            printf("Erreur de transmition");
        }
        Lib_Temp_MRF89_Change_Mode(MRF89_MODE_SLEEP);
        
        return 0;
    }
    //-------------------------------------

    return 1;
}

