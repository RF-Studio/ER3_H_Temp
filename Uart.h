/* 
 * File:   Uart.h
 * Author: g2b7a2
 *
 * Created on 23 octobre 2020, 14:17
 */

#ifndef UART_H
    #define UART_H

    #ifndef UART_C // Pour les variables globales
        #define UART_EXT extern
    #else
        #define UART_EXT
    #endif

    void UART_Init(void);
    int Mesure(void);

#endif

