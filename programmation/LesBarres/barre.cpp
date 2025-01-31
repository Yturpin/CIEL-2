#include "barre.h"

Barre::Barre(string _reference, int _longueur, float _densite):
    reference(_reference),
    longueur(_longueur),
    densite(_densite)
{
    cout << "Appel du constructeur de Barre" << endl;
}

Barre::~Barre()
{
    cout << "Appel du destructeur de Barre" << endl;
}

void Barre::afficherCaracteristiques()
{
    cout << "Réference : " << reference << endl;
    cout << "Longueur : " << longueur << " cm" << endl;
    cout << "Densité : " << densite << " g/cm³" << endl;

}
