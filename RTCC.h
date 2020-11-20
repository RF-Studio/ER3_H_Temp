/* 
 * File:   RTCC.h
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:21
 */

#ifndef RTCC_H
    #define RTCC_H

    #ifndef RTCC_C // Pour les variables globales
        #define RTCC_EXT extern
    #else
        #define RTCC_EXT
    #endif

    void RTCC_Init(void);

#endif