#ifndef MISEENOEUVREBDD_H
#define MISEENOEUVREBDD_H

#include <QWidget>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MiseEnOeuvreBDD;
}
QT_END_NAMESPACE

class MiseEnOeuvreBDD : public QWidget
{
    Q_OBJECT

public:
    MiseEnOeuvreBDD(QWidget *parent = nullptr);
    ~MiseEnOeuvreBDD();

private slots:
    void on_pushButtonObtenirNomDep_clicked();

    void on_comboBoxRegions_currentIndexChanged(int index);

    void on_comboBoxDepartements_currentIndexChanged(int index);

private:
    void chargerRegion();
    Ui::MiseEnOeuvreBDD *ui;
    QSqlDatabase db;
};
#endif // MISEENOEUVREBDD_H
