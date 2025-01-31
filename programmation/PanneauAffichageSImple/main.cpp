#include "panneauaffichagesimple.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PanneauAffichageSimple w;
    w.show();
    return a.exec();
}
