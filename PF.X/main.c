/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1827
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "ledMatrix.h"


/*************************************************************************
**************************************************************************
**************************************************************************
****                 Universidade de Brasília FGA                     ****
**************************************************************************
************************************************************************** 
****                 Eletrônica Embarcada - FGA0096                   ****
**************************************************************************     
**************************************************************************
**** PROF.: GUILLERMO ALVAREZ BESTARD                                 ****
**** Alunos: JOÃO PAULO DIAS                  Matrícula: 170146324    ****
****         LEONI GABRIEL SILVESTRE          Matrícula: 170108112    ****
****         LUCAS PINHEIRO DE SOUZA          Matrícula: 160156866    ****
****         RODRIGO RIBEIRO LOPES TRINDADE   Matrícula: 170113922    **** 
**************************************************************************
************************************************************************** 
*************************************************************************/


/*

 ADC       -        Coleta informações sobre a temperatura
 CCP3(PWM) -        Define o ciclo útil da tensão de alimentação do motor
 CMP1      -        Utilizado para identificar a posição do elevador pelo sensor hall S3
 CMP2      -        Utilizado para identificar a posição do elevador pelo sensor hall S4
 EUSART    -        Comunicacação serial com PC
 FVR       -        
 DAC       -
 MEMORY    -        Armazena os valores para ser exibido no LED
 TIMER1    -        
 TIMER2    -        Usado para o PWM
 TIMER4    -
 * 
 */

#define pwm_dc     460
#define pulse      .837

float position;
int motor_state   = 0,
    floor_current = 0,
    pulses        = 0,
    speed         = 0,
    temperature   = 0,
    floor_req     = 3;

uint16_t colect_value =0;
uint8_t txBytes[4],
        LEDs[8],                 
        rxByte;                 
         
/*
 motor_state = 0 stop
             = 1 up
             = 2 down
 */
  
    /*Funções para os LEDs*/

void led(void){
    for(int i = 0;i<8;i++){
        txMAX7219(i+1,LEDs[i]);
    }
}

void show_led(){
    
    for(int i =0;i<4;i++){
        LEDs[i] = DATAEE_ReadByte(4*(floor_current+1)+i);
        LEDs[i+4] = DATAEE_ReadByte(4*(motor_state+6)+i);
    }
    led();
    
    
}


    /*função para o encoder*/



void Encoder(uint16_t encoder_value){
    
    colect_value = encoder_value;
    if(motor_state == 1 && pulses < 215 ){
        pulses ++;
    }
    else if(motor_state == 2 && pulses >0){
        pulses --;
    }
    else if(motor_state==0){
        speed = 0;
    }
    
    else {
        pulses = 0;
    }
    TMR1_WriteTimer(0);
}

void ser_com(){
    
    txBytes[0] = 0xB3 & ((uint8_t)motor_state<<4| (0b10000000)|((uint8_t)pulses));
    txBytes[1] = 0x7F & (uint8_t)(position/2);
    txBytes[2] = 0x7F & (uint8_t)(speed*4);
    txBytes[3] = 0x7F & (uint8_t)(temperature*2);
    
    for(int i=0; i<4;i++){
        EUSART_Write(txBytes[i]);
    }
    
}

/*Função que controla o elevador*/

void motion(void){
    
    // Controla o movimento do elevador
    if (floor_current != floor_req){
        PWM3_LoadDutyValue(pwm_dc);
        
    }
    else {
        PWM3_LoadDutyValue(0);
        motor_state = 0;
        __delay_ms(2000); // Espera de dois segundos pra pessoa poder sair.
        
    }
}

void ctrl(){
    // RA7 = DIR
    if (floor_current<floor_req){
        if (motor_state == 2){
            
            PWM3_LoadDutyValue(0);
            __delay_ms(500);
            
        }
        
        IO_RA7_SetHigh();
        motor_state = 1;
        
    }
    else if(floor_current>floor_req){
        if(motor_state == 1){
        
            PWM3_LoadDutyValue(0);
            __delay_ms(500);
            
        }
        
        IO_RA7_SetLow();
        motor_state = 2;
    }
    
    motion();    
    
    
}
/*
void sensor1_ISR(void) {

    // Add custom IOCBF6 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF6_InterruptHandler)
    {
        IOCBF6_InterruptHandler();
    }
    floor_current = 0;
    IOCBFbits.IOCBF6 = 0;
}

void sensor2_ISR(void) {

    // Add custom IOCBF7 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF7_InterruptHandler)
    {
        IOCBF7_InterruptHandler();
    }
    floor_current = 1;
    IOCBFbits.IOCBF7 = 0;
}


void CMP1_ISR(void)
{   
    floor_current = 2;
    // clear the CMP1 interrupt flag
    PIR2bits.C1IF = 0;
}

void CMP2_ISR(void)
{
    floor_current = 2;
    // clear the CMP2 interrupt flag
    PIR2bits.C2IF = 0;
}
*/

void current_floor(){
//Verificando sensor S1
    if(IO_RB6_GetValue()==1){
        floor_current = 0;                
    }
//Verificando sensor S2
    else if(IO_RB7_GetValue()==1){
        floor_current = 1;
    }
//Verificando sensor S3
    else if(RA2_GetValue()==1){
        floor_current = 2;
    }
//Verificando sensor S4
    else if(RA1_GetValue()==1){
        floor_current = 3;
    }    
}


void main(void)
{
    // initialize the devices
    SYSTEM_Initialize();
    SPI1_Open(SPI1_DEFAULT);
    initMAX7219();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    // Another iterruptions
    TMR4_SetInterruptHandler(ser_com);
    IOCBF6_SetInterruptHandler(IOCBF6_ISR);
    IOCBF7_SetInterruptHandler(IOCBF7_ISR);
    
    
            

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    CCP4_SetCallBack(Encoder);
    current_floor();

    
    while (1)
    {
        ctrl();
        show_led();
        temperature = (int)(ADC_GetConversion(channel_AN0)*2.0);
        speed = (int)(pulse/(((float)colect_value)*.000002))*4;
        position = (pulse*pulses);  
        
        if(EUSART_is_rx_ready()){
            rxByte = EUSART_Read();
            floor_req = (int)(rxByte & 0x03);
        }
        
        // Add your application code
    }
}
/**
 End of File
*/