#include "uart.h"

void uart_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio;

    // TX -> PD5
    gpio.GPIO_Pin = GPIO_Pin_5;
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpio);

    // RX -> PD6
    gpio.GPIO_Pin = GPIO_Pin_6;
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &gpio);

    USART_InitTypeDef uart;
    uart.USART_BaudRate = 115200;   
    uart.USART_WordLength = USART_WordLength_8b;
    uart.USART_StopBits = USART_StopBits_1;
    uart.USART_Parity = USART_Parity_No;
    uart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    uart.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &uart);
    USART_Cmd(USART1, ENABLE);
}

void uart_print(char *str)
{
    while (*str)
    {
        while (!USART_GetFlagStatus(USART1, USART_FLAG_TXE));
        USART_SendData(USART1, *str++);
    }
}

void uart_println(char *str)
{
    uart_print(str);
    uart_print("\r\n");
}