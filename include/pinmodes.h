//
// Created by snaens on 20/10/2026.
//

#ifndef TESTING_PINMODES_H
#define TESTING_PINMODES_H


// GPIO port mode register values
#define PIN_MODE_INPUT  0b00
#define PIN_MODE_OUTPUT 0b01
#define PIN_MODE_ALT    0b10
#define PIN_MODE_ANALOG 0b11

// GPIO port output type register values
#define PIN_OTYPE_PUSHPULL  0b0
#define PIN_OTYPE_OPENDRAIN 0b1

// GPIO port output speed register values
#define PIN_OSPEED_LOW       0b00
#define PIN_OSPEED_MEDIUM    0b01
#define PIN_OSPEED_HIGH      0b10
#define PIN_OSPEED_VERY_HIGH 0b11

// GPIO port pull-up/pull-down register values
#define PIN_PUPDR_NONE     0b00
#define PIN_PUPDR_PULLUP   0b01
#define PIN_PUPDR_PULLDOWN 0b10
//#define PIN_PUPDR_RESERVED 11

// GPIO port bit set/reset register values
#define PIN_BSRR_NOP 0b0
#define PIN_BSRR_SET 0b1
#define PIN_BSRR_RST 0b1

// GPIO port configuration lock register values
#define PIN_LCKR_INACTIVE 0b0
#define PIN_LCKR_ACTIVE   0b1

// GPIO port bit reset register values
#define PIN_BRR_NOP 0b0
#define PIN_BRR_RST 0b1



#endif //TESTING_PINMODES_H