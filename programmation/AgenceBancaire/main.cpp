#include "agencebancaire.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AgenceBancaire w;
    w.show();
    return a.exec();
}
