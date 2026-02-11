#include "SimPart.h"
using namespace std;

SimPart::SimPart(const array<double, 4>& p_in, string id_particle, string id_parent) {
    p = p_in;
    pID = id_particle;
    parentID = id_parent;
}

void SimPart::setIDParticle(string id_particle) {
    pID = id_particle;
}

void SimPart::setIDParent(string id_parent) {
    parentID = id_parent;
}

string SimPart::getIDParticle() const {
    return pID;
}

string SimPart::getIDParent() const {
    return parentID;
}