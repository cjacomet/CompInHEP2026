#!/usr/bin/env python
import datetime
import awkward as ak
import hist
from coffea.nanoevents import NanoEventsFactory, NanoAODSchema
from coffea.nanoevents.methods import candidate
import uproot

def main():
    filename = "file://../DYJetsToLL.root"
    
    # Creating events
    events = NanoEventsFactory.from_root(
        {filename: "Events"},
        metadata={"dataset": "DrellYan"},
        schemaclass=NanoAODSchema,
    ).events()

    counter1 = len(events)

    mask = events.HLT.IsoMu24
    pileup = events.PV.npvs[mask]
    counter2 = len(pileup)

    # Flatten table for filling histogram
    pileup_flat = ak.flatten(pileup, axis=None)
    
    # Creating and filling histogram
    h_pileup = hist.Hist.new.Reg(100, 0, 100, name="x", label="Number of primary vertices").Double()
    h_pileup.fill(x=pileup_flat)

    with uproot.recreate("output.root") as fOUT:
        now = datetime.datetime.now()
        fOUT[f"produced_{now.strftime('%Y%m%d_%H%M%S')}"] = ""
        fOUT["h_pileup"] = h_pileup

    print(f"All events:             ",counter1)
    print(f"Events passing trigger: ",counter2)

if __name__ == "__main__":
    main()