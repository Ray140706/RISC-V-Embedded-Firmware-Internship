# Power-On Self Test (POST) Firmware

## Project Description

This project implements a Power-On Self Test (POST) firmware. On every reset, the firmware automatically runs a structured hardware self-test sequence and prints a detailed PASS/FAIL report over UART.
The objective is to validate core peripherals during boot and provide a clear diagnostic output.


## Drivers Used

- GPIO Driver
- UART Driver
- Timer Driver 


## API Summary

### GPIO
- `gpio_init()`
- `gpio_led_on()`
- `gpio_led_off()`
- `gpio_led_toggle()`

### UART
- `uart_init()`
- `uart_print(char *str)`
- `uart_println(char *str)`

### Timer
- `timer_init()`
- `delay_ms(uint32_t ms)`

### POST Module
- `post_run_all_tests()`


## Build and Flash Steps

1. Build the application on PlatformIO using the GPIO, UART and Timer drivers
2. Run 'pio run' on the terminal to get the firmware binary of the source code
3. Run 'pio run -t upload' to flash the firmware binary onto the board


## Demo Steps

1. Connect board via USB
2. Open Serial Monitor (115200 baud)
3. Press RESET
4. Observe:
   - LED blinking during GPIO test
   - Structured UART test messages
   - Timer delay confirmation
   - Final PASS report
  

## UART Configuration

- Baud Rate: 115200
- Data Bits: 8
- Stop Bits: 1
- Parity: None
- Flow Control: None
