/* 
 * File:   GPIO.h
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:20
 */

#ifndef GPIO_H
    #define GPIO_H

    #ifndef GPIO_C // Pour les variables globales
        #define GPIO_EXT extern
    #else
        #define GPIO_EXT
    #endif

    void GPIO_Init(void);

#endif

