#include "alveoleslibres.h"


AlveolesLibres::AlveolesLibres(const int _nbRangees, const int _nbColonnes):
    nbRangees(_nbRangees),
    nbColonnes(_nbColonnes)
{

    reserve(nbRangees * nbColonnes);

    for(int i = 0; i < nbRangees * nbColonnes; i++){
        push(i + 1); //Réserve le nb d'alvéoles
    }

    qDebug() << "Dans le constructeur : "<< *this;

}

bool AlveolesLibres::Reserver(int &_rangee, int &_colonne)
{
    /*
    pop() Retire l’élément au sommet de la pile
    isEmpty() Retourne true si la pile est vide
    */

    bool retourLibre = false;

    if(!isEmpty()){
        int numAlveole = pop();
        _rangee = ((numAlveole - 1) / nbColonnes) + 1;
        _colonne = ((numAlveole - 1) % nbColonnes) + 1;
        retourLibre = true;
    }

    qDebug() << "Dans le Reserver :" << *this;

    return retourLibre;
}

void AlveolesLibres::Liberer(const int _rangee, const int _colonne)
{
    /*
    Push()Ajouter un élément au sommet de la pile
    Contains()  Retourne true si l’élément est présent dans la pile
    */

    int numAlveole = (_rangee - 1) * nbColonnes + _colonne;
    if(!contains(numAlveole)){
        push(numAlveole);
    }

    qDebug() << "Dans libérer : " << *this;
}
