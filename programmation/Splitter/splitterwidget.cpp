#include "splitterwidget.h"
#include "ui_splitterwidget.h"
#include <QString>

SplitterWidget::SplitterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SplitterWidget)
{
    ui->setupUi(this);
}

SplitterWidget::~SplitterWidget()
{
    delete ui;
}

void SplitterWidget::on_pushButtonDecoder_clicked()
{
    QString texte = ui->lineEditDecoder->text();        //récuperer le texte de la lineEdit quand on clique sur le bouton
    QStringList liste = texte.split(";");               //split découpe avec un ;

    //Décode la chaine et la replace en ordre dans chaque lineEdit
    ui->lineEditNom->setText(liste.at(0));
    ui->lineEditPrenom->setText(liste.at(1));
    ui->lineEditAge->setText(liste.at(2));
    //ui->lcdNumberAge->value() = liste.at(2).toInt(); ligne bug
    ui->lineEditPoids->setText(liste.at(3));
    ui->lineEditTaille->setText(liste.at(4));
}

