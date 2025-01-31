#ifndef LIAISONSERIE_H
#define LIAISONSERIE_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include <QDebug>
#include <QSerialPort>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class LiaisonSerie;
}
QT_END_NAMESPACE

class LiaisonSerie : public QMainWindow
{
    Q_OBJECT

public:
    LiaisonSerie(QWidget *parent = nullptr);
    ~LiaisonSerie();

private slots:
    void on_pushButtonOuvrirPortSerie_clicked();

    void on_pushButtonEnvoyer_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void onQSerialPortready_read();

private:
    Ui::LiaisonSerie *ui;
    QSerialPort lePortSerie;
};
#endif // LIAISONSERIE_H
