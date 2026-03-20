#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main() {
    Pythia pythia;

    // Setup for SM Higgs production
    pythia.readString("HiggsSM:all = on");    // gluon fusion Higgs production
    pythia.readString("25:m0 = 125.0");        // Higgs mass = 125 GeV

    // Set PDF
    pythia.readString("PDF:pSet = 8");      // 8: CTEQ6L1

    int nEvents = 1000;
    pythia.init();

    std::ofstream outFile("higgs_masses.txt");

    for (int iEvent = 0; iEvent < nEvents; ++iEvent) {
        if (!pythia.next()) continue;

        for (int i = 0; i < pythia.event.size(); ++i) {
            if (pythia.event[i].id() == 25) { // Higgs PDG ID
                outFile << pythia.event[i].m() << "\n";
            }
        }
    }

    outFile.close();
    pythia.stat();

    return 0;
}