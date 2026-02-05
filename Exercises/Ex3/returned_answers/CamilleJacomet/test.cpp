#include "Met.h"
#include <iostream>
using namespace std;

void testCreator() {
    {
        Met met1;
    }
    cout << "Tested default creator and destructor" << endl;
    Met met2(1.1,2.2,3.3);
    cout << "Tested creator with arguments" << endl;
}

bool testValue() {
    double val = 2.2;
    Met met(val,1,1);
    return met.getValue() == val;
}

bool testX() {
    double x = 3.1;
    Met met(1,x,1);
    return met.getX() == x;
}

bool testY() {
    double y = 0.5;
    Met met(1,1,y);
    return met.getY() == y;
}

bool testPhi() {
    double x = 0.3;
    double y = 1.2;
    Met met(5,x,y);
    return met.getPhi() == atan2(y, x);
}

int main() {
    testCreator();
    cout << "Test getValue: " << (testValue() ? "pass" : "fail") << endl;
    cout << "Test getX: " << (testX() ? "pass" : "fail") << endl;
    cout << "Test getY: " << (testY() ? "pass" : "fail") << endl;
    cout << "Test getPhi: " << (testPhi() ? "pass" : "fail") << endl;
    return 0;
}
