int ledPin = 13;  

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);  // Turn LED ON
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);   // Turn LED OFF
    }
  }
}
