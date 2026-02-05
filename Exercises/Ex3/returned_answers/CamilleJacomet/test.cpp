#include "MeasMET.h"
#include <iostream>
using namespace std;

void testCreator() {
    {
        MeasMET met1;
    }
    cout << "Tested default creator and destructor" << endl;
    MeasMET met2(1.1,2.2,3.3);
    cout << "Tested creator with arguments" << endl;
};

void testValue() {
    double val = 2.2;
    MeasMET met(val,1,1);
    if (met.getValue() == val) {
        cout << "Test getValue: pass" << endl;
    } else {
        cout << "Test getValue: fail" << endl;
    }
};

void testX() {
    double x = 3.1;
    MeasMET met(1,x,1);
    if (met.getX() == x) {
        cout << "Test getX: pass" << endl;
    } else {
        cout << "Test getX: fail" << endl;
    }
};

void testY() {
    double y = 0.5;
    MeasMET met(1,1,y);
    if (met.getY() == y) {
        cout << "Test getY: pass" << endl;
    } else {
        cout << "Test getY: fail" << endl;
    }
};

void testPhi() {
    double x = 0.3;
    double y = 1.2;
    MeasMET met(5,x,y);
    if (met.getPhi() == atan(y/x)) {
        cout << "Test getPhi: pass" << endl;
    } else {
        cout << "Test getPhi: fail" << endl;
    }
};

int main() {
    testCreator();
    testValue();
    testX();
    testY();
    testPhi();
    return 0;
};