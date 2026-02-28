#ifndef TIMER_H
#define TIMER_H

#include "ch32v00x.h"

void timer_init(void);
void delay_ms(uint32_t ms);
uint32_t timer_get_ticks(void);

#endif