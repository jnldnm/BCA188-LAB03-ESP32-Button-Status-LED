
// ESP32 Button and Complementary Status LEDs

const int BUTTON_PIN = 4;
const int LED_1_PIN = 18;
const int LED_2_PIN = 19;

int lastButtonState = -1;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT);  // External 10kΩ pull-down
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);

  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, HIGH);

  Serial.println("ESP32 Button and LED Test");
  Serial.println("-------------------------");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  digitalWrite(LED_1_PIN, buttonState);
  digitalWrite(LED_2_PIN, !buttonState);

  // Print only when the button state changes
  if (buttonState != lastButtonState) {
    Serial.print("Button: ");

    if (buttonState == HIGH) {
      Serial.println("PRESSED (HIGH)");
      Serial.println("LED 1: ON | LED 2: OFF");
    } else {
      Serial.println("RELEASED (LOW)");
      Serial.println("LED 1: OFF | LED 2: ON");
    }

    Serial.println("-------------------------");
    lastButtonState = buttonState;
  }

  delay(20);
}
