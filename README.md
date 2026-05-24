<p align="center">
  <img src="robot.png" alt="Line Following Robot Chassis" width="500">
</p>

# Line-Follower-Robot
An autonomous 2-wheel drive (2WD) robotic rover built using an Arduino Uno controller and infrared (IR) sensor modules to detect and track paths.

## 🏆 About
This project was developed during the **IEEE Region 10 Robotics Competition – Stage 1 Workshop**.
* **Organizers:** IEEE Kerala Section, IEEE LINK, & IEEE RAS Kerala Chapter
* **Venue:** Government College of Engineering, Kannur
* **Timeline:** April 2024

---

## ⚙️ How It Works
The robot automatically follows a black line on a white surface using a differential tracking method:
1. **Detection:** Front-mounted IR sensors detect the line position by measuring surface reflectance.
2. **Processing:** The sensors send real-time signals to the **Arduino UNO**.
3. **Correction:** The Arduino evaluates the path data and instantly adjusts the motor directions and speeds to keep the chassis perfectly on track.

---

## 🛠️ Components Used
* **Microcontroller:** Arduino UNO
* **Sensors:** 2x IR Sensors (Line detection array)
* **Motor Driver:** L298N Driver Module
* **Actuators:** 2x DC Geared Motors
* **Chassis:** 2WD Acrylic Robot Chassis
