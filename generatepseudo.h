#ifndef GENERATEPSEUDO_H
#define GENERATEPSEUDO_H

#include "pseudosensor.h"
#include <QThread>

class GeneratePseudo : public QThread
{
    Q_OBJECT
    volatile bool m_fStopped = false;
public:
    explicit GeneratePseudo(QObject *parent = nullptr);
protected:
    void run() override;
signals:
    void sendValues(double temperature, double humidity);
private:
    PseudoSensor sensor;
    double temperature;
    double humidity;
    void stop() {
        m_fStopped = true;
    };
};

#endif // GENERATEPSEUDO_H
