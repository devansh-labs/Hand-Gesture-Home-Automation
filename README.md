<h1 align="center">🏠 Hand Gesture Home Automation</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Build-Passing-brightgreen" />
  <img src="https://img.shields.io/badge/Platform-ESP8266%20%7C%20Arduino-blue" />
  <img src="https://img.shields.io/badge/Python-3.10-yellow" />
  <img src="https://img.shields.io/badge/License-MIT-green" />
  <img src="https://img.shields.io/badge/Project-Active-success" />
</p>

---

<h3 align="center">Control your home with just a wave of your hand — anytime, anywhere.</h3>

---

<h2>🎯 Objective</h2>

<p>
This project enables <b>home automation using hand gestures and IoT</b>, combining:
</p>

<ul>
  <li>Gesture recognition using <b>Python, OpenCV, and MediaPipe</b></li>
  <li>IoT-based remote control using <b>ESP8266 and Sinric Pro</b></li>
</ul>

---

<h2>📸 Project Preview</h2>

<p>🔴 Add your screenshots below:</p>

<pre>
&lt;img src="docs/images/gesture.png" width="600"/&gt;
&lt;img src="docs/images/hardware.png" width="600"/&gt;
&lt;img src="docs/images/app.png" width="600"/&gt;
</pre>

<p><b>How to add screenshots:</b></p>
<ol>
  <li>Create folder: <code>docs/images/</code></li>
  <li>Put your images inside it</li>
  <li>Replace filenames above</li>
</ol>

---

<h2>✨ Features</h2>

<ul>
  <li>✋ Hand gesture-based real-time control</li>
  <li>🌐 IoT-based remote control via Sinric Pro</li>
  <li>🏠 Multi-room automation using relay modules</li>
  <li>🔄 Hybrid system (offline + online)</li>
  <li>🧩 Modular and scalable design</li>
</ul>

---

<h2>🧠 System Architecture</h2>

<h3>🔄 Data Flow</h3>

<p><b>Gesture Control:</b></p>
<pre>Gesture → Python → Serial → Arduino → Relay → Appliance</pre>

<p><b>IoT Control:</b></p>
<pre>Mobile App → Sinric Pro → ESP8266 → Relay → Appliance</pre>

<h3>💡 Why Arduino + ESP8266?</h3>

<ul>
  <li>Arduino → Fast hardware control</li>
  <li>ESP8266 → WiFi + cloud handling</li>
  <li>Better performance and modularity</li>
</ul>

---

<h2>🖼️ Architecture Diagram</h2>

<pre>
&lt;img src="docs/images/architecture.png" width="700"/&gt;
</pre>

---

<h2>🔌 Hardware Components</h2>

<table border="1" cellpadding="8">
<tr><th>Component</th><th>Quantity</th></tr>
<tr><td>Arduino Uno</td><td>1</td></tr>
<tr><td>ESP8266 (ESP-12E)</td><td>1</td></tr>
<tr><td>Power Modules</td><td>2</td></tr>
<tr><td>4-Channel Relay</td><td>1</td></tr>
<tr><td>2-Channel Relay</td><td>1</td></tr>
<tr><td>Jumper Wires</td><td>~20</td></tr>
<tr><td>LED Bulbs</td><td>6</td></tr>
<tr><td>LED Strip</td><td>1</td></tr>
</table>

---

<h2>💻 Software Tools</h2>

<ul>
  <li>Visual Studio Code</li>
  <li>PlatformIO</li>
  <li>Python (3.10.11)</li>
  <li>OpenCV</li>
  <li>MediaPipe</li>
  <li>Sinric Pro</li>
</ul>

---

<h2>🛠️ Installation</h2>

<h3>🔧 Setup</h3>

<ol>
  <li>Install VS Code</li>
  <li>Install PlatformIO</li>
  <li>Install Python 3.10</li>
  <li>Install extensions (Python + C/C++)</li>
</ol>

<h3>📦 Python Dependencies</h3>

<pre>pip install opencv-python mediapipe pyserial</pre>

---

