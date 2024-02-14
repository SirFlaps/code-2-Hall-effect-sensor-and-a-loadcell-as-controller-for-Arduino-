#include "Joystick.h"
#include <Q2HX711.h>

Q2HX711 hx711(A5, A4);
Joystick_ Joystick(
    JOYSTICK_DEFAULT_REPORT_ID,
    JOYSTICK_TYPE_JOYSTICK,
    0,                              // Amount of buttons
    0,                              // Amount of hat switches
    false,                          // x-axis
    false,                          // y-axis
    true,                           // z-axis
    false,                          // x-axis rotation
    false,                          // y-axis rotation
    false,                          // z-axis rotation
    false,                          // rudder
    true,                           // throttle
    false,                          // accelerator
    true,                           // brake
    false                           // steering
    );

void setup() {
    Joystick.begin();
    Serial.begin(9600);
}

void loop() {
    Joystick.setZAxis(analogRead(A2));
    Joystick.setThrottle(analogRead(A0));
    Joystick.setBrake(hx711.read()/30000);
    Serial.println(hx711.read()/30000);
}
