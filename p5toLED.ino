
int leftLedPin = 3;
int brightness = 0;

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(leftLedPin, OUTPUT);

  // Blink to check the wiring
  digitalWrite(leftLedPin, HIGH);
  delay(200);
  digitalWrite(leftLedPin, LOW);

  while (Serial.available() <= 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("0");
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }
}

void loop() {
  if (Serial.available() > 0) {
    digitalWrite(LED_BUILTIN, HIGH);

    // Read brightness from p5.js
    int left = Serial.parseInt();

    if (Serial.read() == '\n') {
      brightness = constrain(left, 0, 255);

      // Set LED brightness
      analogWrite(leftLedPin, brightness);
    }

    digitalWrite(LED_BUILTIN, LOW);
  }
}