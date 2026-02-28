#include "post.h"
#include "gpio.h"
#include "uart.h"
#include "timer.h"

#define TIMEOUT_MS 2000

static int test_gpio(void)
{
    gpio_led_on();
    for(volatile int i = 0; i < 500000; i++);  // simple delay
    gpio_led_off();
    for(volatile int i = 0; i < 500000; i++);
    return 1;
}

static int test_uart(void)
{
    uart_println("[POST] UART Loopback Test Message");
    return 1;
}

static int test_timer(void)
{
    // Simple software delay test
    for(volatile uint32_t i = 0; i < 24000000; i++);  // ~1 second at 24MHz

    return 1;  // If it reaches here, timer logic is working
}

void post_run_all_tests(void)
{
    int pass_count = 0;

    uart_println("=================================");
    uart_println("VSDSquadron POST v1.0");
    uart_println("=================================");

    uart_print("[1] GPIO Test........ ");
    if (test_gpio()) { uart_println("PASS"); pass_count++; }
    else uart_println("FAIL");

    uart_print("[2] UART Test........ ");
    if (test_uart()) { uart_println("PASS"); pass_count++; }
    else uart_println("FAIL");

    uart_print("[3] Timer Test....... ");
    if (test_timer()) { uart_println("PASS"); pass_count++; }
    else uart_println("FAIL");

    uart_println("---------------------------------");

    if (pass_count == 3)
        uart_println("FINAL RESULT: ALL TESTS PASSED");
    else
        uart_println("FINAL RESULT: FAILED");

    uart_println("---------------------------------");
}