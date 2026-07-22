#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
    cli(); // Disable interrupts

    DDRB |= (1 << PB0) | (1 << PB1);

    TCCR0A = (1 << COM0A0) | (1 << COM0B0) | (1 << WGM01);

    OCR0A = 3;
    OCR0B = 1;


    TCCR0B = (1 << CS00);

    while (1) {
       
    }
}
