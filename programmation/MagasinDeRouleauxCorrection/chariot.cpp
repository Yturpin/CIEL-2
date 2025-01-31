#include "chariot.h"
#include <QMessageBox>

Chariot::Chariot(QObject *parent)
    : QObject{parent}
{}

void Chariot::DeplacerChariot(const int rangee, const int colonne, const bool sens)
{
    QMessageBox messageChariot(QMessageBox::Information, "Le chariot", "");

    QString leText;
    if(sens == VERS_MAGASIN)
    {
        leText = QString("Dépot d'un rouleau dans le magasin en %1 - %2")
                     .arg(rangee)
                     .arg(colonne);
    }
    else
    {
        leText = QString("Retrait du rouleau à partir de l'alvéole : %1 - %2")
                     .arg(rangee)
                     .arg(colonne);
    }
    messageChariot.setText(leText);
    messageChariot.exec();
}
