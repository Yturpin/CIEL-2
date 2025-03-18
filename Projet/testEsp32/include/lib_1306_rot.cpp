// lib_1306_rot.cpp v2
// librairie d'utilitaires pour gérer une IHM avec un écran oled ssd1306 et un encodeur rotatif
// Gestion de menu de saisie alphanumérique de nombre et gestion des I/O i2c
// https://castoo.fr
// Février 2021

/*
lib_1306_rot.cpp
- Librairie destinée a être utilisée sur Arduino ou ESPxxx.
Possibilité de supporter différents LCD mais l'objet a été créée avec un OLED SD1306
Attention la librairie utilise la librairie oled SSD1306Wire avec un W majuscule qui n'est pas directement
disponible dans l IDE Arduino il faut la chercher sur internet sur le site "github"
Possibilité de supporter différents Encodeurs rotatifs mais l'objet a été créée avec un KY-040 30 pas
Remarque (interface 5 fils ou 2 fils voir description sur castoo.fr) :
si vous passez le parametre adr_i2c_io à 0 la lib considere que les signaux clk, dt et sw sont des num de port du processeur
si vous passez le parametre adr_i2c_io avec l'adresse du PCF85741 la lib considere que les signaux clk, dt et sw sont des sortie du PCF85741

Création 1er version Jean Michel Castille décembre 2019 / https://castoo.fr
Cette bibliothèque est un logiciel libre;
Vous pouvez la redistribuer et ou la modifier.
Cette bibliothèque est distribuée dans l'espoir qu'elle sera utile,
mais SANS AUCUNE GARANTIE, sans même la garantie implicite de
QUALITÉ MARCHANDE ou ADÉQUATION À UN USAGE PARTICULIER. 
*/

#include "lib_1306_rot.h"

// Constructeur / Initialisation
util_1306::util_1306(uint8_t adr_i2c_io, uint8_t vclk, uint8_t vdt, uint8_t vsw, SSD1306Wire &ecran){
	this->adr_i2c_io = adr_i2c_io; // Adr circuit i/o
	this->PinCLK = vclk; // Clk du selecteur rotatif
	this->PinDT = vdt; // DT du selecteur rotatif
	this->PinSW = vsw; // SW du selecteur rotatif
	this->_ecran = &ecran; // Ecran OLED
	this->sortieH = false; // N'autorise pas la sortie du balayage des caracteres par le début
	if(!this->adr_i2c_io){ 
		// Si les sorties sont des gpio du processeur on les initialise en sortie avec un rappel au +
		// ceci peut éviter des problèmes si les résistances de rappel ne sont pas installées (Merci Guy)
		pinMode(this->PinCLK, INPUT_PULLUP);
		pinMode(this->PinDT, INPUT_PULLUP);
		pinMode(this->PinSW, INPUT_PULLUP);
	}
}

// Initialise la taille de police et l'alignement sur le LCD
void util_1306::prep_aff_LCD(uint8_t typ_pol, char v_align) {
	this->_ecran->clear();
	if(typ_pol == 16) this->_ecran->setFont(ArialMT_Plain_16);
	else if(typ_pol == 24) this->_ecran->setFont(ArialMT_Plain_24);
	else this->_ecran->setFont(ArialMT_Plain_10);
	if(v_align=='D') this->_ecran->setTextAlignment(TEXT_ALIGN_RIGHT);
	else if(v_align=='C') this->_ecran->setTextAlignment(TEXT_ALIGN_CENTER);
	else this->_ecran->setTextAlignment(TEXT_ALIGN_LEFT);
}

// écrit un eb sur circuit I/O i2c
void util_1306::ecri_eb_rot(uint8_t v_eb, bool v_val){
	uint8_t lect_octet;
	if(this->adr_i2c_io){
		Wire.requestFrom(this->adr_i2c_io, 1);
		lect_octet = Wire.read();
		Wire.endTransmission();	
		bitWrite(lect_octet, v_eb, v_val);
		Wire.beginTransmission(this->adr_i2c_io);
		Wire.write(lect_octet);
		Wire.endTransmission();	
	}
}

// retourne etat d'un eb du circuit I/O i2c
bool util_1306::li_eb_rot(uint8_t v_eb){
	if(this->adr_i2c_io){
		uint8_t lect_octet;
		Wire.requestFrom(this->adr_i2c_io, 1);
		lect_octet = Wire.read();
		Wire.endTransmission();	
		return bitRead(lect_octet, v_eb);
	}else{
		return digitalRead(v_eb);
	}
}

