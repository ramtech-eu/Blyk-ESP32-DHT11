#define BLYNK_TEMPLATE_ID "id"
#define BLYNK_TEMPLATE_NAME "name"
#define BLYNK_AUTH_TOKEN "token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

DHT dht(4, DHT11);

char ssid[] = "name";
char pass[] = "pass";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    Blynk.virtualWrite(V0, temperature); // temp v0
    Blynk.virtualWrite(V1, humidity);    // hum v1
  }

  delay(2000);
}
