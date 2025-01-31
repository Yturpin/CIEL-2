#ifndef AGENCEBANCAIRE_H
#define AGENCEBANCAIRE_H

#include <QWidget>
#include <QSettings>
#include <QMessageBox>
#include <QStringList>
#include <vraiaccesbdd.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class AgenceBancaire;
}
QT_END_NAMESPACE

class AgenceBancaire : public QWidget
{
    Q_OBJECT

public:
    AgenceBancaire(QWidget *parent = nullptr);
    ~AgenceBancaire();

private slots:
    void on_pushButtonConnexio_clicked();

    void on_pushButtonAjouter_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_tabWidget_tabBarClicked(int index);

    void on_comboBoxAgences2_currentIndexChanged(int index);

private:
    Ui::AgenceBancaire *ui;
    VraiAccesBdd *laBdd;
};
#endif // AGENCEBANCAIRE_H
