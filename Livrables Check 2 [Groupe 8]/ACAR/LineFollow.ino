#include "Grove_I2C_Motor_Driver.h"

#include <Wire.h>

#define I2C_ADDRESS 0x0f

void VirageAGauche(){
if  ((etatCapteurGauche) && (etatCapteurCentreG)){ //rotation a gauche
    Motor.stop(MOTOR1);
   Motor.stop(MOTOR2);
   delay(500);
    Motor.speed(MOTOR1,0);
   Motor.speed(MOTOR2, 100);
   Serial.println("Tourner à gauche");
   while(!etatCapteurGauche){
    
   }
   Moving();
  }
}

void VirageADroite(){
 if((etatCapteurDroit) && (etatCapteurCentreD)){ //rotation a droite 
     Motor.stop(MOTOR1);
   Motor.stop(MOTOR2);
   delay(500);
     Motor.speed(MOTOR1, -100);
    Motor.speed(MOTOR2, 0);
   Serial.println("Tourner à droite");
   delay(950);
  }
}

void SuperRight(){
    if((etatCapteurDroit) && (!etatCapteurCentreD))//Si le capteur du centre détecte 
  {
   Motor.speed(MOTOR1, -100);
   Motor.speed(MOTOR2, 0);
    delay(350);
  }
  }

  void SuperLeft(){
    if ((etatCapteurGauche) && (!etatCapteurCentreG)){//Si le capteur du centre détecte du blanc, la voiture avance
    Motor.speed(MOTOR1, 0);
   Motor.speed(MOTOR2, 10);
    delay(350);
  }
  }