<h2>🏗️ Setup Steps</h2>
<ol>
  <li>Build a small house model using cardboard, wood, or foam board.</li>
  <li>Install LED bulbs in each room to simulate real home appliances.</li>
  <li>Fix bulb holders properly and ensure safe placement of LEDs.</li>
  <li>Route all wiring outside the model to keep connections visible and organized.</li>
  <li>Label each room wire to avoid confusion during connections.</li>
  <li>Set up a power distribution system using power modules.</li>
  <li>Use Arduino Uno for handling gesture-based control logic.</li>
  <li>Use ESP8266 module for WiFi and IoT communication.</li>
  <li>Connect all room wires to the 4-channel relay module (COM and NO terminals).</li>
  <li>Ensure each relay channel corresponds to one room/device.</li>
  <li>Connect Arduino digital pins 8, 9, 10, and 11 to relay inputs I1, I2, I3, and I4.</li>
  <li>Connect relay VCC to 5V and GND to GND from the power module.</li>
  <li>Double-check all wiring connections before powering the circuit.</li>
  <li>Open Visual Studio Code on your system.</li>
  <li>Install PlatformIO extension inside VS Code.</li>
  <li>Install Python (version 3.10.11 recommended) and add it to system PATH.</li>
  <li>Install required VS Code extensions: Python and C/C++.</li>
  <li>Create a new project folder for gesture recognition.</li>
  <li>Open the project folder in VS Code.</li>
  <li>Create a Python virtual environment using:</li>
  <pre>python -m venv venv</pre>
  <li>Activate the virtual environment:</li>
  <pre>venv\Scripts\activate</pre>
  <li>Install required Python libraries:</li>
  <pre>pip install opencv-python mediapipe pyserial</pre>
  <li>Create a Python script file (e.g., <code>gesture.py</code>).</li>
  <li>Write or paste your OpenCV + MediaPipe hand tracking code.</li>
  <li>Implement gesture logic (e.g., fingers count → command mapping).</li>
  <li>Establish serial communication using PySerial.</li>
  <li>Set correct COM port and baud rate (e.g., 9600).</li>
  <li>Send control commands from Python to Arduino.</li>
  <li>Create a new PlatformIO project for Arduino.</li>
  <li>Select Arduino Uno board during project creation.</li>
  <li>Open <code>src/main.cpp</code> file.</li>
  <li>Write Arduino code to receive serial data.</li>
  <li>Map received commands to relay control (HIGH/LOW).</li>
  <li>Initialize serial communication using <code>Serial.begin(9600);</code>.</li>
  <li>Set relay pins as OUTPUT using <code>pinMode()</code>.</li>
  <li>Upload Arduino code using USB Type-B cable.</li>
  <li>Open Serial Monitor (optional for debugging).</li>
  <li>Run Python script to start gesture detection.</li>
  <li>Verify that gestures correctly turn ON/OFF LEDs.</li>
  <li>If not working, debug serial communication or wiring.</li>
  <li>Create a new PlatformIO project for ESP8266.</li>
  <li>Select appropriate ESP8266 board (e.g., ESP-12E).</li>
  <li>Go to Sinric Pro website and create an account.</li>
  <li>Create devices (switch type) inside Sinric Pro dashboard.</li>
  <li>Copy API Key, API Secret, and Device IDs.</li>
  <li>Paste credentials inside ESP8266 code.</li>
  <li>Add WiFi SSID and password in the code.</li>
  <li>Add Sinric Pro library in <code>platform.ini</code>.</li>
  <li>Write code to handle device ON/OFF callbacks.</li>
  <li>Connect ESP8266 relay module (2-channel) properly.</li>
  <li>Upload code to ESP8266.</li>
  <li>Ensure your WiFi network is 2.4 GHz.</li>
  <li>Open Sinric Pro mobile app.</li>
  <li>Test turning devices ON/OFF from the app.</li>
  <li>Verify that relays respond correctly.</li>
  <li>Integrate both systems (gesture + IoT).</li>
  <li>Test the complete system thoroughly.</li>
  <li>Fix any delay, misfire, or wiring issues.</li>
  <li>Finalize the project setup and ensure stable performance.</li>
</ol>

---

<h2>🎮 Usage</h2>

<ul>
  <li>✋ Control appliances using gestures</li>
  <li>📱 Use mobile app remotely</li>
  <li>🔄 Both systems work independently</li>
</ul>

---

<h2>⚡ Working Principle</h2>

<ul>
  <li>Camera captures gesture</li>
  <li>MediaPipe processes it</li>
  <li>Python sends serial command</li>
  <li>Arduino triggers relay</li>
  <li>ESP8266 handles IoT</li>
</ul>

---

<h2>🛠 Troubleshooting</h2>

<table border="1" cellpadding="8">
<tr><th>Problem</th><th>Solution</th></tr>
<tr><td>Camera not working</td><td>Check drivers</td></tr>
<tr><td>Serial error</td><td>Check COM port</td></tr>
<tr><td>Relay not working</td><td>Check wiring</td></tr>
<tr><td>ESP8266 issue</td><td>Use 2.4GHz WiFi</td></tr>
<tr><td>Sinric issue</td><td>Verify API keys</td></tr>
</table>

---

<h2>🔮 Future Improvements</h2>

<ul>
  <li>Edge AI (no Arduino)</li>
  <li>Voice assistant integration</li>
  <li>Custom mobile app</li>
  <li>PCB design</li>
</ul>

---

<h2>⚠️ Safety</h2>

<ul>
  <li>Check voltage before powering</li>
  <li>Avoid short circuits</li>
  <li>Use proper insulation</li>
</ul>

---

<h2>📊 Learning Outcomes</h2>

<ul>
  <li>Embedded Systems</li>
  <li>IoT Development</li>
  <li>Computer Vision</li>
  <li>Hardware Integration</li>
</ul>

---

<h2>🏁 Conclusion</h2>

<p>
This project combines <b>Computer Vision and IoT</b> to build a smart automation system that is real-time, scalable, and remotely accessible.
</p>

---

<h2>⭐ Support</h2>

<p>If you like this project, give it a ⭐ on GitHub.</p>
