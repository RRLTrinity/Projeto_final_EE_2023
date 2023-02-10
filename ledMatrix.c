
#include "mcc_generated_files/mcc.h"
#include "ledMatrixV.h"
//#include <string.h>


void txMAX7219(uint8_t addr, uint8_t dat){
    CS_SetLow();
    SPI1_WriteByte(addr);
    while(!PIR1bits.SSP1IF);
    PIR1bits.SSP1IF = 0;
    SPI1_WriteByte(dat);
    while(!PIR1bits.SSP1IF);
    PIR1bits.SSP1IF = 0;
    CS_SetHigh();
}

void initMAX7219(){
    // Decode mode = 0
    txMAX7219(0x09,0x00);
    // Intensity 17/32
    txMAX7219(0x0A,0x00);
    // Shutdown mode = 0
    txMAX7219(0x0C,0x00);
    // Scan Limit
    txMAX7219(0x0B,0x07);
    // Shutdown mode = 1
    txMAX7219(0x0C,0x01);
    // Display-Test = 1
    txMAX7219(0x0F,0x01);
    __delay_ms(1000);
    // Display-Test = 0
    txMAX7219(0x0F,0x00);
    // Shutdown mode = 1
    txMAX7219(0x0C,0x01);
}

void updateMatrix(uint8_t pos, uint8_t val){
	// Leitura do valor (a eeprom guarda 8 bits por localização)
	// e se precisam 4 localizações para um valor na matriz de LEDs.
	// Se multiplica o valor (val) por 4 (deslocar para a direita 2 vezes) e com isso temos a localização na EEPROM 	
	uint8_t eeAdd = val<<2;
	for(uint8_t i=0;i<4;i++){
		matrix[pos++]=DATAEE_ReadByte(eeAdd++);   
    }
}

void sendMatrix(){
    for(uint8_t i=0;i<8;i++){
#if CAMERA_FLIP==1
        txMAX7219(i+1,matrix[7-i]);
#else
        txMAX7219(i+1,matrix[i]);
#endif
    }
}

