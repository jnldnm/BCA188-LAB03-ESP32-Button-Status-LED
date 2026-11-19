# ESP32 Button and Status LED Circuit

## 1. Introduction

This laboratory activity demonstrates digital input and output using an ESP32, a pushbutton, and two status LEDs. The circuit uses the pushbutton state to control one LED while the second LED displays the opposite state.

## 2. About the Project

The project reads a pushbutton through an ESP32 GPIO input and controls two LED outputs. In the proposed implementation, the button input uses an external pull-down resistor so that the input remains LOW while the button is released. Pressing the button connects the input to 3.3 V and changes its reading to HIGH.

The first LED follows the button state. The second LED follows the inverse of that state. Consequently, one LED is ON whenever the other is OFF.

The activity description supplied for this project did not identify the subject code, laboratory number, exact ESP32 board, or original Example 2 source code. The pin assignments and circuit values documented here are an explicit example implementation rather than a claim about an unseen original circuit.

## 3. Objectives

- Assemble and label the GPIO connections for a pushbutton and status LED circuit.
- Verify the released and pressed behavior of the pushbutton.
- Explain the HIGH and LOW logic levels of the button input.
- Add a second LED that displays the opposite state of the first LED.
- Confirm stable input behavior when the button is released.
- Reset the board and identify the expected initial outputs.

## 4. Technologies and Requirements

| Item | Purpose |
|---|---|
| ESP32 development board | Microcontroller used to read the button and control the LEDs |
| Arduino IDE | Source-code editing and board programming environment |
| Pushbutton | Digital input device |
| Two LEDs | Complementary visual status indicators |
| 10 kΩ resistor | Pull-down resistor that holds the button input LOW while released |
| Two 220 Ω resistors | Current-limiting resistors for the LEDs |
| Breadboard and jumper wires | Circuit assembly |
| USB data cable | Board power and programming connection |

The implementation uses Arduino C/C++ and the standard Arduino GPIO functions. No additional library is required for the basic digital input/output behavior.

## 5. Project Structure

```text
SUBJECTCODE-LABNUMBER-ESP32-Button-Status-LED/
│
├── README.md
├── ACTIVITY-ANSWERS.md
├── Documentation/
│   ├── screenshot-01-circuit-connections.png
│   ├── screenshot-02-source-code.png
│   ├── screenshot-03-released-state.png
│   ├── screenshot-04-pressed-state.png
│   └── screenshot-05-final-verification.png
│
└── SourceCode/
    └── main.ino
```

- `README.md` contains the project overview and implementation summary.
- `ACTIVITY-ANSWERS.md` contains the technical explanations and observation table.
- `Documentation/` is intended for genuine circuit, code, and test evidence.
- `SourceCode/main.ino` contains the Arduino program.

## 6. Implementation Overview

### GPIO assignments

| Component | ESP32 connection |
|---|---|
| Pushbutton input | GPIO 4 |
| First LED | GPIO 18 |
| Second LED | GPIO 19 |
| Button pull-down resistor | 10 kΩ between GPIO 4 and GND |
| Button supply | 3.3 V through the pushbutton |
| LED current limiting | 220 Ω in series with each LED |

The pushbutton connects GPIO 4 to 3.3 V when pressed. A 10 kΩ resistor connects GPIO 4 to GND, establishing a defined LOW state while the button is released.

Each LED is connected in series with a 220 Ω resistor between its GPIO output and GND. The LED anode faces the GPIO side and its cathode faces GND.

### Program behavior

The program reads GPIO 4. The first LED is set HIGH when the button input is HIGH. The second LED is assigned the inverse of the button reading. This produces complementary output states.

The selected external pull-down arrangement makes LOW the released state and HIGH the pressed state. The LED outputs are initialized to the released-state condition when the program starts.

### Results and discussion

The expected logic behavior is:

| Button condition | GPIO 4 reading | LED on GPIO 18 | LED on GPIO 19 |
|---|---|---|---|
| Released | LOW | OFF | ON |
| Pressed | HIGH | ON | OFF |

These are the expected states derived from the circuit and program logic. No physical test photographs or measured observations were included with the activity description, so successful hardware operation is not asserted here.

## 7. Project Documentation

No screenshot evidence was included in the materials available when this document was prepared. The `Documentation/` directory is the designated location for genuine project evidence.

## 8. Conclusion

The activity demonstrates how an ESP32 reads a digital pushbutton input and controls two digital outputs. A pull-down resistor provides a defined LOW input while the button is released, while pressing the button applies 3.3 V and produces a HIGH input. The complementary output logic makes the two LEDs display opposite states. The expected behavior also establishes the initial released-state output after the program starts.

## 9. References

- Espressif Systems, ESP32 Documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/
- Arduino Language Reference, `pinMode()`: https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/
- Arduino Language Reference, `digitalRead()`: https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalRead/
- Arduino Language Reference, `digitalWrite()`: https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalWrite/
