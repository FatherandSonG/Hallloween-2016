/*
 * Skeleton Head Movement 2016 MMovement for Skull Head
 * Robin and Finley Gambin
 */

#include <arduino.h> //not sure if I need this one or if it is there by default
#include <Stepper.h> //stepper motor library

# define STEPS_PER_MOTOR_REV 32
# define STEPS_PER_OUTPUT_REV 32 * 64 //internal shaft * gear ratio = 2048

Stepper small_stepper(STEPS_PER_MOTOR_REV, 10,12,11,13);

int Steps2Take=512;
int photo_detect = 7; //dio for detect sensor 1

void setup() 
{
  // Setup ports
  Serial.begin(9600); //remove this later?
  pinMode(photo_detect,INPUT);
  }

void loop() 
{
 if(digitalRead(photo_detect) == HIGH)
  {
  	head_move();
  	}
   else 
  {
    head_move();
  }
}

void head_move()
{
  small_stepper.setSpeed(700);   
  small_stepper.step(Steps2Take);
  Steps2Take = -Steps2Take;
}

