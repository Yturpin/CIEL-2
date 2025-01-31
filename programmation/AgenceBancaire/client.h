#ifndef CLIENT_H
#define CLIENT_H

#include <QString>

class Client
{
public:
    Client(const int _idCompte, const float _solde, const QString _nom, const QString _prenom, const QString _ville, const int _idAgence);

    const QString nom;
    const QString prenom;
    const int idCompte;
    const float solde;
    const QString ville;
    const int idAgence;
};

#endif // CLIENT_H
