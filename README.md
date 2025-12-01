# IoT Smart Door Lock System using ESP32 & Blynk

![Status](https://img.shields.io/badge/Status-Active-success)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![IoT](https://img.shields.io/badge/IoT-Blynk-green)

A wireless door lock automation system built with the ESP32 microcontroller. This project allows users to remotely lock and unlock a door using the Blynk mobile application, featuring real-time status feedback via an LCD display and Serial Monitor.

## 🌟 Features

* **Remote Control:** Lock/Unlock mechanism controlled via Blynk IoT Cloud (Web & Mobile).
* **Visual Feedback:** 16x2 I2C LCD displays current status ("OPENED" or "CLOSED").
* **Power Efficiency:** Servo motor detaches after movement to reduce power consumption and jitter.
* **Status Monitoring:** Real-time logging via Serial Monitor for debugging.
* **Fail-Safe:** Checks previous state before moving to prevent unnecessary servo actuation.

## 🛠️ Hardware Requirements

1.  **Microcontroller:** ESP32 Development Board (DOIT DEVKIT V1 or similar).
2.  **Actuator:** Servo Motor (SG90 Micro Servo or MG995 High Torque).
3.  **Display:** 16x2 LCD with I2C Interface Module.
4.  **Power Supply:** 5V USB or External Battery.
5.  **Connectivity:** Jumper wires and Breadboard.

## 🔌 Pin Configuration

| Component | Pin | ESP32 GPIO |
| :--- | :--- | :--- |
| **Servo Signal** | PWM | GPIO 4 |
| **LCD SDA** | SDA | GPIO 21 (Default) |
| **LCD SCL** | SCL | GPIO 22 (Default) |
| **VCC/GND** | Power | 5V / GND |

## 💻 Software & Libraries

To compile this project, you need the **Arduino IDE** with the **ESP32 Board Manager** installed.

### Required Libraries:
1.  **Blynk:** `BlynkSimpleEsp32.h`
2.  **ESP32Servo:** `ESP32Servo.h`
3.  **LiquidCrystal I2C:** `LiquidCrystal_I2C.h`

*Install these via the Arduino Library Manager (Sketch > Include Library > Manage Libraries).*

## ⚙️ Blynk Setup

1.  Create a new Template in the Blynk Console.
2.  Create a **Datastream**:
    * **Name:** Door Switch
    * **Pin:** Virtual Pin **V0**
    * **Data Type:** Integer
    * **Min/Max:** 0/1
3.  Create a Web/Mobile Dashboard and add a **Switch Widget** linked to **V0**.
4.  Copy your `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN`.

## 🚀 Installation

1.  Clone this repository:
    ```bash
    git clone [https://github.com/your-username/esp32-door-lock.git](https://github.com/your-username/esp32-door-lock.git)
    ```
2.  Open the `.ino` file in Arduino IDE.
3.  Update the credentials in the code:
    ```cpp
    char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
    char ssid[] = "YOUR_WIFI_SSID";
    char pass[] = "YOUR_WIFI_PASSWORD";
    ```
4.  Connect your ESP32 and select the correct Board and Port.
5.  Upload the code.

## 📸 Usage

1.  Power up the ESP32. The LCD will show "Connecting WiFi...".
2.  Once connected, the LCD will show "Status: Closed".
3.  Open the Blynk App and toggle the Switch (V0).
    * **ON (1):** Servo moves to 90° (Unlock), LCD shows "OPENED".
    * **OFF (0):** Servo moves to 0° (Lock), LCD shows "CLOSED".

## 🔮 Future Improvements

* Add a physical keypad for password entry backup.
* Integrate a buzzer for audio feedback.
* Implement MQTT protocol for Home Assistant integration.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

## 📜 License

[MIT](https://choosealicense.com/licenses/mit/)
