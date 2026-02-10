#ifndef RECTRACK_H
#define RECTRACK_H
#include <array>

class RecTrack{
    public:
    RecTrack() = default;
    RecTrack(const std::array<double, 4>& p_in);
    ~RecTrack() = default;

    void setTrack(const std::array<double, 4>& p_in);

    std::array<double, 4> get4Mom() const;
    double getTransMom() const;
    double getPseudoRap() const;

    protected:
    std::array<double, 4> p; //t,x,y,z components in that order
};
#endif