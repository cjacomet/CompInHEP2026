void randNTree(){
   Int_t randN = 1000;
   TRandom2 *rand = new TRandom2(0); // Default seed is 1, 0 for random seed

   TFile *fOUT = TFile::Open("data.root","recreate");
   fOUT->cd();

   TTree *randTree = new TTree("randTree","Random Tree");
   Double_t r;
   randTree->Branch("r", &r, "r/D");
   
   for(int i=0; i<randN; i++){
        r = rand->Gaus(50,15);
        randTree->Fill();
   }
   randTree->Write();
   fOUT->Close();
}