/*
===========================================================
Project: Hand-Gesture-Home-Automation (Sinric Pro)
Author: Devansh Upadhyay

  Description:
  This program connects an ESP8266 (NodeMCU) to WiFi and allows
  controlling two relays using the Sinric Pro platform.

  You can control the devices using:
  - Sinric Pro mobile app
  - Alexa or Google Assistant

  Setup steps:
  1. Create an account on Sinric Pro
  2. Add two switch devices
  3. Copy the APP_KEY, APP_SECRET, and DEVICE IDs
  4. Replace the values below with your credentials
  5. Upload the code to ESP8266
  6. Connect relays to D1 and D2
  ===========================================================
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

// WiFi credentials
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASS "YOUR_WIFI_PASSWORD"

// Sinric Pro credentials
#define APP_KEY "YOUR_APP_KEY"
#define APP_SECRET "YOUR_APP_SECRET"

// Device IDs from Sinric Pro dashboard
#define DEVICE_ID_1 "DEVICE_ID_LIGHT1"
#define DEVICE_ID_2 "DEVICE_ID_LIGHT2"

// Relay pins
#define LIGHT1 D1
#define LIGHT2 D2

// This function is called whenever a device state is changed from the app
bool onPowerState(const String &deviceId, bool &state) {

  if (deviceId == DEVICE_ID_1) {
    digitalWrite(LIGHT1, state ? HIGH : LOW);
    Serial.println(state ? "Light 1 turned ON" : "Light 1 turned OFF");
  }

  if (deviceId == DEVICE_ID_2) {
    digitalWrite(LIGHT2, state ? HIGH : LOW);
    Serial.println(state ? "Light 2 turned ON" : "Light 2 turned OFF");
  }

  return true;
}

// Connect to WiFi network
void setupWiFi() {
  Serial.print("Connecting to WiFi");

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// Initialize Sinric Pro and attach callbacks
void setupSinricPro() {

  SinricProSwitch &light1 = SinricPro[DEVICE_ID_1];
  SinricProSwitch &light2 = SinricPro[DEVICE_ID_2];

  light1.onPowerState(onPowerState);
  light2.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
}

// Runs once when the board starts
void setup() {
  Serial.begin(115200);

  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);

  // Set default state (OFF for most relay modules)
  digitalWrite(LIGHT1, HIGH);
  digitalWrite(LIGHT2, HIGH);

  setupWiFi();
  setupSinricPro();
}

// Runs continuously
void loop() {
  SinricPro.handle();
}

/*
  Note:
  Some relay modules are active LOW.
  That means:
    HIGH = OFF
    LOW  = ON

  If your relay behaves opposite, swap HIGH and LOW.
*/