#include "magasin.h"
#include "ui_magasin.h"
#include <QMessageBox>

Magasin::Magasin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Magasin)
{
    ui->setupUi(this);
}

Magasin::~Magasin()
{
    delete ui;
}

void Magasin::on_pushButtonEntrerRouleau_clicked()
{
    QString reference = ui->lineEditReference->text();
    int diametre = ui->lineEditDiametre->text().toInt();

    int rangee;
    int colonne;
    bool placeDisponible = lesAlveoles.Reserver(rangee, colonne);

    if(placeDisponible)
    {
        Rouleau nouveau(reference, diametre, this);
        nouveau.AffecterLocalisation(rangee, colonne);
        leStock.AjouterRouleau(nouveau);
        leChariot.DeplacerChariot(rangee, colonne, Chariot::VERS_MAGASIN);
        AfficherStock();
    }
    else
    {
        QMessageBox messageErreur(QMessageBox::Warning, "Erreur à l'entrée du magasin!\n",
                                  "Le magasin est plein");
        messageErreur.exec();
    }

}

void Magasin::on_pushButtonSortirSerieDeRouleaux_clicked()
{
    QMultiMap<int,Rouleau>::iterator debut;
    int nbRouleaux = leStock.RechercherSerie(debut);
    ui->listWidgetEnceinte->clear();

    if(nbRouleaux > 0)
    {
        auto posDebut = debut;
        for (int indice = 0; indice < nbRouleaux; ++indice) {
            Rouleau unRouleau = posDebut.value();
            int rangee;
            int colonne;
            unRouleau.ObtenirLocalisation(rangee, colonne);
            lesAlveoles.Liberer(rangee, colonne);
            leChariot.DeplacerChariot(rangee, colonne, Chariot::VERS_ENCEINTE);
            debut++;
            leStock.RetirerRouleauDuStock(posDebut);
            AfficherRouleauEnceinte(unRouleau);
            AfficherStock();
            posDebut = debut;
        }
    }
else
    {
        QMessageBox messageErreur(QMessageBox::Warning, "Erreur à la sortie du magasin!\n",
                                  "Le magasin est vide");
        messageErreur.exec();
    }
}

void Magasin::AfficherStock()
{
    ui->listWidgetStock->clear();
    QStringList descriptions = leStock.ObtenirContenuDuStock();
    ui->listWidgetStock->addItems(descriptions);
}

void Magasin::AfficherRouleauEnceinte(const Rouleau &rouleau)
{
    QString description = QString("Référence : %1, Diamètre : %2")
                              .arg(rouleau.getReference())
                              .arg(rouleau.getDiametre());

    ui->listWidgetEnceinte->addItem(description);
}
