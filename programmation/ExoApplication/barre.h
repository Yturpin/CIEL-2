#ifndef BARRE_H
#define BARRE_H
#include <string>

using namespace std;


class Barre
{
public:
    Barre(string _reference, int _longueur, float _densite, string _nomAlliage);
    void afficherCaracteristique();

protected:
    int longueur;
    float densite;
    string nomAlliage;
    string reference;

};

#endif // BARRE_H
