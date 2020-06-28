/* 
 * File:   SPI_Master.h
 * Author: Nabila
 *
 * Created on June 24, 2020, 12:36 AM
 */

#ifndef SPI_MASTER_H
#define	SPI_MASTER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

    void SPI_Master_init();
    void SPI_Slave_init();
    char SPI_Read();
    void SPI_Write(char data);
    void SPI_ReadString(char *buffer);
    void SPI_WriteString(char *buffer);
    unsigned char data;
    unsigned char counter;

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_MASTER_H */

