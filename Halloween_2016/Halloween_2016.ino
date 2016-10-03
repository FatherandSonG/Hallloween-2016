/*
 * Halloween 2016 Music, SFX and Lights for Skull Head
 * Robin and Finley Gambin
 */

#include <arduino.h> //not sure if I need this one or if it is there by default

const int eyes = 2; //dio for eyes
const int head = 3; //dio for servo
const int music = 4; //dio for music
const int sfx1 = 5; //dio sound fx 1
const int sfx2 = 6; //dio sound fx 2
const int sfx3 = 7; //dio sound fx 2
const int detect1 = 8; //dio for detect sensor 1
const int detect2 = 9; //dio for detect sensor 2
const char a = "LOW";
const char b = "HIGH";

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(eyes,OUTPUT);
  pinMode(head,OUTPUT); 
  pinMode(music,OUTPUT);
  pinMode(sfx1,OUTPUT);
  pinMode(sfx2,OUTPUT);
  pinMode(sfx3,OUTPUT);
  pinMode(detect1,INPUT);
  pinMode(detect2,INPUT);
  
}

void loop() 
{
 if(digitalRead(detect1) == HIGH)
{
 // move head right and flash lights code here. Probably add for loop.
 digitalWrite(eyes,b);
 digitalWrite(sfx1,a);
 digitalWrite(head,b);
}
 else if (digitalRead(detect2)==HIGH)
{
void head_left();
}
 else 
{
//Just play music file here
digitalWrite(music,a);
}
}


void head_left(void)
{
int i=0;
//move head left and flash lights code here
 digitalWrite(sfx2,a);
 digitalWrite(head,a);
 for (i=0;i>=15;i++)
{
 digitalWrite(eyes,b);
 delay(100);
 digitalWrite(eyes,a);
}
 digitalWrite(head,a);
}

