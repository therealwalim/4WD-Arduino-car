#include <Arduino.h>
#include "deplacement.h"

// Correction legere à droite
void CorrectDroite() {
  Motor.speed(MOTOR1, 100);
  Motor.speed(MOTOR2, -100);
}

// Correction legere à gauche
void CorrectGauche() {
  Motor.speed(MOTOR1, -100);
  Motor.speed(MOTOR2, 100);
}

// Correction rapide à droite
void CorrectRapideDroite() {
  Motor.speed(MOTOR1, 100);
  Motor.speed(MOTOR2, 50);
}

// Correction rapide à gauche
void CorrectRapideGauche() {
  Motor.speed(MOTOR1, 50);
  Motor.speed(MOTOR2, 100);
}

// Tourner à droite
void TournerDroite() {
  Motor.speed(MOTOR1, 100);
  Motor.speed(MOTOR2, 0);
}

// Tourner à gauche
void TournerGauche() {
  Motor.speed(MOTOR1, 0);
  Motor.speed(MOTOR2, 100);
}

// Avancer tout droit
void ToutDroit() {
  Motor.speed(MOTOR1, 100);
  Motor.speed(MOTOR2, 100);
}

// Arrêt du véhicule
void Arret() {
 Motor.speed(MOTOR1, 0);
 Motor.speed(MOTOR2, 0);
}