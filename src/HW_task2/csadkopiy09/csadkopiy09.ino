#include <Arduino.h>

void setup() {
    Serial.begin(9600);  // Починаємо серійну передачу
}

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');  // Читаємо вхідне повідомлення

        // Перевіряємо, чи отримали ми повідомлення "Hello, Arduino Uno R3!"
        if (input == "Hello, Arduino Uno R3!") {
            // Відправляємо відповідь клієнту
            Serial.println("Hello, Client!");
        }
    }
}
