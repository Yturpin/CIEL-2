#include <iostream>
#include <string>
#include "barre.h"
#include "barreronde.h"
#include "barrerectangle.h"
#include "barrecarree.h"

using namespace std;

int main()
{
    Barre uneBarre("B154", 200, 8.73, "Laiton");
    BarreRonde uneBarreRonde("Barre ronde", 200, 8.73, "cuivre", 5.23);
    BarreRectangle uneBarreRectangle("Barre Rectangle", 90, 30.30, "iron", 120);
    BarreCarree uneBarreCarree("Barre Carrée", 5, 36.2, "iron", 5);

    //uneBarre.afficherCaracteristique();
    uneBarreRectangle.afficherCaracteristique();
    uneBarreRonde.afficherCaracteristique();
    uneBarreCarree.afficherCaracteristique();

    return 0;
}
