#include "barrecarree.h"
#include <iostream>

BarreCarree::BarreCarree(string _reference, int _longueur, float _densite, string _nomAlliage, float _cote) :
    Barre(_reference, _longueur, _densite, _nomAlliage),
    cote(_cote)
{}

void BarreCarree::afficherCaracteristique()
{
    Barre::afficherCaracteristique();
    cout << "Côté : " << cote << " cm" << endl;
    cout << "Masse :" << calculMasse() << " kg" << endl;
    cout <<"-----------------------" << endl;
    cout << endl;
}

double BarreCarree::calculSection()
{
    return cote * cote;
}

double BarreCarree::calculMasse()
{
    return calculSection() * longueur * densite / 1000.0;
}
