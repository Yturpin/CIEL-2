#include <iostream>
#include <iomanip>
#include <limits>
#include "emballage.h"


using namespace std;

int main()
{
    //Emballage colis("XS", 1, 270, 190);
    Emballage *pColis;
    Emballage *tabColis[5];

    string format;
    int resistanceMax;
    int largeur;
    int longueur;
    int hauteur;

    for (int var = 0; var < 5; ++var) {
        cout << "Nom du format :";
        getline(cin, format);
        cout << "largeur :";
        cin >> largeur;
        cout << "longeur :";
        cin >> longueur;
        cout << "hauteur :";
        cin >> hauteur;
        cout << "Resistance max :";
        cin >> resistanceMax;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Vider le buffer cours page 31
        tabColis[var] = new Emballage(format, resistanceMax, largeur, longueur, hauteur); //

    }

    //Partie haute du tableau (légende)

    cout << setfill('-');
    cout << "+" << setw(18) << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";

    cout << endl;
    cout << setfill(' ');
    cout << "|" << setw(17) << left << "Format";
    cout << "|" << setw(11) << left << "Resistance";
    cout << "|" << setw(17) << left << "Dimension";
    cout << "|";

    //cout << endl;
    cout << setfill('-');
    cout << "+" << setw(18) << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";

    cout << endl;
    cout << setfill(' ');

    for (int indice = 0; indice < 5; ++indice) {
        tabColis[indice]->Visualise();
    }
    pColis = new Emballage("XL", 7, 383, 250, 196);


    cout << setfill('-');
    cout << "+" << setw(18) << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";

    if(*tabColis[0] < *tabColis[1])
        cout << "tabColis[0] est plus petit que tabColis[1]" << endl;
    else
        cout << "tabColis[1] est plus petit que tabColis[0]" << endl;

    if(*tabColis[0] == *tabColis[1])
        cout << "Les emballages tabColis[0] et tabColis[1] sont identiques" << endl;
    else
        cout << "Les emballages tabColis[1] et tabColis[0] sont différents" << endl;

    float volume = *tabColis[0];
    cout << "Volume de tabColis[0] est de " << volume << " cm3" << endl;

    delete pColis;
    for(int indice = 0; indice < 5; ++indice){
        delete tabColis[indice];
    }

    return 0;
}


//setfil(remplir le fil)
