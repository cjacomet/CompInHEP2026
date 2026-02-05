#include "MeasMET.h"

MeasMET::MeasMET(double val, double xVal, double yVal) : value(val), x(xVal), y(yVal) {};

double MeasMET::getValue() {return value;};

double MeasMET::getX() {return x;};

double MeasMET::getY() {return y;};

double MeasMET::getPhi() {
    return 0.0;
};