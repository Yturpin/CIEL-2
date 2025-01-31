#ifndef STOCK_H
#define STOCK_H

#include <QObject>
#include <QMultiMap>
#include <QStringList>
#include "rouleau.h"

class Stock : public QObject
{
    Q_OBJECT
public:
    explicit Stock(QObject *parent = nullptr);
    void AjouterRouleau(const Rouleau _nouveau);
    int RechercherSerie(QMultiMap<int,Rouleau>::iterator &_positionDebut);
    bool RetirerRouleauDuStock(const QMultiMap<int,Rouleau>::iterator &_positionRouleau);
    QStringList ObtenirContenuDuStock() const;

private:
    QMultiMap<int,Rouleau> lesRouleaux;
};

#endif // STOCK_H
