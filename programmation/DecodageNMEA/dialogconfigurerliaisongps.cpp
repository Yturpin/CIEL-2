#include "dialogconfigurerliaisongps.h"
#include "ui_dialogconfigurerliaisongps.h"

DialogConfigurerLiaisonGPS::DialogConfigurerLiaisonGPS(QSerialPort &_lePort, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogConfigurerLiaisonGPS)
    , lePort(_lePort)
{
    ui->setupUi(this);

    ui->comboBoxChoixPort->addItem("Choisissez un port");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        qDebug() << "Nom : " << info.portName();
        ui->comboBoxChoixPort->addItem(info.portName());
    }

    //Boucle pour choisir les valeurs multiple de 2
    for (int vitesse = 1200; vitesse <= 19200; vitesse *= 2){
        ui->comboBoxVitesseTransmi->addItem(QString::number(vitesse));
    }

    //ui->comboBoxVitesseTransmi->addItem("1200");
    //ui->comboBoxVitesseTransmi->addItem("2400");
    //ui->comboBoxVitesseTransmi->addItem("4800");
    ui->comboBoxVitesseTransmi->setCurrentText("9600");
    ui->comboBoxVitesseTransmi->addItem("19200");
    ui->comboBoxVitesseTransmi->addItem("38400");
    ui->comboBoxVitesseTransmi->addItem("57600");
    ui->comboBoxVitesseTransmi->addItem("115200");

    lePort.setBaudRate(QSerialPort::Baud9600);  //Config vitesse de transmission port

    ui->spinBoxNbBitsDonnees->setRange(5, 8);
    ui->spinBoxNbBitsDonnees->setValue(8);
    lePort.setDataBits(QSerialPort::Data8); //Nb de bits de données

    //Parité
    ui->radioButtonPasDeParite->setChecked(true);

    //Bit de stop
    lePort.setStopBits(QSerialPort::OneStop); //1 bit de stop

    //Controle de flux
    ui->comboBoxControleFlux->addItem("Pas de contrôle de flux");
    ui->comboBoxControleFlux->addItem("Matériel (RTS/CTS)");
    ui->comboBoxControleFlux->addItem("Logiciel (XON/XOFF)");
    lePort.setFlowControl(QSerialPort::NoFlowControl); //Pas de controle de flux

    //Bouton ok nn validé si pas de port valide select
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

DialogConfigurerLiaisonGPS::~DialogConfigurerLiaisonGPS()
{
    delete ui;
}

void DialogConfigurerLiaisonGPS::on_comboBoxVitesseTransmi_currentTextChanged(const QString &arg1)
{

}


void DialogConfigurerLiaisonGPS::on_comboBoxChoixPort_currentIndexChanged(int index)
{
    if(index != 0){
        QString nomPort = ui->comboBoxChoixPort->currentText();
        lePort.setPortName(nomPort);
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    else{
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}


void DialogConfigurerLiaisonGPS::on_checkBoxBitsDeStop_toggled(bool checked)
{

}


void DialogConfigurerLiaisonGPS::on_radioButtonPaire_toggled(bool checked)
{

}


void DialogConfigurerLiaisonGPS::on_radioButtonImpaire_toggled(bool checked)
{

}


void DialogConfigurerLiaisonGPS::on_radioButtonPasDeParite_toggled(bool checked)
{

}


void DialogConfigurerLiaisonGPS::on_spinBoxNbBitsDonnees_valueChanged(int arg1)
{

}

