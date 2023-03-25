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

//function to run each Servo
void contractFinger(Servo fingerObject, bool directionOpposite = false) {
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

  fingerServos[0].write(180);
  fingerServos[1].write(0);
  fingerServos[2].write(180);
  fingerServos[3].write(0);
  fingerServos[4].write(0);
}

void loop() {
  contractFinger(fingerServos[0], true); // index
  contractFinger(fingerServos[1]); // middle
  contractFinger(fingerServos[2], true); // ring
  contractFinger(fingerServos[3]); // pinkie
  contractFinger(fingerServos[4]); // thumb
}