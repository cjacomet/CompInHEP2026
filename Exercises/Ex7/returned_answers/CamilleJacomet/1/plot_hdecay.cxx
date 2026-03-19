void plot_hdecay() {
    ifstream file("br.sm2");
    if (!file.is_open()) {
        cout << "Error: could not open br.sm2" << endl;
        return;
    }

    vector<double> mass;
    vector<double> width;

    string line;

    // Skip header lines
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);

        double mH, dummy, gamma;

        // HDECAY format: first column = mass, last column = total width
        vector<double> cols;
        double val;
        while (ss >> val) cols.push_back(val);

        if (cols.size() < 2) continue;

        mH = cols[0];
        gamma = cols.back();  // last column = total width

        mass.push_back(mH);
        width.push_back(gamma);
    }

    file.close();

    TGraph *graph = new TGraph(mass.size(), &mass[0], &width[0]);

    graph->SetTitle("SM Higgs Width using HDECAY; m_{H} (GeV); #Gamma_{H} (GeV)");
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.5);
    graph->SetLineWidth(2);

    TCanvas *canv = new TCanvas("c1", "Higgs Width", 800, 600);
    // canv->SetLogy();
    graph->Draw("APL");

    canv->SaveAs("HDECAY_higgs_width.png");
}