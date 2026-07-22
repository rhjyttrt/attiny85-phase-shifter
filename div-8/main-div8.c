#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
    cli(); // Disable interrupts for exact cycle timing

    // Disconnect Timer0 hardware PWM overrides from PB0 and PB1
    TCCR0A = 0;
    TCCR0B = 0;

    // Set PB0 (Q) and PB1 (E) as digital outputs
    DDRB |= (1 << PB0) | (1 << PB1);

    // 4x Unrolled Divide-by-8 Loop
    // States 1-15: 2 cycles each (1 cyc out + 1 cyc nop)
    // State 16: 3 cycles (1 cyc out + 2 cyc rjmp)
    asm volatile (
        "1:\n\t"
        // --- Period 1 ---
        "out %[port], %[s1]\n\t" "nop\n\t"
        "out %[port], %[s2]\n\t" "nop\n\t"
        "out %[port], %[s3]\n\t" "nop\n\t"
        "out %[port], %[s0]\n\t" "nop\n\t"

        // --- Period 2 ---
        "out %[port], %[s1]\n\t" "nop\n\t"
        "out %[port], %[s2]\n\t" "nop\n\t"
        "out %[port], %[s3]\n\t" "nop\n\t"
        "out %[port], %[s0]\n\t" "nop\n\t"

        // --- Period 3 ---
        "out %[port], %[s1]\n\t" "nop\n\t"
        "out %[port], %[s2]\n\t" "nop\n\t"
        "out %[port], %[s3]\n\t" "nop\n\t"
        "out %[port], %[s0]\n\t" "nop\n\t"

        // --- Period 4 ---
        "out %[port], %[s1]\n\t" "nop\n\t"
        "out %[port], %[s2]\n\t" "nop\n\t"
        "out %[port], %[s3]\n\t" "nop\n\t"
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