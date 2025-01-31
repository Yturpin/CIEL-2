#ifndef TESTGESTIONSTOCK_H
#define TESTGESTIONSTOCK_H

#include <QWidget>
#include <QFile>
#include <QIODevice>
#include <QFileDialog>
#include <QTextStream>
#include "rouleau.h"
#include "stock.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TestGestionStock;
}
QT_END_NAMESPACE

class TestGestionStock : public QWidget
{
    Q_OBJECT

public:
    TestGestionStock(QWidget *parent = nullptr);
    ~TestGestionStock();

private slots:
    void on_pushButtonAjouterNouveau_clicked();

    void on_pushButtonDemanderRetrait_clicked();

    void on_pushButtonSupprimerDuSotck_clicked();

    void on_pushButtonEnregistrer_clicked();

    void on_pushButtonCharger_clicked();

private:
    Ui::TestGestionStock *ui;
    int nbRouleaux;
    Stock leStock;
    QMultiMap<int, Rouleau>::iterator debut;
};
#endif // TESTGESTIONSTOCK_H
