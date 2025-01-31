#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//Du serveur au client
void Widget::envoyerDonneesJoueurs(const QChar _commande, const QString &_parametre)
{
    quint16 tailleTrame = 0;
    QBuffer tampon;
    if(tampon.open(QIODevice::WriteOnly))
    {
        QDataStream sortie(&tampon);
        sortie << tailleTrame << _commande << _parametre ;
        tailleTrame = tampon.size() - sizeof(tailleTrame);
        tampon.seek(0);
        sortie << tailleTrame;
        socketClient.write(tampon.buffer());

    }

}

//void calculerScores();
//void envoyerScore();
//


//Du client au serveur
void Widget::on_pushButton_clicked()
{
    envoyerDonneesJoueurs('C', ui->lineEdit->setText("Frycade"));



}

