/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1827
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_ANS                  ANSELAbits.ANSA0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_ANS                  ANSELBbits.ANSB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF6 pin functionality
 * @Example
    IOCBF6_ISR();
 */
void IOCBF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_InterruptHandler);

*/
extern void (*IOCBF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_DefaultInterruptHandler);

*/
void IOCBF6_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF7 pin functionality
 * @Example
    IOCBF7_ISR();
 */
void IOCBF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_InterruptHandler);

*/
extern void (*IOCBF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_DefaultInterruptHandler);

*/
void IOCBF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/