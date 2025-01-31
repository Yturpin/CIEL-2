#include "element.h"

/**
 * @brief Element::Element
 * constructeur avec liste d'initialistion
 */
Element::Element(double _vitesse):
    numero(0),
    vitesse(_vitesse)
{

}

Element::~Element()
{

}

int Element::getNumero()
{
    return numero;
}

void Element::setNumero(const int _numero)
{
    numero = _numero;
}
