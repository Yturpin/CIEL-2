#ifndef BARRERONDE_H
#define BARRERONDE_H
#include "barre.h"

class BarreRonde: public Barre
{
public:
    BarreRonde(string _reference, int _longueur, float _densite, string _nomAlliage, float _diametre);
    void afficherCaracteristique();
    double calculSection();
    double calculMasse();

protected:                  //En cas de besoin au niveau de l'héritage
    float diametre;
};

#endif // BARRERONDE_H
