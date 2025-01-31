#include "barreronde.h"
#include <math.h>

BarreRonde::BarreRonde(string _reference, int _longueur, float _densite, float _diametre):
    Barre(_reference, _longueur, _densite),
    diametre(_diametre)
{
    cout << "Appel du constructeur de BarreRonde" << endl;
    cout << endl;
}

BarreRonde::~BarreRonde()
{
    cout << "Appel du destructeur de BarreRonde" << endl;
}

void BarreRonde::afficherCaracteristiques()
{
    Barre::afficherCaracteristiques();
    cout << "Diamètre de la section : " << diametre << " cm" << endl;
}

double BarreRonde::calculerSection()
{
    return M_PI * diametre * diametre / 4;
}

float BarreRonde::calculerMasse()
{
    return calculerSection() * longueur * densite;
}

