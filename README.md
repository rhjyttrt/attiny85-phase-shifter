# ATtiny85 Phase Clock Generator

Hardware quadrature clock generator built on the ATtiny85. 

It accepts a 1 pin or 2 pin external clock/crystal input and outputs two 50% duty cycle clock signals (E and Q) shifted by 90 degrees. This output can be used for Motorola 6800 series MPUs and other processors requiring two phase quadrature clocks.

## Clock Ratios & Frequencies

| Mode | Division | 4 MHz Input | 8 MHz Input | 16 MHz Input | 20 MHz Input |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Divide by 8** | F_out = F_clk / 8 | 0.50 MHz | 1.00 MHz | 2.00 MHz | 2.50 MHz |
| **Divide by 12** | F_out = F_clk / 12 | 0.33 MHz | 0.67 MHz | 1.33 MHz | 1.67 MHz |

## Pinout

| ATtiny85 Pin | Port Pin | Function |
| :--- | :--- | :--- |
| Pin 2 | `PB3` | Crystal Input 1 / External Clock |
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
    ├── div-8/                             # Divide by 8 firmware & source
    │   ├── attiny85-div8.ino
    │   └── main-div8.c
    ├── div-12/                            # Divide by 12 firmware & source
    │   ├── attiny85-div12.ino
    │   └── main-div12.c
    ├── .gitignore
    ├── LICENSE
    └── README.md
