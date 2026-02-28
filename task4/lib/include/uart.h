#ifndef UART_H
#define UART_H

#include "ch32v00x.h"

void uart_init(void);
void uart_print(char *str);
void uart_println(char *str);

#endif