// Reinit les entrées de l'encodeur rotatif circuit I/O i2c
void util_1306::init_eb_rot(){
	if(this->adr_i2c_io){
		uint8_t lect_octet;
		Wire.requestFrom(this->adr_i2c_io, 1);
		lect_octet = Wire.read();
		Wire.endTransmission();	
		bitWrite(lect_octet, this->PinCLK, true);
		bitWrite(lect_octet, this->PinDT, true);
		bitWrite(lect_octet, this->PinSW, true);
		Wire.beginTransmission(this->adr_i2c_io);
		Wire.write(lect_octet);
		Wire.endTransmission();	
	}
}

// retourne etat du signal SW
bool util_1306::li_rot_sw(){
	return this->li_eb_rot(this->PinSW);
}

// valide ou invalide la sortie du balayage des caracteres aprés chaque saisie
void util_1306::sortie_deb(bool val){
	this->sortieH = val;
}

// Affichage du menu Alpha
String util_1306::sai_Alpha(String v_question){
	this->_v_question = v_question; // Question passe en titre
	this->val_ch = 2;
	while (this->val_ch > 1){
		this->sel_menu_Alpha(nb_ch_menu_Alpha);
	}
	if (this->val_ch == 1) return this->ch_saisie;
		else return "";
}

// Affichage menu de selection de fonction du menu alpha
void util_1306::aff_menu_alpha_maitre(uint8_t pos){
	for (uint8_t i = 0; i < nb_ch_menu_Valid; i++) this->_ecran->drawString(105, 15+(12*i), this->ch_menuAlpha[i]);
	this->_ecran->drawRect(103, 15+(12*pos), 22, 13);
	if(this->flech_d){ this->_ecran->drawString(85, 28, "<<");this->_ecran->drawString(85, 40, "<<");}
		  else { this->_ecran->drawString(85, 28, ">>");this->_ecran->drawString(85, 40, ">>");}
}

// Affichage menu de selection de fonction du menu alpha
void util_1306::aff_menu_alpha_string(){
	this->_ecran->setFont(ArialMT_Plain_16);
	this->_ecran->setTextAlignment(TEXT_ALIGN_CENTER);
	if(this->ch_saisie.length()==0)
		this->_ecran->drawString(64,0, this->_v_question);
	else
		this->_ecran->drawString(64,0, this->ch_saisie);
	this->_ecran->setTextAlignment(TEXT_ALIGN_LEFT);
	this->_ecran->setFont(ArialMT_Plain_10);
}

// Un caractere a été selectionné on met à jour la chaine de saisie
void util_1306::maj_ch(uint8_t pos, uint8_t menu){
	uint8_t car = 0;
	switch (menu){
		case 0 :
			car = pos + 64;
			break;
		case 1 :
			car = pos + 95;
			break;
		case 2 :
			car = pos + 32;
			break;
		case 3 :
			switch(pos){
				case 0 :
					// Correction
					this->ch_saisie.remove((this->ch_saisie.length())-1);
				break;
				case 1 :
					// Tout effacer
					this->ch_saisie = "";
				break;
				case 2 :
					// Validation
					this->val_ch = 1;
				break;
				case 3 :
					// Annulation
					this->val_ch = 0;
				break;
			}
			break;
	}
	if(menu < 3){
		char ch_car = car;
		this->ch_saisie = this->ch_saisie + ch_car;
	}
}

// Affichage du menu Alpha Maj.
void util_1306::aff_menu_Alpha_Maj(uint8_t pos, bool en_cours){
	char ch_i[2];
	uint8_t vx;
	uint8_t vy;
	for (uint8_t i = 64; i < 92; i++){
		snprintf(ch_i, 2, "%c", i);
		vy = 15+(12 * ((i - 64) % 4));
		vx = ((i - 64) / 4) * 10;
		this->_ecran->drawString(vx, vy, ch_i );
	}
	if (en_cours) {
		vy = 15+(12 * (pos % 4));
		vx = (pos / 4) * 10;
		this->_ecran->drawRect(vx, vy, 10, 13);
	}
}

