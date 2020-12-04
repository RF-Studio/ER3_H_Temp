/* 
 * File:   Main.h
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:15
 */

#ifndef MAIN_H
    #define	MAIN_H
    
    #ifdef MAIN_C // Pour les variables globales
        #define MAIN_EXT extern
    #else
        #define MAIN_EXT
    #endif
        
    #include <xc.h>
    #include "../Sources/ADC.h"
    #include "../Sources/GPIO.h"
    #include "../Sources/Horloge.h"
    #include "../Sources/MRF89.h"
    #include "../Sources/RTCC.h"
    #include "../Sources/SPI.h"
    #include "../Sources/Uart.h"
    #include "../Sources/Lib_Temp_PIC24FJ256GA702_V2-0.h"

    void Main_Init(void);
    int Mesure(void);

#endif	/* MAIN_H */

