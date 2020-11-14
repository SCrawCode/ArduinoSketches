// Main code for IFWS 
#include<Servo.h>

// Initializes Servo Object 
Servo servo1;
Servo servo2;

int posUp = 0;
int posDown = 90;

// Initializes Ultrasonic Sensors
const int trigPinR = 2; // Right Sensor
const int echoPinR = 3; 

const int trigPinL = 4; // Left Sensor
const int echoPinL = 5;

long timeR, distR, timeL, distL;

// Emergency LEDS
int LEDRedR = 7;
int LEDRedL = 9;
int LEDYellowR = 6;
int LEDYellowL = 8;

// Initializes Water Level Sensors
int sensor;

void setup() {
 servo1.attach(11); // Attaches servo 1 to pin 5
 servo2.attach(12); // Attaches servo 2 to pin 6
 

 pinMode(LEDRedR, OUTPUT);
 pinMode(LEDRedL, OUTPUT);
 pinMode(LEDYellowR, OUTPUT);
 pinMode(LEDYellowL, OUTPUT);
 
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



void eLEDY() {
  digitalWrite(LEDYellowR, HIGH);
  digitalWrite(LEDYellowL, HIGH);
  delay(500);
  digitalWrite(LEDYellowR, LOW);
  digitalWrite(LEDYellowL, LOW);
  delay(500);
}
void eLEDROn() {
  digitalWrite(LEDRedR, HIGH);
  digitalWrite(LEDRedL, HIGH);
}
void eLEDROff() {
  digitalWrite(LEDRedR, LOW);
  digitalWrite(LEDRedL, LOW);
}

void WaterSensor() {
 sensor = analogRead(A0);
 Serial.println(sensor);

 delayMicroseconds(5);
}

void loop() {
 
 SR04();
 
   WaterSensor();

   if (sensor > 600) {
      eLEDROn();
      delay(50);
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
   eLEDROff();
   eLEDY();
  SG90UP(posUp);
 }
 
 delay(5000);
}


