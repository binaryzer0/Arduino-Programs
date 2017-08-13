#include "SevSeg.h"

#define trigPin 9
#define echoPin 10

long duration;
int distance;

SevSeg sevseg; //Initiate a seven segment controller object

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //pinMode(led, OUTPUT);
  //pinMode(led2, OUTPUT);


  // Light display
  

  byte numDigits = 3;
  byte digitPins[] = {12, 13, 11};
  byte segmentPins[] = {8, 6, 5, 4, 2, 7};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  sevseg.setNumber(8888);
  sevseg.refreshDisplay(); // Must run repeatedly
} 
