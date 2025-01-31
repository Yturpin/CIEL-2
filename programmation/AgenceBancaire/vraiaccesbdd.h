#ifndef VRAIACCESBDD_H
#define VRAIACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QComboBox>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <client.h>
#include <QTimer>

class VraiAccesBdd : public QObject
{
    Q_OBJECT
public:
    explicit VraiAccesBdd(QObject *parent = nullptr);
    bool ConnecterAuSGBD(const QStringList _paramConnexion);
    void Deconnecter();
    void ObtenirAgences(QComboBox *_lesAgences);
    bool AjouterClient(const Client _client);
    QSqlTableModel *ConsulterComptesClients(const int _agence);

private:
    QSqlDatabase *db;

signals:
};

#endif // VRAIACCESBDD_H
