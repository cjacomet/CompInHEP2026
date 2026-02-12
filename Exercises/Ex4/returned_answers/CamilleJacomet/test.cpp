#include "RecTrack.h"
#include "SimPart.h"
#include <iostream>
using namespace std;

void testRTset(array<double, 4>& p_in) {
    cout << "Testing default constructor and setTrack for RecTrack class" << endl;
    RecTrack testTrack;
    testTrack.setTrack(p_in);

    array<double, 4> p_out = testTrack.get4Mom();
    cout << "Get 4-momentum (t,x,y,z): ";
    for (const auto& i : p_out)
        cout << i << ' ';
    cout << endl;

    cout << "Get transverse momentum: " << testTrack.getTransMom() << endl;
    cout << "Get pseudorapidity: " << testTrack.getPseudoRap() << endl;
}

void testRTconstr(array<double, 4>& p_in) {
    cout << "Testing constructor with argument of RecTrack class" << endl;
    RecTrack testTrack(p_in);

    array<double, 4> p_out = testTrack.get4Mom();
    cout << "Get 4-momentum (t,x,y,z): ";
    for (const auto& i : p_out)
        cout << i << ' ';
    cout << endl;
}

void testSPset(array<double, 4>& p_in, string id_particle, string id_parent) {
    cout << "Testing default constructor and setTrack for SimPart class" << endl;
    SimPart testPart;
    testPart.setTrack(p_in);
    testPart.setIDParticle(id_particle);
    testPart.setIDParent(id_parent);

    array<double, 4> p_out = testPart.get4Mom();
    cout << "Get 4-momentum (t,x,y,z): ";
    for (const auto& i : p_out)
        cout << i << ' ';
    cout << endl;
    cout << "Get particle ID: " << testPart.getIDParticle() << endl;
    cout << "Get parent ID: " << testPart.getIDParent() << endl;
}

void testSPconstr(array<double, 4>& p_in, string id_particle, string id_parent) {
    cout << "Testing constructor with argument for SimPart class" << endl;
    SimPart testPart(p_in, id_particle, id_parent);

    array<double, 4> p_out = testPart.get4Mom();
    cout << "Get 4-momentum (t,x,y,z): ";
    for (const auto& i : p_out)
        cout << i << ' ';
    cout << endl;
    cout << "Get particle ID: " << testPart.getIDParticle() << endl;
    cout << "Get parent ID: " << testPart.getIDParent() << endl;
}

int main() {
    array<double, 4> p_in = {0.707, 0.3, 0.4, 0.5};
    string id_particle = "electron";
    string id_parent = "muon";
    cout << "Input four-momentum: ";
    for (const auto& i : p_in)
        cout << i << ' ';
    cout << endl;
    cout << "Input particle ID: " << id_particle << endl;
    cout << "Input parent ID: " << id_parent << endl;

    testRTset(p_in);
    testRTconstr(p_in);
    testSPset(p_in, id_particle, id_parent);
    testSPconstr(p_in, id_particle, id_parent);
    return 0;
}