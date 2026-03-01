# Application Guide

## Application Behavior

The POST firmware executes automatically at every reset.

## Execution Sequence

### Step 1: GPIO Test
- LED toggles to verify pin configuration.
- PASS if LED control executes correctly.

### Step 2: UART Test
- Sends test string over serial.
- PASS if transmission completes.

### Step 3: Timer Test
- Executes calibrated 1-second delay.
- PASS if delay completes without hang.

## Timing Behavior

- Software delay calibrated for 24 MHz clock.
- Blocking design ensures deterministic sequence.

## Edge Cases Handled

- Avoided interrupt-based timing instability.
- Removed SysTick dependency.
- Structured output prevents ambiguous logs.

## State Model

Boot → Test 1 → Test 2 → Test 3 → Summary → Idle

No runtime state transitions after POST.
