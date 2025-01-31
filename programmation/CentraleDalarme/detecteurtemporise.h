#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H
#include <detecteur.h>
#include <QTimer>

class DetecteurTemporise : public Detecteur
{
public:
    DetecteurTemporise();
    ~DetecteurTemporise();
    void LancerTempo();
private slots:
    void on_pushButtonPresence_clicked();
private:
    QTimer timerPresence;
};

#endif // DETECTEURTEMPORISE_H
