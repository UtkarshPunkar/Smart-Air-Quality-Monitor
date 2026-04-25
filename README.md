# 🌫️ Smart Air Quality Monitor using ESP8266, DHT11, MQ135, and OLED.

A DIY IoT project that monitors temperature, humidity, and air quality using ESP8266 and displays the data on an OLED screen. It also sends live data to [ThingSpeak](https://thingspeak.com) for remote tracking and visualization.

---

## 📦 Features:

- 🌡️ Real-time Temperature & Humidity
- 🌬️ Air Quality Monitoring (via MQ135/MQ2)
- 📺 OLED Display Output
- ☁️ Cloud Data Upload to ThingSpeak.
- 🚨 (Optional) Buzzer or LED for Alerts.

---

## 🔩 Hardware Components:

| Component         | Description                  |
|------------------|------------------------------|
| ESP8266 NodeMCU   | Wi-Fi microcontroller        |
| DHT11 Sensor      | Temperature & Humidity       |
| MQ135 Sensor      | Air Quality (Gas Detector)   |
| OLED Display (I2C)| 0.96" 128x64 Display         |
| Breadboard & Wires| Connections                  |
| Buzzer/LED (opt.) | Alerts for air quality       |

---

### 📌 Pin Connections:

| Component   | ESP8266 Pin  |
|-------------|--------------|
| DHT11 Data  | D4 (GPIO2)   |
| MQ135 A0    | A0           |
| OLED SDA    | D2 (GPIO4)   |
| OLED SCL    | D1 (GPIO5)   |
| VCC         | 3.3V         |
| GND         | GND          |

---

## ⚙️ How It Works:

1. ESP8266 reads data from DHT11 and MQ135 sensors
2. Displays the live values on OLED
3. Sends temperature, humidity & air quality to ThingSpeak channel via WiFi
4. (Optional) Buzzer or LED turns on if air quality is poor.

---

## 🖥️ Software & Libraries:

- **Arduino IDE**
- **Libraries Needed**:
  - `Adafruit_SSD1306`
  - `Adafruit_GFX`
  - `DHT sensor library`
  - `ESP8266WiFi`

---

## 📶 ThingSpeak Setup:

1. Sign up at [ThingSpeak](https://thingspeak.com).
2. Create a new channel with 3 fields:
   - Field1: Temperature
   - Field2: Humidity
   - Field3: Air Quality
3. Copy the **Write API Key** and **Channel ID**
4. Paste these into the Arduino code.

For detailed steps, see [docs/ThingSpeak_setup.md](docs/ThingSpeak_setup.md).

---

## 🧠 Code Overview:

Code is inside the `code/` folder:

- Connects to WiFi
- Reads from sensors
- Displays on OLED
- Sends data to ThingSpeak every 15 seconds

---

## 🛠️ How to Upload Code:

1. Open `.ino` file in Arduino IDE
2. Select the board: **NodeMCU 1.0 (ESP8266)**
3. Select the correct COM port
4. Click **Upload**
5. Open Serial Monitor to debug

---

## 📄 License:

This project is licensed under the MIT License.  
Feel free to use, modify, and share!

---

## 🙎‍♂️ Author

Utkarsh Punkar.

test yolo
---

