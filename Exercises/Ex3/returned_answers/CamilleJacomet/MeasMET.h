#ifndef MET_H
#define MET_H

class MeasMET {
    public:
    MeasMET()=default;
    MeasMET(double val, double xVal, double yVal);
    ~MeasMET()=default;
    double getValue();
    double getX();
    double getY();
    double getPhi();

    private:
    double value;
    double x;
    double y;
};
#endif