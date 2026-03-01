# API Reference

# GPIO Driver

## void gpio_init(void)

**Purpose:**  
Initializes the onboard LED GPIO pin.

**Parameters:**  
None

**Return:**  
None

**Notes:**  
Configures LED pin as push-pull output.

## void gpio_led_on(void)

Turns LED ON.

## void gpio_led_off(void)

Turns LED OFF.

## void gpio_led_toggle(void)

Toggles LED state.

# UART Driver

## void uart_init(void)

**Purpose:**  
Initializes USART peripheral for serial communication.

**Configuration:**
- Baud: 115200
- 8 data bits
- 1 stop bit
- No parity

## void uart_print(char *str)

Transmits a null-terminated string.

## void uart_println(char *str)

Transmits a string followed by CRLF.

# Timer Driver

## void timer_init(void)

Initializes timing mechanism.

In this implementation, a calibrated software delay loop is used.

## void delay_ms(uint32_t ms)

Blocking delay function.

**Note:**  
Based on 24 MHz system clock.

# POST Module

## void post_run_all_tests(void)

Executes complete self-test sequence:

1. GPIO test
2. UART test
3. Timer test
4. Structured summary report

Returns: None

## Example
    gpio_init();
    
    uart_init();
    
    timer_init();

    post_run_all_tests();

    while(1)
    {
        gpio_led_toggle();
        delay_ms(1000);
    }

