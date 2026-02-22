# Advanced GPIO Library + Application
## API list
-> gpio_init: To initialize a pin as input or output

-> gpio_set: To set an output pin

-> gpio_clear: To clear an output pin

-> gpio_toggle: To toggle the state of a pin

-> gpio_read: To read an input pin

## Demo application
The demo application reads input from a push button and toggles an LED. UART messages are displayed
in a serial monitor to observe the state changes of the LED.

## How to build and flash the firmware
-> Build the firmware on PlatformIO

-> Convert the source code into a firmware binary by running "pio run" in the VS code terminal

-> Run "pio run -t upload" to flash the firmware binary onto the board

## UART configuration
UART communication was configured using USART1 with a baud rate of 9600
