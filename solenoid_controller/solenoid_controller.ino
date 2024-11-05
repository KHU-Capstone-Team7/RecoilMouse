const int solenoidPin = 3;  // 솔레노이드가 연결된 핀

void setup() {
  pinMode(solenoidPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    Serial.println(input);
    if (input == "click") {
      digitalWrite(solenoidPin, LOW);  // 솔레노이드 동작
      delay(100);                      // 1초 대기
      digitalWrite(solenoidPin, HIGH);   // 솔레노이드 종료
    }
  }
}
