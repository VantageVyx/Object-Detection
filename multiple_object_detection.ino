void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); //1 person
  pinMode(10, OUTPUT); //2+ people
  pinMode(9, OUTPUT);  //cup
}

void loop() {
  static String input = "";

  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      
      int commaIndex = input.indexOf(',');
      if (commaIndex > 0) {
        int personCount = input.substring(0, commaIndex).toInt();
        int cupFlag = input.substring(commaIndex + 1).toInt();

        //person LEDs
        digitalWrite(13, personCount == 1 ? HIGH : LOW);    //1 person
        digitalWrite(10, personCount >= 2 ? HIGH : LOW);    //2+ people

        //cup LEDs
        digitalWrite(9, cupFlag == 1 ? HIGH : LOW);         //Cup present
      }

      input = ""; // Reset buffer
    } else {
      input += c;
    }
  }
}