// Affichage du menu Alpha Min.
void util_1306::aff_menu_Alpha_Min(uint8_t pos, bool en_cours){
	char ch_i[2];
	uint8_t vx;
	uint8_t vy;
	//for (uint8_t i = 96; i < 124; i++){
	for (uint8_t i = 95; i < 127; i++){
		snprintf(ch_i, 2, "%c", i);
		vy = 15+(12 * ((i - 95) % 4));
		vx = ((i - 95) / 4) * 10;
		this->_ecran->drawString(vx, vy, ch_i );
	}
	if (en_cours) {
		vy = 15+(12 * (pos % 4));
		vx = (pos / 4) * 10;
		this->_ecran->drawRect(vx, vy, 10, 13);
	}
}

// Affichage du menu Alpha Car. Spe.
void util_1306::aff_menu_Alpha_Spe(uint8_t pos, bool en_cours){
	char ch_i[2];
	uint8_t vx;
	uint8_t vy;
	for (uint8_t i = 32; i < 64; i++){
		snprintf(ch_i, 2, "%c", i);
		vy = 15+(12 * ((i - 32) % 4));
		vx = ((i - 32) / 4) * 10;
		this->_ecran->drawString(vx, vy, ch_i );
	}
	if (en_cours) {
		vy = 15+(12 * (pos % 4));
		vx = (pos / 4) * 10;
		this->_ecran->drawRect(vx, vy, 10, 13);
	}
}

// Affichage du menu Alpha Val/Annul.
void util_1306::aff_menu_Alpha_Val(uint8_t pos, bool en_cours){
	for (uint8_t i = 0; i < nb_ch_menu_Valid; i++) this->_ecran->drawString(10, 15+(12*i), this->ch_menuValid[i]);
	if (en_cours) {
		this->_ecran->drawRect(0, 15+(pos*12), 80, 13);
	}
}

// Affichage ensemble
void util_1306::aff_menu_alpha_zones(uint8_t pos, uint8_t menu, bool val_sys, bool val_det){
	this->_ecran->clear();
	this->aff_menu_alpha_maitre(menu);
	switch(menu){
		case 0 :
			this->aff_menu_Alpha_Maj(pos, val_det);
			if(val_sys){ delay(300); this->sel_menu_Alpha_detail(28, menu);}
			break;
		case 1 :
			this->aff_menu_Alpha_Min(pos, val_det);
			if(val_sys){ delay(300);  this->sel_menu_Alpha_detail(28, menu);}
			break;
		case 2 :
			this->aff_menu_Alpha_Spe(pos, val_det);
			if(val_sys){ delay(300);  this->sel_menu_Alpha_detail(32, menu);}
			break;
		case 3 :
			this->aff_menu_Alpha_Val(pos, val_det);
			if(val_sys){ delay(300);  this->sel_menu_Alpha_detail(4, menu);}
			break;
	}
	this->aff_menu_alpha_string();
	this->_ecran->display();
}

// Selection dans le menu Alpha dans la partie droite
uint8_t util_1306::sel_menu_Alpha(uint8_t max){
	this->flech_d = true;
	max--;
	bool B_val = false, val_clk = true, memo_clk = true;
	int B_choix = 0;
	this->aff_menu_alpha_zones(0, B_choix, false, false);
	while (! B_val){
		val_clk = this->li_eb_rot(this->PinCLK);
		if (val_clk != memo_clk){
			if (this->li_eb_rot(this->PinDT) != val_clk) { B_choix++; if (B_choix > max) B_choix = max;}
				else { B_choix--; if (B_choix < 0) B_choix = 0;}
			this->aff_menu_alpha_zones(0, B_choix, false, false); delay(10);
		}
		if (!(this->li_eb_rot(this->PinSW))) { B_val = true; } // Bouton validation
		memo_clk = val_clk;	delay(5);
	}
	this->aff_menu_alpha_zones(0, B_choix, true, false);
	return B_choix;
}

// Selection dans le menu Alpha dans la partie gauche
uint8_t util_1306::sel_menu_Alpha_detail(uint8_t max, uint8_t menu){
	this->flech_d = false;
	max--;
	bool B_val = false, val_clk = true, memo_clk = true;
	int B_choix = 0;
	this->aff_menu_alpha_zones(B_choix, menu, false, true);
	while (! B_val){
		val_clk = this->li_eb_rot(this->PinCLK);
		if (val_clk != memo_clk){
			if (this->li_eb_rot(this->PinDT) != val_clk) {
				B_choix++;
				if (B_choix > max){
					B_choix = 0;
					return B_choix;
				}
			} else { 
				B_choix--;
				if (B_choix < 0){ 
					B_choix = 0;
					if(this->sortieH) return B_choix;
				}
			}
			this->aff_menu_alpha_zones(B_choix, menu, false, true); delay(10);
		}
		if (!(this->li_eb_rot(this->PinSW))) { B_val = true; } // Bouton validation
		memo_clk = val_clk;	delay(5);
	}
	maj_ch(B_choix, menu);
	if(this->val_ch < 2) return 0;
	delay(100);
	this->aff_menu_alpha_zones(B_choix, menu, true, false);
	return B_choix;
}

