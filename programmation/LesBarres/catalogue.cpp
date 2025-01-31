#include <iostream>
#include "catalogue.h"

using namespace std;

Catalogue::Catalogue(const int _nbBarres):
    Barre(_reference, _longueur, _densite),
    nbBarres(_nbBarres)
{
    lesBarres = new Barre *[nbBarres];
    index = 0;
}
Catalogue::~Catalogue()
{
    delete[] lesBarres;
}
bool Catalogue::AjouterBarre(Barre *ptrBarre)
{
    bool retour = true;
    if (index < nbBarres)
        lesBarres[index++] = ptrBarre ;
    else
        retour = false;
    return retour;
}
void Catalogue::AfficherCatalogue()
{
    for (int indice = 0; indice < index ; indice++)
    {
        lesBarres[indice]->afficherCaracteristiques();
        cout << lesBarres[indice]->calculerMasse() << endl;
    //erreur de compilation pour cette dernière ligne
    }
}
