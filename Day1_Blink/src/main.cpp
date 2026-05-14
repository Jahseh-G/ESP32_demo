#include <Arduino.h>

// put function declarations here:
#define LED_PIN 2   // On most ESP32 boards, the on‑board LED is GPIO2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);       // Enable serial communication
  pinMode(LED_PIN, OUTPUT);
  Serial.println("=== Day1 LED Lighting successful ===");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  Serial.println("LED blinking now...");
}

// put function definitions here:
