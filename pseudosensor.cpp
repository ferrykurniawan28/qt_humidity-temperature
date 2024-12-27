#include "pseudosensor.h"

PseudoSensor::PseudoSensor()
    : h_range({0, 20, 20, 40, 40, 60, 60, 80, 80, 90, 70, 70, 50, 50, 30, 30, 10, 10}),
    t_range({-20, -10, 0, 10, 30, 50, 70, 80, 90, 80, 60, 40, 20, 10, 0, -10}),
    h_range_index(0),
    t_range_index(0),
    humVal(h_range[0]),
    tempVal(t_range[0]) {}

// Generate random values
std::pair<double, double> PseudoSensor::generateValues() {
    humVal = h_range[h_range_index] + getRandom(0.0, 10.0);
    tempVal = t_range[t_range_index] + getRandom(0.0, 10.0);

    h_range_index = (h_range_index + 1) % h_range.size();
    t_range_index = (t_range_index + 1) % t_range.size();

    return {humVal, tempVal};
}

// Generate a random value between min and max
double PseudoSensor::getRandom(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}
