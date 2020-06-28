/* 
 * File:   USART.h
 * Author: Nabila
 *
 * Created on June 20, 2020, 11:31 PM
 */

#ifndef USART_H
#define	USART_H

#ifdef	__cplusplus
extern "C" {
#endif

#define F_CPU 8000000UL

#include <xc.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>

#define Button 0
#define LED    0


    void USART_init();
    void USART_TransmitChar(char data);
    void USART_TransmitString(char *data);
    void USART_TransmitValue(int val);
    void USART_NewLine();
    char USART_ReceiveByte();
    void USART_ReceiveString(char *str);
    int checkData(char *buffer, char *cmpStr);


#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */

