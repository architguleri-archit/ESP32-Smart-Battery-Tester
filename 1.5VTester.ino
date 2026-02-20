#include <LiquidCrystal.h>

/* ================= USER SETTINGS =================
   Change ONLY these values if needed
   ---------------------------------
   ADC_PIN            : ESP32 analog pin used
   CALIBRATION_FACTOR : Adjust this for accurate voltage
                         (Measure with multimeter and tweak)
   DIVIDER_RATIO      : Based on resistor divider used
================================================== */

#define ADC_PIN 34

#define ADC_MAX 4095.0        // 12-bit ADC max value
#define REF_VOLTAGE 3.3       // ESP32 reference voltage

#define DIVIDER_RATIO 2.0     // For equal resistors (e.g. 330k + 330k)
#define CALIBRATION_FACTOR 0.98   // <<< PUT YOUR CALIBRATION VALUE HERE

#define LOW_BATTERY_LIMIT 1.0     // Below this = LOW VOLTAGE warning
#define HIGH_VOLTAGE_LIMIT 1.6    // Above this = HIGH VOLTAGE warning


// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);


/* ================= BLINK SETTINGS ================= */
bool blinkHigh = true;
bool blinkLow  = true;

unsigned long lastBlinkHigh = 0;
unsigned long lastBlinkLow  = 0;

const unsigned long HIGH_BLINK_INTERVAL = 200; // Fast blink for HIGH voltage
const unsigned long LOW_BLINK_INTERVAL  = 500; // Slow blink for LOW voltage


/* ================= STARTUP ANIMATION ================= */
void startupAnimation() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cell Tester");

  const int totalBars  = 10;
  const int totalSteps = 50;   // Smoothness
  const int stepDelay  = 25;   // Speed

  for (int step = 1; step <= totalSteps; step++) {
    float progress = ((float)step / totalSteps) * totalBars;
    int bars = (int)progress;

    lcd.setCursor(0,1);
    lcd.print("[");
    for (int i = 0; i < totalBars; i++) {
      if (i < bars) lcd.print("|");
      else lcd.print(" ");
    }
    lcd.print("]");

    delay(stepDelay);
  }

  delay(500);
  lcd.clear();
}


/* ================= SETUP ================= */
void setup() {
  analogReadResolution(12);
  analogSetPinAttenuation(ADC_PIN, ADC_11db);

  lcd.begin(16,2);
  startupAnimation();
}


/* ================= MAIN LOOP ================= */
void loop() {
  unsigned long currentMillis = millis();

  // Blink timing control
  if (currentMillis - lastBlinkHigh >= HIGH_BLINK_INTERVAL) {
    lastBlinkHigh = currentMillis;
    blinkHigh = !blinkHigh;
  }
  if (currentMillis - lastBlinkLow >= LOW_BLINK_INTERVAL) {
    lastBlinkLow = currentMillis;
    blinkLow = !blinkLow;
  }

  // Read ADC multiple times for stability
  int sum = 0;
  for (int i = 0; i < 30; i++) {
    sum += analogRead(ADC_PIN);
    delay(2);
  }
  int adcValue = sum / 30;

  // No cell detected
  if (adcValue < 200) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Cell");
    lcd.setCursor(0,1);
    lcd.print("Insert Cell");
    delay(400);
    return;
  }

  // Voltage calculation
  float adcVoltage = (adcValue / ADC_MAX) * REF_VOLTAGE;
  float batteryVoltage = adcVoltage * DIVIDER_RATIO * CALIBRATION_FACTOR;

  // Battery percentage for 1.5V dry cell
  int percent = 0;
  bool isDryCell = false;

  if (batteryVoltage >= LOW_BATTERY_LIMIT && batteryVoltage <= HIGH_VOLTAGE_LIMIT) {
    percent = map(batteryVoltage * 100, 100, 150, 0, 100);
    percent = constrain(percent, 0, 100);
    isDryCell = true;
  }

  // Display voltage
  lcd.setCursor(0,0);
  lcd.print("Volt: ");
  lcd.print(batteryVoltage, 2);
  lcd.print("V   ");

  // Display status
  lcd.setCursor(0,1);

  if (batteryVoltage < LOW_BATTERY_LIMIT) {
    if (blinkLow) lcd.print("LOW VOLTAGE! ");
    else lcd.print("                ");
  }
  else if (batteryVoltage > HIGH_VOLTAGE_LIMIT) {
    if (blinkHigh) lcd.print("HIGH VOLTAGE! ");
    else lcd.print("                ");
  }
  else if (isDryCell) {
    int bars = map(percent, 0, 100, 0, 10);
    lcd.print("[");
    for (int i = 0; i < 10; i++) {
      if (i < bars) lcd.print("|");
      else lcd.print(" ");
    }
    lcd.print("]");
    lcd.print(percent);
    lcd.print("%");
  }
  else {
    lcd.print("                ");
  }

  delay(200);
}
