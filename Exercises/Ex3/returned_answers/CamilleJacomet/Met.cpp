#include "Met.h"

Met::Met(double val, double xVal, double yVal) : value(val),x(xVal),y(yVal) {};

double Met::getValue() {return value;};

double Met::getX() {return x;};

double Met::getY() {return y;};

double Met::getPhi() {
    // tan(phi) = y/x
    return atan(y / x);
};
