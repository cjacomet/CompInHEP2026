#!/usr/bin/env python

import ROOT
import os, sys

def usage():
    print
    print("### Usage:   ",os.path.basename(sys.argv[0])," <root file>")
    print
    sys.exit()

def main():
    if len(sys.argv) < 2:
        usage()
    
    fIN = ROOT.TFile.Open(sys.argv[1])
    histo = fIN.Get("h_pileup")

    canvas = ROOT.TCanvas("canvas","",500,500)
    canvas.cd()
    histo.SetStats(0)
    histo.SetLineColor(1)
    histo.SetLineWidth(2)
    histo.GetXaxis().SetTitle("Number of primary vertices")
    histo.Draw()
   
    canvas.Print("pileup.pdf")
    fIN.Close()

main()