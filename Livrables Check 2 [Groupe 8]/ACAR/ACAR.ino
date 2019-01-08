#include "Grove_I2C_Motor_Driver.h"

#include "Move.h"

#include <Wire.h>

#define I2C_ADDRESS 0x0f


//this is for our sensor connection
const int capteurGauche = 6;
const int capteurCentreG = 7;
const int capteurCentreD = 5;
const int capteurDroit = 8;

//the use of boolean form
bool etatCapteurGauche;
bool etatCapteurCentreD;
bool etatCapteurCentreG;
bool etatCapteurDroit;


 int position[14]={3,2,2};
 int i=0;

void setup(){

   Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurCentreG, INPUT);
  pinMode(capteurCentreD, INPUT);
  pinMode(capteurDroit, INPUT);
  
}

void loop(){

//this step is for states of the boolean form
  etatCapteurGauche = digitalRead(capteurGauche);
  etatCapteurCentreG = digitalRead(capteurCentreG);
  etatCapteurCentreD = digitalRead(capteurCentreD);
  etatCapteurDroit = digitalRead(capteurDroit);

 Moving();

}

