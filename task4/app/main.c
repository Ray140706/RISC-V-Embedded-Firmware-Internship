#include "gpio.h"
#include "uart.h"
#include "timer.h"
#include "post.h"

int main(void)
{
    gpio_init();
    uart_init();
    timer_init();

    post_run_all_tests();

    while(1)
    {
        gpio_led_toggle();
        delay_ms(1000);
    }
}

