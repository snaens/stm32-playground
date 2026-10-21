/* Snaens' STefi-Light LED pattern demo
 *
 * Author: Sam 'snaens' Pelz
 */

#include "stm32g431xx.h"
#include "STefi-Light.h"
#include "pinmodes.h"

#define LOOPS_PER_MS    1244             // NOP-loops for delay()
#define WAITTIME        500


static void delay(uint16_t ms);

static void GPIO_init();


int main() {
    /* --- initialization --- */
    __disable_irq(); // disable interrupts globally

    GPIO_init();

    __enable_irq(); // enable interrupts globally


    /* --- infinite processing loop --- */
    while (true) {
        auto digitalWriteInv = [](int pin, bool state) {
            if (!state)
                GPIOA->BSRR = (1 << pin); /* LED ON  */
            else
                GPIOA->BSRR = (1 << pin) << 16U; /* LED OFF */
        };

        // implement a 2px wide "sliding bar" effect with 4 LEDs
        int delaytime = 300;
        digitalWriteInv(0, true);
        delay(delaytime);
        digitalWriteInv(1, true);
        delay(delaytime);
        digitalWriteInv(0, false);
        digitalWriteInv(2, true);
        delay(delaytime);
        digitalWriteInv(1, false);
        digitalWriteInv(3, true);
        delay(delaytime);
        digitalWriteInv(2, false);
        delay(delaytime);
        digitalWriteInv(3, false);
        delay(delaytime);
    }
}

// Initialize GPIOs on STefi Light for pins with peripherals attached.
static void GPIO_init() {
    // enable GPIO peripheral clock
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    /* Read-back ensures the clock domain is active */
    (void) RCC->AHB2ENR;

    auto setpin = [](int pin) {
        // GPIO A0 Reset value is 0b11
        // set values we want to change to 0b00
        GPIOA->MODER &= ~(0b11 << (pin * 2U));
        // enable GPIO A0
        GPIOA->MODER |= 0b1 << (pin * 2U);

        /* Push-pull output */
        // pushpull is already the default so technically this is unneeded
        GPIOA->OTYPER |= PIN_OTYPE_PUSHPULL << pin;

        // default 0b00
        // set to medium speed
        GPIOA->OSPEEDR |= PIN_OSPEED_MEDIUM << (pin * 2U);

        // default is 0b00
        GPIOA->PUPDR |= PIN_PUPDR_NONE << (pin * 2U);

        // We wanna start with 1 - low active LEDs
        GPIOA->ODR |= (1 << pin);
    };
    setpin(0);
    setpin(1);
    setpin(2);
    setpin(3);
}

// Implements a millisecond delay via very bad busy-wait.
static void delay(const uint16_t ms) {
    for (uint16_t i = 0; i < ms; ++i) {
        for (uint16_t j = 0; j < LOOPS_PER_MS; ++j) {
            __asm("NOP");
        }
    }
}
