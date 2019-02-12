/*  DHT22 Sensor Temperature and Humidity
 */

#include "DHT.h"
#define dhtPin 7
#define dhtType DHT22
#define TRACE 1  // 0= off 1 = on

DHT dht(dhtPin, dhtType);

// Declare setup
void setup() {
  Serial.begin (9600);
  dht.begin();
}


// Main loop
void loop()
{
  delay(2000);
    // Send temperature and humidity
    tempandHumidity();
}

// Reading value of temperature and humidity from DHT22
void tempandHumidity(){
  digitalWrite(dhtPin, HIGH);
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  if (isnan(humidity) || isnan(temp)) {
    trc("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
  }
}

// Trace function
void trc(String msg){
  if (TRACE) {
  Serial.println(msg);
  }
}
