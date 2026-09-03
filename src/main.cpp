#include <Arduino.h>

// --- Pin Definitions ---
constexpr uint8_t GSR_PIN = A0;
constexpr uint8_t CAL_POT_PIN = A1;

constexpr uint8_t LED_GREEN_PIN = 2;
constexpr uint8_t LED_YELLOW_PIN = 3;
constexpr uint8_t LED_RED_PIN = 4;
constexpr uint8_t BUZZER_PIN = 5;

// --- Sampling Configurations ---
constexpr unsigned long SAMPLE_INTERVAL_MS = 100;
unsigned long previousMillis = 0;

void setup() {
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(115200);
  Serial.println(F("--- Skin Conductance Stress-Meter System Online ---"));
}

void loop() {
  unsigned long currentMillis = millis();

  // Non-blocking sampling loop
  if (currentMillis - previousMillis >= SAMPLE_INTERVAL_MS) {
    previousMillis = currentMillis;

    // Read analog values (0 - 1023)
    int rawGSR = analogRead(GSR_PIN);
    int baseline = analogRead(CAL_POT_PIN);

    // Stress threshold calculation based on potentiometer calibration
    int moderateThreshold = baseline + 30;
    int highThreshold = baseline + 80;

    // Telemetry output
    Serial.print(F("GSR Raw: "));
    Serial.print(rawGSR);
    Serial.print(F(" | Baseline: "));
    Serial.println(baseline);

    // Visual & Acoustic Feedback Logic
    if (rawGSR >= highThreshold) {
      digitalWrite(LED_GREEN_PIN, LOW);
      digitalWrite(LED_YELLOW_PIN, LOW);
      digitalWrite(LED_RED_PIN, HIGH);
      tone(BUZZER_PIN, 2500); // High warning tone
    } 
    else if (rawGSR >= moderateThreshold) {
      digitalWrite(LED_GREEN_PIN, LOW);
      digitalWrite(LED_YELLOW_PIN, HIGH);
      digitalWrite(LED_RED_PIN, LOW);
      tone(BUZZER_PIN, 1000); // Moderate tone
    } 
    else {
      digitalWrite(LED_GREEN_PIN, HIGH);
      digitalWrite(LED_YELLOW_PIN, LOW);
      digitalWrite(LED_RED_PIN, LOW);
      noTone(BUZZER_PIN);
    }
  }
}
