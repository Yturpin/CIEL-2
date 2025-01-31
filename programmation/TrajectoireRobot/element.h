#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
public:
    Element(double _vitesse = 1);
    virtual ~Element();
    virtual void afficher() = 0;
    virtual int getNumero();      //accesseur --> récupérer le contenu de l'attribut numero
    virtual void setNumero(const int _numero);      //mutateur --> modification de l'attribut numero

protected:
    int numero;
    double vitesse;
};

#endif // ELEMENT_H
