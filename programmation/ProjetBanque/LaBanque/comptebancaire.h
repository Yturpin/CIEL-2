#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

using namespace std;

class CompteBancaire
{
public:
    CompteBancaire(const float _solde = 0);
    void Deposer (float _montant);
    bool Retirer(float _montant);
    float ConsulterSolde();

protected:
    float solde;
};

#endif // COMPTEBANCAIRE_H
