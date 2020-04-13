#include "HC_SR04.h"

double cm = 0.0;

int trigPin = D4;
int echoPin = D5;
int LED = D7;



HC_SR04 rangefinder = HC_SR04(trigPin, echoPin);

void setup() 
{

    pinMode(LED,OUTPUT);
}

void loop() 
{   
    digitalWrite(LED,HIGH);
    

    String distance = String(rangefinder.getDistanceCM());
    Particle.publish("distance",distance,PRIVATE);

    delay(30000);
    
    digitalWrite(LED,LOW);
    delay(30000);
    
}
