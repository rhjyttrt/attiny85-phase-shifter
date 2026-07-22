#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
    cli(); // Disable interrupts

    // Set PB0 (OC0A / Q) and PB1 (OC0B / E) as digital outputs
    DDRB |= (1 << PB0) | (1 << PB1);

    // Timer0 CTC Mode: Toggle OC0A (PB0) and OC0B (PB1) on hardware compare match
    TCCR0A = (1 << COM0A0) | (1 << COM0B0) | (1 << WGM01);

    // OCR0A = 3 (Resets timer every 4 ticks)
    // OCR0B = 1 (Toggles PB1 2 ticks apart from PB0 for 90-degree phase shift)
    OCR0A = 3;
    OCR0B = 1;

    // Start Timer0 with clk/1 (no prescaler) -> Zero-jitter Divide-by-8
    TCCR0B = (1 << CS00);

    while (1) {
        // Hardware toggles pins directly in silicon (Zero CPU overhead)
    }
}
