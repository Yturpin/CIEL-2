/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <Arduino.h>
uint8_t LED = 2;

//Fonction init périphériques et variables
void setup(){
    pinMode(LED, OUTPUT);
}

//Boucle infinie qui s'occupe du traitement attendu
void loop(){
    digitalWrite(LED,HIGH);
    delay(10000);
    digitalWrite(LED,LOW);
    delay(10000);

}