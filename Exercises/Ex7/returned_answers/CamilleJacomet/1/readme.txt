SM Higgs boson width for Higgs mass = 125 GeV:
    Set parameters in input file hdecay.in:
        HIGGS = 0
        MABEG = 125.D0
        MAEND = 125.D0
        NMA = 1
    ./run_hdecay.job
    Find width in br.sm2: 
        WIDTH = 0.4076E-02 GeV = 4.076 MeV

Width as a function of SM Higgs mass:
    Set parameters in input file hdecay.in:
        HIGGS = 0           (SM Higgs)
        MABEG = 100.D0      (start value for Higgs mass, in GeV)
        MAEND = 200.D0      (end value for Higgs mass, in GeV)
        NMA = 100           (number of iterations for input Higgs mass)
    ./run_hdecay.job

---
When running HDECAY with job script
    --> Adapt HDECAY_DIR to path for HDECAY code