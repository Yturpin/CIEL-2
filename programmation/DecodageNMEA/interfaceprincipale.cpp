#include "interfaceprincipale.h"
#include "ui_interfaceprincipale.h"

InterfacePrincipale::InterfacePrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfacePrincipale)
    , configGPS(lePort)
{
    ui->setupUi(this);

    //Initialisation
    labelEtatPort.setText("Port fermé");
    ui->statusbar->addPermanentWidget(&labelEtatPort);
    ui->statusbar->show();
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode();
}

InterfacePrincipale::~InterfacePrincipale()
{
    delete ui;
}


void InterfacePrincipale::on_actionQuitter_triggered()
{
    qDebug() << "quITTER";
}


void InterfacePrincipale::on_actionConfigurer_triggered()
{
    //On verifie qu'un port est sélectionner pour actionner le bouton ok

    if(configGPS.exec() == QDialog::Accepted){
            if(lePort.open(QIODevice::ReadOnly)){
            QString message;
            QTextStream flux (&message);
            QString parite;

            switch (lePort.parity()){
            case QSerialPort::NoParity:
                parite = "n";
                break;
            case QSerialPort::EvenParity:
                parite = "p";
                break;
            case QSerialPort::OddParity:
                parite = "i";
                break;
            default:
                break;
            }

            flux << "Port : " << lePort.portName() << ","
                 << lePort.baudRate() << "," << lePort.dataBits();

        }
    }
}

