/*
 * Author:Luke Carlson
 * Reaction  Time Monitor
 */

//grnled
#include <list>
int grnled = D4;
//redled
int redled = D2;

int strtime;
int stptime;
int react;

int max = 0;
int min = 0;
int mean = 0;
int range = 0;

std::list<int> list1 = {};

void setup() { //Setup: ======================================================
  // Declare variables---------------
  //srtbut
  pinMode(D0, INPUT_PULLUP);
  //stpbut
  pinMode(D1, INPUT_PULLUP);
  //grnled
  pinMode(grnled, OUTPUT);
  //redled
  pinMode(redled, OUTPUT);
  //(Go ahead and light the red LED in setup)
  digitalWrite(D2, HIGH); //Turns light A0 on
  Serial.begin(9600);
}
//The green LED is lit when the time is going, the red when its stopped. Never at the same time.

void loop() { //Loop =========================================================
  //When srtbut pushed{
   int r = random(500, 5000);
  if(digitalRead(D0) == LOW){ //When srtbut pressed
      tone(A4, 600, 200);//Get ready sound
      delay(r);//Wait random amount of time:
      //-----------------------------------------
      digitalWrite(D2, LOW); //Stop redled
      digitalWrite(D4, HIGH); //Start grnled
      tone(A4, 900, 600);//Hit the button sound!
      strtime = millis();
      //Beep buzzer
      //Start timer
  }

  if(digitalRead(D1) == LOW){ //When stpbut pressed
      stptime = millis();
      digitalWrite(D2, HIGH); //Start redled
      digitalWrite(D4, LOW); //Stop grnled
      tone(A4, 1000, 100);//Timer reset sound
      //Print stptime-srttime to screen to find reaction time
      list.push_back(stptime-srttime);
      react = stptime-srttime;
      if (react > max)
        max = react;
      if (react < min)
        min = react;
      range = max-min;
      for (int n : list1) {

      }
      Serial.printf("Button was pressed after %d milliseconds\n", react);
      delay(500);
  }
}
