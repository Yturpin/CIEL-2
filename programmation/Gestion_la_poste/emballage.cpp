#include "emballage.h"
#include <iomanip>

Emballage::Emballage(const string _format, const int _resistanceMax, const int _longueur, const int _largeur, const int _hauteur)
:
    format(_format),
    resistanceMax(_resistanceMax),
    longueur(_longueur),
    largeur(_largeur),
    hauteur(_hauteur),
    nbEmballagesDispo(0)

{
    cout << "Constructeur : Emballage / " << format << endl;
}

Emballage::~Emballage()
{
    cout << "Destructeur : Emballage / " << format << endl;
}

void Emballage::Visualise()
{
    /*cout << "| " << setfill(' ') << setw(10) << format << " | " << setw(5) << resistanceMax << " | " << setw(15) << largeur << " x " << longueur;
    if(hauteur != 0)
        cout << " x " << hauteur;
    cout << " | " << endl;
    */

    /*
    cout << "+" << setfill('-') << setw(70) << "+" << setfill(' ') << endl;
    cout << "|" << setw(30) << left << "Format" << "|" << internal << "Resistance" << "|" << setw(30) << right << "Dimensions" << "| " << endl;
    cout << "+" << setfill('-') << setw(70) << "+" << setfill(' ') << endl;
    */

    cout << "| ";
    cout << setw(15) << left << format;
    cout << "| ";
    cout << left << resistanceMax << " kg" << setw(9);
    cout << right << "| ";
    cout << setw(3) << longueur << " X " << setw(3) << largeur;
    if(hauteur > 0)
        cout << " X " << setw(3) << hauteur;
    else cout << setw(6) << " ";
    cout <<"| " << endl;
}


//Surcharge d'opérateurs cours page 22
bool Emballage::operator <(Emballage &_autre)
{
    return CalculerVolume() < _autre.CalculerVolume();
}

bool Emballage::operator ==(Emballage &_autre)
{
    return (longueur == _autre.longueur && largeur == _autre.largeur && hauteur == _autre.hauteur && resistanceMax == _autre.resistanceMax);
}

Emballage::operator float()
{
    return CalculerVolume();
}


double Emballage::CalculerVolume()
{
    int volume = longueur * largeur;
    if(hauteur != 0)
        volume *= hauteur;

    double volumeCm3 = volume / 1000.0;

    return volumeCm3;

}
