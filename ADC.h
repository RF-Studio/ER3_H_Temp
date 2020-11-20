/* 
 * File:   ADC.h
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:21
 */

#ifndef ADC_H
    #define ADC_H

    #ifndef ADC_C // Pour les variables globales
        #define ADC_EXT extern
    #else
        #define ADC_EXT
    #endif

    void ADC_Init(void);

#endif

