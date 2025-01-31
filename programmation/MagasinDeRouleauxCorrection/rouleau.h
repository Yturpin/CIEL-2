#ifndef ROULEAU_H
#define ROULEAU_H

#include <QObject>

class Rouleau : public QObject
{
    Q_OBJECT
public:
    Rouleau();  //Constructeur par défaut
    Rouleau(const Rouleau &_autre); //Constructeur de recopie
    Rouleau(const QString _reference, const int _diametre, QObject *parent = nullptr); //Constructeur avec paramètres
    Rouleau &operator=(const Rouleau& _autre); // Surcharge opérateur '='
    ~Rouleau();  // Destructeur

    void AffecterLocalisation(const int _rangee, const int _colonne);
    void ObtenirLocalisation(int &_rangee, int &_colonne) const;

    QString getReference() const;
    int getDiametre() const;

private:
    QString reference;
    int diametre;
    int rangee;
    int colonne;

};

#endif // ROULEAU_H
