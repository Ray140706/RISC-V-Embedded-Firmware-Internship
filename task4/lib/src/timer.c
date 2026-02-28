#include "timer.h"

volatile uint32_t tick = 0;

void SysTick_Handler(void)
{
    tick++;
}

void timer_init(void)
{
    // Enable SysTick at 1ms interval
    SysTick->SR = 0;
    SysTick->CMP = SystemCoreClock / 1000 - 1;
    SysTick->CNT = 0;
    SysTick->CTLR = 0xF;   // Enable SysTick with interrupt
}

void delay_ms(uint32_t ms)
{
    uint32_t start = tick;
    while ((tick - start) < ms);
}

uint32_t timer_get_ticks(void)
{
    return tick;
}