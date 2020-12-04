/* 
 * File:   SPI.c
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:21
 */

#define SPI_C
#include "../Sources/Main.h"

//------------------------------------------------------------------------------
// Interruption SPI TX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI1TXInterrupt(void)
{
    
    IFS0bits.SPI1TXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Interruption SPI RX
//------------------------------------------------------------------------------
void __attribute__((interrupt, auto_psv)) _SPI1RXInterrupt(void)
{
    
    IFS3bits.SPI1RXIF       = 0;            // Init du bit de reception
}
//------------------------------------------------------------------------------



void SPI_Init(void){ 
    
    Lib_Temp_SPI_Config(1); // on choisis le SPI num 1
    
    Lib_Temp_REMAP_SIGNAL_OUT_SUR_RPx(REMAP_SIGNAL_OUT_SCK1OUT, RP14_RB14_BORNE_25); // Remappage du signal sur SCK1 sur la borne 25
    Lib_Temp_REMAP_SIGNAL_OUT_SUR_RPx(REMAP_SIGNAL_OUT_SDO1, RP15_RB15_BORNE_26); // Remappage du signal sur SD01 sur la borne 26
    Lib_Temp_REMAP_SIGNAL_IN_SUR_RPx(REMAP_SIGNAL_IN_SDI1, RP9_RB9_BORNE_18); // Remappage du signal sur SDI1 sur la borne 18
    
    
    
}

