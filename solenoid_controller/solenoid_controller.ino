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
      analogWrite(solenoidPin, 0);  // 솔레노이드 동작
      delay(50);                      // 1초 대기
      analogWrite(solenoidPin, 255);   // 솔레노이드 종료
      delay(50); 
      analogWrite(solenoidPin, 84);  // 솔레노이드 동작
      delay(50);                      // 1초 대기
      analogWrite(solenoidPin, 255);   // 솔레노이드 종료
    }
  }
}
