#ifndef CALCULATRICEV3_H
#define CALCULATRICEV3_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculatriceV3;
}
QT_END_NAMESPACE

#define NB_TOUCHES 16 //une constante définie comme un entier, initialisée à 16 dans la liste d’initialisation du constructeur.

class CalculatriceV3 : public QWidget
{
    Q_OBJECT

public:
    CalculatriceV3(QWidget *parent = nullptr);
    ~CalculatriceV3();

private slots:
    void onQPushbuttonClicked();

private:
    Ui::CalculatriceV3 *ui;
    QGridLayout *grille;            // un élément de type pointeur vers un QGridLayout
    QLineEdit *afficheur;           // un élément de type pointeur vers un QLineEdit,
    QPushButton **touches;          // un tableau dynamique contenant des pointeurs vers des QPushButton
    int nb_touches;                 // définie comme un entier, initialisée à 16 dans la liste d’initialisation du constructeur.
};
#endif // CALCULATRICEV3_H
