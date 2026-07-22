#include <avr/io.h>

.global start_clock

start_clock:
    cli

    clr  r16
    out  _SFR_IO_ADDR(TIMSK), r16
    out  _SFR_IO_ADDR(TCCR1), r16
    out  _SFR_IO_ADDR(GTCCR), r16

    ldi  r16, (1 << PB0) | (1 << PB1)
    out  _SFR_IO_ADDR(DDRB), r16

    ldi  r16, (1 << COM0A0) | (1 << COM0B0) | (1 << WGM01)
    out  _SFR_IO_ADDR(TCCR0A), r16

    ldi  r16, 5
    out  _SFR_IO_ADDR(OCR0A), r16

    ldi  r16, 2
    out  _SFR_IO_ADDR(OCR0B), r16

    clr  r16
    out  _SFR_IO_ADDR(TCNT0), r16

    ldi  r16, (1 << CS00)
    out  _SFR_IO_ADDR(TCCR0B), r16

loop:
    rjmp loop