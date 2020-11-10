// Main code for IFWS 
#include<Servo.h>

// Initializes Servo Object 
Servo servo1;
Servo servo2;

int posUp = 0;
int posDown = 90;


// Initializes Ultrasonic Sensors
const int trigPinR = 10; // Right Sensor
const int echoPinR = 12; 

const int trigPinL = 11; // Left Sensor
const int echoPinL = 13;

long timeR, distR, timeL, distL;

// Initializes LED Array
int data_pin1 = 8;
int clock_pin1 = 9;
int latch_pin1 = 10;
int data_pin2 = 
int clock_pin2 = 
int latch_pin2 =

// Initializes Water Level Sensors
int sensor;

void setup() {
 servo1.attach(5); // Attaches servo 1 to pin 5
 servo2.attach(6); // Attaches servo 2 to pin 6
 
 //Shift Regiter (LED Array) Setup
 pinMode(data_pin1, OUTPUT);
 pinMode(clock_pin1, OUTPUT);
 pinMode(latch_pin1, OUTPUT);
 pinMode(data_pin2, OUTPUT);
 pinMode(clock_pin2, OUTPUT);
 pinMode(latch_pin2, OUTPUT);
 
 // Ultrasonic Sensor GPIO Init
 pinMode(trigPinR, OUTPUT);
 pinMode(trigPinL, OUTPUT);
 pinMode(echoPinR, INPUT);
 pinMode(echoPinL, INPUT);
 Serial.begin(9600);
}

void SR04() {
  // Rigth HC-SR04
 digitalWrite(trigPinR, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPinR, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPinR, LOW);
 pinMode(echoPinR, INPUT);
 timeR = pulseIn(echoPinR, HIGH);
 distR = (timeR / 2) / 29.1;
 
 // Left HC-SR04
 digitalWrite(trigPinL, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPinL, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPinL, LOW);
 pinMode(echoPinL, INPUT);
 timeL = pulseIn(echoPinL, HIGH);
 distL = (timeL / 2) / 29.1;
  
}

void SG90UP(int up) {
 servo1.write(up);
 servo2.write(up);
}

void SG90DN(int down) {
 servo1.write(down);
 servo2.write(down); 
}

void ledArray1(byte Data) {
  digitalWrite(latch_pin1, LOW);
  shiftOut(data_pin1, clock_pin1, LSBFIRST, Data);
  digitalWrite(latch_pin1, HIGH);
}
void ledArray2(byte Data) {
  digitalWrite(latch_pin2, LOW);
  shiftOut(data_pin2, clock_pin2, LSBFIRST, Data);
  digitalWrite(latch_pin2, HIGH);
}

void WaterSensor() {
 sensor = analogRead(A0);
 Serial.println(sensor);

 delayMicroseconds(5);
}

void loop() {
 
 ledArray(B11111111); 
 SR04();
 
   WaterSensor();

   if (sensor > 600) {
      ledArray(B10111101); 
      SG90DN(posDown);
   }
 
 delay(3000);
 
 Serial.print(distR);
 Serial.print("cm (Right) ");
 Serial.print(distL);
 Serial.print("cm (Left)");
 Serial.println();
 delay(3000);
 
 if (sensor < 600) {
  ledArray(B01111110);
  SG90UP(posUp);
 }
 
 delay(5000);
}


