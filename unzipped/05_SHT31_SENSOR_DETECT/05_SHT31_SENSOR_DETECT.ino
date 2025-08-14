/*HANKERILA MODEL:HKL-ADI16  SHT31 SENSOR DETECT CODE(Temperature and Humidity)
HANKERILA CONTROLLER STORE : https://www.aliexpress.com/store/1103673574
*/
#include <Wire.h>
#include <Adafruit_SHT31.h>

#define SDA 4
#define SCL 5
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA, SCL);   //GPIO4-SDA GPIO5-SCL

// initialize the SHT3X sensor
  if (!sht31.begin(0x44)) {
    Serial.println("Could not find SHT3X sensor!");
    while (1);
  } else {
    Serial.println("SHT3X sensor found!");
  }
}

void loop() {
    
    float temperature_Celsius = sht31.readTemperature();
    // Convert Celsius to Fahrenheit
    float temperature_Fahrenheit = temperature_Celsius * 1.8 + 32;
    Serial.printf("Temperature is: %.2f°F\n", temperature_Fahrenheit);
    delay(1000);
    // Read humidity data (unit: %)
    float humidity = sht31.readHumidity();
    Serial.printf("Humidity is: %.2f%% \n", humidity);
    delay(1000);
}