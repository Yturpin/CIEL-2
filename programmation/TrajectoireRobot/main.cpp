#include <iostream>
#include "trajectoire.h"
#include "segment.h"


using namespace std;

int main()
{

    Trajectoire uneTrajectoire(1);
    Segment unSegment(9.0, 0.0);
    Segment deuxiemeSegment(5, 0.927295);

    uneTrajectoire.afficher();

    /*
    unSegment.afficher();
    deuxiemeSegment.afficher();
    */
    return 0;
}
