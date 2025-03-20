/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
// Démonstration lib_1306_rot.ino v2 exemple test_lib_1306_rot_v2f.ino
// Novembre 2023
// https://castoo.fr
// Démonstration de quelques fonctions de la librairie lib_1306_rot
// Attention la librairie utilise la librairie oled SSD1306Wire avec un W majuscule qui n'est pas directement
// disponible dans l IDE Arduino il faut la chercher sur internet sur le site "github"
// Remarque (interface 5 fils ou 2 fils voir description sur castoo.fr) :
// si vous passez le parametre adr_i2c_io à 0 la lib considere que les signaux clk, dt et sw sont des num de port du processeur
// si vous passez le parametre adr_i2c_io avec l'adresse du PCF85741 la lib considere que les signaux clk, dt et sw sont des sortie du PCF85741
//
// Exemple en version 2 fils avec un ESP8266-12 et un PCF85741

#include <Wire.h>
#include "SSD1306Wire.h"
#include "lib_1306_rot.h" // Déclaration de la librairie

// Pins de racordement I2C sur un esp8266 Wemos D1 mini (OLED et RTC)
uint8_t i2c_sda = 21;
uint8_t i2c_scl = 22;

// l'adresse I2C (ici 0x3C) peut être différente en fonction du module utilisé
SSD1306Wire  display(0x3c, i2c_sda, i2c_scl); // I2C sur un esp8266 donc D2 > SDA & D1 > SCL

// Adresse du PCF85741 peut être différente en fonction de la position des commut. du circuit, en principe c'est 0x20
#define adr_pcf85741 0 // Adresse du circuit I2C 8 I/O
#define encod_sw 32 // P0
#define encod_dt 33 // P1
#define encod_clk 25 // P2
uint8_t bouton = 36; // permet de tester la lecture d'un bouton sur P3 du PCF85741
uint8_t led_1 = 23; // test avec une led de l'écriture sur P4 du PCF85741

// init Uoled (adresse du PCF85741, clk, dt, sw et nom de l'objet LCD)
util_1306 Uoled(0, encod_clk, encod_dt, encod_sw, display);

uint8_t A_menu; // Variable de retour du menu
const int nb_ch_menuA = 4; // Nombre de choix dans le menu
const String ch_menuA[] = {"MENU", "Choix Vannes", "Réglages", "Quitter"};
String _ch_menuA = * ch_menuA; // Pointeur sur liste des choix du menu

uint8_t B_menu; // Variable de retour du menu
const int nb_ch_menuB = 3; // Nombre de choix dans le menu
const String ch_menuB[] = {"Changement heure", "Etat arrosage", "Retour"};
String _ch_menuB = * ch_menuB; // Pointeur sur liste des choix du menu

uint8_t Vannes_menu; // Variable de retour du menu des vannes
const int nb_ch_menuVannes = 4; // Nombre de choix dans le menu des vannes
const String ch_menuVannes[] = {"Vanne 1", "Vanne 2", "Vanne 3", "Vanne 4"};
String _ch_menuVannes = * ch_menuVannes; // Pointeur sur liste des choix du menu

uint8_t Reglages_menu; // Variable de retour du menu des réglages
const int nb_ch_menuReglages = 3; // Nombre de choix dans le menu des réglages
const String ch_menuReglages[] = {"Config cycles arrosage", "Date et heure", "Connexion capteur"};
String _ch_menuReglages = * ch_menuReglages; // Pointeur sur liste des choix du menu

uint8_t Conf_cycles_menu; // Variable de retour du menu des réglages
const int nb_ch_menuConf_cycles = 3; // Nombre de choix dans le menu des réglages
const String ch_menuConf_cycles[] = {"Durée d'arrosage", "Fréquence", "Heure de début d'arrosage"};
String _ch_menuConf_cycles = * ch_menuConf_cycles; // Pointeur sur liste des choix du menu

uint8_t Modes_menu; // Variable de retour du menu
const int nb_ch_menuModes = 3; // Nombre de choix dans le menu des vannes
const String ch_menuModes[] = {"Manuel", "Programmé", "Automatique"};
String _ch_menuModes = * ch_menuModes; // Pointeur sur liste des choix du menu

uint8_t Programme_menu; // Variable de retour du menu
const int nb_ch_menuProgramme = 3; // Nombre de choix dans le menu des vannes
const String ch_menuProgramme[] = {"Heure d'arrosage", "Durée d'arrosage", "Fréquence d'arrosage"};
String _ch_menuProgramme = * ch_menuProgramme; // Pointeur sur liste des choix du menu

// Liste des mois pour exemple de la fonction "déplacement"
const String m_s[] = {"Ouvrir", "Fermer"};
int res_rup=0; // Résultat roolup
int res_rup_heure_debut=0; // Résultat roolup Heure début arrosage
int res_rup_duree=0; // Résultat roolup Durée arrosage
int res_rup_freq=0; // Résultat roolup fréquence
int cpt=0; // Compteur
char sai_dep = ' '; // Utilisée pour le retour de la fonction "déplacement"
unsigned long temps_jeux; // Pour limite de temps démo jeux
int v_y, mem_y; // Gestion déplacement dans jeux
String v_nom; // Chaine pour la saisie alphanumérique
String v_vanne; // Chaine pour la saisie d'une vanne

