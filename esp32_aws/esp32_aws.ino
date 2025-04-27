#include <Arduino_BuiltIn.h>
#include "utils.h"
#include <PubSubClient.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  connectAWS();
}

void loop() {
  // put your main code here, to run repeatedly:
  int metricsValue = random(1,100);
  Serial.print(F("metrics"));
  Serial.print(metricsValue);
  
  publishMessage(metricsValue);
  
  client.loop();
  delay(1000);

}
