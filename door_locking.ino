#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6edJ1481J"
#define BLYNK_TEMPLATE_NAME "Anik"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create servo and LCD objects
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27 (try 0x3F if not working)

// Blynk Authentication
char auth[] = "h0UyBxnLG7H7RsgbY70KOieUWL3r1-tD"; // Your Blynk Auth Token
char ssid[] = "11223344";       // Your WiFi SSID
char pass[] = "876543210";      // Your WiFi Password

// Servo variables
int lastPosition = 0;
int onnPos = 90;    // ON position (in degrees)
int offPos = 0;     // OFF position (in degrees)
int servoPin = 4;   // GPIO4

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi...");
  
  // Attach servo
  servo.attach(servoPin);
  
  // Initial LCD message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door Lock System");
  lcd.setCursor(0, 1);
  lcd.print("Status: Closed");
  
  // Initial Serial message
  Serial.println("Door Lock System Initialized. Status: Closed");
  
  // Set initial position to closed
  servo.write(offPos);
  delay(500);
  servo.detach();
  lastPosition = offPos;
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  Serial.print("Blynk V0 value received: ");
  Serial.println(value);

  if (value == 1 && lastPosition != onnPos) {
    servo.attach(servoPin);
    servo.write(onnPos);  // Move to open position
    
    // LCD Update
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Lock System");
    lcd.setCursor(0, 1);
    lcd.print("Status: OPENED");
    
    // Serial Monitor Update
    Serial.println("Door Status: OPENED");
    
    delay(500);
    servo.detach();
    lastPosition = onnPos;
  } 
  else if (value == 0 && lastPosition != offPos) {
    servo.attach(servoPin);
    servo.write(offPos);  // Move to closed position
    
    // LCD Update
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Lock System");
    lcd.setCursor(0, 1);
    lcd.print("Status: CLOSED");
    
    // Serial Monitor Update
    Serial.println("Door Status: CLOSED");
    
    delay(500);
    servo.detach();
    lastPosition = offPos;
  }
}
