#include "code.h"


Code::Code(int _tailleCode):
    tailleCode(_tailleCode)
{
    codeUsine = new quint8[tailleCode];
    codeUtilisateur = new quint8[tailleCode];

    for(int indice = 0; indice < tailleCode; indice++){
        codeUsine[indice] = indice + 1;
        codeUtilisateur[indice] = 0;
    }
    qDebug() << "Code usine :";
    for(int indice = 0; indice < tailleCode; indice++){
        qDebug() << codeUsine[indice];
    }
    qDebug() << "Code utilisateur :";
    for(int indice = 0; indice < tailleCode; indice++){
        qDebug() << codeUtilisateur[indice];
    }
}

Code::~Code()
{
    delete codeUsine;
    delete codeUtilisateur;
}

bool Code::VerifierCode(const quint8 _unCode[])
{
    //bool retourTest = true;
    bool testUsine = true;
    bool testUtilisateur = true;

    for(int indice = 0; indice < tailleCode; indice++){
        if(codeUsine[indice] != _unCode[indice]){
            testUsine = false;
        }
        if(codeUtilisateur[indice] != _unCode[indice]){
            testUtilisateur = false;
        }
    }
    qDebug() << "Test Utilisateur :" << testUtilisateur;
    qDebug() << "Test Usine :" << testUsine;

    return testUsine || testUtilisateur;


    /*
    for(int indice = 0; indice < tailleCode; indice++){
        if(codeUsine[indice] != _unCode[indice] && codeUtilisateur[indice] != _unCode[indice]){
            retourTest = false;
        }
    }
    return retourTest;
    */
}

void Code::Memoriser(const quint8 _unCode[])
{
    for(int indice = 0; indice < tailleCode; indice++){
        codeUtilisateur[indice] = _unCode[indice];
    }

    //qDebug() << " Le code utilisateur est :";
}
