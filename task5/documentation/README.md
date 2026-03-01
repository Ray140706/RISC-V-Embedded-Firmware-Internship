# Power-On Self Test (POST) Firmware

## Overview
This project implements a structured Power-On Self Test (POST) firmware for the VSDSquadron Mini development board based on the CH32V003 RISC-V microcontroller.
On every reset, the firmware automatically validates core peripherals (GPIO, UART, and Timer) and generates a formatted PASS/FAIL diagnostic report over UART. 
The goal is to verify system integrity at boot time and demonstrate clean multi-driver integration.


## Target Hardware

Board: VSDSquadron Mini  
MCU: CH32V003F4U6 (RISC-V, 24 MHz)  


## Drivers Used

- GPIO Driver
- UART Driver
- Timer Driver
- POST Application Module


## Folder Structure

task4/

|___app/

    |___main.c
    
|___evidence/

    |___Task4(1).mp4
    |___Task4(2).mp4
    |___evidence.md
    
|___lib/

    |___include
        |___gpio.h
        |___post.h
        |___timer.h
        |___uart.h
    |___src
        |___gpio.c
        |___post.c
        |___timer.c
        |___uart.c
        
|___README.md


## Quick Start (Build & Flash)

1. Build the application on PlatformIO using the GPIO, UART and Timer drivers
2. Run 'pio run' on the terminal to get the firmware binary of the source code
3. Run 'pio run -t upload' to flash the firmware binary onto the board
4. Open Serial Monitor (115200 baud)
5. Press RESET 
    
