#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

void gpio_init(void);
void gpio_led_on(void);
void gpio_led_off(void);
void gpio_led_toggle(void);

#endif