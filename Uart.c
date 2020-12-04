/* 
 * File:   Uart.c
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:17
 */

#define UART_C
#include "../Sources/Main.h"

//------------------------------------------------------------------------------
// Interruption U1RX - Reception UART 1
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void)
{
    printf("%c\n\r", U1RXREG);
    if(U1RXREG == '1'){Mesure();}
    IFS0bits.U1RXIF                 = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Interruption U1TX - Emission UART 1
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _U1TXInterrupt(void)
{
    IFS0bits.U1TXIF             = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------

void UART_Init(void){
    Lib_Temp_REMAP_SIGNAL_IN_SUR_RPx(REMAP_SIGNAL_IN_U1RX, RP7_RB7_BORNE_16); // Remap RX signal on RB7
    Lib_Temp_REMAP_SIGNAL_OUT_SUR_RPx(REMAP_SIGNAL_OUT_U1TX, RP6_RB6_BORNE_15); // Remap TX signal on RB6
    Lib_Temp_UART_Config(1, 4000000, 115200); // config UART
    Lib_Temp_UART_Activation_Interruption_RX(ON, 7); // enable interrupt on RX
    Lib_Temp_UART_Activation_Interruption_TX(ON, 7); // enable interrupt on TX
}

int Mesure(void){
    unsigned long sec;
    char date_string[50];
    RTCC_DATE Date;

    /*------------------------------------
    *   Printing temp and date
    * -----------------------------------*/
    if(U1RXREG == '1'){
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
        printf("%s | %.2f %cC \n\r", date_string, (double)Lib_Temp_ADC_Temperature_en_Centieme_de_degre(2500)/100, 0xF8);
        return 0;
    }
    //-------------------------------------
    return 1;
}

