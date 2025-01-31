#include "barre.h"
#include <iostream>
#include <string>

using namespace std;


Barre::Barre(string _reference, int _longueur, float _densite, string _nomAlliage):
    reference(_reference),
    longueur(_longueur),
    densite(_densite),
    nomAlliage(_nomAlliage)

{


}

void Barre::afficherCaracteristique()
{
    cout << "Reference de la barre : " << reference << endl;
    cout << "Nom de l'alliage : " << nomAlliage << " -densité de l'alliage " << densite << " g/cm³" <<endl;
    cout << "Longueur de la barre : " << longueur << " cm" << endl;
    cout <<"-----------------------" << endl;
}
