/*
 * File:   USART.c
 * Author: Nabila
 *
 * Created on June 20, 2020, 11:29 PM
 */

#include "USART.h"

char NewLine[] = "\t\r";

void USART_init() {
    UCSRB |= (1 << TXEN) | (1 << RXEN);
    // UCSRB |= (1 << UDRIE); // Enable UDRE Interrupt
    // UCSRB |= (1 << RXCIE); //Enable RX Interrupt
    UBRRL = 51; //BaudRate
}

void USART_TransmitChar(char data) {
    //Pooling //Wait until UDR is Empty
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void USART_TransmitString(char *data) {
    for (int i = 0; data[i] != '\0'; i++) {
        USART_TransmitChar(data[i]);
    }
}

void USART_TransmitValue(int val) {
    char buff[20];
    itoa(val, buff, 10);
    USART_TransmitString(buff);
}

void USART_NewLine() {
    USART_TransmitString(NewLine);
}

char USART_ReceiveByte() {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}

void USART_ReceiveString(char *str) {
    unsigned int i = 0;
    str[i] = USART_ReceiveByte();
    while (str[i] != '#') {
        i++;
        str[i] = USART_ReceiveByte();
    }
    str[i] = '\0';
}

int checkData(char *buffer, char *cmpStr) {
    int flag = strcmp(buffer, cmpStr);
    return flag == 0 ? 1 : 0;
}
