// Main code for IFWS (Currently only has servo control (Adding HCsr04))
#include<Servo.h>

// Initializes servo object 
Servo servo1;
Servo servo2;

// Initial 

int pos = 0; // Initializes servo position

void setup() {
 servo1.attach(9); // Attaches servo 1 to pin 9 
 servo2.attach(10); // Attaches servo 2 to pin 10
}

void loop() {
 // Sweeps 180 degrees in increments of 1
  for (pos = 0; pos <= 90; pos += 1) {
  servo1.write(pos);
  servo2.write(pos);
  delay(15);
 }

 // Sweeps back to 0 degrees
 // for (pos = 90; pos >= 0; pos -= 1) {
 //  servo1.write(pos);
 //  servo2.write(pos);
 //  delay(15); 
 //}
  
}

