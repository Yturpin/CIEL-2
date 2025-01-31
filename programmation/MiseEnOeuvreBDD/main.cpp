#include "miseenoeuvrebdd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MiseEnOeuvreBDD w;
    w.show();
    return a.exec();
}
