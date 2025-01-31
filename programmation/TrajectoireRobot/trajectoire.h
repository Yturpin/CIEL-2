#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H
#include "element.h"

class Trajectoire
{
public:
    Trajectoire(int _nbEtapesMax);
    ~Trajectoire();
    bool ajouter(Element * _pElement);
    void afficher();

private:
    int nbEtapesMax;
    int prochaineEtape;         //
    Element ** parcours;        //tableau dynamique de pointeurs qui stock les éléments

};

#endif // TRAJECTOIRE_H
