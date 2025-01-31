//#include <QCoreApplication>
#include <QtGlobal>
#include "code.h"
#include <iostream>

using namespace std;

#define TAILLE_CODE 4

int main(int argc, char *argv[])
{

    char choix;
    quint8 combinaison[TAILLE_CODE];
    Code leCode(TAILLE_CODE);

    cout << " Voulez vous modifier le code ? O/N : ";
    cin >> choix;

    if(choix == 'O' || choix == 'o'){
        cout << "Entrez le nouveau code à 4 chiffres" << endl;
            for(int i = 0; i < TAILLE_CODE; i++){
            cin >> combinaison[i];
            combinaison[i] -= '0';
        }
        leCode.Memoriser(combinaison);

        qDebug() << "Code mémorisé saisie :";
        for(int i = 0; i < TAILLE_CODE; i++){
            qDebug() << combinaison[i];
        }
    }

    cout << "Entrez un code à 4 chiffres" << endl;
    for(int i = 0; i < TAILLE_CODE; i++){
        cin >> combinaison[i];
        combinaison[i] -= '0';
    }

    qDebug() << " Code Utilisateur :";
    for(int i = 0; i < TAILLE_CODE; i++){
        qDebug() << combinaison[i];


        if(leCode.VerifierCode(combinaison))
        {
            cout << "Le code est valide" << endl;
        }
        else
        {
            cout << "Le code n'est pas valide" << endl;
        }
    }

    return 0;

    /*
    QCoreApplication a(argc, argv);

    return a.exec();
    */
}
