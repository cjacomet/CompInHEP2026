#!/usr/bin/env python

import ROOT
import array

def main():
    pT = []
    eta = []

    fIN = open("muons.out")
    for line in fIN:
        if line.strip():
            p, e = line.split()
            pT.append(float(p))
            eta.append(float(e))

    h_pT = ROOT.TH1F("h_pT", "Muon Transverse momentum; pT [GeV]; Entries", 100, 0, 10)
    h_pT.SetColors(ROOT.kBlack,ROOT.kBlack,ROOT.kCyan)
    h_pT.SetLineWidth(3)
    h_eta = ROOT.TH1F("h_eta", "Muon Pseudorapidity; Pseudorapidity; Entries", 100, -10, 10)
    h_eta.SetColors(ROOT.kBlack,ROOT.kBlack,ROOT.kCyan)
    h_eta.SetLineWidth(3)

    for p, e in zip(pT, eta):
        h_pT.Fill(p)
        h_eta.Fill(e)

    canvas = ROOT.TCanvas("canvas", "Muon Distributions", 800, 400)
    canvas.SetLeftMargin(0.14)
    canvas.SetRightMargin(0.06)
    canvas.Divide(2, 1)  # Split canvas into 2 columns

    canvas.cd(1)
    h_pT.Draw()

    canvas.cd(2)
    h_eta.Draw()

    canvas.SaveAs("muon_hists.png")


if __name__ == "__main__":
    main()