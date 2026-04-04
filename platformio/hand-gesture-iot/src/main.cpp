/*
Project: Hand Gesture Controlled Home Automation (Arduino Side)
Author: Devansh Upadhyay

Description:
This Arduino program receives serial commands from a Python script
(OpenCV + MediaPipe hand tracking) and controls 4 output devices (rooms).

Command Mapping:
'1' → Room 1 ON
'2' → Room 2 ON
'3' → Room 3 ON
'4' → Room 4 ON

'5' → Room 1 OFF
'6' → Room 2 OFF
'7' → Room 3 OFF
'8' → Room 4 OFF

NOTE:
- LOW  = ON  (for relay modules, active LOW logic)
- HIGH = OFF
*/

#include <Arduino.h>

// -------------------- PIN CONFIGURATION --------------------

// Define digital pins connected to relays / devices
int Room1 = 8;
int Room2 = 9;
int Room3 = 10;
int Room4 = 11;


// -------------------- SETUP FUNCTION --------------------

void setup() {
  // Initialize serial communication (must match Python baud rate)
  Serial.begin(9600);

  // Set all room pins as output
  pinMode(Room1, OUTPUT);
  pinMode(Room2, OUTPUT);
  pinMode(Room3, OUTPUT);
  pinMode(Room4, OUTPUT);

  // Initialize all rooms to OFF state (HIGH for active LOW relays)
  digitalWrite(Room1, HIGH);
  digitalWrite(Room2, HIGH);
  digitalWrite(Room3, HIGH);
  digitalWrite(Room4, HIGH);
}


// -------------------- MAIN LOOP --------------------

void loop() {

  // Check if data is available from serial (Python script)
  if (Serial.available() > 0) {

    // Read incoming command
    char command = Serial.read();

    // -------------------- COMMAND HANDLING --------------------

    switch (command) {

      // Turn ON rooms (active LOW)
      case '1': digitalWrite(Room1, LOW); break;
      case '2': digitalWrite(Room2, LOW); break;
      case '3': digitalWrite(Room3, LOW); break;
      case '4': digitalWrite(Room4, LOW); break;

      // Turn OFF rooms
      case '5': digitalWrite(Room1, HIGH); break;
      case '6': digitalWrite(Room2, HIGH); break;
      case '7': digitalWrite(Room3, HIGH); break;
      case '8': digitalWrite(Room4, HIGH); break;

      // Optional: ignore invalid input
      default: break;
    }
  }
}