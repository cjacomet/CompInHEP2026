void randHist(){
    TCanvas *canvas = new TCanvas();
    TFile *fIN = TFile::Open("data.root");
    fIN->ls();

    TTree *readTree = (TTree*)fIN->Get("randTree");
    Double_t r;
    readTree->SetBranchAddress("r",&r);

    TH1D *hist = new TH1D("hist", "Histogram of random numbers", 50, 0, 100);

    for(int i=0; i<readTree->GetEntries(); i++){
        readTree->GetEntry(i);
        hist->Fill(r);
    }

    TF1 *fit = new TF1("fit","gaus",0,100);

    hist->GetXaxis()->SetTitle("Number");
    hist->GetYaxis()->SetTitle("Counts");
    hist->SetColors(kBlack,kBlack,kYellow);
    hist->SetLineWidth(3);

    hist->Draw();
    hist->Fit("fit");

    TLegend *leg = new TLegend(0.1,0.7,0.35,0.9);
    leg->AddEntry(hist,"Data","l");
    leg->AddEntry(fit,"Fitted gaussian","l");
    leg->Draw();
}