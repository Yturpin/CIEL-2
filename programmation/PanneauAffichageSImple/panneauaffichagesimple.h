#ifndef PANNEAUAFFICHAGESIMPLE_H
#define PANNEAUAFFICHAGESIMPLE_H

#include <QWidget>
#include <QUdpSocket>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui {
class PanneauAffichageSimple;
}
QT_END_NAMESPACE

class PanneauAffichageSimple : public QWidget
{
    Q_OBJECT

public:
    PanneauAffichageSimple(QWidget *parent = nullptr);
    ~PanneauAffichageSimple();
    void RecevoirMessage();

private:
    Ui::PanneauAffichageSimple *ui;
    QUdpSocket *socketClient;       //Composition
};
#endif // PANNEAUAFFICHAGESIMPLE_H
