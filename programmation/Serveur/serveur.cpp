#include "serveur.h"

    Serveur::Serveur(QObject *parent)
    : QObject{parent}
    , serveur(new QTcpServer(this))
    ,client(nullptr)
{
    connect(serveur, &QTcpServer::newConnection,this,&Serveur::onQTcpServer_NewConnection);
}
void Serveur::LancerServeur(quint16 _port)
{
    if(!serveur->listen(QHostAddress::Any, _port))
        qDebug() << "Echec au lancement du serveur : " << serveur->errorString();
    else
        qDebug() << "Serveur lancé sur le port : "<< QString::number(_port);
}
void Serveur::onQTcpServer_NewConnection()
{
    client = serveur->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&Serveur::onQTcpSocket_ReadyRead);
    connect(client,&QTcpSocket::disconnected,this,&Serveur::onQTcpSocket_Disconnected);
    connect(client,&QTcpSocket::errorOccurred,this,&Serveur::onQTcpSocket_ErrorOccurred);
}
void Serveur::onQTcpSocket_Disconnected()
{
    qDebug() << "Client déconnecté";
    client->deleteLater();
    client = nullptr;
}
void Serveur::onQTcpSocket_ReadyRead()
{
    if(client)
    {
        QByteArray data = client->readAll();
        qDebug() << "Données reçues : " << QString(data);
        client->write("Message reçu sur le serveur : " + data);
    }
}
void Serveur::onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError)
{
    if(client)
    {
        QString messageErreur;
        switch (_socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            messageErreur = "Le client a fermé la connexion";
            break;
        default:
            messageErreur = "Erreur inattendue : " + client->errorString();
            break;
        }
        qDebug() << "Erreur client : " << messageErreur ;
        client->disconnect();
    }
}