// Affichage un rool up
void util_1306::aff_rool_up(uint8_t v_pos, int v_ref, bool en_cours=false){
	int vx = 0;
	int vs_ref = v_ref-1;
	switch (v_pos){
		case 1 : vx = 5; break;
		case 2 : vx = 25; break;
		case 3 : vx = 45; break;
	}
	this->_ecran->setColor(BLACK);
	this->_ecran->fillRect(vx-3, 15, 21, 48);
	this->_ecran->setColor(WHITE);
	this->_ecran->drawRect(vx, 16, 15, 48);
	if(en_cours){
		this->_ecran->drawRect(vx-1, 16, 17, 48);
		this->_ecran->drawRect(vx-2, 16, 19, 48);
		this->_ecran->drawRect(vx-3, 16, 21, 48);
	}
	this->_ecran->setFont(ArialMT_Plain_10);
	if(vs_ref<0) vs_ref = 9;
	this->_ecran->drawString(vx + 6, 18, String(vs_ref));
	this->_ecran->setFont(ArialMT_Plain_24);
	this->_ecran->drawString(vx + 2, 26, String(v_ref));
	this->_ecran->setFont(ArialMT_Plain_10);
	if((v_ref+1)>9) vs_ref = 0; else vs_ref = v_ref+1;
	this->_ecran->drawString(vx + 6, 49, String(vs_ref));
	this->_ecran->display();
}

// Affichage un rool up string Puissance de 10
void util_1306::aff_rool_up_p10(int v_ref, bool en_cours=false){
	int vx = 65;
	int vs_ref = v_ref-1;
	this->_ecran->setColor(BLACK);
	this->_ecran->fillRect(vx-3, 16, 66, 48);
	this->_ecran->setColor(WHITE);
	this->_ecran->drawRect(vx, 16, 60, 48);
	if(en_cours){
		this->_ecran->drawRect(vx-1, 16, 62, 48);
		this->_ecran->drawRect(vx-2, 16, 64, 48);
		this->_ecran->drawRect(vx-3, 16, 66, 48);
	}
	this->_ecran->setFont(ArialMT_Plain_10);
	if(vs_ref<0) vs_ref = 6;
	this->_ecran->drawString(vx + 20, 18, "10P" + String(vs_ref));
	this->_ecran->setFont(ArialMT_Plain_24);
	this->_ecran->drawString(vx + 2, 26, "10P" + String(v_ref));
	this->_ecran->setFont(ArialMT_Plain_10);
	if((v_ref+1)>6) vs_ref = 0; else vs_ref = v_ref+1;
	this->_ecran->drawString(vx + 20, 49, "10P" + String(vs_ref));
	this->_ecran->display();
}

// Saisie d'un rool up
int util_1306::sai_1_rool_up(uint8_t v_pos, int v_ref){
	int vx = 0;
	bool B_val = false, val_clk = true, memo_clk = true;
	if(v_pos==0)
		this->aff_rool_up_p10(v_ref, true);
	else
		this->aff_rool_up(v_pos, v_ref, true);
	while (! B_val){
		val_clk = this->li_eb_rot(this->PinCLK);
		if (val_clk != memo_clk){
			if (this->li_eb_rot(this->PinDT) != val_clk) {
				v_ref++;
				if(v_pos==0){
					if(v_ref>6) v_ref=0;
				}else{
					if(v_ref>9) v_ref=0;
				}
			}else{ 
				v_ref--;
				if(v_pos==0){
					if(v_ref<0) v_ref = 6;
				}else{
					if(v_ref<0) v_ref = 9;
				}
			}
			if(v_pos==0)
				this->aff_rool_up_p10(v_ref, true);
			else
				this->aff_rool_up(v_pos, v_ref, true);
			delay(10);
		}
		if (!(this->li_eb_rot(this->PinSW))) { B_val = true; } // Bouton validation
		memo_clk = val_clk;	delay(5);
	}
	if(v_pos!=0){
		switch (v_pos){
			case 1 : vx = 5; break;
			case 2 : vx = 25; break;
			case 3 : vx = 45; break;
		}
		this->_ecran->setColor(BLACK);
		this->_ecran->drawRect(vx-1, 16, 18, 48);
		this->_ecran->drawRect(vx-2, 16, 19, 48);
		this->_ecran->drawRect(vx-3, 16, 20, 48);
		this->_ecran->setColor(WHITE);
		this->_ecran->drawRect(vx, 16, 15, 48);
	}
	return v_ref;
}

