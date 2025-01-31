#ifndef TESTALVEOLESLIBRES_H
#define TESTALVEOLESLIBRES_H

#include <QWidget>
#include <QMessageBox>
#include "alveoleslibres.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TestAlveolesLibres;
}
QT_END_NAMESPACE

class TestAlveolesLibres : public QWidget
{
    Q_OBJECT

public:
    TestAlveolesLibres(QWidget *parent = nullptr);
    ~TestAlveolesLibres();

private slots:

    void on_pushButtonLiberer_clicked();

    void on_pushButtonReserver_clicked();

private:
    Ui::TestAlveolesLibres *ui;
    AlveolesLibres lesAlveoles;     //Composition
};
#endif // TESTALVEOLESLIBRES_H
