#ifndef CHARIOT_H
#define CHARIOT_H

#include <QObject>

class Chariot : public QObject
{
    Q_OBJECT
public:
    explicit Chariot(QObject *parent = nullptr);
    void DeplacerChariot(const int rangee, const int colonne, const bool sens);

    enum SENS {
        VERS_MAGASIN = false,
        VERS_ENCEINTE
    };

signals:
};

#endif // CHARIOT_H
