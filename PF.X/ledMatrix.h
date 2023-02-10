/* 
 * File:   ledMatrix.h
 * Author: Guillermo
 *
 * Created on 10/09/2022
 */

#ifndef LEDMATRIX_H
#define	LEDMATRIX_H

#define CAMERA_FLIP 0

uint8_t matrix[8];  ///< Array que vai armazenar o que será enviado para a matriz de LEDs (MAX7219). São 8 columnas ou registradores x 8 filas de LEDs cada.

/**
 * Envia dados para os MAX7219
 * @param addr0 Enedereço do registrador.
 * @param dat0  Valor a ser enviado.
 */
void txMAX7219(uint8_t addr, uint8_t dat);

/**
 * Inicializa os MAX7219
 */
void initMAX7219();

/**
 * Atualiza variável que contem os valores a serem enviados para o MAX7219.
 * @param pos Posição de inicio do caracter na matriz de LEDs (número do registrador)
 * @param val Valor a ser exibido
 */
void updateMatrix(uint8_t pos, uint8_t val);

/**
 * Envia matriz para o MAX7219
 */
void sendMatrix();


#endif	/* LEDMATRIX_H */

