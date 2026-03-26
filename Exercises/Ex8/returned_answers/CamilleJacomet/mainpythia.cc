#include <ctime>
#include <fstream>

#include "Pythia8/Pythia.h"
using namespace Pythia8;
int main() {
  // Generator. Process selection. LHC initialization.
  Pythia pythia;
  pythia.readString("Beams:eCM = 13600");
  pythia.readString("SoftQCD:nonDiffractive = on"); // minimum-bias events

  //  pythia.readString("PDF:pSet = 8");

  pythia.init();

  ofstream fOUT;
  fOUT.open ("muons.out");

  for (int iEvent = 0; iEvent < 100000; ++iEvent) {
    if (!pythia.next()) continue;

    for (int i = 0; i < pythia.event.size(); ++i)
      if (abs(pythia.event[i].id()) == 13 && pythia.event[i].isFinal()) {
        double pT = pythia.event[i].pT();
        double eta = pythia.event[i].eta();
        cout << "transverse momentum = " << std::setprecision(9) << pT;
        cout << ", pseudo-rapidity = " << std::setprecision(9) << eta << endl;
        fOUT << std::setprecision(9) << pT << " " << eta << endl;
      }
  }

  fOUT.close();
  pythia.stat();

  return 0;
}