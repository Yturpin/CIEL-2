/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>>
#include <SSD1306.h>
#include <esp_snir.h>

#define DATALEDS 19
#define NB_PIXELS 4

//uint8_t LED = 2;

Adafruit_NeoPixel pixels(NB_PIXELS, DATALEDS, NEO_RGB);
SSD1306 afficheurOLED(0x3C,21,22);

//Fonction init périphériques et variables
void setup(){
    pixels.begin();
    afficheurOLED.init();
    afficheurOLED.flipScreenVertically();
    afficheurOLED.setFont(ArialMT_Plain_16);
    afficheurOLED.drawRect(0,0,127,63);
    afficheurOLED.drawString(20,5,"YANEUINO !");
    afficheurOLED.display();
    
    pinMode(BP1,INPUT);
    pinMode(BP2,INPUT);
    pinMode(BP3,INPUT);
    pinMode(D1,OUTPUT);
    pinMode(D2,OUTPUT);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
}

//Boucle infinie qui s'occupe du traitement attendu
void loop(){
    /*pixels.clear();
    pixels.show();
    delay(500);
    for(int i = 0 ; i < NB_PIXELS ; i++){
        pixels.setPixelColor(i,16,0,0);
        pixels.show();
        delay(500);
    }*/
    
    if(digitalRead(BP1) == LOW)
        digitalWrite(D1,HIGH);
    if(digitalRead(BP2) == LOW)
        digitalWrite(D2,HIGH);
    if(digitalRead(BP3) == LOW)
    {
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
    }
}
