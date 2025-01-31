#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H

#include <QStack>

class AlveolesLibres : public QStack<int>
{
public:
    AlveolesLibres(const int _nbRangees = 10, const int _nbColonnes = 20);
    bool Reserver(int &_rangee, int &_colonne);
    void Liberer(const int _rangee, const int _colonne);

private:
    const int nbRangeees;
    const int nbColonnes;
};
#endif // ALVEOLESLIBRES_H
