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
int interval = 2;
int delay_interval = 10;

//init potentiometer
int potentiometer_pin = 0;
int value_poteniometer;


//function to run each Servo
void contractFinger(Servo fingerObject, bool directionOpposite = false, int startTurn = 0, int endTurn = 180) {
  if (directionOpposite) {
    // 180 to 0 degrees
    for (int position = endTurn; position >= startTurn; position -= interval)
    {
      fingerObject.write(position);
      delay(delay_interval); //milliseconds
    }

    // 0 to 180 degrees
    for (int position = startTurn; position <= endTurn; position += interval)
    {
      fingerObject.write(position);
      delay(delay_interval); //milliseconds
    }
  }

  else {
    // 0 to 180 degrees
    for (int position = startTurn; position <= endTurn; position += interval)
    {
      fingerObject.write(position);
      delay(delay_interval); //milliseconds
    }

    // 180 to 0 degrees
    for (int position = endTurn; position >= startTurn; position -= interval)
    {
      fingerObject.write(position);
      delay(delay_interval); //milliseconds
    }
  }
}

void setup() {
  fingerServos[0].attach(8);
  fingerServos[1].attach(9);
  fingerServos[2].attach(10);
  fingerServos[3].attach(11);
  fingerServos[4].attach(12);

  // fingerServos[0].write(180);
  // fingerServos[1].write(0);
  // fingerServos[2].write(180);
  // fingerServos[3].write(0);
  // fingerServos[4].write(0);
}

void loop() {
  
  
  //completed
  contractFinger(middleFinger, false, 0, 120); // middle
  contractFinger(ringFinger, true, 20, 300); // ring
  contractFinger(indexFinger, false, 0, 120); // index
  
  contractFinger(pinkieFinger, false, 0, 180); // pinkie
  contractFinger(thumbFinger, false, 0, 180); // thumb
}