/*
 * Halloween 2016 Music, SFX and Lights for Skull Head
 * Robin and Finley Gambin
 */

#include <arduino.h> //not sure if I need this one or if it is there by default

int eyes = 2; //dio for eyes
int headlight1 = 3; //dio for headlight
int music = 4; //dio for music
int sfx1 = 5; //dio sound fx 1
int sfx2 = 6; //dio sound fx 2
int detect1 = 7; //dio for detect sensor 1
int detect2 = 8; //dio for detect sensor 2
//int head = 11; //dio for head
int time1;
int time2;
int time3;

void setup() 
{
  // Setup ports
  Serial.begin(9600); //remove this later?
  pinMode(eyes,OUTPUT);
  pinMode(headlight1,OUTPUT);
  pinMode(music,OUTPUT);
  pinMode(sfx1,OUTPUT);
  pinMode(sfx2,OUTPUT);
  pinMode(detect1,INPUT);
  pinMode(detect2,INPUT);
  }

void loop() 
{
 if(digitalRead(detect1) == HIGH)
  {
  	digitalWrite(music,HIGH); // turn off music
    head_left();  //call head movemnent and SFX fucntion
  }
  else if (digitalRead(detect2)==HIGH)
  {
    digitalWrite(music,HIGH);
		head_left();
  }
  else 
  {
    digitalWrite(music,LOW); //Play music if no motion detected
    digitalWrite(eyes,LOW); //just to make sure they are off
    digitalWrite(headlight1,LOW); //just to make sure they are off
    
  }
}


void head_left()
{
int i=0;
//move head left and flash lights code here. 4 seconds total
  time1=millis();
  digitalWrite(sfx1,LOW);
  digitalWrite(headlight1,HIGH);
  
  for (i=0;i<=15;i++)
  {
    digitalWrite(eyes,HIGH);
    delay(150);
    digitalWrite(eyes,LOW);
    delay(100);
  }
	digitalWrite(eyes,LOW); //reset eyes
  digitalWrite(headlight1,LOW); //reset headlight
  time2=millis();
  time3=(time2-time1);
  Serial.println(time3);
}

