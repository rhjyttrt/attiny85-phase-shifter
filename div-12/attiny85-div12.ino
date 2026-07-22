#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
    cli();
    TCCR0A = 0;
    TCCR0B = 0;
    DDRB |= (1 << PB0) | (1 << PB1);

    asm volatile (
        "1:\n\t"
        "out %[port], %[s1]\n\t" "nop\n\t" "nop\n\t"
        "out %[port], %[s2]\n\t" "nop\n\t" "nop\n\t"
        "out %[port], %[s3]\n\t" "nop\n\t" "nop\n\t"
        "out %[port], %[s0]\n\t"
        "rjmp 1b\n\t"
        :
        : [port] "I" (_SFR_IO_ADDR(PORTB)),
          [s0]   "r" ((uint8_t)0x00),
          [s1]   "r" ((uint8_t)0x01),
          [s2]   "r" ((uint8_t)0x03),
          [s3]   "r" ((uint8_t)0x02)
    );

    __builtin_unreachable();
}

void loop() {}
