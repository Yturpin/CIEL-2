#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QString>
#include <QJSEngine>

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::on_pushButtonEffacer_clicked()
{
    ui->lineEditAfficheur->clear();
}


void Calculatrice::on_pushButton0_clicked()
{
    QString expression, expression2 = "0";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    //Concatenation des chaines
    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonEgal_clicked()
{
    QJSEngine evalExpressionMath;
    QJSValue retourEvalExpressionMath;

    retourEvalExpressionMath = evalExpressionMath.evaluate(ui->lineEditAfficheur->text());

    ui->lineEditAfficheur->setText(retourEvalExpressionMath.toString());
}


void Calculatrice::on_pushButtonDiviser_clicked()
{
    QString expression, expression2 = "/";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton1_clicked()
{
    QString expression, expression2 = "1";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);

}


void Calculatrice::on_pushButton2_clicked()
{
    QString expression, expression2 = "2";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton3_clicked()
{
    QString expression, expression2 = "3";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonMultiplier_clicked()
{
    QString expression, expression2 = "*";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton4_clicked()
{
    QString expression, expression2 = "4";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton5_clicked()
{
    QString expression, expression2 = "5";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton6_clicked()
{
    QString expression, expression2 = "6";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonSoustraire_clicked()
{
    QString expression, expression2 = "-";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton7_clicked()
{
    QString expression, expression2 = "7";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton8_clicked()
{
    QString expression, expression2 = "8";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton9_clicked()
{
    QString expression, expression2 = "9";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonAdditionner_clicked()
{
    QString expression, expression2 = "+";

    //Récupérer le contenu du lineEditAfficheur
    expression = ui->lineEditAfficheur->text();

    expression = expression + expression2;

    //Replacer le résultat dans la lineEditAfficheur
    ui->lineEditAfficheur->setText(expression);
}

