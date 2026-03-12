#!/usr/bin/env python

import ROOT

def main():
    canvas = ROOT.TCanvas()
    fIN = ROOT.TFile.Open("data.root")
    fIN.ls()

    readTree = fIN.Get("randTree")
    # Double_t r;
    # readTree->SetBranchAddress("r",&r);

    hist = ROOT.TH1D("hist", "Histogram of random numbers", 50, 0, 100)

    for entry in readTree:
        # readTree.GetEntry(i)
        hist.Fill(entry.r)

    fit = ROOT.TF1("fit","gaus",0,100)

    canvas.SetFillColor(ROOT.kWhite)

    hist.GetXaxis().SetTitle("Number")
    hist.GetYaxis().SetTitle("Counts")
    hist.SetColors(ROOT.kBlack,ROOT.kBlack,ROOT.kYellow)
    hist.SetLineWidth(3)

    hist.Draw()
    hist.Fit("fit")

    leg = ROOT.TLegend(0.1,0.7,0.35,0.9)
    leg.AddEntry(hist,"Data","l")
    leg.AddEntry(fit,"Fitted gaussian","l")
    leg.Draw()

    canvas.Print("hist.png")

if __name__ == "__main__":
    main()