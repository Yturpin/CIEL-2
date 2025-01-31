#include "alveoleslibres.h"
#include <QDebug>

AlveolesLibres::AlveolesLibres(const int _nbRangees, const int _nbColonnes):
    nbRangeees(_nbRangees),
    nbColonnes(_nbColonnes)
{
    reserve(nbRangeees * nbColonnes);
    for (int indice = 0; indice < nbRangeees * nbColonnes; ++indice)
    {
        push(indice + 1);  // Réserve le nombre d'alvéoles
    }
    qDebug() << "Dans le constructeur : " << *this;
}

bool AlveolesLibres::Reserver(int &_rangee, int &_colonne)
{
    bool retourLibre = false;

    if(!isEmpty())
    {
        int numAlveole = pop();
        _rangee = ((numAlveole - 1) / nbColonnes) + 1;
        _colonne = ((numAlveole - 1) % nbColonnes) + 1;
        retourLibre = true;
    }
    qDebug() << "Dans réserver : " << *this;

    return retourLibre;
}

void AlveolesLibres::Liberer(const int _rangee, const int _colonne)
{
    //bool retourLibre = false;

    int numAlveole = (_rangee - 1) * nbColonnes + _colonne;
    if(!contains(numAlveole))
    {
        push(numAlveole);
        //retourLibre = true;
    }
    qDebug() << "Dans libérer : " << *this;

    //return retourLibre;
}
