const int trigPin = 3;
const int echoPin = 2;

// Duration and measurment values (Don't use int, it's not accurate)
long duration, cm, inches;

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
}

void loop() {
 // Sends the high and low signals to bounce off objects
 digitalWrite(trigPin, LOW);
 delayMicroseconds(5);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 
 digitalWrite(trigPin, LOW);
 
 // Method that takes the echoPins' high input an measures how long it took
 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH);
 
 // Converts travel duration into distances
 cm = (duration/2) / 29.1;
 inches = (duration/2) / 74;
 
 // Prints measured values into serial monitor 
 Serial.print(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
 
 // Delay function that stops measurment for 1 second
 delay(1000);
  
  
}
