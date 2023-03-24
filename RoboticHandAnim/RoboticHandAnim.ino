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
int startTurn = 40;
int endTurn = 140;
int interval = 2;

//function to run each Servo
void contractFinger(Servo &fingerObject) { // pass by pointer
  // 40 to 140 degrees
  for (int position = startTurn; position <= endTurn; position += interval)
  {
    fingerObject.write(position);
    delay(15); //milliseconds
  }

  // 140 to 40 degrees
  for (int position = endTurn; position >= startTurn; position -= interval)
  {
    fingerObject.write(position);
    delay(15); //milliseconds
  }

}

void setup() {
  //setup servo ports in digital input arduino
  for (int i = 0; i < 5; i++) {
    fingerServos[i].attach(i + 8);
  }
}

void loop() {
  // go through servo array
  for (int i = 0; i < sizeof(fingerServos); i++) {
    contractFinger(fingerServos[i]); // runs the finger for each
  }
}
