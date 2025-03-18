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
uint8_t i2c_sda = D2;
uint8_t i2c_scl = D1;

// l'adresse I2C (ici 0x3C) peut être différente en fonction du module utilisé
SSD1306Wire  display(0x3c, i2c_sda, i2c_scl); // I2C sur un esp8266 donc D2 > SDA & D1 > SCL

// Adresse du PCF85741 peut être différente en fonction de la position des commut. du circuit, en principe c'est 0x20
#define adr_i2c_io 0x20 // l'adresse classique du PCF85741 est 0x20
uint8_t encod_sw  = 0; // signal SW  de l'encodeur rotatif sur P0 du PCF85741
uint8_t encod_dt  = 1; // signal DT  de l'encodeur rotatif sur P1 du PCF85741
uint8_t encod_clk = 2; // signal CLK de l'encodeur rotatif sur P2 du PCF85741
uint8_t bouton = 3; // permet de tester la lecture d'un bouton sur P3 du PCF85741
uint8_t led_1 = 4; // test avec une led de l'écriture sur P4 du PCF85741

// init Uoled (adresse du PCF85741, clk, dt, sw et nom de l'objet LCD)
util_1306 Uoled(adr_i2c_io, encod_clk, encod_dt, encod_sw, display);

uint8_t A_menu; // Variable de retour du menu
const int nb_ch_menuA = 5; // Nombre de choix dans le menu
const String ch_menuA[] = {"Saisie de Fréquence", "Saisie de poids ", "Menu déplacements", "Saisir un Nom", "Bouton Led"};
String _ch_menuA = * ch_menuA; // Pointeur sur liste des choix du menu
uint8_t B_menu; // Variable de retour du menu
const int nb_ch_menuB = 3; // Nombre de choix dans le menu
const String ch_menuB[] = {"Déplacement TXT", "Déplacement Jeux", "Retour"};
String _ch_menuB = * ch_menuB; // Pointeur sur liste des choix du menu
// Liste des mois pour exemple de la fonction "déplacement"
const String m_s[] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Décembre"};
int res_rup=0; // Résultat roolup
int cpt=0; // Compteur
char sai_dep = ' '; // Utilisée pour le retour de la fonction "déplacement"
unsigned long temps_jeux; // Pour limite de temps démo jeux
int v_y, mem_y; // Gestion déplacement dans jeux
String v_nom; // Chaine pour la saisie alphanumérique

void setup(){
	display.init(); // Init de l'écran OLED
	display.flipScreenVertically();
	Uoled.prep_aff_LCD(10, 'C'); // On va afficher en caractères de 10 centrés
	display.clear();
	delay(200);
}

void loop(){
	delay(300);
	A_menu = 0;
	A_menu = Uoled.init_menu(nb_ch_menuA, _ch_menuA);
	delay(300); // Un délai est necessaire pour éviter les rebonds du bouton de l'encodeur rotatif
	switch (A_menu){
		case 0: // Saisie d'une fréquence
			res_rup = Uoled.sai_Num(3, true, "Fréquence Hz ?"); // Saisie d'un numérique 3 roolup + 1 pour puissance de 10
			Uoled.prep_aff_LCD(16, 'C');
			display.drawString(64, 30, String(res_rup) + " Hz");
			display.display();
			break;
		case 1: // Saisie du poids
			Uoled.prep_aff_LCD(16, 'C');
			while(res_rup<1||res_rup>200){ 
				res_rup = Uoled.sai_Num(3, false, "Votre poids kg ?");  // Saisie d'un numérique 3 roolup
				if(res_rup<1||res_rup>200){
					Uoled.prep_aff_LCD(16, 'C');
					display.drawString(64, 30, "Erreur !");
					display.display();
					while(Uoled.li_rot_sw()){delay(10);}
				}
			}
			Uoled.prep_aff_LCD(16, 'C');
			display.drawString(64, 30, String(res_rup) + " Kg");
			display.display();
			break;
		case 2: // Menu déplacements
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
		case 3: // Saisie d'un nom
			v_nom = Uoled.sai_Alpha("Saisir Nom ?"); // Saisie alphanumérique
			Uoled.prep_aff_LCD(16, 'C');
			display.drawString(64, 30, v_nom);
			display.display();
			break;
		case 4: // Bouton led (voir schèma de câblage dans la documentation sur le site https://castoo.fr)
			Uoled.prep_aff_LCD(16, 'C');
			while(Uoled.li_rot_sw()){
				if(Uoled.li_eb_rot(bouton)){ // Lecture d'un eb sur une entrée du circuit i2c I/O
					display.drawString(64, 30, "Bouton ok !");
					delay(20);
					Uoled.ecri_eb_rot(led_1, false); // Ecriture d'un eb sur une sortie du circuit i2c I/O
				}else{
					display.drawString(64, 30, "Rien vu !");
					delay(20);
					Uoled.ecri_eb_rot(led_1, true); // Ecriture d'un eb sur une sortie du circuit i2c I/O
				}
				display.display();
				delay(100);
				Uoled.prep_aff_LCD(16, 'C');
			}
			Uoled.init_eb_rot(); // Remise dans un état stable de l'encodeur rotatif (nécessaire pour rattraper le timing)
			break;
	}
	delay(300);
	if(A_menu!=4) while(Uoled.li_rot_sw()){delay(10);} // Attente que le bouton de l'encodeur rotatif soit pressé pour continuer
	Uoled.prep_aff_LCD(10, 'G');
}
