/* Industrial Design and Physical Computing by:
 * Viraj Joshi  (http://virajvjoshi.com)
 * Matteo Bandi (http://matteobandidesign.com)
 * August 2018
 */


//Include standard servo library
#include <Servo.h>      

//Servos on the Hard Form: pins and position
int servoPinForm1 = 9;     
int servoPinForm2 = 8;
Servo ServoForm1;
Servo ServoForm2; 
int FormPos = 90;

//Servos on the Soft Tube: pins and position
int servoPinTube1 = 7;     
int servoPinTube2 = 6;      
Servo ServoTube1;
Servo ServoTube2;
int TubePos = 90;

//Initialising ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

//Initialise Versalume
int ledPin = 4;


void setup() {
  //Attaching all Servos
  ServoForm1.attach(9);
  ServoForm2.attach(8);
  ServoTube1.attach(7);
  ServoTube2.attach(6);
  Serial.begin(9600);
}

void loop(){
  long duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);

if (cm > 1 && cm < 20){
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);
  }
  loop1();
}

else if (cm > 20){
 for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
 }
  loop2();
}

}

void loop1() {
  long duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  //Moving Form Servos To
  if (FormPos > 85){
  for (FormPos = 90; FormPos > 0; FormPos--){
    ServoForm1.write(FormPos);
    ServoForm2.write(FormPos);
    ServoTube1.write(FormPos);
    ServoTube2.write(FormPos);
    delay(50);
  }
  }

Serial.println("Going down");
Serial.println(cm);
delay(1000);
}

void loop2() {
  long duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  //Moving Form Servos Fro
  if (FormPos < 5){
  for (FormPos = 0; FormPos < 90; FormPos++){
    ServoForm1.write(FormPos);
    ServoForm2.write(FormPos);
    ServoTube1.write(FormPos);
    ServoTube2.write(FormPos);
    delay(50); 
  }
Serial.println("Going up");
Serial.println(cm);
delay(1000);
}
}

long microsecondsToCentimeters(long microseconds) {
return microseconds / 29 / 2;
}

 
