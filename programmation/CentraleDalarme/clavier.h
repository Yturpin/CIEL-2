#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <detecteur.h>
#include <centraledalarme.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Clavier;
}
QT_END_NAMESPACE

class Clavier : public QWidget
{
    Q_OBJECT

public:
    Clavier(QWidget *parent = nullptr);
    ~Clavier();

private slots:

    void TraiterChiffre();

    void on_pushButtonMarche_clicked();

    void on_pushButtonArret_clicked();

    void onTimerLed_timeout();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

private:
    Ui::Clavier *ui;
    QTimer timerLed;
    Detecteur *leDetecteur;
};
#endif // CLAVIER_H
