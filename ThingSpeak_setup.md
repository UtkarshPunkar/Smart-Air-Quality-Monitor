# 📡 ThingSpeak Setup Guide for Smart Air Quality Monitor

This guide explains how to create and configure a ThingSpeak channel to receive data from your ESP8266-based Air Quality Monitoring device.

---

## ✅ Step 1: Create a ThingSpeak Account

1. Go to [https://thingspeak.com](https://thingspeak.com)
2. Click on **Sign Up** and create a free account (or **Sign In** if you already have one)
3. Once logged in, go to **Channels > My Channels > New Channel**

---

## 🧱 Step 2: Create a New Channel

1. Name your channel: `Smart Air Quality Monitor`
2. Check these **Fields**:
   - ✅ Field1: Temperature (°C)
   - ✅ Field2: Humidity (%)
   - ✅ Field3: Air Quality (Analog Value from MQ135)

3. (Optional) Add a description and tags like:  
   `"ESP8266, DHT11, MQ135, IoT, Air Quality"`

4. Click **Save Channel**

---

## 🔑 Step 3: Get Your Write API Key

After saving:
- Go to your **Channel View**
- Click **API Keys** tab (top menu)
- Copy your **Write API Key** — this key allows your ESP8266 to send data

You'll need to paste this into your Arduino code here:
```cpp
String apiKey = "YOUR_API_KEY";  // Replace with your Write API Key
