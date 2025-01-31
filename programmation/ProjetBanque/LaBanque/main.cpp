#include <iostream>
#include "comptebancaire.h"
#include "menu.h"

using namespace std;

int main()
{
    //              --Programme compte bancaire--
    int choix;
    float montant;
    cout << "Programme la banque" << endl;


    CompteBancaire compte(100.0);

    //try permet de tester le code et envoyer une exception a catch qui pourra l'a traiter
    try{
        Menu leMenu("../LaBanque/compteBancaire.txt");
        while (choix != 4){
            choix = leMenu.Afficher();
            cout << "vous avez choisi : " << choix << endl;
            switch (choix) {
            case 1:
                cout << "Votre solde est de : " << compte.ConsulterSolde() << "€" << endl;
                break;
            case 2:
                cout << "Indiquer  le montant à déposer : " << endl;
                cin >> montant;
                compte.Deposer(montant);
                cout << "Votre solde est de : " << compte.ConsulterSolde() << "€" << endl;
                break;
            case 3:
                cout << "Indiquer  le montant à retirer : " << endl;
                cin >> montant;
                compte.Retirer(montant);
                cout << "Votre solde est de : " << compte.ConsulterSolde() << "€" << endl;
            default:
                break;
            }
        }
    }
    catch(Exception & e ){
        cout << e.ObtenirMessage() << endl;

    }



    //                  --Programme compte d'épargne--

    /*int
    cout << "Programme compte épargne" << endl;
    */
    return 0;
}
