#ifndef DETECTEUR_H
#define DETECTEUR_H

#include <QDialog>
#include <QMessageBox>



namespace Ui {
class Detecteur;
}

class Detecteur : public QDialog
{
    Q_OBJECT

public:
    explicit Detecteur(QWidget *parent = nullptr);
    ~Detecteur();

private slots:
    void on_pushButtonIntrus_clicked();
    virtual void on_pushButtonPresence_clicked();

signals:
    void IntrusDetecte();

private:
    Ui::Detecteur *ui;
};

#endif // DETECTEUR_H
