// Main code for IFWS (Currently only has servo control (Adding HCsr04))
#include<Servo.h>

// Initializes Servo Object 
Servo servo1;
Servo servo2;

// Initializes Ultrasonic Sensors
const int trigPinR = 2; // Right Sensor
const int echoPinR = 3; 

const int trigPinL = 12; // Left Sensor
const int echoPinL = 11;

long timeR, timeL, cmR, cmL;

// Initializes LED Array
const int Red = 10;
const int Green = 9;

// Initializes Water Level Sensors

int pos = 0; // Initializes servo position

void setup() {
 servo1.attach(9); // Attaches servo 1 to pin 9 
 servo2.attach(10); // Attaches servo 2 to pin 10
 
 pinMode(Red, OUTPUT); // Test LED OUTPUT
 pinMode(Green, OUTPUT); 
 
 // Ultrasonic Sensor GPIO Init
 pinMode(trigPinR, OUTPUT);
 pinMode(trigPinL, OUTPUT);
 pinMode(echoPinR, INPUT);
 pinMode(echoPinL, INPUT);
 Serial.begin(9600);
}

void loop() {
// Command that tells ultrasonic sensors to begin echo tracking
 digitalWrite(trigPinR, LOW);
 digitalWrite(trigPinL, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPinR, HIGH);
 digitalWrite(trigPinL, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPinR, LOW);
 digitalWrite(trigPinL, LOW);
 
 // Calculates Echo Time
 pinMode(echoPinR, INPUT);
 pinMode(echoPinL, INPUT);
 timeR = pulseIn(echoPinR, HIGH);
 timeL = pulseIn(echoPinL, HIGH);
 
 // Converts Time to Distance
 cmR = (timeR/2) / 29.1;
 cmL = (timeL/2) / 29.1;
 
 if (cmR <= 5 || cmL <= 5) {
  digitalWrite(Red, HIGH);
  delay(50);
  digitalWrite(Red, LOW);
  delay(50);
  digitalWrite(Red, High);
 }
 else {
  digitalWrite(Red, HIGH);
  digitalWrite(Green, HIGH);
 }
 
 delay(3000);
}

