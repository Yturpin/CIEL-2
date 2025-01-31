#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include "comptebancaire.h"

class CompteEpargne : public CompteBancaire
{
public:
    //CompteEpargne(const float _solde = 0, float _tauxInterets);
    float calculerInterets();
    float modifierTaux();

private:
    float tauxInterets;
};

#endif // COMPTEEPARGNE_H
