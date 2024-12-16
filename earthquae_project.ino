#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define VIBRATION_SENSOR_PIN 2
#define GREEN_LED_PIN 3
#define RED_LED_PIN 4
#define BUZZER_PIN 5

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.begin(16, 2);
  lcd.backlight();

  // Initial State
  digitalWrite(GREEN_LED_PIN, HIGH);  // Green LED on to show device is on
  digitalWrite(RED_LED_PIN, LOW);     // Red LED off initially
  digitalWrite(BUZZER_PIN, LOW);      // Buzzer off initially
  lcd.setCursor(0, 0);
  lcd.print("No quakes detected");
}

void loop() {
  int vibration = digitalRead(VIBRATION_SENSOR_PIN);

  if (vibration == HIGH) {
    // Quake Detected
    digitalWrite(GREEN_LED_PIN, LOW);   // Turn off Green LED
    digitalWrite(RED_LED_PIN, HIGH);    // Turn on Red LED
    digitalWrite(BUZZER_PIN, HIGH);     // Turn on Buzzer
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Detected Quakes");

    delay(5000); // Alert duration

    // Reset to No Quakes Detected State
    digitalWrite(RED_LED_PIN, LOW);     // Turn off Red LED
    digitalWrite(BUZZER_PIN, LOW);      // Turn off Buzzer
    digitalWrite(GREEN_LED_PIN, HIGH);  // Turn on Green LED
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No quakes detected");
  }
}
