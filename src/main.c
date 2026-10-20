/* Snaens' STefi-Light blink demo
 *
 * Author: Sam 'snaens' Pelz
 */

#include "stm32g431xx.h"
#include "STefi-Light.h"
#include "pinmodes.h"

#define LOOPS_PER_MS    1244             // NOP-loops for delay()
#define WAITTIME        500


static void delay(const uint16_t ms);

static void GPIO_init(void);


int main(void) {
    /* --- initialization --- */
    __disable_irq(); // disable interrupts globally

    GPIO_init();

    __enable_irq(); // enable interrupts globally


    /* --- infinite processing loop --- */
    while (1) {
        // LEDs low-active!
        // Both methods described here work
        GPIOA->BSRR = 1 << PIN_LED0; /* Bit set -> LED OFF  */
        // GPIOA->ODR = 1 << PIN_LED0; /* LED OFF  */
        delay(1000);
        GPIOA->BSRR = (1 << PIN_LED0) << 16U; /* Bit reset -> LED ON */
        // GPIOA->ODR = 0 << PIN_LED0; /* LED ON  */
        delay(1000);
    }
}


// Initialize GPIOs on STefi Light
static void GPIO_init(void) {
    // enable GPIO peripheral clock
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    /* Read-back ensures the clock domain is active */
    (void) RCC->AHB2ENR;

    // GPIO A0 Reset value is 0b11
    // set values we want to change to 0b00
    GPIOA->MODER &= ~(0b11 << (PIN_LED0 * 2U));
    // enable GPIO A0
    GPIOA->MODER |= 0b1 << (PIN_LED0 * 2U);

    /* Push-pull output */
    // pushpull is already the default so technically this is unneeded
    GPIOA->OTYPER |= PIN_OTYPE_PUSHPULL << PIN_LED0;

    // default 0b00
    // set to medium speed
    GPIOA->OSPEEDR |= PIN_OSPEED_MEDIUM << (PIN_LED0 * 2U);

    // default is 0b00
    GPIOA->PUPDR |= PIN_PUPDR_NONE << (PIN_LED0 * 2U);

    // start from a known state
    GPIOA->ODR |= 1 << PIN_LED0;
}

// Implement a millisecond delay via very bad busy-wait.
static void delay(const uint16_t ms) {
    for (uint16_t i = 0; i < ms; ++i) {
        for (uint16_t j = 0; j < LOOPS_PER_MS; ++j) {
            __asm("NOP");
        }
    }
}
