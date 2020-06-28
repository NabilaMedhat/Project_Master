/*
 * File:   main.c
 * Author: Nabila
 *
 * Created on May 22, 2020, 1:12 AM
 */

#include "USART.h"
#include "SPI_Master.h"

char O1[] = "O1 ";
char C1[] = "C1 ";
char O2[] = "O2 ";
char C2[] = "C2 ";


char str1[] = "LED 1 is ON\t\r";
char str2[] = "LED 1 is OFF\t\r";
char str3[] = "LED 2 is ON\t\r";
char str4[] = "LED 2 is OFF\t\r";

char Welcome[] = "Please type 'O1 #' or 'O2 #' or 'C1 #' or 'C2 #' to choose\t\r";
char Buffer[20];

int main(void) {
    DDRA |= (1 << LED);
    USART_init();
    SPI_Master_init();
    USART_TransmitString(Welcome);
    while (1) {
        USART_ReceiveString(Buffer);
        if (checkData(Buffer, O1)) {
            PORTA |= (1 << LED);
            USART_NewLine();
            USART_TransmitString(str1);
            SPI_WriteString(O1);
        } else if (checkData(Buffer, C1)) {
            PORTA &= ~(1 << LED);
            USART_NewLine();
            USART_TransmitString(str2);
            SPI_WriteString(C1);
        } else if (checkData(Buffer, O2)) {
            PORTA |= (1 << LED);
            USART_NewLine();
            USART_TransmitString(str3);
            SPI_WriteString(O2);
        } else if (checkData(Buffer, C2)) {
            PORTA &= (1 << LED);
            USART_NewLine();
            USART_TransmitString(str4);
            SPI_WriteString(C2);
        }

    }
}


