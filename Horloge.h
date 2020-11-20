/* 
 * File:   Horloge.h
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:17
 */

#ifndef HORLOGE_H
    #define HORLOGE_H

    #ifndef HORLOGE_C // Pour les variables globales
        #define HORLOGE_EXT extern
    #else
        #define HORLOGE_EXT
    #endif

    void HORLOGE_Init(void);

#endif

