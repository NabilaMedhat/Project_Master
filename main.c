/*
 * File:   main.c
 * Author: Nabila
 *
 * Created on May 22, 2020, 1:12 AM
 */


#define F_CPU 8000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>

#include "USART.h"
#include "SPI_Master.h"

/*ISR(USART_RXC_vect) {

    char Rec = UDR;
    if (Rec == 'O') {
        PORTA |= (1 << LED);
        USART_TransmitString(str1);
        SPI_write('O');

    } else if (Rec == 'C') {
        PORTA &= ~(1 << LED);
        USART_TransmitString(str2);
        SPI_write('C');
    }
    //USART_TransmitChar(Rec);

}*/
char *Buffer;
char O1[] = "O1 ";
char C1[] = "C1 ";
char O2[] = "O2 ";
char C2[] = "C2 ";

//char msg[] = "Temp = ";

char str1[] = "LED 1 is ON\t\r";
char str2[] = "LED 1 is OFF\t\r";
char str3[] = "LED 2 is ON\t\r";
char str4[] = "LED 2 is OFF\t\r";

char Rec[1000];

int main(void) {
    DDRA |= (1 << LED);
    USART_init(); // Enable Transmitter ONLY
    SPI_Master_init();
    /* Replace with your application code */
    //sei();
    while (1) {
        /* if (PINC & (1 << 0)) {
             USART_TransmitChar('A');
             USART_TransmitString(msg);
             USART_TransmitValue(20);
             USART_NewLine();
             _delay_ms(500);
             //SPI_write('A');
             //SPI_write(counter++);
             //_delay_ms(1000);*/

        USART_ReceiveString(Rec);
        if (checkData(Rec, O1)) {
            PORTA |= (1 << LED);
            USART_NewLine();
            USART_TransmitString(str1);
            SPI_WriteString(O1);
        } else if (checkData(Rec, C1)) {
            PORTA &= ~(1 << LED);
            USART_NewLine();
            USART_TransmitString(str2);
            SPI_WriteString(C1);
        } else if (checkData(Rec, O2)) {
            PORTA |= (1 << LED);
            USART_NewLine();
            USART_TransmitString(str3);
            SPI_WriteString(O2);
        } else if (checkData(Rec, C2)) {
            PORTA &= (1 << LED);
            USART_NewLine();
            USART_TransmitString(str4);
            SPI_WriteString(C2);
        }
        /*
        char Rec = UDR;
                if (Rec == 'O') {
                    PORTA |= (1 << LED);
                    USART_TransmitString(str1);
                    //SPI_Write('O');
                    SPI_WriteString(O1);

                } else if (Rec == 'C') {
                    PORTA &= ~(1 << LED);
                    USART_TransmitString(str2);
                    //SPI_Write('C');
                    SPI_WriteString(C1);
                }
         */
    }
}


