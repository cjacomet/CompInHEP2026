#!/usr/bin/env python

from array import array
import ROOT

def main():
    randN = 1000
    rand = ROOT.TRandom2(0) # Default seed is 1, 0 for random seed

    fOUT = ROOT.TFile.Open("data.root","recreate")
    fOUT.cd()

    randTree = ROOT.TTree("randTree","Random Tree")
    r = array('d', [ 0.0 ])
    randTree.Branch("r", r, "r/D")

    for i in range(randN):
        r[0] = rand.Gaus(50,15)
        randTree.Fill()

    randTree.Write()
    fOUT.Close()

if __name__ == "__main__":
    main()