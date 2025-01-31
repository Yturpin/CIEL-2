#include <QCoreApplication>
#include "client.h"
#include <QTimer>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.ConnecterAuServeur("172.18.58.150", 1234);
    QTimer::singleShot(2000, [&]() {
        client.EnvoyerMessage("Hello, Serveur c'est Yane!");
        });
    return a.exec();
}
