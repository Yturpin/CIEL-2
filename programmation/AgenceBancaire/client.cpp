#include "client.h"

Client::Client(const int _idCompte, const float _solde, const QString _nom, const QString _prenom, const QString _ville, const int _idAgence)
    :idCompte(_idCompte)
    , solde(_solde)
    , nom(_nom)
    , prenom(_prenom)
    , ville(_ville)
    , idAgence(_idAgence)
{}
