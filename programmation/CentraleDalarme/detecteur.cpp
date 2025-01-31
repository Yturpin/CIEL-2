#include "detecteur.h"
#include "ui_detecteur.h"

Detecteur::Detecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Detecteur)
{
    ui->setupUi(this);

    setWindowTitle("Détecteur");
}

Detecteur::~Detecteur()
{
    delete ui;

}

void Detecteur::on_pushButtonIntrus_clicked()
{
    QMessageBox messageIntrusion;
    messageIntrusion.setText("Intrus détecté");
    messageIntrusion.exec();


}

