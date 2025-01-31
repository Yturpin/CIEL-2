#ifndef DIALOGCONFIGURERLIAISONGPS_H
#define DIALOGCONFIGURERLIAISONGPS_H

#include <QDialog>
#include <QPushButton>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class DialogConfigurerLiaisonGPS;
}

class DialogConfigurerLiaisonGPS : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigurerLiaisonGPS(QSerialPort &_lePort, QWidget *parent = nullptr);
    ~DialogConfigurerLiaisonGPS();

private slots:
    void on_comboBoxVitesseTransmi_currentTextChanged(const QString &arg1);

    void on_comboBoxChoixPort_currentIndexChanged(int index);

    void on_checkBoxBitsDeStop_toggled(bool checked);

    void on_radioButtonPaire_toggled(bool checked);

    void on_radioButtonImpaire_toggled(bool checked);

    void on_radioButtonPasDeParite_toggled(bool checked);

    void on_spinBoxNbBitsDonnees_valueChanged(int arg1);

private:
    Ui::DialogConfigurerLiaisonGPS *ui;
    QSerialPort &lePort;
};

#endif // DIALOGCONFIGURERLIAISONGPS_H
