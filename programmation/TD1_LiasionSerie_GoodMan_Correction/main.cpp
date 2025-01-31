#include "liaisonserie.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LiaisonSerie w;
    w.show();
    return a.exec();
}
