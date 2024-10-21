#include <Arduino.h>

void setup() {
    Serial.begin(9600);  // Start serial transmission
}

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');  // Read the incoming message

        // Checking if we received the message "Hello, Arduino Uno R3!"
        if (input == "Hello, Arduino Uno R3!") {
            // Send a response to the client
            Serial.println("Hello, Client!");
        }
    }
}
