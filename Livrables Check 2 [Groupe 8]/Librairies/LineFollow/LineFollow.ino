#include "Grove_I2C_Motor_Driver.h"

#include <Wire.h>

#define I2C_ADDRESS 0x0f

//Left turning step
void VirageAGauche(){
if  ((etatCapteurGauche) && (etatCapteurCentreG)){ //left rotation
    Motor.stop(MOTOR1);
   Motor.stop(MOTOR2);
   delay(500);
    Motor.speed(MOTOR1,0);
   Motor.speed(MOTOR2, 100);
   Serial.println("Tourner à gauche");
   delay(1000);
  }
}

//Right turning step
void VirageADroite(){
 if((etatCapteurDroit) && (etatCapteurCentreD)){ //right rotation
     Motor.stop(MOTOR1); //we stop the first motor
   Motor.stop(MOTOR2); //we stop the second motor
   delay(500); //giving a delay of 500ms
     Motor.speed(MOTOR1, -100); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
    Motor.speed(MOTOR2, 0); //as for as the second motor, it stayes at 0
   Serial.println("Tourner à droite");
   delay(950);
  }
}

//if we want to use the extremities we call the following steps (right and left one)
void SuperRight(){
    if((etatCapteurDroit) && (!etatCapteurCentreD))//if the center sensor detects
  {
   Motor.speed(MOTOR1, -100); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
   Motor.speed(MOTOR2, 0); //as for as the second motor, it stayes at 0
    delay(350);
  }
  }

  void SuperLeft(){
    if ((etatCapteurGauche) && (!etatCapteurCentreG)){//if the center sensor detects the white, the car runs
    Motor.speed(MOTOR1, 0); //our first motor will stop
   Motor.speed(MOTOR2, 10); //as for as the second motor, it has a speed of 10 
    delay(350); // the delay is 350ms
  }
  }

