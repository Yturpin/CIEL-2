#include "miseenoeuvrebdd.h"
#include "ui_miseenoeuvrebdd.h"

MiseEnOeuvreBDD::MiseEnOeuvreBDD(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MiseEnOeuvreBDD)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();    //Vérifier les drivers prsts

    //CONFIG BDD
    db = QSqlDatabase::addDatabase("QMARIADB");
    db.setHostName("172.18.58.7");
    db.setDatabaseName("france2018");
    db.setUserName("snir");
    db.setPassword("snir");

    //VERIFICATION DE LA CONNEXION À LA BDD
    if(db.open()){
        qDebug() << "Connexion réussie à la BDD";
        chargerRegion();
    }
    else{
        qDebug() << "Echec de la connexion à la BDD";
    }
}

MiseEnOeuvreBDD::~MiseEnOeuvreBDD()
{
    delete ui;
}

void MiseEnOeuvreBDD::on_pushButtonObtenirNomDep_clicked()
{
    QString code = ui->lineEditCodeDepartement->text();
    if(!code.isEmpty())
    {
        if(db.isOpen())
        {
            QSqlQuery requete;
            requete.prepare("SELECT name FROM departments WHERE code = :code");
            requete.bindValue(":code", code);
            if(requete.exec())
            {
                qDebug() << "Requete exécuté : " << requete.lastQuery();
                if(requete.next())
                {
                    QString nom = requete.value("name").toString();
                    ui->lineEditNomDepartement->setText(nom);
                }
                else
                {
                    QMessageBox::critical(this, "Erreur", "Ce code de département n'existe pas");
                }
            }
            else
            {
                qDebug() << "Erreur lors de la sélection : " << requete.lastError().text();
            }
        }
    }
}

void MiseEnOeuvreBDD::chargerRegion()
{
    QSqlQuery requete;
    requete.prepare("SELECT name, code FROM regions");
    if(requete.exec())
    {
        QString nom;
        QString id;
        ui->comboBoxRegions->clear();
        ui->comboBoxRegions->addItem("Choisissez une région", QVariant());
        qDebug() << "Requete exécuté : " << requete.lastQuery();
        while(requete.next())
        {
            nom = requete.value("name").toString();
            id = requete.value("code").toString();
            ui->comboBoxRegions->addItem(nom, id);
        }
    }
    else qDebug() << "Erreur lors de la sélection des régions: " << requete.lastError().text();
}


void MiseEnOeuvreBDD::on_comboBoxRegions_currentIndexChanged(int index)
{
    QSqlQuery requete;
    requete.prepare("SELECT name, code FROM departments WHERE code FROM regions");

    QString idRegion = ui->comboBoxRegions->itemData(index).toString();
    ui->comboBoxDepartements->clear();
    ui->comboBoxDepartements->addItem("Choisissez un département");

    //if(idRegion.isEmpty())
    qDebug() << "Requete exécuté : " << requete.lastQuery();
}


void MiseEnOeuvreBDD::on_comboBoxDepartements_currentIndexChanged(int index)
{

}

