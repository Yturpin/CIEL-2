#ifndef AUDITCLIENTWIDGET_H
#define AUDITCLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class AuditClientWidget;
}
QT_END_NAMESPACE

class AuditClientWidget : public QWidget
{
    Q_OBJECT

public:
    AuditClientWidget(QWidget *parent = nullptr);
    ~AuditClientWidget();

private slots:
    void on_pushButtonConnexion_clicked();

    void on_pushButtonOrdinateur_clicked();

    void on_pushButtonUtilisateur_clicked();

    void on_pushButtonProcesseur_clicked();

    void on_pushButtonOs_clicked();

    void onQTcpSocketConnected();

    void onQTcpSocketDisconnected();

    void onQTcpSocketReadyRead();

    void onQTcpSocketErrorOccured(const QAbstractSocket::SocketError _socketError);

    void onQTcpSocketHostFound();

    void onQTcpSocketStateChanged(const QAbstractSocket::SocketState _socketState);

    void onQTcpSocketAboutToClose();

    void onQTcpSocketBytesWritten(const qint64 _bytes);

    void onQTcpSocketChannelBytesWritten(const int _channel, const qint64 _bytes);

    void onQTcpSocketChannelReadyRead(const int _channel);

    void onQTcpSocketReadChannelFinished();

    void onQTcpSocketDestroyed(const QObject *_obj);

private:
    Ui::AuditClientWidget *ui;
    char typeDeDemande;
    QTcpSocket *socketClient;
};
#endif // AUDITCLIENTWIDGET_H
