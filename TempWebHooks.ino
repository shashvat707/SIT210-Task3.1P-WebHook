#include "DHT.h"
#define DHTPIN D2       
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);     // Initializing DHT sensor.

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {

  delay(2000);        // Wait a few seconds between temp reading
  float t = dht.readTemperature();      // Reads temp as Celsius (defualt)
  float f = dht.readTemperature(true);  // Reads tempe as Fahrenheit 

  // Gives error if no data is read from DHT
  if (isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // if user wish to print data on Serial Monitor
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  
  String temp = String(t);
  Particle.publish("temp", temp, PRIVATE);
  delay(2000);               
}