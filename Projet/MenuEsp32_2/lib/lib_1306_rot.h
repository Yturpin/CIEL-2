// lib_1306_rot.h v2
// librairie d'utilitaires pour gérer une IHM avec un écran oled ssd1306 et un encodeur rotatif
// Gestion de menu de saisie alphanumérique de nombre et gestion des I/O i2c
// https://castoo.fr
// Février 2021

/*
lib_1306_rot.h
- Objet destiné à être utilisé avec Arduino ou ESPxxx.
Possibilité de supporter différents LCD mais l'objet a été créée avec un OLED SD1306
Attention la librairie utilise la librairie oled SSD1306Wire avec un W majuscule qui n'est pas directement
disponible dans l IDE Arduino il faut la chercher sur internet sur le site "github"
Possibilité de supporter différents Encodeurs rotatifs mais l'objet a été créée avec un KY-040 30 pas
Remarque (interface 5 fils ou 2 fils voir description sur castoo.fr) :
si vous passez le parametre adr_i2c_io à 0 la lib considere que les signaux clk, dt et sw sont des num de port du processeur
si vous passez le parametre adr_i2c_io avec l'adresse du PCF85741 la lib considere que les signaux clk, dt et sw sont des sortie du PCF85741

Création Jean Michel Castille décembre 2019 / https://castoo.fr
Cette bibliothèque est un logiciel libre;
Vous pouvez la redistribuer et ou la modifier.
Cette bibliothèque est distribuée dans l'espoir qu'elle sera utile,
mais SANS AUCUNE GARANTIE, sans même la garantie implicite de
QUALITÉ MARCHANDE ou ADÉQUATION À UN USAGE PARTICULIER. 
*/

#ifndef lib_1306_rot_h
#define lib_1306_rot_h

// Adresse I2C du 4585
//pour mémo 0x3F => interface vieux écrans tft
//pour mémo 0x20 => interface E/S PCF85741 (modifiable avec les petits boutons sur le circuit) dans exemple j'utilise 0x21

#include <Wire.h>
#include <SSD1306Wire.h>

// Ancien circuit I2C PCF8574 utilisé par exemple pour les écrans LCD 2 lignes de 20 caractères
// Correspondance des broches sur le connecteur I2C LCD
// Ce tableau est à revoir suivant schéma réel de la plaquette !
//	P0	P1	P2	P3	P4	P5	P6	P7
//	4	5	6	NC	11	12	13	14

// ou 

// circuit I2C PCF85741 interface I/OLED adr de base i2c : 0x20 ou 0x21 suivant la position des petits boutons sur le circuit
// Dans ce cas P0 à P7 sans surprise !

class util_1306{
  private:
	uint8_t adr_i2c_io; // adresse i2c circuit i/o
	uint8_t PinCLK; // Gpio x sur sortie Clk du selecteur rotatif
	uint8_t PinDT;  // Gpio x sur sortie DT du selecteur rotatif
	uint8_t PinSW;  // Gpio x sur sortie SW du selecteur rotatif
	String ch_saisie; // Chaine de la saisie avec le menu sur OLED
	uint8_t val_ch; // Fin de la saisie
	bool flech_d; // sens des fleches dans menu sel chaine
	bool sortieH; // Permet la sortie rapide aprés saisie d'un caractère lors du balayage.
	String _v_question; // Question posée en titre
	SSD1306Wire *_ecran; // Ecran OLED
	#define nb_ch_menu_Alpha 4 // Nombre de choix du menu Alphanumérique
	String ch_menuAlpha[nb_ch_menu_Alpha] = { "Maj", "Min", "Spe", "Val" }; // Choix du menu Alphanumérique
	#define nb_ch_menu_Valid 4 // Nombre de choix du menu Validation
	String ch_menuValid[nb_ch_menu_Valid] = { "Correction", "Tout effacer", "Validation", "Annulation" }; // Choix du menu valid
	int max_ch; // Nb max de chaine du menu
	String * _ch_menu; // Pointeur sur tableau des chaines
	
  public:
	// Constructeur objet avec les 3 signaux clk, dt et sw du rotatif ainsi qu'un pointeur vers l'OLED
	util_1306(uint8_t adr_i2c_io, uint8_t vclk, uint8_t vdt, uint8_t vsw, SSD1306Wire &ecran);
	// Initialise la taille de police et l'alignement sur le LCD
	void prep_aff_LCD(uint8_t typ_pol, char v_align);
    // Affichage du menu alphanumerique retourne la chaine saisie ou "";
	String sai_Alpha(String v_question);
	// valide ou invalide la sortie du balayage des caracteres aprés chaque saisie (valide par defaut)
	void sortie_deb(bool val);
	// retourne etat d'un eb du circuit I/O i2c
	bool li_eb_rot(uint8_t v_eb);
	// retourne etat du signal sw
	bool li_rot_sw();
	// écrit un eb sur circuit I/O i2c
	void ecri_eb_rot(uint8_t v_eb, bool v_val);
	// Affichage et saisie des rool_up
	double sai_Num(uint8_t nb_pos, bool aff_p10, String titre_sai);
	// Retourne deplacement Gauche Droite ou Bouton 
	char sai_mov();
	// Initialisation du menu permet de passer le nb de choix et un tableau des chaines de choix
	uint8_t init_menu(uint8_t nb_ch_menu, String &ch_menu);
	// Reinit les entrées de l'encodeur rotatif circuit I/O i2c
	void init_eb_rot();
  private:
	void aff_menu_alpha_maitre(uint8_t pos);
	void aff_menu_alpha_string();
	void maj_ch(uint8_t pos, uint8_t menu);
	void aff_menu_Alpha_Maj(uint8_t pos, bool en_cours);
	void aff_menu_Alpha_Min(uint8_t pos, bool en_cours);
	void aff_menu_Alpha_Spe(uint8_t pos, bool en_cours);
	void aff_menu_Alpha_Val(uint8_t pos, bool en_cours);
	void aff_menu_alpha_zones(uint8_t pos, uint8_t menu, bool val_sys, bool val_det);
	void aff_rool_up(uint8_t v_pos, int v_ref, bool en_cours);
	void aff_rool_up_p10(int v_ref, bool en_cours);
	int sai_1_rool_up(uint8_t v_pos, int v_ref);
	uint8_t sel_menu_Alpha(uint8_t max);
	uint8_t sel_menu_Alpha_detail(uint8_t max, uint8_t menu);
	void aff_menu(int pos); // Affichage du menu A
	uint8_t sel_menu(int max); // Selection dans le menu A à l'aide selecteur rotatif
};

#endif
