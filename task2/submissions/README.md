## Brief explanation: 

The program validates real hardware operation on the VSDSquadron Mini board by 
initializing a GPIO pin as an output and continuously toggling it to blink an LED, while 
simultaneously sending a startup message and an incrementing counter over UART. The 
firmware follows a layered design where “main.c” handles application logic and all GPIO 
register access is abstracted through dedicated API functions, ensuring clean hardware–
software separation and proper embedded system architecture. 

## GPIO pin chosen and why: 
• PD6 - To control the onboard LED for GPIO validation 

• PD5 - To transmit UART messages for firmware execution verification. 

## UART message description: 
The UART was used to transmit status messages such as “LED_ON” or “LED_OFF” to 
indicate the state of the onboard LED and “Hello from VSDSquadron!” to indicate reset, 
which allows the real time verification of the firmware execution through a serial terminal. 

## How to build and flash (short steps): 
• Build the firmware 

• Navigate the project directory in the terminal 

• Run “pio run” to generate the firmware binary 

• Run “pio run -t upload” to flash the firmware onto the board 

• Open “PlatformIO Serial monitor” to verify the output


