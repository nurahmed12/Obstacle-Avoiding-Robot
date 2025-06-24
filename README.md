<h1 align="center">Arduino Obstacle-Avoiding Robot</h1>
<p align="center"><em>An autonomous Arduino robot that detects and avoids obstacles using ultrasonic sensing and servo-mounted scanning</em></p>

---

## 🧩 Project Overview

The **Arduino Obstacle-Avoiding Robot** drives forward until it senses an object within a set distance, then stops, sweeps its ultrasonic sensor left and right on a servo, and intelligently turns left, right, or executes a 180° pivot to navigate around obstacles in real time.

---

## 🎮 Features

- 🔊 **Ultrasonic Sensing**: Measures distance ahead and triggers avoidance when too close  
- 🤖 **Servo-Mounted Scanner**: Rotates sensor to compare left/right distances for optimal path  
- 🔄 **Adaptive Navigation**: Moves forward, turns left/right, or performs U-turns based on scanned data  
- 🛠️ **Modular Design**: Easily swap motors, sensors, or chassis components  
- ⚙️ **Configurable**: Adjust `SET_DISTANCE` and motor speeds directly in code  

---

## 🚀 How to Run

1. **Clone the repository**  
   ```bash
   git clone https://github.com/nurahmed12/Obstacle-Avoiding-Robot.git
2. **Open the sketch**
In Arduino IDE: File → Open → obstacle_avoiding_robot.ino

3. **Install libraries**
Use Library Manager to install Adafruit Motor Shield V1

4. **Wire the components**

- Ultrasonic Sensor: TRIG → A5, ECHO → A0, VCC → 5V, GND → GND

- Servo: Signal → D10, VCC → 5V, GND → GND

- Motors: M1–M4 on the Motor Shield

5. **Upload & Test**

- Select the correct board/port in Arduino IDE

- Click Upload

- Power the motors via the shield’s external supply

Place the robot on a flat surface and watch it avoid obstacles!

⚠️ Ensure your power supply can handle both the Arduino and the motors to prevent voltage drops during operation.
