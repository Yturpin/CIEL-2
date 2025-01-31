#include "panneauaffichagesimple.h"
#include "ui_panneauaffichagesimple.h"

PanneauAffichageSimple::PanneauAffichageSimple(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PanneauAffichageSimple)
{
    ui->setupUi(this);
    socketClient = new QUdpSocket(this);

    if(socketClient->bind(45455, QUdpSocket::ShareAddress)){
        connect(socketClient, &QUdpSocket::readyRead, this, &PanneauAffichageSimple::RecevoirMessage);
        qDebug() << "Client prêt à recevoir le message sur le port 45455";
    }
    else {
        qDebug() << "Erreur de liaison du client au port 45455" << socketClient->error();
    }


    //Inscription au groupe multicast
    /*
    if (socketClient->bind(45454, QUdpSocket::ShareAddress)) {
        if (socketClient->joinMulticastGroup(QHostAddress("224.0.1.1"))) {
            connect(socketClient, &QUdpSocket::readyRead, this, &PanneauAffichageSimple::RecevoirMessage);
            qDebug() << "Client rejoint le groupe multicast et est prêt à recevoir des messages";
        }
        else {
            qDebug() << "Erreur : impossible de rejoindre le groupe multicast";
        }
    }
    else {
          qDebug() << "Erreur de liaison du client au port 45454";
    }
    */
}

PanneauAffichageSimple::~PanneauAffichageSimple()
{
    delete ui;
}

void PanneauAffichageSimple::RecevoirMessage()
{
    while(socketClient->hasPendingDatagrams()){
        QByteArray buffer;
        buffer.resize(socketClient->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        socketClient->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
        ui->textEditInformation->append(QString::fromUtf8(buffer));
        qDebug() << "Recu de " << sender.toString() << "\nPort :" << senderPort << "\nDonnées : " << buffer;
    }


}
