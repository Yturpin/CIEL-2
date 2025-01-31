#include <QCoreApplication>
#include "serveur.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Serveur serveur;
    serveur.LancerServeur(1234);
    return a.exec();
}
