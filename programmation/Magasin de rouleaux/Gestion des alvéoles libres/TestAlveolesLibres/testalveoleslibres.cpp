#include "testalveoleslibres.h"
#include "ui_testalveoleslibres.h"

TestAlveolesLibres::TestAlveolesLibres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestAlveolesLibres)
    ,lesAlveoles(4,5)
{
    ui->setupUi(this);
}

TestAlveolesLibres::~TestAlveolesLibres()
{
    delete ui;
}

void TestAlveolesLibres::on_pushButtonLiberer_clicked()
{

    QListWidgetItem *currentItem = ui->listWidgetAlveolesLibres->currentItem();

    if(currentItem) // Vérifier qu'un item est bien sélectionné
    {
        QString texte = currentItem->text();
        QStringList parts = texte.split(": ");
        if(parts.size() == 2)
        {
            //Extraire la rangée et la colonne a partir de chiffres séparés par une virgule
            QStringList position = parts[1].split(",");
            if(position.size() == 2)
            {
                int rangee = position[0].toInt();
                int colonne = position[1].toInt();
                lesAlveoles.Liberer(rangee, colonne);
            }
        }
        //Supprimer l'item de la QListWIdget
        delete ui->listWidgetAlveolesLibres->takeItem(ui->listWidgetAlveolesLibres->row(currentItem));
        ui->lineEditNumAlveole->setText("libre en : " + parts[1]);
    }
}


void TestAlveolesLibres::on_pushButtonReserver_clicked()
{
    int rangee;
    int colonne;

    if(lesAlveoles.Reserver(rangee, colonne)){
        QString texte = "Alvéole occupée en : ";
        texte += QString::number(rangee) + "," + QString::number(colonne);
        ui->listWidgetAlveolesLibres->addItem(texte);
        ui->lineEditNumAlveole->clear();
    }
    else{
        QMessageBox messageErreur;
        messageErreur.setText("Le magasin est plein, \n il n'y a plus d'alvéole de libre");
        messageErreur.exec();
    }
}
