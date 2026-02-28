#include "gpio.h"

#define LED_PIN GPIO_Pin_6   // PC6

void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = LED_PIN;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOC, &gpio);
}

void gpio_led_on(void)
{
    GPIO_SetBits(GPIOC, LED_PIN);
}

void gpio_led_off(void)
{
    GPIO_ResetBits(GPIOC, LED_PIN);
}

void gpio_led_toggle(void)
{
    GPIOC->OUTDR ^= LED_PIN;
}