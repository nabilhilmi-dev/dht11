#define BLYNK_PRINT Serial

#include <DHT.h>

#include <ESP8266WiFi.h> // file untuk model wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk

char auth[] =  "BBFF-JJm98gGJwaUGrdLkxjZ6npNrTXicfs";
char ssid[] = "TytydMeongs";
char pass[] = "siniguabisikin";

#define DHTPIN 14
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read temp and humidity");
    return;
  }

  Blynk.virtualWrite(V1, t); //setting virtual suhu di blynk
  Blynk.virtualWrite(V2. h); //setting virtual kelembapan di blynk
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, pass, ssid)
  dht.begin(); //sensor mulai membaca suhu dan kelembapan
  timer.setInterval(1000, sendSensor); //waktu untuk mengirimkan data

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();

}
