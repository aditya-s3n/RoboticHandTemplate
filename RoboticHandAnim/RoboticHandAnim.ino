/*

*/
#include <Servo.h>
//init all servos
Servo indexFinger;
Servo middleFinger;
Servo ringFinger;
Servo pinkieFinger;
Servo thumbFinger;
Servo fingerServos[5] = {indexFinger, middleFinger, ringFinger, pinkieFinger, thumbFinger};

//init degrees of turning
int startTurn = 0;
int endTurn = 180;
int interval = 2;
int delay_interval = 10;

//init potentiometer
int potentiometer_pin = 0;
int value_poteniometer;


//function to run each Servo
void contractFingers(int value) {
  fingerServos[0].write(value);
  fingerServos[1].write(value);
  fingerServos[2].write(value);
  fingerServos[3].write(value);
  fingerServos[4].write(value);
}

void setup() {
  fingerServos[0].attach(8);
  fingerServos[1].attach(9);
  fingerServos[2].attach(10);
  fingerServos[3].attach(11);
  fingerServos[4].attach(12);

  fingerServos[0].write(0);
  fingerServos[1].write(0);
  fingerServos[2].write(0);
  fingerServos[3].write(0);
  fingerServos[4].write(0);
}

void loop() {
  value_poteniometer = analogRead(potentiometer_pin);
  value_poteniometer = map(value_poteniometer, 0, 1023, 0, 180); //scale from 1023 to 180

  contractFingers(value_poteniometer);
}