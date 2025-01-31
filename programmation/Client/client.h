#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void ConnecterAuServeur(const QString &_host,const quint16 _port);
    void EnvoyerMessage(const QString &_message);
private slots:
    void onQTcpSocket_Connected();
    void onQTcpSocket_Disconnected();
    void onQTcpSocket_ReadyRead();
    void onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError);
private:
    QTcpSocket *socket;
};
#endif // Client_H

