#define MyAnalysis_cxx
// The class definition in MyAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():          called every time a loop on the tree starts,
//                      a convenient place to create your histograms.
//    SlaveBegin():     called after Begin()
//    Process():        called for each event, in this function you decide what
//                      to read and fill your histograms.
//    SlaveTerminate(): called at the end of the loop on the tree.
//    Terminate():      called at the end of the loop on the tree,
//                      a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("MyAnalysis.C")
// root> T->Process("MyAnalysis.C","some options")
// root> T->Process("MyAnalysis.C+")
//


#include "MyAnalysis.h"
#include <TH2.h>
#include <TStyle.h>

void MyAnalysis::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // The tree argument is deprecated.

   TString option = GetOption();

   pileup = new TH1I("pileup","",100,0,100);
}

void MyAnalysis::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // The tree argument is deprecated.

   TString option = GetOption();

}

bool MyAnalysis::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree
   // to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

   if (*HLT_IsoMu24) pileup->Fill(*PV_npvs);

   return true;
}

void MyAnalysis::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed.

}

void MyAnalysis::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   TFile* fOUT = TFile::Open("output.root","RECREATE");
   fOUT->cd();

   std::time_t result = std::time(nullptr);
   TNamed* timestamp = new TNamed(std::asctime(std::localtime(&result)),"");
   timestamp->Write();

   pileup->GetXaxis()->SetTitle("Number of primary vertices");
   pileup->GetYaxis()->SetTitle("Counts");
   pileup->SetLineWidth(3);

   pileup->Write();
   fOUT->Close();
}