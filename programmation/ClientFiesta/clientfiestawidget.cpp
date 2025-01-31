#include "clientfiestawidget.h"
#include "ui_clientfiestawidget.h"

ClientFiestaWidget::ClientFiestaWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientFiestaWidget)
    , socketClient(new QTcpSocket(this))
{
    ui->setupUi(this);

    // Connexions des signaux et slots liés à la communication réseau.
    connect(socketClient, &QTcpSocket::connected, this, &ClientFiestaWidget::onQTcpSocketConnected);
    connect(socketClient, &QTcpSocket::disconnected, this, &ClientFiestaWidget::onQTcpSocketDisconnected);
    connect(socketClient, &QTcpSocket::readyRead, this, &ClientFiestaWidget::onQTcpSocketReadyRead);
}

ClientFiestaWidget::~ClientFiestaWidget()
{
    delete ui;
}

void ClientFiestaWidget::onQTcpSocketConnected()
{
    qDebug() << "Connecté au serveur";
    ui->pushButtonConnexion->setText("Déconnexion");
}

void ClientFiestaWidget::onQTcpSocketDisconnected()
{
    qDebug() << "Déconnecté du serveur";
    ui->pushButtonConnexion->setText("Connexion");
}

void ClientFiestaWidget::onQTcpSocketReadyRead()
{
    QByteArray buffer;

    quint16 taille = 0;
    QString message;
    // si le nombre d'octets reçu est au moins égal a celui de la taille de ce que l'on doit recevoir
    if(socketClient->bytesAvailable() >= static_cast<qint64>(sizeof(taille)))
    {
        // association de la socket au flux d'entrée
        QDataStream entree(socketClient);

        // extraction de la taille de ce que l'on doit recevoir
        entree >> taille;

        // si le nombre d'octets reçu est au moins égal a celui de ce que l'on doit recevoir
        if (socketClient->bytesAvailable() >= static_cast<qint64>(taille))
        {
            entree >> message;
            // Afficher dans la QLineEdit
            ui->textEdit->setText(message);
        }
    }

    if(socketClient->bytesAvailable() > 0){
        buffer = socketClient->readAll();
        qDebug() << "Données reçues du serveur : " << QString(buffer);
        qDebug() << "Message reçu : " << QString(buffer);
    }
}

void ClientFiestaWidget::on_pushButtonConnexion_clicked()
{

    //void Widget::envoyerDonneesJoueurs(const QChar _commande, const QString &_parametre)
    if(ui->pushButtonConnexion->text() == "Connexion"){
        if(ui->lineEditPseudo->text().isEmpty()){
            QMessageBox::warning(this, "ERREUR", "Il faut entrer un pseudo !!");
        }
        qDebug() << "Attente de connexion avec : 172.18.58.70, port 8888";
        socketClient->connectToHost("172.18.58.70", 8888);
        //envoyerDonneesJoueurs('C', ui->lineEdit->Text());
    }

    //deconnexion du serveur
    else if(ui->pushButtonConnexion->text() == "Déconnexion"){
        socketClient->disconnectFromHost();
    }
    else{
        qDebug() << "Il faut ";
    }
}


void ClientFiestaWidget::on_pushButtonQuitter_clicked()
{
    //envoyerDonneesJoueurs('Q', "");

}


void ClientFiestaWidget::on_pushButtonNewGame_clicked()
{
    //envoyerDonneesJoueurs('N', "");
}


void ClientFiestaWidget::on_pushButtonPropMot_clicked()
{
    //Concatener proposition avec mot reçu du serveur
    //envoyerDonneesJoueurs('P', mot reçu serveur + ui->lineEditPropMot->text());
    ui->lineEditPropMot->clear();
}

// void ClientFiestaWidget::Comparerpersonnage(){

// }

void ClientFiestaWidget::CalculerScore()
{
 /*
if(deduction == true){
      score = score + 1;

}

if (score == ){


}
if (score == 6)
 vous remportez un Souvenir

*/

}

