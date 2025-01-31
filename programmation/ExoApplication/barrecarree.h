#ifndef BARRECARREE_H
#define BARRECARREE_H
#include "barre.h"

class BarreCarree : Barre
{
public:
    BarreCarree(string _reference, int _longueur, float _densite, string _nomAlliage, float _cote);
    void afficherCaracteristique();
    double calculSection();
    double calculMasse();

protected:
    float cote;
};

#endif // BARRECARREE_H
