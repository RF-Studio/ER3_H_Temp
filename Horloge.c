/* 
 * File:   Horloge.c
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:17
 */

#define HORLOGE_C
#include "../Sources/Main.h"

void HORLOGE_Init(){
    OSCCON = 0; // init OSSCON register to 0
    OSCCONbits.SOSCEN = 1; // secondary oscillator activation
    OSCCONbits.POSCEN = 1; // osc 1 contunue during sleep mode
    REFOCONL = 0; // init REFOCONL register to 0
    REFOCONLbits.ROEN = 1; // enable REFO
    REFOCONLbits.ROOUT = 1; // enable output
    REFOCONLbits.ROSEL = 5; // select FRC
    Lib_Temp_REMAP_SIGNAL_OUT_SUR_RPx(REMAP_SIGNAL_OUT_REFO, RP5_RB5_BORNE_14); // select the clock and point it on RB5
}

