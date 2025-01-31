#ifndef SERVEUR_H
#define SERVEUR_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
class Serveur : public QObject
{
    Q_OBJECT
public:
    explicit Serveur(QObject *parent = nullptr);
    void LancerServeur(quint16 _port);
private slots:
    void onQTcpServer_NewConnection();
    void onQTcpSocket_Disconnected();
    void onQTcpSocket_ReadyRead();
    void onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError);
private:
    QTcpServer *serveur;
    QTcpSocket *client;
};
#endif // Serveur_H
