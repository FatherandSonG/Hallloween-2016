 /*
 * Skeleton Head Movement and sound fxs
 * Halloween 2016
 * Code was written for Arduino UNO, Adafruit Sound FX Board 16MB 
 * with HC-SR04 for trick or treater detection.
 * Uses a generic stepper motor to drive the head.
 * Robin and Finley Gambin
 */

#include <arduino.h>
#include <Stepper.h> //stepper motor library

# define STEPS_PER_MOTOR_REV 32
# define STEPS_PER_OUTPUT_REV 32 * 64 //internal shaft * gear ratio = 2048 only applies to motor that came with the kit

Stepper small_stepper(STEPS_PER_MOTOR_REV, 10,12,11,13);

int Steps2Take=400; //steps to move from center to look of shoulder
int pingPin = 7; //trigger HC-SR04
int echoPin = 8; //return HC-SR04
const int a = 5000; //minimum distance to trigger
int head; //result of ping
int music=2; //play music
int sfx1=3; //play sound fx 1
int sfx2=4; //play sound fx 2
int sfx3=5; //play sound fx 3
int playing=6; //is sound still playing?

void setup() 
{
  // Setup ports and pins
  Serial.begin(9600); //remove this later?
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sfx1,OUTPUT);
  pinMode(sfx2,OUTPUT);
  pinMode(sfx3,OUTPUT);
  pinMode(music,OUTPUT);
  pinMode(playing,INPUT);
  }

void loop() 
{ 
  digitalWrite(sfx1,HIGH); //make sure sfx is off
  digitalWrite(sfx2, HIGH);
  digitalWrite(sfx3, HIGH);
  digitalWrite(music,LOW); //play music
  
  ping(); //check distance

 if((head) ==1)
  {
  	head_move(); //move head to the right
  	}
   else 
  {
   delay(100); //delay before next ping
  }
}

void head_move() //head move function
{
  int x=random(1,3); //pick random sound fx
  digitalWrite(music, HIGH); //turn off music
  small_stepper.setSpeed(500);   //move head to the right
  small_stepper.step(300);
  switch(x) //select sound fx based on random number x
 {
  case 1:
  digitalWrite(sfx1, LOW); //turn on sfx trigger
  delay(250); //wait for sound to start
  digitalWrite(sfx1,HIGH); //turn off sfx trigger
  break;
  case 2:
  digitalWrite(sfx1,LOW);
  delay(250);
 digitalWrite(sfx1,HIGH);
  break;
  case 3:
  digitalWrite(sfx1,LOW);
  delay(250);
  digitalWrite(sfx1,HIGH);
  break;
 }
 
do //wait for music to stop playing to reset head position
  {
   delay(100);
  } while (digitalRead(playing) == LOW);
  digitalWrite(music,LOW); //turn music on
  small_stepper.setSpeed(500); //reset head to center   
  small_stepper.step(-300);
}

void ping() //function to test distance
{
  long duration; //init variable for pulse duration
  digitalWrite(pingPin, LOW); //verify ping pin low
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH); //set ping pin high
  delayMicroseconds(8);
  digitalWrite(pingPin, LOW); //set ping pin low
  duration=pulseIn(echoPin, HIGH); //read echo pulse
  Serial.println(duration);
  if ((duration) < 5000) //if pulse duration is less than 5000 move head
  {
    head= 1;
  }
  else
  {
    head= 0;
  }
}

