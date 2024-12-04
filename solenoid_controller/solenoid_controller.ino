const int solenoidPin = 3;  // Solenoid connected to pin 3
const int MAX_NUMS = 100;    // Maximum number of numbers to process


void setup() {
  pinMode(solenoidPin, OUTPUT);  
  analogWrite(solenoidPin, 255); // Initial value to solenoid pin
  Serial.begin(9600);            // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read input from Serial until newline
    input.trim();  // Remove leading/trailing whitespace
    int numbers[MAX_NUMS];       // Array to store the numbers
    int numCount = 0;            // Variable to keep track of the number of parsed numbers
    
    // Split input based on spaces and convert to integers
    int index = 0;
    while (index < input.length() && numCount < MAX_NUMS) {
      int spaceIndex = input.indexOf(' ', index);
      if (spaceIndex == -1) spaceIndex = input.length();  // End of string if no more spaces

      String numStr = input.substring(index, spaceIndex);
      numbers[numCount] = numStr.toInt();  // Convert to integer and store in array
      numCount++;

      index = spaceIndex + 1;  // Move to the next number
    }

    // Now process the numbers and control the solenoid
    for (int i = 0; i < numCount / 3; i++) {
        analogWrite(solenoidPin, numbers[i*3+2]);
        delay(numbers[i*3+3]);
    }

  }
}
