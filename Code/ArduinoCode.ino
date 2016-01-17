
#include <Servo.h>

Servo myservo1;
Servo myservo2;

const int analogInPin = A5; 

const int analogOutPin11 = 11;
const int analogOutPin10 = 10;
const int analogOutPin9 = 9;
const int analogOutPin8 = 8;
const int analogOutPin7 = 7;
const int analogOutPin6 = 6;

int sensorValue = 0;
int outputValue = 0;

int pos = 0;    // variable to store the servo position
int state =0;
int dingetje = 0;

void setup() {
  for (int i=6;i<12;i++)
  {
    pinMode(i, OUTPUT); 
  }
  myservo1.attach(12);
  myservo2.attach(13);
} 

void updateLights(){
      sensorValue = analogRead(analogInPin);
      outputValue = map(sensorValue, 0, 1023, 0, 255);
      analogWrite(analogOutPin11, outputValue);
      analogWrite(analogOutPin6, outputValue);
      analogWrite(analogOutPin7, outputValue);
      analogWrite(analogOutPin8, outputValue);
      analogWrite(analogOutPin9, outputValue);
      analogWrite(analogOutPin10, outputValue);
}

void loop() {

  digitalWrite(10, HIGH); 
  updateLights();


   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      myservo2.write(pos);
      updateLights();
      delay(50);                       // waits 15ms for the servo to reach the position
    }
   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      myservo2.write(pos);
      updateLights();
      delay(50);                       // waits 15ms for the servo to reach the position
    }


}

