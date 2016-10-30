/*
 * Halloween 2016 eyes, head and ambiance lights for Skull  
 * Robin and Finley Gambin
 */

#include <arduino.h> //not sure if I need this one or if it is there by default


int eyes = 3; //dio for eyes
int headlight1 = 9; //dio for headlight
int coffin_red = 5;
int coffin_white = 6;
int time1;
int time2;
int time3;
int a=0;
int coffin1=0;
int coffin2=0;
int interval=5000;
void setup() 
{
  // Setup ports
  Serial.begin(9600); //remove this later?
  pinMode(eyes,OUTPUT);
  pinMode(headlight1,OUTPUT);
  pinMode(coffin_red,OUTPUT);
  pinMode(coffin_white,OUTPUT);
  }

void loop() 
{
 
 time1=millis();
if ((time1-time2)>interval)
 {
  head_light();
  time2=millis();
  interval=random(5000,20000);
 }
 else
 {
 coffin1=random(50,255); //used to make the coffin lights flicker
 coffin2=random(50,255);
  
    analogWrite(eyes,0); //just to make sure they are off
    analogWrite(headlight1,0); //just to make sure they are off
    analogWrite(coffin_red,coffin1);
    analogWrite(coffin_white,coffin2);
    //analogWrite(headlight1,100); 
    delay(100); 
 } 
}


void head_light()
{
int i=0;
//flash lights code here. 4 seconds total
 // time1=millis();
    analogWrite(headlight1,coffin1);
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
  // delay(200); //delay to reset head
  time2=millis();
  time3=(time2-time1);
  //Serial.println("LED:");
 // Serial.println(time3);
}
