#ifndef SEGMENT_H
#define SEGMENT_H
#include "element.h"

class Segment : public Element
{
public:
    Segment(double _longueur, double _angle);
    void afficher();


protected:
    double longueur;
    double angle;
};

#endif // SEGMENT_H
