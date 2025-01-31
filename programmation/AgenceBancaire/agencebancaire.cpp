#include "agencebancaire.h"
#include "ui_agencebancaire.h"

AgenceBancaire::AgenceBancaire(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AgenceBancaire)
    , laBdd(new VraiAccesBdd(this))
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);

    QSettings settings("Touchard", "AgenceBancaire");
    if(settings.contains("Bdd/HostName")){
        settings.beginGroup("Bdd");
        ui->lineEditAdresseIP->setText(settings.value("HostName").toString());
        ui->lineEditBdd->setText(settings.value("DataBase").toString());
        ui->lineEditLogin->setText(settings.value("Login").toString());
        ui->lineEditMotDePasse->setText(settings.value("Mdp").toString());
        settings.endGroup();
    }
}

AgenceBancaire::~AgenceBancaire()
{
    delete ui;
    delete laBdd;
}

void AgenceBancaire::on_pushButtonConnexio_clicked()
{
    if(ui->pushButtonConnexio->text() == "Connexion"){
        QStringList connexion;
        connexion << ui->lineEditAdresseIP->text();
        connexion << ui->lineEditBdd->text();
        connexion << ui->lineEditLogin->text();
        connexion << ui->lineEditMotDePasse->text();
        //connexion << "172.18.58.7" << "ciel2_yturpin" << "ciel2023_yturpin" << "s9CH4zV6";


        if(laBdd->ConnecterAuSGBD(connexion)){
            ui->tabWidget->setTabEnabled(1, true);
            ui->tabWidget->setTabEnabled(2, true);
            ui->pushButtonConnexio->setText("Déconnexion");

            QSettings settings("Touchard", "AgenceBancaire");
            settings.beginGroup("Bdd");
            settings.setValue("HostName", ui->lineEditAdresseIP->text());
            settings.setValue("DataBase", ui->lineEditBdd->text());
            settings.setValue("Login", ui->lineEditLogin->text());
            settings.setValue("Mdp", ui->lineEditMotDePasse->text());
            settings.endGroup();
        }
    }
    else{
        laBdd->Deconnecter();
        ui->pushButtonConnexio->setText("Connexion");
        ui->tabWidget->setTabEnabled(1, false);
        ui->tabWidget->setTabEnabled(2, false);
    }
}


void AgenceBancaire::on_pushButtonAjouter_clicked()
{
    if(!ui->lineEditNom->text().isEmpty() &&
        !ui->lineEditPrenom->text().isEmpty() &&
        !ui->lineEditNumeroCompte->text().isEmpty() &&
        !ui->lineEditSolde->text().isEmpty() &&
        !ui->lineEditVille->text().isEmpty()){
        QVariant idAgence = ui->comboBoxAgences2->currentData();
        if(!idAgence.isValid()){
            QMessageBox::critical(this, "Erreur", "Vous devez choisir une agence");
            return;
        }
        //Construire l'objet de la classe client
        Client nouveauClient(
            ui->lineEditNom->text(),
            ui->lineEditPrenom->text(),
            ui->lineEditNumeroCompte->text(),
            ui->lineEditSolde->text(),
            ui->lineEditVille->text(),
            idAgence.toInt());

        //Ajouter le client à la BDD
        if(laBdd->AjouterClient(nouveauClient)){
            QMessageBox::information(this, "Succès", "Le client a");
        }
        else{
            QMessageBox::critical(this, "Erreur", "Impossible d'a");
        }
    }
}


void AgenceBancaire::on_comboBox_currentIndexChanged(int index)
{

}


void AgenceBancaire::on_tabWidget_tabBarClicked(int index)
{
    if(index > 0){
        QComboBox* comboAgences = (index == 1) ? ui->comboBoxAgences1 : ui->comboBoxAgences2;
        comboAgences->clear();
        comboAgences->addItem("Choisissez une agence");
        laBdd->ObtenirAgences(comboAgences);
    }
}


void AgenceBancaire::on_comboBoxAgences2_currentIndexChanged(int index)
{
    if(index == 0){
        ui->tableView->setModel(nullptr);
        ui->lineEdit->clear();
    }
    else{
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QSqlTableModel* model = laBdd->ConsulterComptesClients(ui->comboBoxAgences2->currentData().toInt());
        model->setHeaderData(0, Qt::Horizontal, "Compte numéro");
        model->setHeaderData(1, Qt::Horizontal, "Solde en euro");
        model->setHeaderData(2, Qt::Horizontal, "Nom");
        model->setHeaderData(3, Qt::Horizontal, "Prénom");
        model->setHeaderData(4, Qt::Horizontal, "Ville");
        ui->tableView->setModel(model);

        ui->tableView->setColumnHidden(5, true);
        ui->lineEdit->setText(QString::number(model->rowCount()));
    }
}

