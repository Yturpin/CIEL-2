#include "calculatricev2.h"
#include "ui_calculatricev2.h"
#include <QString>
#include <QJSEngine>

CalculatriceV2::CalculatriceV2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatriceV2)
{
    ui->setupUi(this);

//     QObject::connect(ui->pushButton0, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton1, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton2, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton3, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton4, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton5, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton6, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton7, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton8, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButton9, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButtonSoustraire, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButtonAdditionner, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButtonDiviser, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
//     QObject::connect(ui->pushButtonMultiplier, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);

    //findchildren<QPushbutton*> pour récupérer tous les boutons de l'interface
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    //On parcours la liste de boutons avec la boucle foreach
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "=" && button->text() != "c") {
            connect(button, &QPushButton::clicked, this, &CalculatriceV2::onQPushButtonClicked);
        }
    }
}

CalculatriceV2::~CalculatriceV2()
{
    delete ui;
}

void CalculatriceV2::onQPushButtonClicked()
{
    QPushButton *touche;
    touche = qobject_cast<QPushButton*>(sender());

    QString textBouton = touche->text();

    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text() + textBouton);

}


void CalculatriceV2::on_pushButtonEgal_clicked()
{
    QJSEngine evalExpressionMath;
    QJSValue retourEvalExpressionMath;

    retourEvalExpressionMath = evalExpressionMath.evaluate(ui->lineEditAfficheur->text());

    ui->lineEditAfficheur->setText(retourEvalExpressionMath.toString());
}


void CalculatriceV2::on_pushButtonEffacer_clicked()
{
    ui->lineEditAfficheur->clear();
}

