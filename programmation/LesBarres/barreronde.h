#ifndef BARRERONDE_H
#define BARRERONDE_H
#include "barre.h"


class BarreRonde :  public Barre
{
public:
    BarreRonde(string _reference, int _longueur, float _densite, float _diametre);
    ~BarreRonde();
    virtual void afficherCaracteristiques();
    virtual float calculerMasse();
    double calculerSection();

protected:
    float diametre;
};

#endif // BARRERONDE_H
