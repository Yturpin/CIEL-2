// test_menu_util_1306.ino 
// Démonstration d'un menu simple avec la librairie lib_1306_rot
// Castoo https://castoo.fr
// Février 2021

#include <Arduino.h>
#include <SSD1306.h>
#include "lib_1306_rot.h"

// l'adresse I2C (ici 0x3C) peut être différente en fonction du module utilisé
//SSD1306Wire  display(0x3c, 4, 5); // I2C sur un esp8266 donc gpio 4 > SDA & gpio 5 > SCL
SSD1306Wire display(0x3c, 21, 22); // I2C sur un Wemos D1 mini (esp8266 donc gpio 4 (ou D2) > SDA & gpio 5 (ou D1) > SCL)

#define adr_pcf85741 0 // Adresse du circuit I2C 8 I/O
#define encod_sw 32 // P0
#define encod_dt 33 // P1
#define encod_clk 25 // P2

// L'adresse du circuuit PCF8574 doit etre passée en premier parametre ceci permet l'utilisation de différents types de circuit I/O
// L'adresse peut etre 20 ou 21 ou tout autre suivant les petit boutons sur le dessus du circuit ...
util_1306 Uoled(adr_pcf85741, encod_clk, encod_dt, encod_sw, display);

int A_menu; // Choix selectionné dans menu
const int nb_ch_menuA = 3; // choix du menu Principal
const String ch_menuA[] = {"Saisir votre nom", "Saisir votre prénom", "Afficher Nom Prénom"};
String _ch_menuA = * ch_menuA;
String nom = "";
String prenom = "";
String ch_result = "";

// Initialisation
void setup() { 
	display.init(); // Init OLED
	display.flipScreenVertically();
	display.clear();
} 

// Boucle principale
void loop(){
	A_menu = 0;
	A_menu = Uoled.init_menu(nb_ch_menuA, _ch_menuA);
	delay(300);
	switch (A_menu){ // Menu général
		case 0 : // Saisie du nom
			nom = Uoled.sai_Alpha("Saisir Nom ?"); // On lance la saisie
			break;
		case 1 : // Saisie du prénom
			prenom = Uoled.sai_Alpha("Saisir Prénom ?"); // On lance la saisie
			break;
		case 2 : // Affichage du nom et du prénom
			delay(200); // Anti rebond bouton
			ch_result = nom + " " + prenom;
			if(ch_result == " ") ch_result = "Vous devez faire une saisie !";
			Uoled.prep_aff_LCD(10, 'C'); // On va afficher en caractères de 10 centrés
			display.clear();
			display.drawString(64, 25, ch_result);
			display.display();
			while(Uoled.li_rot_sw()){ // On attend que le bouton soit pressé pour sortir de l'affichage
				delay(10); 
			}
			break;
	}
	delay(600);
}