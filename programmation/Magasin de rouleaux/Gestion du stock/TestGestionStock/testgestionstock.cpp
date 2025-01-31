#include "testgestionstock.h"
#include "ui_testgestionstock.h"

TestGestionStock::TestGestionStock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionStock)
{
    ui->setupUi(this);
}

TestGestionStock::~TestGestionStock()
{
    delete ui;
}

void TestGestionStock::on_pushButtonAjouterNouveau_clicked()
{
    QString reference = ui->lineEditReference->text();
    int diametre = ui->lineEditDiametre->text().toInt();

    if(!reference.isEmpty() && diametre > 0){
        Rouleau nouveauRouleau(reference, diametre);
        leStock.AjouterRouleau(nouveauRouleau);

        ui->listWidgetStock->clear();
        QStringList descriptionStock = leStock.ObtenirContenuDuStock();
        ui->listWidgetStock->addItems(descriptionStock);
    }
}


void TestGestionStock::on_pushButtonDemanderRetrait_clicked()
{
    nbRouleaux = leStock.RechercherSerie(debut);
    ui->listWidgetRouleauxRetenus->clear();
    auto posDebut = debut;

    for(int indice = 0; indice < nbRouleaux; indice++){
        QString descriptionRetenus = QString("Référence : %1, Diamètre : %2")
                                         .arg(posDebut.value().getReference())
                                         .arg(posDebut.value().getDiametre());

        posDebut++;
        ui->listWidgetRouleauxRetenus->addItem(descriptionRetenus);
    }
}


void TestGestionStock::on_pushButtonSupprimerDuSotck_clicked()
{
    auto posDebut = debut;

    for(int indice = 0; indice < nbRouleaux; indice++){
        posDebut++;
        leStock.RetirerRouleauDuStock(debut);
        debut = posDebut;
    }

    ui->listWidgetStock->clear();
    QStringList descriptionStock = leStock.ObtenirContenuDuStock();
    ui->listWidgetStock->addItems(descriptionStock);
    ui->listWidgetRouleauxRetenus->clear();
}


void TestGestionStock::on_pushButtonEnregistrer_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), "/home/USERS/ELEVES/CIEL2023/yturpin/Ciel2_2024-2025/Magasin de rouleaux/Gestion du stock",
                                                    tr("Fichiers texte (*.txt);;Tous les fichiers(*)"));
    if(!fileName.isEmpty()){
        QFile monFile(fileName);
        if(monFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream in(&monFile);
        }
    }
}


void TestGestionStock::on_pushButtonCharger_clicked()
{
    QFile monFile("testFile.txt");

    //Ecrire le contenu du stock dans un fichier
    if(monFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        while(!monFile.atEnd());
        QDataStream out(&monFile);
        //QStringList descriptionStock = leStock.ObtenirContenuDuStock();
        //in >> descriptionStock;
        out << leStock.ObtenirContenuDuStock();
        monFile.close();
    }
    else{
        qDebug() << "Impossible d'ouvrir le fichier en lecture";
    }
}

