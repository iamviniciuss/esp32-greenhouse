#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager

void setupWifi() {
  WiFiManager wm;
  // wm.resetSettings();

  bool res;
  // res = wm.autoConnect("ESP32","password");
  res = wm.autoConnect("ESP32");

  if (!res) {
    Serial.println("Failed to connect");
  } else {
    Serial.println("connected...yeey :)");
  }
}