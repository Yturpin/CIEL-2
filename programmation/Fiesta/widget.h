#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QBuffer>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void envoyerDonneesJoueurs(const QChar _commande,const QString &_parametre);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
