#include "client.h"


Client::Client(QObject *parent)
    : QObject{parent}
    ,socket(new QTcpSocket(this))
{
    connect(socket,&QTcpSocket::connected, this,&Client::onQTcpSocket_Connected);
    connect(socket,&QTcpSocket::disconnected, this,&Client::onQTcpSocket_Disconnected);
    connect(socket,&QTcpSocket::readyRead, this,&Client::onQTcpSocket_ReadyRead);
    connect(socket,&QTcpSocket::errorOccurred, this,&Client::onQTcpSocket_ErrorOccurred);
}
void Client::ConnecterAuServeur(const QString &_host, const quint16 _port)
{
    qDebug() << "Attente de connexion avec : " << _host << " sur le port : "<< _port;
    socket->connectToHost(_host,_port);
}
void Client::EnvoyerMessage(const QString &_message)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(_message.toLatin1());
        qDebug() << "Message envoyé : " << _message;
    }
    else
        qDebug() << "Le message ne peut pas être envoyé au serveur";
}
void Client::onQTcpSocket_Connected()
{
    qDebug() << "Connecté au serveur";
}
void Client::onQTcpSocket_Disconnected()
{
    qDebug() << "Déconnecté du serveur";
}
void Client::onQTcpSocket_ReadyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Données reçues du serveur :" << QString(data);
}

void Client::onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError)
{
    QString messageErreur;
    switch (_socketError) {
    case QAbstractSocket::HostNotFoundError:
        messageErreur = "Hôte non trouvé. Vérifier l'adresse du serveur et le port";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        messageErreur = "Connexion refusée par le serveur";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        messageErreur = "L'hôte distant a fermé la connexion.";
        break;
    case QAbstractSocket::SocketTimeoutError:
        messageErreur = "La connexion a expiré";
        break;
    default:
        messageErreur = "Erreur inattendue : " + socket->errorString();
        break;
    }
    qDebug() << messageErreur;
}
