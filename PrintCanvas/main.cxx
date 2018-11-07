#include <iostream>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"

// #include "RooRealVar.h"
// #include "RooGaussian.h"
// #include "RooDataSet.h"
// #include "RooPlot.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH1F.h"
// #include "TPostScript.h"
// #include "RooRealVar.h"


using namespace std;
// using namespace RooFit;

void PrintCanvas(char *s) {
    TFile *f = new TFile(s);
    TTree *kmfit = (TTree *) f->Get("kmfit");
    
    Double_t lamd, lamdbar, sigma0, sigma1;
    kmfit->SetBranchAddress("lamd", &lamd);
    kmfit->SetBranchAddress("lamdbar", &lamdbar);
    kmfit->SetBranchAddress("sigma0", &sigma0);
    kmfit->SetBranchAddress("sigma1", &sigma1);
    TH1F *lamdHF = new TH1F("lamd", "lamd invariant mass", 100, 1.08, 1.18);
    TH1F *lamdbarHF = new TH1F("lamdbar", "lamdbar invariant mass", 100, 1.08, 1.18);

    for (Int_t i = 0; i < (Int_t) kmfit->GetEntries(); i++) {
        kmfit->GetEntry(i);
        lamdHF->Fill(lamd);
        lamdbarHF->Fill(lamdbar);
    }

    TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);
    //
    // lamdHF->SetFillColor(45);
    lamdHF->Draw();
    lamdbarHF->Draw();
    lamdHF->Print("lamdhf.pdf");
    c1->Print("tmp.pdf");
    c1->Draw();
}

int main(int argc, char *argv[]) {
    // TApplication *app = new TApplication("app", 0, 0);

    // cout << "Files count is: " << argc - 1 << endl;

    if(argc > 1) {
        TFile *argf[argc];
        for (int i = 1; i < argc; i++) {
            // cout << "Reading file " << argv[i] << endl;
            PrintCanvas(argv[i]);
        } 
    }




    // TBrowser *b = new TBrowser();
    // app->Run();
    return 0;
}

