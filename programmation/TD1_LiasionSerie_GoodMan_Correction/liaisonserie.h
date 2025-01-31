#ifndef LIAISONSERIE_H
#define LIAISONSERIE_H

#include <QWidget>
#include <QSerialPort>
#include <QIODevice>

QT_BEGIN_NAMESPACE
namespace Ui {
class LiaisonSerie;
}
QT_END_NAMESPACE

class LiaisonSerie : public QWidget
{
    Q_OBJECT

public:
    LiaisonSerie(QWidget *parent = nullptr);
    ~LiaisonSerie();

private slots:
    void on_pushButtonOuvrir_clicked();
    void on_pushButtonEnvoyer_clicked();
    void onQSerialPort_readyRead();
    void on_comboBoxPort_currentTextChanged(const QString &arg1);

private:
    Ui::LiaisonSerie *ui;

    QSerialPort lePortSerie;
};
#endif // LIAISONSERIE_H
