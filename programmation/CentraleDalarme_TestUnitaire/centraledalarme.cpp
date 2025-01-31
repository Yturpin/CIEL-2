#include <QDebug>
#include "centraledalarme.h"
#include "clavier.h"

CentraleDalarme::CentraleDalarme(const int _tailleCode, QObject *parent) :
    QObject(parent),
    tailleCode(_tailleCode),
    indiceCourant(0)
{
    // Initialisation à compléter
    combinaison = new quint8[tailleCode];

    leClavier = new Clavier(this);
    leClavier->show();
}

CentraleDalarme::~CentraleDalarme()
{
    delete[] combinaison;
    delete leClavier;
}

void CentraleDalarme::FabriquerCode(const quint8 chiffre)
{
    // Code à compléter
    if(indiceCourant < tailleCode){
        combinaison[indiceCourant] = chiffre;
        indiceCourant = indiceCourant +1;
    }
    else{
        for(int i = 0; i < tailleCode - 1; i++){
            combinaison[i] = combinaison[i +1];
        }
        combinaison[tailleCode - 1] = chiffre;
    }
}
