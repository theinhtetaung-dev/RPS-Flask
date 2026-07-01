void setup() {
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the string until newline character '\n'
    String data = Serial.readStringUntil('\n');
    data.trim(); // Clean up any trailing/leading whitespaces

    if (data.length() > 0) {
      // Find the separating comma
      int commaIndex = data.indexOf(',');
      if (commaIndex != -1) {
        String userChoice = data.substring(0, commaIndex);
        String aiChoice = data.substring(commaIndex + 1);

        // Print exactly what was requested
        Serial.print("User Choice is - ");
        Serial.println(userChoice);
        Serial.print("AI is ");
        Serial.println(aiChoice);
        Serial.println("--------------------"); // separator for readability
      }
    }
  }
}
