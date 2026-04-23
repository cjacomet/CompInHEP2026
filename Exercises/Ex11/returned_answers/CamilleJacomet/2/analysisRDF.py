#!/usr/bin/env python

import datetime

import ROOT

ROOT.ROOT.EnableImplicitMT()

def main():

    df = ROOT.RDataFrame("Events", "../DYJetsToLL.root")

    counter1 = df.Count()
    ROOT.RDF.Experimental.AddProgressBar(df)

    df_trigger = df.Filter("HLT_IsoMu24", "Events passing HLT_IsoMu24 trigger")
    counter2 = df_trigger.Count()
    histo = df_trigger.Histo1D(("h_pileup", ";x-axis;y-axis", 100, 0, 100), "PV_npvs")

    fOUT = ROOT.TFile.Open("output.root","RECREATE")

    days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
    now = datetime.datetime.now()
    m = "produced: %s %s"%(days[now.weekday()],now)
    timestamp = ROOT.TNamed(m,"")
    timestamp.Write()

    histo.Write()

    fOUT.Close()

    print(f"All events:             ",counter1.GetValue())
    print(f"Events passing trigger: ",counter2.GetValue())

if __name__ == "__main__":
    main()