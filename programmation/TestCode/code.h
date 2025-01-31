#ifndef CODE_H
#define CODE_H

#include <QtGlobal>
#include <QDebug>

class Code
{
public:
    Code(int _tailleCode);
    ~Code();
    bool VerifierCode(const quint8 _unCode[]);
    void Memoriser(const quint8 _unCode[]);
private:
    quint8 *codeUsine;
    quint8 *codeUtilisateur;
    int tailleCode;
};

#endif // CODE_H
