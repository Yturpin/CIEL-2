#include "comptebancaire.h"

CompteBancaire::CompteBancaire(const float _solde):
    solde(_solde)
{

}

void CompteBancaire::Deposer(float _montant)
{
    solde += _montant;
}

bool CompteBancaire::Retirer(float _montant)
{
    solde -= _montant;
}

float CompteBancaire::ConsulterSolde()
{
    return solde;
}

//VOIR COURS PAGE 31
