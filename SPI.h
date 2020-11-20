/* 
 * File:   SPI.h
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:21
 */

#ifndef SPI_H
    #define SPI_H

    #ifndef SPI_C // Pour les variables globales
        #define SPI_EXT extern
    #else
        #define SPI_EXT
    #endif

    void SPI_Init(void);

#endif
