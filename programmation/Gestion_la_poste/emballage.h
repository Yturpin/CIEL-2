#ifndef EMBALLAGE_H
#define EMBALLAGE_H

#include <string>
#include <iostream>
using namespace std;

class Emballage
{
public:
    Emballage(const string _format, const int _resistanceMax, const int _longueur, const int _largeur, const int _hauteur = 0);
    ~Emballage();
    void Visualise();
    bool operator < (Emballage &_autre);
    bool operator == (Emballage &_autre);
    operator float();
    double CalculerVolume();

private:
    string format;
    int resistanceMax;
    int longueur;
    int largeur;
    int hauteur;
    int nbEmballagesDispo;

};

#endif // EMBALLAGE_H
