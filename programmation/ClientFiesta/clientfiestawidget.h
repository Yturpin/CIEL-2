#ifndef CLIENTFIESTAWIDGET_H
#define CLIENTFIESTAWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class ClientFiestaWidget;
}
QT_END_NAMESPACE

class ClientFiestaWidget : public QWidget
{
    Q_OBJECT

public:
    ClientFiestaWidget(QWidget *parent = nullptr);
    ~ClientFiestaWidget();

private slots:
    void onQTcpSocketConnected();

    void onQTcpSocketDisconnected();

    void onQTcpSocketReadyRead();

    void on_pushButtonConnexion_clicked();

    void on_pushButtonQuitter_clicked();

    void on_pushButtonNewGame_clicked();

    void on_pushButtonPropMot_clicked();

    void CalculerScore();

private:
    Ui::ClientFiestaWidget *ui;
    QTcpSocket *socketClient;
};
#endif // CLIENTFIESTAWIDGET_H
