#include "barrecarree.h"

BarreCarree::BarreCarree(string _reference, int _longueur, float _densite, float _cote):
    Barre(_reference, _longueur, _densite),
    cote(_cote)
{
    cout << "Appel du constructeur de BarreCarree" << endl;
    cout << endl;
}

BarreCarree::~BarreCarree()
{
    cout << "Appel du destructeur de BarreCarree" << endl;
}

double BarreCarree::calculerSection()
{
    return cote * cote;
}

float BarreCarree::calculerMasse()
{
    return longueur * calculerSection() * densite;
}

void BarreCarree::afficherCaracteristiques()
{
    Barre::afficherCaracteristiques();
    cout << "Côté du carré: " << cote << " cm" << endl;
}
