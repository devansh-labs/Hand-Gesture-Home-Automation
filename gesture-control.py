"""
Project: Hand Gesture Controlled Home Automation
Author: Devansh Upadhyay

Description:
This script uses computer vision (OpenCV + MediaPipe) to detect hand gestures
and control multiple rooms via serial communication (e.g., Arduino).

Each finger represents a room:
- Index  → Room 1
- Middle → Room 2
- Ring   → Room 3
- Little → Room 4

Finger state (open/closed) is detected and corresponding signals are sent
to the microcontroller.
"""

import serial
import cv2
import mediapipe as mp


# -------------------- INITIALIZATION --------------------

# Initialize serial communication
# NOTE: Update COM port and baud rate according to your system
ser = serial.Serial('COM5', 9600)

# Initialize MediaPipe Hands model
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()

# Utility for drawing landmarks on frame
mp_draw = mp.solutions.drawing_utils

# Start webcam capture (0 = default camera)
cap = cv2.VideoCapture(0)

# Store previous finger states to avoid redundant serial signals
prev_index = False
prev_middle = False
prev_ring = False
prev_little = False


# -------------------- MAIN LOOP --------------------

while True:
    # Capture frame from webcam
    ret, frame = cap.read()
    if not ret:
        print("Error: Failed to capture frame from camera.")
        break

    # Flip frame horizontally for mirror effect
    frame = cv2.flip(frame, 1)

    # Convert BGR → RGB (required by MediaPipe)
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Process frame for hand detection
    results = hands.process(frame_rgb)

    # -------------------- HAND DETECTION --------------------

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:

            # Draw hand landmarks and connections
            mp_draw.draw_landmarks(
                frame,
                hand_landmarks,
                mp_hands.HAND_CONNECTIONS
            )

            # -------------------- HAND ORIENTATION --------------------

            # Compare wrist and middle finger tip to determine orientation
            wrist_y = hand_landmarks.landmark[0].y
            middle_tip_y = hand_landmarks.landmark[12].y

            # True  → Hand upright
            # False → Hand inverted
            hand_normal = middle_tip_y < wrist_y

            # -------------------- FINGER STATE DETECTION --------------------

            # Landmark indices for fingertips and lower joints
            tips = [8, 12, 16, 20]
            joints = [6, 10, 14, 18]

            fingers = []

            # Detect whether each finger is open or closed
            for i in range(4):
                tip = hand_landmarks.landmark[tips[i]]
                joint = hand_landmarks.landmark[joints[i]]

                # Adjust logic based on hand orientation
                if hand_normal:
                    fingers.append(tip.y < joint.y)
                else:
                    fingers.append(tip.y > joint.y)

            # Assign finger states
            index_open, middle_open, ring_open, little_open = fingers

            # -------------------- ROOM CONTROL LOGIC --------------------

            # Send signal only when state changes (prevents spamming serial)

            # Room 1 → Index Finger
            if index_open != prev_index:
                print("Room 1 ON" if index_open else "Room 1 OFF")
                ser.write(b'1') if index_open else ser.write(b'5')
                prev_index = index_open

            # Room 2 → Middle Finger
            if middle_open != prev_middle:
                print("Room 2 ON" if middle_open else "Room 2 OFF")
                ser.write(b'2') if middle_open else ser.write(b'6')
                prev_middle = middle_open

            # Room 3 → Ring Finger
            if ring_open != prev_ring:
                print("Room 3 ON" if ring_open else "Room 3 OFF")
                ser.write(b'3') if ring_open else ser.write(b'7')
                prev_ring = ring_open

            # Room 4 → Little Finger
            if little_open != prev_little:
                print("Room 4 ON" if little_open else "Room 4 OFF")
                ser.write(b'4') if little_open else ser.write(b'8')
                prev_little = little_open

    # -------------------- DISPLAY OUTPUT --------------------

    # Show processed frame
    cv2.imshow("Hand Detection", frame)

    # Press 'a' to exit the program
    if cv2.waitKey(1) & 0xFF == ord('a'):
        break


# -------------------- CLEANUP --------------------

# Release camera and close all OpenCV windows
cap.release()
cv2.destroyAllWindows()