void setup(){
	display.init(); // Init de l'écran OLED
	display.flipScreenVertically();
	Uoled.prep_aff_LCD(10, 'C'); // On va afficher en caractères de 10 centrés
	display.clear();
	delay(200);
        pinMode(bouton,INPUT_PULLUP);
        pinMode(led_1,OUTPUT);
}

void loop(){
	delay(300);
	A_menu = 0;
	A_menu = Uoled.init_menu(nb_ch_menuA, _ch_menuA);
	delay(300); // Un délai est necessaire pour éviter les rebonds du bouton de l'encodeur rotatif
	switch (A_menu){
		case 1: // Menu choix des vannes
			Vannes_menu = 0;
			Vannes_menu = Uoled.init_menu(nb_ch_menuVannes, _ch_menuVannes);
			delay(300); // Un délai est necessaire pour éviter les rebonds du bouton de l'encodeur rotatif
			switch (Vannes_menu){ // Sous menu modes des vannes
				case 0: // Vanne 1 modes
					Modes_menu = 0;
                                        Modes_menu = Uoled.init_menu(nb_ch_menuModes, _ch_menuModes);
                                        delay(300);
                                        switch (Modes_menu){ //Sous menu configuration des mode 
                                            case 0: //configuration du mode Manuel
                                                    Uoled.prep_aff_LCD(16, 'C');
                                                    display.drawString(64, 0, "Etat vanne");
                                                    display.display();
                                                    sai_dep = ' ';
                                                    while(sai_dep != 'B'){
                                                            sai_dep = Uoled.sai_mov(); // Saisie d'un déplacement de l'encodeur ou d'un appuis
                                                            if(sai_dep == 'G') cpt = (cpt-1<0)?1:(cpt-1); else if(sai_dep == 'D') cpt = (cpt+1) %2;
                                                            display.setColor(BLACK);
                                                            display.fillRect(0, 22, 128, 20);
                                                            display.setColor(WHITE);
                                                            display.drawString(64, 22, m_s[cpt]);
                                                            display.display();
                                                            delay(30);
                                                    }
                                                    display.clear();
                                                    display.drawString(64, 22, "état> " + m_s[cpt]);
                                                    display.display();
                                                    break;
                                            case 1: // Configuration du mode programmé
                                                Programme_menu = 0;
                                                Programme_menu = Uoled.init_menu(nb_ch_menuProgramme, _ch_menuProgramme);
                                                delay(300);
                                                switch (Programme_menu){
                                                    case 0: // Configuration heure d'arrosage
                                                        Uoled.prep_aff_LCD(16, 'C');
                                                            while(res_rup_heure_debut<1||res_rup_heure_debut>24){
                                                                    res_rup_heure_debut = Uoled.sai_Num(2, false, "Heure d'arrosage ?");  // Saisie d'un numérique 3 roolup
                                                                    if(res_rup_heure_debut<1||res_rup_heure_debut>24){
                                                                        Uoled.prep_aff_LCD(16, 'C');
                                                                        display.drawString(64, 30, "Erreur !");
                                                                        display.display();
                                                                        while(Uoled.li_rot_sw()){delay(10);}
                                                                    }
                                                            }
                                                            Uoled.prep_aff_LCD(16, 'C');
                                                            display.drawString(64, 30, String(res_rup_heure_debut) + " h");
                                                            display.display();
                                                            break;
                                                    case 1: // Configuration durée d'arrosage
                                                        Uoled.prep_aff_LCD(16, 'C');
                                                            while(res_rup_duree<1||res_rup_duree>24){ 
                                                                    res_rup_duree = Uoled.sai_Num(2, false, "Durée ?");  // Saisie d'un numérique 3 roolup
                                                                    if(res_rup_duree<1||res_rup_duree>24){
                                                                        Uoled.prep_aff_LCD(16, 'C');
                                                                        display.drawString(64, 30, "Erreur !");
                                                                        display.display();
                                                                        while(Uoled.li_rot_sw()){delay(10);}
                                                                    }
                                                            }
                                                            Uoled.prep_aff_LCD(16, 'C');
                                                            display.drawString(64, 30, String(res_rup_duree) + " min");
                                                            display.display();
                                                            break;
                                                    case 2: // Configuration fréquence d'arrosage
                                                        Uoled.prep_aff_LCD(16, 'C');
                                                            while(res_rup_freq<1||res_rup_freq>24){ 
                                                                    res_rup_freq = Uoled.sai_Num(2, false, "Fréquence ?");  // Saisie d'un numérique 3 roolup
                                                                    if(res_rup_freq<1||res_rup_freq>24){
                                                                        Uoled.prep_aff_LCD(16, 'C');
                                                                        display.drawString(64, 30, "Erreur !");
                                                                        display.display();
                                                                        while(Uoled.li_rot_sw()){delay(10);}
                                                                    }
                                                            }
                                                            Uoled.prep_aff_LCD(16, 'C');
                                                            display.drawString(64, 30, String(res_rup_freq) + " h");
                                                            display.display();
                                                            break;
                                                }
                                            case 2: // Configuration du mode automatique
                                                break;
                                        }
                                        break;
                                case 1: // Vanne 2 modes
                                        break;
                                case 2: // Vanne 3 modes
                                        break;
                                case 3: // Vanne 4 modes
                                        break;
                        }       
                        break;
		case 2: // Réglages
			Reglages_menu = 0;
			Reglages_menu = Uoled.init_menu(nb_ch_menuReglages, _ch_menuReglages);
			delay(300); // Un délai est necessaire pour éviter les rebonds du bouton de l'encodeur rotatif
			switch (Reglages_menu){ // Sous menu réglages
				case 0: // Config cycles d'arrosage
                                    break;
                                case 1: // Date et heure
                                    break;
                        }    
                        break;
		case 3: // Quitter
			B_menu = 0;
			B_menu = Uoled.init_menu(nb_ch_menuB, _ch_menuB);
			delay(300); // Un délai est necessaire pour éviter les rebonds du bouton de l'encodeur rotatif
			switch (B_menu){ // Sous menu déplacement
				case 0: // Test de déplacement mois de l'année
					Uoled.prep_aff_LCD(16, 'C');
					display.drawString(64, 0, "Test déplacement");
					display.display();
					sai_dep = ' ';
					while(sai_dep != 'B'){
						sai_dep = Uoled.sai_mov(); // Saisie d'un déplacement de l'encodeur ou d'un appuis
						if(sai_dep == 'G') cpt = (cpt-1<0)?11:(cpt-1); else if(sai_dep == 'D') cpt = (cpt+1) %12;
						display.setColor(BLACK);
						display.fillRect(0, 22, 128, 20);
						display.setColor(WHITE);
						display.drawString(64, 22, m_s[cpt]);
						display.display();
						delay(30);
					}
					display.clear();
					display.drawString(64, 22, "choix> " + m_s[cpt]);
					display.display();
					break;
				case 1: // Test de déplacement jeux
					Uoled.prep_aff_LCD(10, 'C');
					display.drawString(64, 0, "Test prémices petit jeux");
					display.drawString(64, 12, "avec fonction déplacement");
					display.drawString(64, 24, "Arret auto aprés");
					display.drawString(64, 36, "60 secondes");
					display.drawString(64, 48, "Jouer avec rot < > et B");
					display.display();
					while(Uoled.li_rot_sw()){delay(10);}
					display.clear();
					display.drawString(0, 0, "O->"); display.display();
					temps_jeux = millis();
					v_y=0; mem_y=0;	sai_dep = ' ';
					while((millis() - temps_jeux) < 6000){ // limite du jeux à 60 secondes
						sai_dep = Uoled.sai_mov(); // Saisie d'un déplacement de l'encodeur ou d'un appuis
						switch (sai_dep){
							case 'G': mem_y = v_y;((v_y+10)>64)?v_y=64:v_y+=10;break;// Gauche (Haut)
							case 'D': mem_y = v_y;((v_y-10)<0)?v_y=0:v_y-=10;break;// Droite (Bas)
							case 'B': // Bouton (Feu... Tire)
								for(byte cpt=30; cpt<115; cpt+=10){display.drawString(cpt, v_y, "->"); display.display();}
								delay(150);
								display.setColor(BLACK);display.fillRect(25, v_y, 103, 11); display.setColor(WHITE);
								display.display(); delay(150); // Attention aux rebonds du bouton
							break;
						}
						if(sai_dep!='B'){
							display.setColor(BLACK);
							display.fillRect(0, mem_y, 30, 11); 
							display.setColor(WHITE);
							display.drawString(0, v_y, "O->");	
							display.display();
						}
					}
					display.clear();display.drawString(64, 30, "FIN !");display.display();
					break;
				}
			break;
	}
	delay(300);
	if(A_menu!=4) while(Uoled.li_rot_sw()){delay(10);} // Attente que le bouton de l'encodeur rotatif soit pressé pour continuer
	Uoled.prep_aff_LCD(10, 'G');

}

/*
//MES PETITS TESTS
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
    
    //CONTROLE BANDE LED
    if(digitalRead(BP1) == LOW){
        int i = 0;
        pixels.setPixelColor(i,25,25,25);
        pixels.show();
    }
    if(digitalRead(BP3) == LOW){
        pixels.clear();
        pixels.show();
    }
    if(digitalRead(BP2) == LOW){
        int i = 1;
        pixels.setPixelColor(i,0,25,0);
        pixels.show();
    }
    
    
    /*
    //CONTROLE LED (D1, D2) AVEC BOUTONS
    if(digitalRead(BP1) == LOW)
        digitalWrite(D1,HIGH);
    if(digitalRead(BP2) == LOW)
        digitalWrite(D2,HIGH);
    if(digitalRead(BP3) == LOW)
    {
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
    }

}*/

