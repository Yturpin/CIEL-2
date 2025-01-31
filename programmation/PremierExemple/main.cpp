#include "monwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MonWidget w;
    w.show();
    return a.exec();
}
