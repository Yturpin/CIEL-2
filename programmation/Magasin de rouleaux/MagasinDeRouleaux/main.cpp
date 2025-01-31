#include "magasinderouleaux.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MagasinDeRouleaux w;
    w.show();
    return a.exec();
}
