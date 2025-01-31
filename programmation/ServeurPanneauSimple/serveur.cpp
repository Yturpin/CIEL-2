#include "serveur.h"
#include "ui_serveur.h"

Serveur::Serveur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Serveur)
    ,datagram(QByteArray(), QHostAddress::Broadcast, 45455)
{
    ui->setupUi(this);
    socketServeur = new QUdpSocket(this);
    alerte = false;
    alternanceAlerte = false;
    indexMessage = 0;
}

Serveur::~Serveur()
{
    delete ui;
    delete socketServeur;
}

void Serveur::on_pushButtonDiffuser_clicked()
{
    QByteArray datagram = ui->textEditInformation->toPlainText().toUtf8();
    //socketServeur->writeDatagram(datagram, QHostAddress("127.0.0.1"), 45455); // ou QHostAddress::Broadcast
    socketServeur->writeDatagram(datagram, QHostAddress("224.0.1.1"), 45455);
    qDebug() << "Message envoyé : " << datagram;
}


void Serveur::on_pushButtonAjouterMessage_clicked()
{
    QString infos = ui->textEditInformation_2->toPlainText();

    if(!infos.isEmpty()){
        ui->listWidgetMessage->addItem(infos);
        ui->textEditInformation_2->clear();
    }
}


void Serveur::on_pushButtonCreerAlerte_clicked()
{

    if(!ui->textEditAlerte->toPlainText().isEmpty()){
        ui->pushButtonCreerAlerte->setText("Supprimer une alerte");
    }
    else{
        ui->pushButtonCreerAlerte->setText("Créer une alerte");
    }

}


void Serveur::on_pushButtonLancerDiffusion_clicked()
{

    if(ui->pushButtonLancerDiffusion->text() == "Lancer la diffusion"){
        ui->pushButtonLancerDiffusion->setText("Arrêter la diffusion");
        timerInformation.setInterval(10000);
        timerInformation.start();
        connect(&timerInformation, &QTimer::timeout, this, &Serveur::onTimerInformation_timeout);
    }
    else{
        ui->pushButtonLancerDiffusion->setText("Lancer la diffusion");
        timerInformation.setInterval(10000);
        timerInformation.stop();
    }

    timerHeure.setInterval(600000);

    //ui->textEditAlerte->toPlainText().isEmpty()
}


void Serveur::on_pushButtonSupMessage_clicked()
{
    QListWidgetItem *item = ui->listWidgetMessage->currentItem();
    if(item != nullptr){
        delete ui->listWidgetMessage->currentItem();
    }
    else {
        QMessageBox::warning(this, "Erreur", "Vous devez selectionner le message à supprimer");
    }
}

void Serveur::EnvoyerDatagram(const QByteArray _data)
{
    datagram.setData(_data); // Configure les données à envoyer
    if (socketServeur->writeDatagram(datagram) == -1) {
        qDebug() << "Erreur lors de l'envoi du datagram :" << socketServeur->errorString();
    } else {
        qDebug() << "Datagram envoyé avec succès : " << _data;
    }
}


void Serveur::on_pushButtonModifBulletinMeteo_clicked()
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << 'M' << ui->lineEditMeteo->text();
    EnvoyerDatagram(buffer);
}

void Serveur::onTimerInformation_timeout()
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << 'I' << ui->listWidgetMessage->item(indexMessage)->text();
    indexMessage++;
    if (indexMessage != 0){
        indexMessage++;
    }
    else if(indexMessage == ui->listWidgetMessage->count()){        //ui->listWidgetMessage->count(); //Cb de messages dns la listWidget
        indexMessage = 0;
    }
    EnvoyerDatagram(buffer);

}

void Serveur::onTimerHeure_timeout()
{
    QTime heure = QTime::currentTime(); // donne l’heure courante
    heure.toString("HH:mm"); // retourne une Qstring contenant l’heure au format HH:mm


}

