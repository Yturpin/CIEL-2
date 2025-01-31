#include "liaisonserie.h"
#include "ui_liaisonserie.h"

#include <QSerialPortInfo>
#include <QList>
#include <QDebug>
#include <QSerialPort>
#include <QFile>
#include <QMessageBox>

LiaisonSerie::LiaisonSerie(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LiaisonSerie)
{
    ui->setupUi(this);

    for(const auto &info : QSerialPortInfo::availablePorts() ) // foreach
    {
        qDebug() << info.portName();
        ui->comboBoxPort->addItem(info.portName());
    }
    ui->pushButtonOuvrir->setDisabled(true);
    ui->pushButtonEnvoyer->setDisabled(true);

    //Connectez le slot pour le bouton



}

LiaisonSerie::~LiaisonSerie()
{
    delete ui;
}

void LiaisonSerie::on_pushButtonOuvrir_clicked()
{
    // Configurer les paramètres de communication série
    if(ui->pushButtonOuvrir->text()=="Ouvrir le port série")
    {
        ui->pushButtonOuvrir->setText("Fermer le port");
        lePortSerie.setBaudRate(QSerialPort::Baud115200);
        lePortSerie.setDataBits(QSerialPort::Data8);
        lePortSerie.setParity(QSerialPort::NoParity);
        lePortSerie.setStopBits(QSerialPort::OneStop);
        lePortSerie.setFlowControl(QSerialPort::NoFlowControl);
        if (lePortSerie.open(QIODevice::ReadWrite))
        {
            qDebug() << "Ouverture du port";
            ui->pushButtonEnvoyer->setEnabled(true);
            connect(&lePortSerie,&QSerialPort::readyRead,this,&LiaisonSerie::onQSerialPort_readyRead);
        }
        else
        {
            QMessageBox message;
            message.setText("Le port ne peut pas s'ouvrir");
            message.exec();
        }

    }
    else
    {
        ui->pushButtonOuvrir->setText("Ouvrir le port série");
        lePortSerie.close();
        ui->pushButtonEnvoyer->setDisabled(true);
    }

}


void LiaisonSerie::on_pushButtonEnvoyer_clicked()
{
    QString texte = ui->lineEdit->text();
    lePortSerie.write(texte.toLatin1());
}

void LiaisonSerie::onQSerialPort_readyRead()
{
    QByteArray data = lePortSerie.readAll();
    ui->textEdit->append(data);
}

void LiaisonSerie::on_comboBoxPort_currentTextChanged(const QString &arg1)
{
    ui->pushButtonOuvrir->setEnabled(true);
    lePortSerie.setPortName(arg1);

}

