#include "vraiaccesbdd.h"

VraiAccesBdd::VraiAccesBdd(QObject *parent)
    : QObject{parent}
    , db(new QSqlDatabase)
{
    qDebug() << QSqlDatabase::drivers();    //Vérifier les drivers prsts

}

bool VraiAccesBdd::ConnecterAuSGBD(const QStringList _paramConnexion)
{

    //CONFIG BDD
    *db = QSqlDatabase::addDatabase("QMARIADB");
    db->setHostName(_paramConnexion[0]);
    db->setDatabaseName(_paramConnexion[1]);
    db->setUserName(_paramConnexion[2]);
    db->setPassword(_paramConnexion[3]);

    //VERIFICATION DE LA CONNEXION À LA BDD
    if(db->open()){
        qDebug() << "Connexion réussie à la BDD";
        return true;
    }
    else{
        qDebug() << "Echec de la connexion à la BDD" << db->lastError().text();
        return false;
    }

}

void VraiAccesBdd::Deconnecter()
{
    db->close();
    QTimer::singleShot(100,this, [=]() { // Délai de 100ms avant de retirer la base
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    });
}

void VraiAccesBdd::ObtenirAgences(QComboBox *_lesAgences)
{
    if(db->isOpen()){
        QSqlQuery requete("SELECT nom, id FROM Agences");
        if(requete.exec()){
            while(requete.next()){
                int id = requete.value("id").toInt();
                QString nom = requete.value("nom").toString();
            }
        }
        else{
            qDebug() << "Erreur lors de la création";
        }
    }


}

bool VraiAccesBdd::AjouterClient(const Client _client)
{

    bool retourAjout = false;

    if(db->isOpen()){
        QSqlQuery requete;
        requete.prepare("INSERT INTO comptes VALUES (:idCompte, :solde, :nom, :prenom, :ville, :idAgence");

        requete.bindValue(":idCompte", _client.idCompte);
        requete.bindValue(":solde", _client.solde);
        requete.bindValue(":nom", _client.nom);
        requete.bindValue(":prenom", _client.prenom);
        requete.bindValue(":ville", _client.ville);
        requete.bindValue(":idAgence", _client.idAgence);

        if (requete.exec())
            qDebug() << "Requete exécuté : " << requete.lastQuery();
        else
            qDebug() << "Erreur lors de l'ajout d'un utilisateur : " << requete.lastError().text();
        retourAjout = true;
    }

    return retourAjout;
}

QSqlTableModel *VraiAccesBdd::ConsulterComptesClients(const int _agence)
{    
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable("comptes");
    QString filtre = "id_agence = " + QString::number(_agence);
    model->setFilter(filtre);
    model->setSort(1, Qt::AscendingOrder);
    model->select();

    return model;
}
