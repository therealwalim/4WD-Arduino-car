
#include "Grove_I2C_Motor_Driver.h"
#include "TimerOne.h"




// default I2C address is 0x0f
#define I2C_ADDRESS 0x0f


const int capteur=5; //capteur port OUT relié au pin5 de l'arduino 


const int droite = 6 ; //initialisation du port en pin 4
const int gauche = 4 ; // ....
const int milieu = 3 ; //... 

//int lumiere; // affiche si le faisceau lumineux est coupé ou non par le disque. Si la lumière est allumé la partie trouée est devant le capteur
//int tour=0; //variable qui compte le nombre de fois où la partie trouée du disque passe devant le capteur
//float trmin; // variable qui affichera la vitesse du disque en tour/min

//unsigned long temps;  //sert à enregistrer le temps écoulé depuis la dernière mise à jour du compteur


int lumiere;  //affiche si le faisceau lumineux est coupé ou non par le disque. Si la lumière est allumé la partie trouée est devant le capteur
int tour=0; //variable qui compte le nombre de fois où la partie trouée du disque passe devant le capteur
float trmin;  //variable qui affichera la vitesse du disque en tourmin

unsigned long temps;  //sert à enregistrer le temps écoulé depuis la dernière mise à jour du compteur



void setup() {
  Motor.begin(I2C_ADDRESS);
 
   
      pinMode(milieu, INPUT);
   pinMode(gauche, INPUT);
   pinMode(droite, INPUT);

temps=millis();
}

void loop() {
  // Set speed of MOTOR1, Clockwise, speed: 0~100 
  //Motor.speed(MOTOR1, 100);
    //Motor.speed(MOTOR2, 100);

  // Set speed of MOTOR2, Anticlockwise
// Motor.speed(MOTOR1, 0);
 // Motor.speed(MOTOR2, 100);

  //delay(7000);
  // Change speed and direction of MOTOR1
  //Motor.speed(MOTOR1, 0);
  // Change speed and direction of MOTOR2
  //Motor.speed(MOTOR2, 0);
  //delay(2000);
  // Stop MOTOR1 and MOTOR2
 // Motor.stop(MOTOR1);
  //Motor.stop(MOTOR2);
  //delay(4000);

//LOW =0 and high = 1;
// moteur 1 est le moteur  
//moteur 2 est le moteur droit
// on exprime le moteur droit/ arriere par la valeur négative par exemple 0
// dans ce cas: on a l'extreme ,  l'extreme  et  ont une valeur null (0)
// LE capteur  s'allume quand il detecte le blanc, et il s'eteind quand il detecte le noir
  
    
    
    
    //digitalWrite(, HIGH);
      //  digitalWrite(, LOW);

    //digitalWrite(, HIGH);
       // digitalWrite(, LOW);

     //digitalWrite(, HIGH);
       //  digitalWrite(, LOW);

    // digitalWrite(, HIGH);
   // digitalWrite(, LOW);



                         
// if(HIGH == digitalRead(gauche))
//{ Serial.println("black");
//}
// if(LOW == digitalRead(gauche))
//{ Serial.println("white");
//}
// this will be : marche tt droit


//-100 DEFINI Marche avant dans le moteur gauche
// 100 defini marche arriere


if( LOW == digitalRead(droite)  && LOW == digitalRead(gauche) && LOW == digitalRead(milieu)){  
Motor.speed(MOTOR1, 0); // not sure about this value quand le moteur s'arrete , on donne quel valeur? 0?
Motor.speed(MOTOR2,0 );  
}

//
if( HIGH == digitalRead(droite)  && LOW == digitalRead(gauche) && LOW == digitalRead(milieu))  {  
Motor.speed(MOTOR1, -100);
Motor.speed(MOTOR2, 0);
}
if(LOW == digitalRead(gauche) && HIGH == digitalRead(milieu) && LOW == digitalRead(droite)){
  Motor.speed(MOTOR1, -100);
  Motor.speed(MOTOR2, 100);
}

if(LOW == digitalRead(gauche) && HIGH == digitalRead(milieu) && HIGH == digitalRead(droite)){
  Motor.speed(MOTOR1, -100);
  Motor.speed(MOTOR2, 100);
}
if(HIGH == digitalRead(gauche) && LOW == digitalRead(milieu) && LOW == digitalRead(droite)){
  Motor.speed(MOTOR1, 0);
  Motor.speed(MOTOR2, 100);
}
if(HIGH == digitalRead(gauche) && HIGH == digitalRead(milieu) && LOW == digitalRead(droite)){
  Motor.speed(MOTOR1, 100);
  Motor.speed(MOTOR2, 100);
}
if(HIGH == digitalRead(gauche) && HIGH == digitalRead(milieu) && HIGH == digitalRead(droite)){
  Motor.speed(MOTOR1, -100);
  Motor.speed(MOTOR2, 100);
}


//Vérifie si le trou arrive à hauteur du capteur
  lumiere = digitalRead(capteur);

  if (lumiere == HIGH) {

//     on ajoute 1 à la variable qui compte le nombre de tours

    tour=tour+1;
      Serial.println(tour);
//     si il s'est passé plus d'une seconde depuis le début du calcul du nombre de tours

  
  if ((millis() - temps)*1000){

//     trmin= (nb de tours depuis le dernier calcul) (temps écoulé entre les deux caculs en minute 1min=60 000ms

    //trmin= tour*(millis()-temps)/60000.0;
    trmin = (60 / (trmin*(millis() / 1000000.0);

    Serial.print("vitesse en tourmin" );

    Serial.println(trmin);

//    Réinitialisation du temps et du nombre de tours

    temps=millis();

    tour=0;

    }
}
}
