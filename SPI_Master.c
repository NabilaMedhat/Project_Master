/*
 * File:   SPI_Master.c
 * Author: Nabila
 *
 * Created on June 24, 2020, 12:35 AM
 */

#include "SPI_Master.h"

void SPI_Master_init() {
    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);
}

char SPI_Read() /* SPI read data function */ {
    SPDR = 0xFF;
    while (!(SPSR & (1 << SPIF))); /* Wait till reception complete */
    return (SPDR); /* Return received data */
}

void SPI_Write(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}

void SPI_WriteString(char *buffer) {
    while (*buffer) {
        SPI_Write(*buffer);
        buffer++;
    }
}

void SPI_ReadString(char *buffer) {
    for (int i = 0; SPI_Read() != 10; i++) {
        buffer[i] = SPI_Read();
    }
}

unsigned char data;
unsigned char counter;

