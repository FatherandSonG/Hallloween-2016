u/*
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
const char l = "LOW"; //state control
const char h = "HIGH"; //state control

void setup() 
{
  // Setup ports
  Serial.begin(9600); //remove this later?
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
		digitalWrite(music,h); // turn off music
    void head_left();  //call head movemnent and SFX fucntion
  }
  else if (digitalRead(detect2)==HIGH)
  {
    digitalWrite(music,h);
		void head_left();
  }
  else 
  {
    digitalWrite(music,a); //Play music if no motion detected
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
    digitalWrite(eyes,h);
    delay(250);
    digitalWrite(eyes,l);
    delay(250);
  }
	digitalWrite(eyes,l); //reset eyes
  digitalWrite(head,l); //reset head
}

