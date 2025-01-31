#ifndef MAGASIN_H
#define MAGASIN_H

#include <QWidget>
#include "alveoleslibres.h"
#include "chariot.h"
#include "stock.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Magasin;
}
QT_END_NAMESPACE

class Magasin : public QWidget
{
    Q_OBJECT

public:
    Magasin(QWidget *parent = nullptr);
    ~Magasin();

private slots:
    void on_pushButtonEntrerRouleau_clicked();
    void on_pushButtonSortirSerieDeRouleaux_clicked();

private:
    Ui::Magasin *ui;
    Chariot leChariot;
    AlveolesLibres lesAlveoles;
    Stock leStock;

    void AfficherStock();
    void AfficherRouleauEnceinte(const Rouleau &rouleau);
};
#endif // MAGASIN_H 
