#include "Grove_I2C_Motor_Driver.h"

#include <Wire.h>

#include "LineFollow.h"

#define I2C_ADDRESS 0x0f


  void Moving(){
  
    if((!etatCapteurCentreG) && (!etatCapteurCentreD) && (!etatCapteurDroit) && (!etatCapteurGauche))//Si le capteur du centre détecte du blanc, la voiture avance
  {
   Motor.speed(MOTOR1, -60);
   Motor.speed(MOTOR2, 60);
     Serial.println("Tout droit");
  }

    if ((etatCapteurCentreG) && (!etatCapteurCentreD)){ // corrrection premier degres si le robot devie a droite

    Motor.speed(MOTOR1, 0);
   Motor.speed(MOTOR2, 80);
   Serial.println("Tourner à gauche");
  }

     if ((!etatCapteurCentreG) && (etatCapteurCentreD)) { //correction premier degres si le robot devie a gauche
  Motor.speed(MOTOR1, -80);
   Motor.speed(MOTOR2, 0);
   Serial.println("Tourner à droite");
  }

    if((etatCapteurCentreG) && (etatCapteurCentreD) && (etatCapteurDroit) && (etatCapteurGauche))//Si le capteur du centre détecte du noir, la voiture s arrete
  {
   Motor.stop(MOTOR1);
   Motor.stop(MOTOR2);
     Serial.println("Stop");
  }

  
  VirageAGauche();
  VirageADroite();
  SuperRight();
  SuperLeft();
 }

