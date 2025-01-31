#include "barrerectangle.h"
#include "math.h"
#include <iostream>

BarreRectangle::BarreRectangle(string _reference,
                               int _longueur,
                               float _densite,
                               string _nomAlliage,
                               float _largeurRect):
    Barre(_reference, _longueur, _densite, _nomAlliage),
    largeurRect(_largeurRect)
{
    cout << "Constructeur de BarreRectangle" << endl;
}

void BarreRectangle::afficherCaracteristique(){
    Barre::afficherCaracteristique();
    cout << "Largeur de la Barre : " << largeurRect << " cm" << endl;
    cout << "Masse : " << BarreRectangle::calculMasse() << "kg" << endl;
    cout <<"-----------------------" << endl;
    cout << endl;
}

double BarreRectangle::calculSection(){
    return longueur * largeurRect;
}

double BarreRectangle::calculMasse()
{
    return (calculSection() * longueur * densite) / 1000.0; //on divise par 1000 pour obtenir des kilos
}
