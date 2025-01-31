#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>
#include <QLabel>
#include "dialogconfigurerliaisongps.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class InterfacePrincipale;
}
QT_END_NAMESPACE

class InterfacePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    InterfacePrincipale(QWidget *parent = nullptr);
    ~InterfacePrincipale();
    void DecodageNMEA(QString &_trameNMEA);

private slots:
    void onQSerialPort_ReadyRead();

    void on_actionQuitter_triggered();

    void on_actionConfigurer_triggered();

private:
    Ui::InterfacePrincipale *ui;
    QByteArray trameCourante;
    QLabel labelEtatPort;
    DialogConfigurerLiaisonGPS configGPS;   //On respecte l'ordre de lecture du compilateur
    QSerialPort lePort;        //Réference (voir le diagramme de classe losange creux)

};
#endif // INTERFACEPRINCIPALE_H
