#include <iostream>
#include "barrecarree.h"
#include "barreronde.h"
#include "menu.h"
#include "catalogue.h"

using namespace std;

int main()
{

    BarreCarree uneBarreCarree("Barre 2x2 en Cuivre", 200, 8.920, 2);
    //uneBarreCarree.afficherCaracteristiques();
    /*
    cout << "Le poids de la barre est : " ;
    cout << uneBarreCarree.calculerMasse() / 1000.0;
    cout << " kg" << endl;
    cout << endl;
    */

    BarreRonde uneBarreRonde("Barre ronde diametre 2", 200, 8.5, 2);
    /*uneBarreRonde.afficherCaracteristiques();
    cout << "Le poids de la barre est : " ;
    cout << uneBarreRonde.calculerMasse() / 1000.0;
    cout << " kg" << endl;
    cout << endl;
    */

    Catalogue LeCatalogue(2);

    int choix;
    float montant;
    cout << "Programme les barres" << endl;

    //try permet de tester le code et envoyer une exception a catch qui pourra l'a traiter
    try{
        Menu leMenu("../LesBarres/choixCatalogue.txt");
        while (choix != 4){
            choix = leMenu.Afficher();
            cout << "vous avez choisi : " << choix << endl;
            switch (choix) {
            case 1:
                uneBarreCarree.afficherCaracteristiques();
                break;
            case 2:
                uneBarreRonde.afficherCaracteristiques();
                break;
            case 3:
                LeCatalogue.AfficherCatalogue();
            default:
                break;
            }
        }
    }
    catch(Exception & e ){
        cout << e.ObtenirMessage() << endl;

    }


    return 0;
}
