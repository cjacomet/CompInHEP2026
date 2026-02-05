#ifndef MET_H
#define MET_H
#include <cmath>

class Met {
    public:
    Met()=default;
    Met(double val, double xVal, double yVal);
    ~Met()=default;
    double getValue();
    double getX();
    double getY();
    double getPhi();

    private:
    double value,x,y;
};
#endif
