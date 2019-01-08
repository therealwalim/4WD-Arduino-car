#include "Grove_I2C_Motor_Driver.h"

#include "Move.h"

#include "LineFollow.h"

#include <Wire.h>

#define I2C_ADDRESS 0x0f

int i = 0;

int position [15]={3,2,1,1,2,2,3,3,2,2,1,2,1,1};

int lumiere;


const int capteurGauche = 4;
const int capteurCentreG = 3;
const int capteurCentreD = 6;
const int capteurDroit = 5;

bool etatCapteurGauche;
bool etatCapteurCentreD;
bool etatCapteurCentreG;
bool etatCapteurDroit;

void setup(){

   Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurCentreG, INPUT);
  pinMode(capteurCentreD, INPUT);
  pinMode(capteurDroit, INPUT);
  
}

void loop(){



  etatCapteurGauche = digitalRead(capteurGauche);
  etatCapteurCentreG = digitalRead(capteurCentreG);
  etatCapteurCentreD = digitalRead(capteurCentreD);
  etatCapteurDroit = digitalRead(capteurDroit);

    if( (etatCapteurDroit == LOW ) && (etatCapteurCentreD == LOW) && (etatCapteurGauche == LOW ) &&(etatCapteurCentreG == HIGH ))//Si le capteur du centre détecte 
    
  {
   Motor.speed(MOTOR1,0 ); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
   Motor.speed(MOTOR2, 100); //as for as the second motor, it stayes at 0
   delay(80);
  }

      if((etatCapteurDroit == LOW ) && (etatCapteurCentreD == LOW) && (etatCapteurGauche == HIGH ) &&(etatCapteurCentreG == LOW ))//Si le capteur du centre détecte 
    
  {
   Motor.speed(MOTOR1,100 ); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
   Motor.speed(MOTOR2, 100); //as for as the second motor, it stayes at 0
   delay(150);
  }

      if( (etatCapteurDroit == LOW ) && (etatCapteurCentreD == HIGH) && (etatCapteurGauche == LOW ) &&(etatCapteurCentreG == LOW ))//Si le capteur du centre détecte 
    
  {
   Motor.speed(MOTOR1, -100); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
   Motor.speed(MOTOR2, 0); //as for as the second motor, it stayes at 0
   delay(80);
  }

        if((etatCapteurDroit == HIGH ) && (etatCapteurCentreD == LOW) && (etatCapteurGauche == LOW ) &&(etatCapteurCentreG == LOW ))//Si le capteur du centre détecte 
    
  {
   Motor.speed(MOTOR1, -100); //our first motor will have a speed of 100 (we use the negative forme because of the orientation)
   Motor.speed(MOTOR2, -100); //as for as the second motor, it stayes at 0
   delay(150);
  }



 Moving();
if(((etatCapteurDroit == HIGH ) && (etatCapteurCentreD == HIGH) && (etatCapteurGauche == LOW ) &&(etatCapteurCentreG == LOW )) || ((etatCapteurGauche) == HIGH &&(etatCapteurCentreG ) == HIGH && (etatCapteurDroit) == HIGH && (etatCapteurCentreD) == HIGH) || ((etatCapteurGauche) == HIGH &&(etatCapteurCentreG ) == HIGH && (etatCapteurDroit) == LOW && (etatCapteurCentreD) == LOW)){

   Motor.stop(MOTOR1); //we stop the first motor
   Motor.stop(MOTOR2); //we stop the second motor
   delay(700);

  if ( position[i]==2) {                 
               // left  gauche

      VirageAGauche();      
  
    }

    else if(position[i]==1){ 
    //right droite
    
           VirageADroite();
              }
      else if(position[i]==3) {
      // if it detectes only white, it keeps walking straight

        Straight();
}
        i++; 
}




}

 void speed()
{

   if(lumiere  == LOW){
      half++; 
      }
   if (half >= 20) {
     rpm = 60000/(millis() - timeold);
     timeold = millis();
     half = 0;
     Serial.println(rpm);
     Serial.println("tour/min");
     vtt = (rpm/60)* 0.2041;
     Serial.println(vtt);
     Serial.println("m/s");
   }
}


