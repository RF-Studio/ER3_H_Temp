/* 
 * File:   MRF89.c
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:22
 */

#define MRF89_C
#include "../Sources/Main.h"

void MRF89_Init(void){
    char r;
    MRF89_DEFINE_PORT Config_port;

    Config_port.BIT_CSCON = MRF89_BIT_RB12; // CSCON on RB12
    Config_port.BIT_CSDATA = MRF89_BIT_RB8; // CSDATA on RB8
    Config_port.BIT_IRQ0 = MRF89_BIT_RB13; // IRQ0 on RB13
    Config_port.BIT_IRQ1 = MRF89_BIT_RB10; // IRQ1 on RB10
    Config_port.BIT_RESET = MRF89_BIT_RB11; // RESET on RB11
    

    Lib_Temp_SPI_Config(1);
    r = Lib_Temp_MRF89_Config(Config_port);    // config defaut : 93.75 kbits par seconde - P_out = 13 dBm
    if (r == -1) 
    {
        printf("Error config MRF89");
    }
    
    Lib_Temp_MRF89_Ecriture_SPI_FIFO(10,(unsigned char *)"Hello World !");
    r = Lib_Temp_MRF89_Attend_Fin_Transmission_Hertzienne();
    if(r == -1){
        printf("Erreur de transmition");
    }
    Lib_Temp_MRF89_Change_Mode(MRF89_MODE_SLEEP);
}

