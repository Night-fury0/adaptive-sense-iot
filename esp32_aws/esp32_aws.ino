#include <Arduino_BuiltIn.h>
#include "aws_utils.h"
#include "ultrasonic_utils.h"
#include <PubSubClient.h>

const int trigPin = 2;
const int echoPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  connectAWS();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  long cm = ultrasonic_ping(trigPin, echoPin);
  publishMessage(cm);
  delay(1000);
  client.loop();

}
