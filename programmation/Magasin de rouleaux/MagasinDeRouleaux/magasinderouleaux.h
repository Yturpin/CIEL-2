#ifndef MAGASINDEROULEAUX_H
#define MAGASINDEROULEAUX_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MagasinDeRouleaux;
}
QT_END_NAMESPACE

class MagasinDeRouleaux : public QWidget
{
    Q_OBJECT

public:
    MagasinDeRouleaux(QWidget *parent = nullptr);
    ~MagasinDeRouleaux();

private:
    Ui::MagasinDeRouleaux *ui;
};
#endif // MAGASINDEROULEAUX_H
