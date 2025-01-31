#include "auditserveurwidget.h"
#include "ui_auditserveurwidget.h"

AuditServeurWidget::AuditServeurWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditServeurWidget)
    , socketDialogueClient(nullptr)
{
    ui->setupUi(this);
    socketEcouteServer = new QTcpServer(this);
    socketEcouteServer->setMaxPendingConnections(1);

    connect(socketEcouteServer, &QTcpServer::newConnection, this, &AuditServeurWidget::onQTcpServerNewConnection);
    connect(socketEcouteServer, &QTcpServer::acceptError, this, &AuditServeurWidget::onQTcpServerAcceptError);

    process = new QProcess(this);
    connect(process, &QProcess::readyReadStandardOutput, this, &AuditServeurWidget::onQProcessReadyReadStandardOutput);
}

AuditServeurWidget::~AuditServeurWidget()
{
    delete ui;

    if(socketDialogueClient != nullptr){
        socketDialogueClient->close();
        delete socketDialogueClient;
    }

    delete socketEcouteServer;
    delete process;
}

void AuditServeurWidget::on_pushButtonLancementServeur_clicked()
{
    if(!socketEcouteServer->listen(QHostAddress::Any, ui->spinBoxPort->value())){
        QString message = "Impossible de démarrer le serveur" + socketEcouteServer->errorString();
        ui->textEditInformations->append(message);
        qDebug() << "Echec au lancement du serveur : " << socketEcouteServer->errorString();
    }
    else{
        qDebug() << "Serveur connecté sur le port" << ui->spinBoxPort->value();
        QList<QHostAddress> listeAdresses = QNetworkInterface::allAddresses();
        QList<QHostAddress>::iterator it;
        for(it = listeAdresses.begin(); it != listeAdresses.end(); it++){
            ui->textEditInformations->addAction(it);
        }
    }
}

void AuditServeurWidget::onQTcpServerNewConnection()
{
    /*QTcpSocket *client;
    client = socketEcouteServeur->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&AuditServeurWidget::onQTcpSocketReadyRead);
    //...
    lesClient.append(client); // ajout dans la liste des sockets
    //...
    */
}

void AuditServeurWidget::onQTcpServerAcceptError()
{

}

void AuditServeurWidget::onQTcpSocketConnected()
{

}

void AuditServeurWidget::onQTcpSocketDisconnected()
{

}

void AuditServeurWidget::onQTcpSocketReadyRead()
{

}

void AuditServeurWidget::onQTcpSocketErrorOccured(const QAbstractSocket::SocketError _socketError)
{

}

void AuditServeurWidget::onQTcpSocketStateChanged(const QAbstractSocket::SocketState _socketState)
{

}

void AuditServeurWidget::onQTcpSocketHostFound()
{
    QString reponse;
    reponse = getenv("USER");
    reponse = QHostInfo::localHostName();
}

void AuditServeurWidget::onQTcpSocketBytesWritten(const qint64 _bytes)
{

}

void AuditServeurWidget::onQTcpSocketAboutToClose()
{

}

void AuditServeurWidget::onQProcessReadyReadStandardOutput()
{
    QString reponse = process->readAllStandardOutput();
    if(!reponse.isEmpty())
        socketDialogueClient->write(reponse.toLatin1());
}

