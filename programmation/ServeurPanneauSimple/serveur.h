#ifndef SERVEUR_H
#define SERVEUR_H

#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QWidget>
#include <QUdpSocket>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui {
class Serveur;
}
QT_END_NAMESPACE

class Serveur : public QWidget
{
    Q_OBJECT

public:
    Serveur(QWidget *parent = nullptr);
    ~Serveur();

private slots:
    void on_pushButtonDiffuser_clicked();

    void on_pushButtonAjouterMessage_clicked();

    void on_pushButtonCreerAlerte_clicked();

    void on_pushButtonLancerDiffusion_clicked();

    void on_pushButtonSupMessage_clicked();

    void EnvoyerDatagram(QByteArray const _data);

    void on_pushButtonModifBulletinMeteo_clicked();

    void onTimerInformation_timeout();

    void onTimerHeure_timeout();

private:
    Ui::Serveur *ui;
    QUdpSocket *socketServeur;
    int indexMessage;
    bool alerte;
    bool alternanceAlerte;
    QNetworkDatagram datagram;
    QTimer timerInformation;
    QTimer timerHeure;
};
#endif // SERVEUR_H
