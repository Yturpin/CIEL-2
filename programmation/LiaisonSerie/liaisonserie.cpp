#include "liaisonserie.h"
#include "ui_liaisonserie.h"

LiaisonSerie::LiaisonSerie(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LiaisonSerie)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        qDebug() << "Nom : " << info.portName();
        qDebug() << "Fabricant : " << info.manufacturer();
        ui->comboBox->addItem(info.portName());
    }

    QSerialPort lePortSerie;
/*
    if(lePortSerie.isOpen()){
        connect (&lePortSerie, &QSerialPort::readyRead, this, &LiaisonSerie::onQSerialPortready_read);
    }
*/
}

LiaisonSerie::~LiaisonSerie()
{
    delete ui;
}

void LiaisonSerie::on_pushButtonOuvrirPortSerie_clicked()
{
   //QSerialPort port;
   //qDebug() << "le port " << ui->comboBox->currentText() << "choisi est ouvert";

   //Ouverture du port série
   if(ui->pushButtonOuvrirPortSerie->text() == "Ouvrir le port série"){
       lePortSerie.setBaudRate(QSerialPort::Baud115200);
       lePortSerie.setDataBits(QSerialPort::Data8);
       lePortSerie.setParity(QSerialPort::NoParity);
       lePortSerie.setStopBits(QSerialPort::OneStop);
       lePortSerie.setFlowControl(QSerialPort::NoFlowControl);
       lePortSerie.open(QIODeviceBase::ReadWrite);
       qDebug() << "port série ouvert avec succès";
       connect (&lePortSerie, &QSerialPort::readyRead, this, &LiaisonSerie::onQSerialPortready_read);
       ui->pushButtonOuvrirPortSerie->setText("Fermer le port série");
   }

   else if(ui->pushButtonOuvrirPortSerie->text() == "Fermer le port série"){
       lePortSerie.close();
       qDebug() << "port série fermé";
       ui->pushButtonOuvrirPortSerie->setText("Ouvrir le port série");
   }
   else{
       qDebug() << "Erreur de l'ouverture du port : " << lePortSerie.errorString();
   }


/*
   if (lePortSerie.open(QIODeviceBase::ReadWrite)){
       qDebug() << "port série ouvert avec succès";
   }
   else{
       qDebug() << "Erreur de l'ouverture du port : " << lePortSerie.errorString();
   }
*/



}


void LiaisonSerie::on_pushButtonEnvoyer_clicked()
{
    QString data = ui->lineEdit->text();

    if (lePortSerie.write(data.toLatin1())){     //toLatin1 pour convertir la chaine
        qDebug() << "ça marche";
    }
    else {
        qDebug() << "ERREUR";

    }
}

void LiaisonSerie::on_comboBox_currentTextChanged(const QString &arg1)
{
    lePortSerie.setPortName(arg1);
}

void LiaisonSerie::onQSerialPortready_read()
{
    QByteArray data = lePortSerie.readAll();
    ui->textEdit->append(data);
    qDebug() << "contenu : " << data;
}



