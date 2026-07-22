#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
    cli();

    DDRB |= (1 << PB0) | (1 << PB1);

    // Configure Timer0 CTC Mode (Toggle PB0 and PB1 on compare match)
    TCCR0A = (1 << COM0A0) | (1 << COM0B0) | (1 << WGM01);
    OCR0A = 3;
    OCR0B = 1;
    TCCR0B = (1 << CS00);
}

void loop() {
    // Empty - Hardware handles output timing
}
