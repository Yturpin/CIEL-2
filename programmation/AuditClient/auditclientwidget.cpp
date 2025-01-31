#include "auditclientwidget.h"
#include "ui_auditclientwidget.h"

AuditClientWidget::AuditClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditClientWidget)
    , socketClient(new QTcpSocket(this))
{
    ui->setupUi(this);

    connect(socketClient, &QTcpSocket::connected, this, &AuditClientWidget::onQTcpSocketConnected);
    connect(socketClient, &QTcpSocket::disconnected, this, &AuditClientWidget::onQTcpSocketDisconnected);
    connect(socketClient, &QTcpSocket::readyRead, this, &AuditClientWidget::onQTcpSocketReadyRead);
    connect(socketClient, &QTcpSocket::errorOccurred, this, &AuditClientWidget::onQTcpSocketErrorOccured);
    connect(socketClient, &QTcpSocket::hostFound, this, &AuditClientWidget::onQTcpSocketHostFound);
    connect(socketClient, &QTcpSocket::stateChanged, this, &AuditClientWidget::onQTcpSocketStateChanged);
    connect(socketClient, &QTcpSocket::aboutToClose, this, &AuditClientWidget::onQTcpSocketAboutToClose);
    connect(socketClient, &QTcpSocket::bytesWritten, this, &AuditClientWidget::onQTcpSocketBytesWritten);
    connect(socketClient, &QTcpSocket::channelBytesWritten, this, &AuditClientWidget::onQTcpSocketChannelBytesWritten);
    connect(socketClient, &QTcpSocket::channelReadyRead, this, &AuditClientWidget::onQTcpSocketChannelReadyRead);
    connect(socketClient, &QTcpSocket::readChannelFinished, this, &AuditClientWidget::onQTcpSocketReadChannelFinished);
    connect(socketClient, &QTcpSocket::destroyed, this, &AuditClientWidget::onQTcpSocketDestroyed);
}

AuditClientWidget::~AuditClientWidget()
{
    delete ui;

    if(socketClient != nullptr){
        socketClient->close();
        delete socketClient;
    }

}

void AuditClientWidget::on_pushButtonConnexion_clicked()
{
    if(ui->pushButtonConnexion->text() == "Connexion"){
        socketClient->connectToHost(ui->lineEditAdresseIP->text(), ui->lineEditPort->text().toInt());
    }
    else{
        socketClient->disconnectFromHost();
    }
}

void AuditClientWidget::on_pushButtonOrdinateur_clicked()
{
    typeDeDemande = 'c';
    socketClient->write(&typeDeDemande,1);
}


void AuditClientWidget::on_pushButtonUtilisateur_clicked()
{
    typeDeDemande = 'u';
    socketClient->write(&typeDeDemande,1);
}


void AuditClientWidget::on_pushButtonProcesseur_clicked()
{
    typeDeDemande = 'a';
    socketClient->write(&typeDeDemande,1);
}


void AuditClientWidget::on_pushButtonOs_clicked()
{
    typeDeDemande = 'o';
    socketClient->write(&typeDeDemande,1);
}

void AuditClientWidget::onQTcpSocketConnected()
{
    ui->textEditEtat->append("Connecté au serveur");
    ui->pushButtonConnexion->setText("Déconnexion");
    ui->lineEditAdresseIP->setEnabled(false);
    ui->lineEditPort->setEnabled(false);
    ui->groupBoxInformationClient->setEnabled(true);
    ui->pushButtonOrdinateur->setEnabled(true);

    ui->lineEditOrdinateur->clear();
    ui->lineEditOs->clear();
    ui->lineEditProcesseur->clear();
    ui->lineEditUtilisateur->clear();

    qDebug() << "Connecté au serveur";
}

void AuditClientWidget::onQTcpSocketDisconnected()
{
    ui->textEditEtat->append("Déconnecté au serveur");
    ui->pushButtonConnexion->setText("Connexion");
    ui->lineEditAdresseIP->setEnabled(true);
    ui->lineEditPort->setEnabled(true);
    ui->groupBoxInformationClient->setEnabled(false);

    qDebug() << "Déconnecté au serveur";
}

void AuditClientWidget::onQTcpSocketReadyRead()
{
    QByteArray buffer;

    if(socketClient->bytesAvailable() > 0){
        buffer = socketClient->readAll();
        qDebug() << "Données reçues du serveur : " << QString(buffer);
    }

    switch(typeDeDemande){
    case 'u':
        ui->lineEditUtilisateur->setText(buffer.data());
        break;
    case 'a':
        ui->lineEditProcesseur->setText(buffer.data());
        break;
    case 'o':
        ui->lineEditOs->setText(buffer.data());
        break;
    case 'c':
        ui->lineEditOrdinateur->setText(buffer.data());
        break;
    }

}

void AuditClientWidget::onQTcpSocketErrorOccured(const QAbstractSocket::SocketError _socketError)
{

    Q_UNUSED(_socketError); // le paramètre n'est pas utilisé dans cette méthode
    ui->textEditEtat->append(socketClient->errorString());

}

void AuditClientWidget::onQTcpSocketHostFound()
{
    ui->textEditEtat->append("Hôte distant trouvé");
}

void AuditClientWidget::onQTcpSocketStateChanged(const QAbstractSocket::SocketState _socketState)
{
    switch(_socketState){
    case QAbstractSocket::UnconnectedState : ui->textEditEtat->append("Socket ...");
        break;
    case QAbstractSocket::HostLookupState: ui->textEditEtat->append("Socket ...");
        break;
    case QAbstractSocket::ConnectingState : ui->textEditEtat->append("Socket ...");
        break;
    case QAbstractSocket::ConnectedState : ui->textEditEtat->append("La ...");
        break;
    case QAbstractSocket::BoundState : ui->textEditEtat->append("Socket ...");
        break;
    case QAbstractSocket::ListeningState : ui->textEditEtat->append("Socket ...");
        break;
    case QAbstractSocket::ClosingState : ui->textEditEtat->append("Socket ...");
        break;
    default:
        break;
    }

}

void AuditClientWidget::onQTcpSocketAboutToClose()
{
    ui->textEditEtat->append("about to close");
}

void AuditClientWidget::onQTcpSocketBytesWritten(const qint64 _bytes)
{
    ui->textEditEtat->append(QString::number(_bytes) + "bytes written");
}

void AuditClientWidget::onQTcpSocketChannelBytesWritten(const int _channel, const qint64 _bytes)
{
    ui->textEditEtat->append(QString::number(_bytes) + "bytes written on channel");
}

void AuditClientWidget::onQTcpSocketChannelReadyRead(const int _channel)
{
    ui->textEditEtat->append("Ready read on channel" + QString::number(_channel));
}

void AuditClientWidget::onQTcpSocketReadChannelFinished()
{
    ui->textEditEtat->append("Read channel finished");
}

void AuditClientWidget::onQTcpSocketDestroyed(const QObject *_obj)
{
    Q_UNUSED(_obj);
    ui->textEditEtat->append("obj destroyed");
}

