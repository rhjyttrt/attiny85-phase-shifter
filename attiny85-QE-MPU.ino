#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
    // 1. Kill standard Arduino Timer0 interrupts (millis/micros) to ensure zero jitter
    cli();

    // 2. Set PB0 (Q) and PB1 (E) as digital outputs
    DDRB |= (1 << PB0) | (1 << PB1);

    // 3. Continuous assembly clock engine
    asm volatile (
        "1:\n\t"
        // --- State 1 (0°): Q=1, E=0 ---
        "out %[port], %[s1]\n\t"  // 1 cycle
        "nop\n\t"                 // 1 cycle
        "nop\n\t"                 // 1 cycle  (Total: 3 cycles)

        // --- State 2 (90°): Q=1, E=1 ---
        "out %[port], %[s2]\n\t"  // 1 cycle
        "nop\n\t"                 // 1 cycle
        "nop\n\t"                 // 1 cycle  (Total: 3 cycles)

        // --- State 3 (180°): Q=0, E=1 ---
        "out %[port], %[s3]\n\t"  // 1 cycle
        "nop\n\t"                 // 1 cycle
        "nop\n\t"                 // 1 cycle  (Total: 3 cycles)

        // --- State 0 (270°): Q=0, E=0 ---
        "out %[port], %[s0]\n\t"  // 1 cycle
        "rjmp 1b\n\t"             // 2 cycles (Total: 3 cycles)
        :
        : [port] "I" (_SFR_IO_ADDR(PORTB)),
          [s0]   "r" ((uint8_t)0x00),
          [s1]   "r" ((uint8_t)0x01),
          [s2]   "r" ((uint8_t)0x03),
          [s3]   "r" ((uint8_t)0x02)
    );

    __builtin_unreachable();
}

void loop() {
    // Unreachable: setup() never returns
}