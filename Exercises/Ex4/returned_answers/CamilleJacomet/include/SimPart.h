#ifndef SIMPART_H
#define SIMPART_H
#include "RecTrack.h"
#include <string>

class SimPart : protected RecTrack{
    public:
    SimPart();
    SimPart(double* p_in, std::string id_particle, std::string id_parent);
    ~SimPart();

    void setIDParticle(std::string id_particle);
    void setIDParent(std::string id_parent);
    std::string getIDParticle() const;
    std::string getIDParent() const;

    protected:
    std::string pID;
    std::string parentID;
};
#endif