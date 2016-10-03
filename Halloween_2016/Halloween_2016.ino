/*
 * Halloween 2016 Music and Lights for Skull Head
 * Robin and Finley Gambin
 */

#include <SD.h>
#include <SPI.h>
#include <MusicPlayer.h>
#include <arduino.h> //not sure if I need this one or if it is there by default

const int eyes = 2; //dio for eyes
const int head = 14; //dio for servo
char song = "Halloween.mp3";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  player.begin();
  player.playOne(song);
  pinMode(eyes,OUTPUT);
  pinMode(head,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  player.play();
  digitalWrite(eyes,HIGH);
  delay(250);
  digitalWrite(eyes,LOW);
}
