#ifndef RECTRACK_H
#define RECTRACK_H

class RecTrack{
    public:
    RecTrack();
    RecTrack(double* p_in);
    ~RecTrack();

    void setTrack(double* p);

    double* get4Mom() const;
    double getTransMom() const;
    double getPseudoRap() const;

    protected:
    double* p;
};
#endif