void plot_hmass() {
    TH1F *hMass = new TH1F("hMass", "Higgs mass;Mass [GeV];Events", 100, 120, 130);

    std::ifstream inFile("higgs_masses.txt");
    double mass;
    while (inFile >> mass) {
        hMass->Fill(mass);
    }
    inFile.close();

    TCanvas *c = new TCanvas("c", "Higgs Mass Distribution", 800, 600);
    c->cd();
    hMass->SetLineWidth(2);
    hMass->Draw();

    // Fit to Breit-Wigner
    TF1 *bw = new TF1("bw", "TMath::BreitWigner(x, [0], [1])", 120, 130);
    bw->SetParameters(125, 0.004); // initial guesses: mass=125 GeV, width=4 MeV
    hMass->Fit(bw, "R"); // "R" = fit within function range
    bw->SetLineColor(kRed);
    bw->Draw("same");

    double mass_fit = bw->GetParameter(0);
    double width_fit = bw->GetParameter(1) * 1e3;

    // Create a box with fitted info
    TPaveText *pt = new TPaveText(0.15, 0.7, 0.45, 0.85, "NDC"); // normalized coordinates
    pt->SetFillColor(kWhite);
    pt->SetBorderSize(1);
    pt->AddText(Form("Fitted mass = %.3f GeV", mass_fit));
    pt->AddText(Form("Fitted width = %.3f MeV", width_fit));
    pt->Draw();

    c->SaveAs("higgs_mass.png");
}