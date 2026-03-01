## Demo Steps

1. Connect board via USB
2. Run 'pio run' on the terminal to get the firmware binary of the source code
3. Run 'pio run -t upload' to flash the firmware binary onto the board
4. Open Serial Monitor (115200 baud)
5. Press RESET
6. Observe:
   - LED blinking during GPIO test
   - Structured UART test messages
   - Timer delay confirmation
   - Final PASS report
  

## UART Configuration

- Baud Rate: 115200
- Data Bits: 8
- Stop Bits: 1
- Parity: None
- Flow Control: None


## Expected Serial Output

VSDSquadron POST v1.0

[1] GPIO Test........ PASS

[2] UART Test........ PASS

[3] Timer Test....... PASS

FINAL RESULT: ALL TESTS PASSED


