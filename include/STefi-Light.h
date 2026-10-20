/* ***************************************************************************************
 *  Project:    task1
 *  File:       STefi-Light.h
 *
 *  Language:   C
 *
 *  Hardware:   STefi Light v1.1
 *  Processor:  STM32F042K6 / STM32G431KBT6U
 *
 *  Author:     Manuel Lederhofer
 *  Datum:      30.07.2021
 *
 *  Version:    1.1
 *  History:
 *      30.07.2021  ML  create file
 *      09.03.2022  ML  check G431 compatibility
 *
 *  Status:     working
 *
 *  Description:
 *          Definitions and declarations related to STefi Light board hardware
 *          extended by application related elements.
 *
 *
 *  Notes:
 *          Default MCU speed at startup is:
 *          - F042 = 8 MHz
 *          - G431 = 16 MHz
 *
 *  ToDo:
 *      - none -
 ************************************************************************************** */
#ifndef STEFI_LIGHT_H_
#define STEFI_LIGHT_H_
/* ==================================================================================== */


/* ------------------------------------ DEFINES --------------------------------------- */

/* --- STefi peripherals related definitions --- */

// LEDs
#define PIN_LED0            0
#define PIN_LED1            1
#define PIN_LED2            2
#define PIN_LED3            3

#define MASK_LED0           (1 << PIN_LED0)
#define MASK_LED1           (1 << PIN_LED1)
#define MASK_LED2           (1 << PIN_LED2)
#define MASK_LED3           (1 << PIN_LED3)

#define MASK_LED_RED        (MASK_LED0)
#define MASK_LED_YELLOW     (MASK_LED1)
#define MASK_LED_GREEN      (MASK_LED2)
#define MASK_LED_BLUE       (MASK_LED3)
#define MASK_LED_ALL        (MASK_LED_RED | MASK_LED_YELLOW | MASK_LED_GREEN | MASK_LED_BLUE)


// buttons
#define PIN_S0          0
#define PIN_S1          4
#define PIN_S2          5
#define PIN_S3          7

#define MASK_S0         (1 << PIN_S0)
#define MASK_S1         (1 << PIN_S1)
#define MASK_S2         (1 << PIN_S2)
#define MASK_S3         (1 << PIN_S3)

#define MASK_KEY0       (MASK_S0)
#define MASK_KEY1       (MASK_S1)
#define MASK_KEY2       (MASK_S2)
#define MASK_KEY3       (MASK_S3)


/* ==================================================================================== */
#endif /* STEFI_LIGHT_H_ */
/* ************************************ E O F ***************************************** */
