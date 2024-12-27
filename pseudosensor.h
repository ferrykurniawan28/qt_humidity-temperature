#ifndef PSEUDOSENSOR_H
#define PSEUDOSENSOR_H

#include <vector>
#include <random>
#include <utility>

class PseudoSensor
{
public:
    PseudoSensor();
    std::pair<double, double> generateValues();
private:
    std::vector<int> h_range;
    std::vector<int> t_range;
    int h_range_index;
    int t_range_index;
    double humVal;
    double tempVal;

    double getRandom(double min, double max);
};

#endif // PSEUDOSENSOR_H
