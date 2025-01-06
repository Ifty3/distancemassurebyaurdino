#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "NewPing.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#define TRIGGER_PIN 5  
#define ECHO_PIN 6     
#define MAX_DISTANCE 400 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); 
  lcd.print("Distance Sensor");
  delay(2000);
  lcd.clear(); 
  Serial.begin(9600);
}

void loop() {
  // Get the distance measurement from the HC-SR04
  int distance = sonar.ping_cm();
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  lcd.setCursor(0, 0); // Set cursor to the first row
  lcd.print("Distance: "); // Display text
  lcd.print(distance);     // Display the measured distance
  lcd.print(" cm    ");    // Extra spaces to overwrite old text

  delay(500);
}
