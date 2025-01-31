#include "barreronde.h"
#include <math.h>
#include <iostream>

using namespace std;

BarreRonde::BarreRonde(string _reference, int _longueur, float _densite, string _nomAlliage, float _diametre):
    Barre(_reference, _longueur, _densite, _nomAlliage),
    diametre(_diametre)
{}

void BarreRonde::afficherCaracteristique()
{
    Barre::afficherCaracteristique();
    cout << "Diametre : " << diametre << endl;
    cout << "Masse : " << BarreRonde::calculMasse() << endl;
    cout <<"-----------------------" << endl;
    cout << endl;
}

double BarreRonde::calculSection()
{
    return (M_PI * diametre * diametre) /4;
}

double BarreRonde::calculMasse()
{
    return calculSection() * longueur * densite;
}
