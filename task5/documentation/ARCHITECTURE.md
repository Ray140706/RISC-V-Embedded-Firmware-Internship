# System Architecture

## High-Level Block Diagram

```
                         +----------------------------------+
                         |              main.c              |
                         |----------------------------------|
                         |  - System Initialization         |
                         |  - Driver Initialization         |
                         |  - Call POST Runner              |
                         +------------------+---------------+
                                            |
                                            v
                         +----------------------------------+
                         |           POST Module            |
                         |----------------------------------|
                         |  - test_gpio()                   |
                         |  - test_uart()                   |
                         |  - test_timer()                  |
                         |  - print_summary()               |
                         +----------+------------+----------+
                                    |            |
               ---------------------+            +---------------------
               |                                                 |
               v                                                 v
     +----------------------+                         +----------------------+
     |      GPIO Driver     |                         |      UART Driver     |
     |----------------------|                         |----------------------|
     | gpio_init()          |                         | uart_init()          |
     | gpio_set()           |                         | uart_print()         |
     | gpio_clear()         |                         | uart_read()          |
     +----------+-----------+                         +----------+-----------+
                |                                                 |
                v                                                 v
        +---------------+                               +------------------+
        |   LED (PC6)   |                               |  Serial Monitor  |
        +---------------+                               +------------------+

                                    |
                                    v
                          +----------------------+
                          |     Timer Driver     |
                          |----------------------|
                          | timer_init()         |
                          | delay_ms()           |
                          +----------+-----------+
                                     |
                                     v
                              +-------------+
                              |  CPU Delay  |
                              +-------------+
```

---

# Execution Flow

```
Reset →
    main()
        → gpio_init()
        → uart_init()
        → timer_init()
        → post_run_all_tests()
                → test_gpio()
                → test_uart()
                → test_timer()
        → idle loop
```


## Layer Separation

### 1. Drivers (Low-Level)
- GPIO
- UART
- Timer

Responsible for hardware abstraction only.

### 2. Application Layer
- POST module
- Structured reporting
- Test sequencing

### 3. Entry Point
- main.c initializes drivers
- Calls POST module

