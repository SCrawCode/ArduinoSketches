// SG90 Microservo sweep test motion
#include<Servo.h>

// Initializes servo object 
Servo servoTemp;

int pos = 0; // Initializes servo position

void setup() {
 servoTemp.attach(9);   // Attaches servos to pin 9 
}

void loop() {
 // Sweeps 180 degrees in increments of 1
  for (pos = 0; pos <= 180; pos += 1) {
  servoTemp.write(pos);
  delay(15);
 }

 // Sweeps back to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
   servoTemp.write(pos);
   delay(15); 
  }
  
}

