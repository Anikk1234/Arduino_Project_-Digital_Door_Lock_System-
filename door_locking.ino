#include <ESP32Servo.h>

Servo servo;

// Pin and Servo Positions
const int servoPin = 2;
const int initialPos = 95;  // Locked position
const int forwardPos = 0;   // Unlocked position

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 Servo Lock Control via Serial");

  servo.attach(servoPin);
  delay(1000);

  // Start at locked position
  servo.write(initialPos);
  delay(1000);
  servo.detach();

  Serial.println("Type '1' to unlock, '0' to lock");
}

void loop() {
  // Check if Serial input is available
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      Serial.println("Unlocking...");
      moveServo(forwardPos);
    }
    else if (command == '0') {
      Serial.println("Locking...");
      moveServo(initialPos);
    }
    else {
      Serial.println("Invalid command! Type 1 or 0.");
    }
  }
}

void moveServo(int position) {
  servo.attach(servoPin);
  delay(10);
  servo.write(position);
  delay(1000);
  servo.detach();
}
