#include <BleGamepad.h>

#define BTN_ACCEL 25
#define BTN_BRAKE 26
#define BTN_LEFT  27
#define BTN_RIGHT 14

BleGamepad bleGamepad;

void setup() {
  pinMode(BTN_ACCEL, INPUT_PULLUP);
  pinMode(BTN_BRAKE, INPUT_PULLUP);
  pinMode(BTN_LEFT,  INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);

  BleGamepadConfiguration config;
  config.setButtonCount(4);   // 4 digital buttons
  config.setAutoReport(true);

  bleGamepad.begin(&config);
}

void loop() {
  if (!bleGamepad.isConnected()) return;

  // Button 1 - Accelerate
  if (digitalRead(BTN_ACCEL) == LOW)
    bleGamepad.press(1);
  else
    bleGamepad.release(1);

  // Button 2 - Brake
  if (digitalRead(BTN_BRAKE) == LOW)
    bleGamepad.press(2);
  else
    bleGamepad.release(2);

  // Button 3 - Left
  if (digitalRead(BTN_LEFT) == LOW)
    bleGamepad.press(3);
  else
    bleGamepad.release(3);

  // Button 4 - Right
  if (digitalRead(BTN_RIGHT) == LOW)
    bleGamepad.press(4);
  else
    bleGamepad.release(4);

  delay(10);
}
