#ifndef BARRE_H
#define BARRE_H
#include <iostream>
#include <string>

using namespace std;

class Barre
{
public:
    Barre(string _reference, int _longueur, float _densite);
    virtual ~Barre();
    virtual void afficherCaracteristiques();
    virtual float calculerMasse() = 0;

protected:
    string reference;
    int longueur;
    float densite;
};

#endif // BARRE_H
