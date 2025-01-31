#include "clientfiestawidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientFiestaWidget w;
    w.show();
    return a.exec();
}
