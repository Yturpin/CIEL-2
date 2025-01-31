#include "clavier.h"
#include "ui_clavier.h"
#include <QMessageBox>


Clavier::Clavier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clavier)
{
    ui->setupUi(this);

    leDetecteur = nullptr;

    connect(ui->pushButton0,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton1,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    //connect(ui->pushButton2,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    //connect(ui->pushButton3,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton4,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton5,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton6,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton7,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton8,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton9,&QPushButton::clicked,this,&Clavier::TraiterChiffre);

    //signal timeout (tps ecoulé) connecté au slot ontTimerLed_timeout
    connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
}

Clavier::~Clavier()
{
    delete ui;
}


void Clavier::TraiterChiffre()
{
    QPushButton *pbouton = qobject_cast<QPushButton *>(sender()); //on utilise qobject_cast ou static_cast à vérifier
    QString texteBouton = pbouton->text();
    QMessageBox messageChiffre;
    messageChiffre.setText("j'ai appuyé sur la touche " + texteBouton);
    messageChiffre.exec();


}


void Clavier::on_pushButtonMarche_clicked()
{
    /*
    QString texteBouton = ui->pushButtonMarche->text();
    QMessageBox messageMarche;
    messageMarche.setText("j'ai appuyé sur la touche " + texteBouton);
    messageMarche.exec();
    */

    ui->checkBoxLedRouge->setCheckState(Qt::Checked);
    timerLed.start(500);
}


void Clavier::on_pushButtonArret_clicked()
{
    ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    timerLed.stop();
}

void Clavier::onTimerLed_timeout()
{
    if(ui->checkBoxLedRouge->checkState() == Qt::Checked)
        ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    else
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
}


void Clavier::on_pushButton2_clicked()
{
    if(leDetecteur ==nullptr)
        leDetecteur = new Detecteur;
    //leDetecteur->exec();          //affichage en mode modal (l'accès aux autres fenêtres est bloqué)
    leDetecteur->show();
}


void Clavier::on_pushButton3_clicked()
{
    if(leDetecteur !=nullptr){
        leDetecteur->hide();
        delete leDetecteur;
        leDetecteur = nullptr;
    }
}

