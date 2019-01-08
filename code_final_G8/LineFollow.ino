#include "Grove_I2C_Motor_Driver.h"

#include <Wire.h>

#define I2C_ADDRESS 0x0f

//tLeft turning step
void VirageAGauche(){

    Motor.speed(MOTOR1,0);
   Motor.speed(MOTOR2, 100);
   delay(800);

Serial.println("Tourner à gauche");
   }  

//Right turning step
void VirageADroite(){

     Motor.speed(MOTOR1, -100); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
    Motor.speed(MOTOR2, 0); //as for as the second motor, it stayes at 0
       delay(800);

   Serial.println("Tourner à droite");
      }  


void Straight(){

     Motor.speed(MOTOR1, -100); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
    Motor.speed(MOTOR2, 100); //as for as the second motor, it stayes at 0
       
       delay(800);

   Serial.println("Tout droit");
  
  }

