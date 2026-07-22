# ATtiny85 Phase Clock Generator

Hardware quadrature clock generator built on the ATtiny85. 

It accepts a 2-pin external crystal input, divides the frequency by 12, and outputs two 50% duty cycle clock signals (E and Q) shifted by 90 degrees. This output can be used for Motorola 6800 series MPUs and other processors requiring two-phase quadrature clocks.

## Pinout

| ATtiny85 Pin | Port Pin | Function |
| :--- | :--- | :--- |
| Pin 2 | `PB3` | Crystal Input 1 |
| Pin 3 | `PB4` | Crystal Input 2 |
| Pin 5 | `PB0` | **Q** Clock Output |
| Pin 6 | `PB1` | **E** Clock Output |

## Timing Output
![Logic Analyzer Output](assets/salae-tiny-16mhz-6809.png)

## Repository Structure

    attiny85-phase-shifter/
    ├── assets/                            # Documentation images and timing captures
    │   ├── ide-options.png
    │   └── salae-tiny-16mhz-6809.png
    ├── firmware/                          # Pre-compiled hex files ready to burn
    │   └── attiny85-QE-MPU.hex
    ├── src/                               # Source code
    │   ├── main.c                         # Standalone AVR-C source
    │   └── attiny85-QE-MPU.ino            # Arduino sketch
    ├── .gitignore
    ├── LICENSE
    └── README.md
