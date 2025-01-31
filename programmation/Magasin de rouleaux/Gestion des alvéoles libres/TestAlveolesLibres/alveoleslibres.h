#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H
#include <QStack>
#include <QDebug>

class AlveolesLibres : public QStack<int>
{
public:
    AlveolesLibres(const int _nbRangees = 10, const int _nbColonnes = 20);
    bool Reserver(int &_rangee, int &_colonne);   //param de sortie
    void Liberer(const int _rangee, const int _colonne);    //param d'entrée
private:
    const int nbRangees;
    const int nbColonnes;
};

#endif // ALVEOLESLIBRES_H
