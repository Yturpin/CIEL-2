#ifndef AUDITSERVEURWIDGET_H
#define AUDITSERVEURWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QProcess>
#include <QDebug>
#include <QHostInfo>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui {
class AuditServeurWidget;
}
QT_END_NAMESPACE

class AuditServeurWidget : public QWidget
{
    Q_OBJECT

public:
    AuditServeurWidget(QWidget *parent = nullptr);
    ~AuditServeurWidget();
    void onQProcessReadyReadStandardOutput();


private slots:
    void on_pushButtonLancementServeur_clicked();

    void onQTcpServerNewConnection();

    void onQTcpServerAcceptError();

    void onQTcpSocketConnected();

    void onQTcpSocketDisconnected();

    void onQTcpSocketReadyRead();

    void onQTcpSocketErrorOccured(const QAbstractSocket::SocketError _socketError);

    void onQTcpSocketStateChanged(const QAbstractSocket::SocketState _socketState);

    void onQTcpSocketHostFound();

    void onQTcpSocketBytesWritten(const qint64 _bytes);

    void onQTcpSocketAboutToClose();

private:
    Ui::AuditServeurWidget *ui;
    QTcpServer *socketEcouteServer;
    QTcpSocket *socketDialogueClient;
    QProcess *process;
};
#endif // AUDITSERVEURWIDGET_H
