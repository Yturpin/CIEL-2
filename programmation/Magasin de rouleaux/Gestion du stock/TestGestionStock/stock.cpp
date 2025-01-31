#include "stock.h"

Stock::Stock() {}

void Stock::AjouterRouleau(const Rouleau _nouveau)
{
    lesRouleaux.insert(_nouveau.getDiametre(), _nouveau);
}

int Stock::RechercherSerie(QMultiMap<int,Rouleau>::iterator &_positionDebut)
{
    auto _positionPremier = lesRouleaux.begin();
    _positionDebut =lesRouleaux.begin();
    int retour = lesRouleaux.size();

    if(retour > 6){
        retour = 6;
        auto positionDernier = lesRouleaux.begin();

        for(int indice = 0; indice < 6; indice++){
            positionDernier++;
        }
        int valeurRetenue = (positionDernier.value().getDiametre() - _positionPremier.value().getDiametre());

        while(positionDernier != lesRouleaux.end()){
            int ecart = (_positionPremier.value().getDiametre() - _positionPremier.value().getDiametre());
            if(ecart < valeurRetenue){
                valeurRetenue = ecart;
                _positionDebut = _positionPremier;
            }
            positionDernier++;
            _positionPremier++;
        }

    }

    return retour;
}

bool Stock::RetirerRouleauDuStock(const QMultiMap<int,Rouleau>::iterator &_positionRouleau)
{
    bool retour = false;
    if(_positionRouleau != lesRouleaux.end()){
        lesRouleaux.erase(_positionRouleau);
        retour = true;
    }

    return retour;
}

QStringList Stock::ObtenirContenuDuStock() const
{
    QStringList descriptionsStock;
    for(auto it = lesRouleaux.begin(); it != lesRouleaux.end(); it++){
        QString descriptionRouleau = QString("Réference : %1, Diamètre : %2")
                                         .arg(it.value().getReference())
                                         .arg(it.value().getDiametre());

        descriptionsStock.append(descriptionRouleau);
    }
    return descriptionsStock;
}
