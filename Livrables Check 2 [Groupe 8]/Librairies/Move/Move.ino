#include "Grove_I2C_Motor_Driver.h"

#include <Wire.h>

#include "LineFollow.h"

#define I2C_ADDRESS 0x0f

//we declare our function named moving
  void Moving(){
  
    if((!etatCapteurCentreG) && (!etatCapteurCentreD) && (!etatCapteurDroit) && (!etatCapteurGauche))//if the centre sensor detects the white, the car moves
  {
   Motor.speed(MOTOR1, -60); //our first motor will have a speed of 60 (we use the negative forme because of the orientation)
   Motor.speed(MOTOR2, 60); //as for as the second motor, it stayes at 0
     Serial.println("Tout droit");
  }

    if ((etatCapteurCentreG) && (!etatCapteurCentreD)){ //first degree correction if the robot turns right

    Motor.speed(MOTOR1, 0); //our first motor stills off
   Motor.speed(MOTOR2, 80);//as for as the second motor, it has a speed of 80
   Serial.println("Tourner à gauche");
  }

     if ((!etatCapteurCentreG) && (etatCapteurCentreD)) { //first degree correction if the robot turns left
  Motor.speed(MOTOR1, -80); //our first motor will have a speed of 80 (we use the negative forme because of the orientation)
   Motor.speed(MOTOR2, 0);//as for as the second motor, it stayes at 0
   Serial.println("Tourner à droite");
  }

    if((etatCapteurCentreG) && (etatCapteurCentreD) && (etatCapteurDroit) && (etatCapteurGauche))//if the center sensor detects the black, the car stops
  {
    //we stop the two motors
   Motor.stop(MOTOR1);
   Motor.stop(MOTOR2);
     Serial.println("Stop");
  }

  //functions call
  VirageAGauche();
  VirageADroite();
  SuperRight();
  SuperLeft();
 }

