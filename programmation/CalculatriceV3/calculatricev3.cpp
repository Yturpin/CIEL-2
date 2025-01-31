#include "calculatricev3.h"
#include "ui_calculatricev3.h"

CalculatriceV3::CalculatriceV3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatriceV3)
    , nb_touches(NB_TOUCHES)

{
    ui->setupUi(this);


    const QString tableDesSymboles[ ] = {"7", "8", "9", "+" ,"4", "5", "6", "-", "1", "2", "3", "*",
                                        "C", "0", "=", "/"};
    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("background-color: rgb(143, 240, 164);");
    touches = new QPushButton*[NB_TOUCHES];
    grille->addWidget(afficheur,0,0,1,4);   //ligne, colonne, nbLignes, nbColonnes
    this->setLayout(grille);


}

CalculatriceV3::~CalculatriceV3()
{
    delete ui;
}

void CalculatriceV3::onQPushbuttonClicked()
{

}
