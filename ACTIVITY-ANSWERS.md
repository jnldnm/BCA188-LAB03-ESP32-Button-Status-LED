# Laboratory Activity Answers

## 1. Introduction

This document presents the technical explanations and expected logic observations for the laboratory activity involving an ESP32 pushbutton input and two complementary status LEDs. The pin assignments described here use an external pull-down resistor and are based on the implementation documented in the project README.

## 2. Activity Questions

### 1. Explain the meaning of HIGH and LOW for the button.

With the external pull-down circuit used in this implementation, **LOW** means the button is released. The 10 kΩ resistor connects the input GPIO to GND, holding the input at a defined LOW logic level.

**HIGH** means the button is pressed. Pressing the button connects the input GPIO to the ESP32's 3.3 V supply, producing a HIGH logic level.

The interpretation depends on the wiring. A circuit using a pull-up resistor would have the opposite button logic: HIGH when released and LOW when pressed.

### 2. Why should the button input not change randomly when released?

A GPIO input must have a defined voltage when the button is not pressed. Without a pull-up or pull-down path, the input can float and may respond to electrical noise or nearby signals. The external 10 kΩ pull-down resistor holds the input LOW while the button is released, preventing an undefined input state.

### 3. How do the two LEDs show opposite states?

The first LED follows the button input. The second LED follows the inverse of that input. When the input is LOW, the first LED is OFF and the second is ON. When the input is HIGH, the first LED is ON and the second is OFF. The outputs are complementary.

### 4. What are the expected initial outputs after resetting the board?

At startup, the program initializes both LED outputs to the released-button condition. With the external pull-down resistor holding the input LOW, the expected initial state is LED 1 OFF and LED 2 ON. This is the expected behavior based on the circuit and code; a physical reset test was not evidenced in the supplied materials.

## 3. Completed Tables

### Pressed/Released Observation Table

| Button condition | Button input (GPIO 4) | LED 1 (GPIO 18) | LED 2 (GPIO 19) | Expected observation |
|---|---|---|---|---|
| Released | LOW | OFF | ON | Pull-down resistor holds the input LOW; the second LED is illuminated |
| Pressed | HIGH | ON | OFF | Button connects the input to 3.3 V; the first LED is illuminated |

**Note:** The table records expected logic behavior from the proposed circuit and source code. It is not a record of measured physical observations.

## 4. Exercises and Additional Activities

### Opposite-state LED logic

The complementary LED behavior is implemented by assigning the first LED the value of the button input and the second LED the logical inverse:

```cpp
digitalWrite(LED_1_PIN, buttonState);
digitalWrite(LED_2_PIN, !buttonState);
```

The logical NOT operator (`!`) reverses the Boolean value. A LOW input therefore produces a HIGH output for the second LED, while a HIGH input produces a LOW output for it.

## 5. Observations and Analysis

The external pull-down resistor establishes a stable default input state. The input is LOW while the pushbutton is released and HIGH while it is pressed. The program uses this reading to drive two complementary LED outputs.

The expected reset state is the released state: LED 1 OFF and LED 2 ON. The activity description supplied for this document did not include a physical circuit photograph, serial log, or test record. Therefore, the pressed/released states and reset behavior are presented as expected results derived from the circuit design and program logic, not as independently verified experimental observations.

## 6. References

- Espressif Systems, ESP32 Documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/
- Arduino Language Reference, `pinMode()`: https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/
- Arduino Language Reference, `digitalRead()`: https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalRead/
- Arduino Language Reference, `digitalWrite()`: https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalWrite/