// Aff complet des rool up
double util_1306::sai_Num(uint8_t nb_pos, bool aff_p10, String titre_sai){
	int res=0;
	if(nb_pos>0 && nb_pos<4){
		uint8_t t_res[4];
		this->prep_aff_LCD(16, 'C');
		this->_ecran->drawString(64, 0, titre_sai);
		this->prep_aff_LCD(10, 'G');
		for(uint8_t cpt=1; cpt <= nb_pos; cpt++){
			this->aff_rool_up(cpt, 0);
		}
		if(aff_p10) this->aff_rool_up_p10(0);
		for(uint8_t cpt=1; cpt <= nb_pos; cpt++){
			t_res[cpt] = this->sai_1_rool_up(cpt, 0);
			delay(500);
		}
		if(aff_p10) t_res[0] = this->sai_1_rool_up(0,0);
		delay(500);
		switch (nb_pos){
			case 1 : res = t_res[1]; break;
			case 2 : res = (t_res[1]*10)+t_res[2]; break;
			case 3 : res = (t_res[1]*100)+(t_res[2]*10)+t_res[3]; break;
		}
		if(aff_p10) res = res * pow(10, t_res[0]);
	}
	return res;
}

// Saisie d'un deplacement
char util_1306::sai_mov(){
	delay(200);
	bool B_val = false, val_clk = true, memo_clk = true;
	char v_char = 'T';
	while (v_char == 'T'){
		val_clk = this->li_eb_rot(this->PinCLK);
		if (val_clk != memo_clk){
			if (this->li_eb_rot(this->PinDT) != val_clk) {
				v_char = 'G';
			}else{ 
				v_char = 'D';
			}
			delay(10);
		}
		if (!(this->li_eb_rot(this->PinSW))) { v_char = 'B'; } // Bouton validation
		memo_clk = val_clk;	delay(5);
	}
	return v_char;
}

// Initialisation du menu permet de passer le nb de choix et un tableau des chaines de choix
uint8_t util_1306::init_menu(uint8_t nb_ch_menu, String &ch_menu){
	this->ch_saisie = "";
	this->_ecran->flipScreenVertically();
	this->_ecran->setFont(ArialMT_Plain_10);
	this->_ecran->setTextAlignment(TEXT_ALIGN_LEFT);
	this->max_ch = nb_ch_menu;
	this->_ch_menu = &ch_menu;
	return this->sel_menu(this->max_ch);
}

// Affichage du menu et encadrement de la valeur en cours de selection
void util_1306::aff_menu(int pos){
	this->_ecran->clear();
	for (uint8_t i = 0; i < this->max_ch; i++) this->_ecran->drawString(0, (12*i), this->_ch_menu[i+1]);
    this->_ecran->drawRect(0, (12*pos), (this->_ch_menu[pos+1].length()*5)+25, 13);
	this->_ecran->display();
}

// Selection dans le menu à l'aide du selecteur rotatif
uint8_t util_1306::sel_menu(int max){
	max--;
	bool B_val = false, val_clk = true, memo_clk = true;
	int B_choix = 0;
	this->aff_menu(B_choix);
	while (! B_val){
		val_clk = this->li_eb_rot(this->PinCLK);
		if (val_clk != memo_clk){
			if (this->li_eb_rot(this->PinDT) != val_clk) { B_choix++; if (B_choix > max) B_choix = max;}
				else { B_choix--; if (B_choix < 0) B_choix = 0;}
			this->aff_menu(B_choix); delay(10);
		}
		if (!(this->li_eb_rot(this->PinSW))) { B_val = true; } // Bouton validation
		memo_clk = val_clk;	delay(5);
	}
	this->aff_menu(B_choix);
	return B_choix;
}
