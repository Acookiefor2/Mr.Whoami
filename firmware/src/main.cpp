// Mr. Whoami? firmware - chunk 1: pin map + button test
// Board: ESP32-S3-DevKitC-1 N16R8
// Pin numbers come from schematics/Mr.Whoami (DevKit left header J1).

#include <Arduino.h>

// ---------- Buttons ----------
// Each button connects the pin to GND when pressed.
// We turn on the chip's internal pull-up, so: not pressed = HIGH, pressed = LOW.
const int BTN_SCRIPT = 15;  // J1 pin 8,  big left arcade button
const int BTN_AI     = 16;  // J1 pin 9,  big right arcade button
const int BTN_START  = 17;  // J1 pin 10, small 16mm button

// ---------- Arcade button LEDs ----------
// These drive NPN transistors (Q1, Q2) that switch the 5V LEDs.
// HIGH = LED on, LOW = LED off.
const int LED_SCRIPT = 18;  // J1 pin 11
const int LED_AI     = 8;   // J1 pin 12

// ---------- Used in later chunks (here so the whole pin map lives in one place) ----------
const int LED_RING = 4;     // J1 pin 4, WS2812B data (through R3)

const int AMP_BCLK = 5;     // J1 pin 5, MAX98357A I2S
const int AMP_LRC  = 6;     // J1 pin 6
const int AMP_DIN  = 7;     // J1 pin 7

const int LCD_DC   = 9;     // J1 pin 15, ST7796 SPI screen
const int LCD_CS   = 10;    // J1 pin 16
const int LCD_MOSI = 11;    // J1 pin 17
const int LCD_SCK  = 12;    // J1 pin 18
const int LCD_MISO = 13;    // J1 pin 19
const int LCD_RST  = 14;    // J1 pin 20

// Remember what each button was last time, so we only print when it CHANGES.
bool lastScript = HIGH;
bool lastAi     = HIGH;
bool lastStart  = HIGH;

// Prints a message only when a button goes from not-pressed to pressed.
// Returns the new state so loop() can remember it.
bool checkButton(int pin, bool lastState, const char* name) {
  bool now = digitalRead(pin);
  if (lastState == HIGH && now == LOW) {
    Serial.print(name);
    Serial.println(" pressed");
  }
  return now;
}

void setup() {
  Serial.begin(115200);
  delay(500);  // give the serial monitor a moment to connect

  pinMode(BTN_SCRIPT, INPUT_PULLUP);
  pinMode(BTN_AI,     INPUT_PULLUP);
  pinMode(BTN_START,  INPUT_PULLUP);

  pinMode(LED_SCRIPT, OUTPUT);
  pinMode(LED_AI,     OUTPUT);
  digitalWrite(LED_SCRIPT, LOW);
  digitalWrite(LED_AI,     LOW);

  Serial.println("Mr. Whoami? waking up - press a button");
}

void loop() {
  lastScript = checkButton(BTN_SCRIPT, lastScript, "SCRIPT");
  lastAi     = checkButton(BTN_AI,     lastAi,     "AI");
  lastStart  = checkButton(BTN_START,  lastStart,  "START");

  // YOUR TURN: make each arcade button's LED glow while it's held down.

  delay(20);  // tiny wait so one press doesn't count as many (debounce)
}
