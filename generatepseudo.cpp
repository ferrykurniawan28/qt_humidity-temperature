#include "generatepseudo.h"

GeneratePseudo::GeneratePseudo(QObject *parent)
    : QThread{parent}
{
    m_fStopped = false;
}

void GeneratePseudo::run()
{
    // generate pseudo values for temperature and humidity 1 times per second until 10 seconds
    for(int i = 0; i < 10; i++){
        if(m_fStopped)
            break;
        auto values = sensor.generateValues();
        temperature = values.first;
        humidity = values.second;
        emit sendValues(temperature, humidity);
        QThread::sleep(1);
    }

    m_fStopped = false;
}
