#include "RecTrack.h"
#include <cmath>
using namespace std;

RecTrack::RecTrack(const array<double, 4>& p_in) {
    p = p_in;
}

void RecTrack::setTrack(const array<double, 4>& p_in) {
    p = p_in;
}

array<double, 4> RecTrack::get4Mom() const {
    return p;
}

double RecTrack::getTransMom() const {
    return sqrt(p[1]*p[1] + p[2]*p[2]);
}

double RecTrack::getPseudoRap() const {
    double theta = atan2(getTransMom(), p[3]);
    return -log(tan(theta / 2));
}