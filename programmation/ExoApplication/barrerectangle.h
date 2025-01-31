#ifndef BARRERECTANGLE_H
#define BARRERECTANGLE_H
#include "barre.h"

class BarreRectangle : public Barre
{
public:
    BarreRectangle(string _reference, int _longueur, float _densite, string _nomAlliage, float _largeurRect);
    void afficherCaracteristique();
    double calculSection();
    double calculMasse();


protected:
    float longueurRect;
    float largeurRect;
};

#endif // BARRERECTANGLE_H
