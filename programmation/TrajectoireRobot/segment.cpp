#include "segment.h"
#include <iostream>

using namespace std;

Segment::Segment(double _longueur, double _angle) :
    longueur(_longueur),
    angle(_angle)
{}

void Segment::afficher()
{
    cout << "SEGMENT L = " << longueur << "   A = " << angle << "   V = " << vitesse << endl;
    //cout << "SEGMENT L = " << longueur << endl;
}
