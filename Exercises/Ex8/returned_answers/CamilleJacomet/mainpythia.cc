#include <ctime>

#include <fstream>
using namespace std;

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

  for (int iEvent = 0; iEvent < 1000; ++iEvent) {
    if (!pythia.next()) continue;

    int idH = 0;
    for (int i = 0; i < pythia.event.size(); ++i)
      if (pythia.event[i].id() == 13) idH = i;
    double pT = pythia.event[idH].pT();
    double eta = pythia.event[idH].eta();
    cout << "transverse momentum = " << std::setprecision(9) << pT;
    cout << ", pseudo-rapidity = " << std::setprecision(9) << eta << endl;
    fOUT << std::setprecision(9) << pT << " " << eta << endl;
  }

  fOUT.close();
  pythia.stat();

  return 0;
}