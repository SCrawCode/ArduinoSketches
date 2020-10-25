const int Red = 11;
const int Green = 10;

void setup() {
 pinMode(Red, OUTPUT);
 pinMode(Green, OUTPUT); 
  
}

void loop() {
 digitalWrite(Red, HIGH);
 delay(500);
 digitalWrite(Red, LOW);
 digitalWrite(Green, HIGH);
 delay(500);
 digitalWrite(Green, LOW); 
  
}
