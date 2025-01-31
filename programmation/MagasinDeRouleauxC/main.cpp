#include "magasin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Magasin w;
    w.show();
    return a.exec();
}
