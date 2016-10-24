/*
 * Halloween 2016 Music, SFX and Lights for Skull Head
 * Robin and Finley Gambin
 */

#include <arduino.h> //not sure if I need this one or if it is there by default
#include "PinChangeInterrupt.h"

#define detect1 7

int eyes = 3; //dio for eyes
int headlight1 = 9; //dio for headlight
int coffin_red = 5;
int coffin_white = 6;
int music = 13; //dio for music
int sfx1 = 12; //dio sound fx 1
int sfx2 = 11; //dio sound fx 2
//int detect1 = 7; //dio for detect sensor 1
int detect2 = 8; //dio for detect sensor 2
int time1;
int time2;
int time3;
int a=0;
int coffin=0;

void setup() 
{
  // Setup ports
  Serial.begin(9600); //remove this later?
  pinMode(eyes,OUTPUT);
  pinMode(headlight1,OUTPUT);
  pinMode(music,OUTPUT);
  pinMode(sfx1,OUTPUT);
  pinMode(sfx2,OUTPUT);
  pinMode(detect1,INPUT_PULLUP); //enable internal pullup detect is on active low
  pinMode(detect2,INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(detect1), head_light, CHANGE);
}

void loop() 
{
 coffin=random(50,255); //used to make the coffin lights flicker
 
 if(digitalRead(detect1) == LOW)
  {
  	digitalWrite(music,HIGH); // turn off music
    head_light();  //call head light and SFX fucntion
  }
  else if (digitalRead(detect2)==LOW)
  {
    digitalWrite(music,HIGH);
		head_light();
  }
  else 
  {
    digitalWrite(music,LOW); //Play music if no motion detected
    digitalWrite(sfx1,HIGH);
    digitalWrite(sfx2,HIGH);
    analogWrite(eyes,0); //just to make sure they are off
    analogWrite(headlight1,0); //just to make sure they are off
    analogWrite(coffin_red,coffin);
    analogWrite(coffin_white,coffin);
    //analogWrite(headlight1,100); 
    delay(100); 
  }
}


void head_light()
{
int i=0;
//flash lights code here. 4 seconds total
  time1=millis();
  digitalWrite(sfx1,LOW);
  analogWrite(headlight1,coffin);
   for (int a=0; a<=255;a++)               //loop from 0 to 255
  {
        analogWrite(eyes, a);
        delay(8);                             //wait for 8 milliseconds    
               
  }
    for (int a=255; a>=0;a--)             //loop from 255 down to 0
  {
    analogWrite(eyes, a);               // set the brightness of pin 9:
       delay(8);                             //wait for 8 milliseconds   
  }
 	analogWrite(eyes,10); //reset eyes
  digitalWrite(sfx1,HIGH);
 // delay(200); //delay to reset head
  time2=millis();
  time3=(time2-time1);
  //Serial.println("LED:");
 // Serial.println(time3);
}
