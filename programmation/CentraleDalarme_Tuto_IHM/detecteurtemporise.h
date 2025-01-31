#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H
#include <detecteur.h>
#include <QTimer>

class DetecteurTemporise : public Detecteur
{
public:
    DetecteurTemporise();
private:
    QTimer timerPresence;
};

#endif // DETECTEURTEMPORISE_H
