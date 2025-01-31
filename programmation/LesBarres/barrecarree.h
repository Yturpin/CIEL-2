#ifndef BARRECARREE_H
#define BARRECARREE_H
#include "barre.h"

class BarreCarree : public Barre
{
public:
    BarreCarree(string _reference, int _longueur, float _densite, float _cote);
    ~BarreCarree();
    double calculerSection();
    virtual float calculerMasse();
    virtual void afficherCaracteristiques();


protected:
    float cote;
};

#endif // BARRECARREE_H
