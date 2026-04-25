#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>

#define DHTPIN 2     
#define DHTTYPE DHT11
#define MQ_PIN A0     

DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// WiFi Credentials
const char* ssid = "User_Id_Name";
const char* password = "Wifi_Password";

// ThingSpeak Credentials
unsigned long myChannelNumber = CHANNELNUMBER;
const char* myWriteAPIKey = "APIKEY";
WiFiClient client;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");

    ThingSpeak.begin(client);
    dht.begin();
    
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        while (1);
    }
    display.clearDisplay();
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int airQuality = analogRead(MQ_PIN);

    // Determine Air Quality Status
    String airQualityStatus;
    if (airQuality < 200) {
        airQualityStatus = "Good";
    } else if (airQuality < 500) {
        airQualityStatus = "Moderate";
    } else {
        airQualityStatus = "Poor";
    }

    // Display Data on OLED
    display.clearDisplay();
    
    // Centered Title: "Air Quality Monitor"
    display.setTextSize(1);
    display.setTextColor(WHITE);
    int16_t x, y;
    uint16_t width, height;
    display.getTextBounds("Air Quality Monitor", 0, 0, &x, &y, &width, &height);
    display.setCursor((SCREEN_WIDTH - width) / 2, 0);  // Centered title
    display.print("Air Quality Monitor");

    // Display Sensor Readings
    display.setCursor(0, 15);
    display.print("Temp: "); display.print(temperature); display.println(" C");

    display.setCursor(0, 30);
    display.print("Humidity: "); display.print(humidity); display.println(" %");

    display.setCursor(0, 45);
    display.print("Air Quality: "); display.print(airQuality);

    // Display Air Quality Status at Bottom
    display.setCursor(0, 55);
    display.print("Status: "); display.print(airQualityStatus);
    
    display.display();

    // Send Data to ThingSpeak
    ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, humidity);
    ThingSpeak.setField(3, airQuality);

    int response = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if (response == 200) {
        Serial.println("Data sent to ThingSpeak successfully.");
    } else {
        Serial.print("Error sending data: "); Serial.println(response);
    }

    delay(20000); // Wait 20 seconds before sending new data
}
