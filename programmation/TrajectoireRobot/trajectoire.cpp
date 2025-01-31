#include "trajectoire.h"
#include "segment.h"
#include <iostream>

using namespace std;

Trajectoire::Trajectoire(int _nbEtapesMax):
    nbEtapesMax(_nbEtapesMax),
    prochaineEtape(0)

{
    parcours = new Element * [nbEtapesMax];         //tableau dynamique
}

Trajectoire::~Trajectoire()
{
    for(int indice = 0; indice < prochaineEtape; indice++){
        delete parcours[indice];
    }
    delete parcours;
}

bool Trajectoire::ajouter(Element *_pElement)
{
    bool retour = false;


    if(prochaineEtape < nbEtapesMax){
        parcours[prochaineEtape] = _pElement;
        prochaineEtape++;
        parcours[prochaineEtape - 1]->setNumero(prochaineEtape);
        retour = true;
    }
    return retour;
}

void Trajectoire::afficher()
{
    cout << "Trajectoire :" << endl;
    cout << endl;

    for (int indice = 0; indice < prochaineEtape; indice++) {
        parcours[prochaineEtape];
        cout << "(" << indice << ")" << "Trajectoire :" << endl;
    }

}
//TD page 3 vecteur à la place de string
