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
#include "THStack.h"
// #include "TPostScript.h"
// #include "RooRealVar.h"

//#define RUN 1


using namespace std;
// using namespace RooFit;

void PrintCanvas(char *s) {
	TFile *f = new TFile(s);
	//THStack hs("hs", "test stacked histograms");
	TCanvas *c1 = new TCanvas("c1", "c1", 2000, 2000);
	c1->Divide(2, 2);
	TTree *kmfit = (TTree *) f->Get("kmfit");

	Double_t lamd, lamdbar, sigma0, sigma1;
	kmfit->SetBranchAddress("lamd", &lamd);
	kmfit->SetBranchAddress("lamdbar", &lamdbar);
	kmfit->SetBranchAddress("sigma0", &sigma0);
	kmfit->SetBranchAddress("sigma1", &sigma1);
	TH1F *lamdHF    = new TH1F("lamd", "#lambda invariant mass", 100, 1.08, 1.18);
	TH1F *lamdbarHF = new TH1F("lamdbar", "#bar{#lambda} invariant mass", 100, 1.08, 1.18);
	TH1F *sigma0HF  = new TH1F("sigma0", "#Sigma^{0}(#lambda + #gamma) invariant mass", 100, 1.1, 1.7);
	TH1F *sigma1HF  = new TH1F("sigma1", "#Sigma^{0}(#bar{#lambda} + #gamma) invariant mass", 100, 1.08, 1.3);

	for (Int_t i = 0; i < (Int_t) kmfit->GetEntries(); i++) {
		kmfit->GetEntry(i);
		lamdHF->Fill(lamd);
		lamdbarHF->Fill(lamdbar);
		sigma0HF->Fill(sigma0);
		sigma1HF->Fill(sigma1);

	}

	//hs.Add(lamdHF);
	//hs.Add(lamdbarHF);
	//hs.Add(sigma1HF);

	//hs.Draw("nostack");
	//hs.Print("hs.pdf");
	//
	c1->cd(1);
	lamdHF->Draw();
	c1->cd(2);
	lamdbarHF->Draw();
	c1->cd(3);
	sigma0HF->Draw();
	c1->cd(4);
	sigma1HF->Draw();
	c1->Print("tmp.pdf");
	//c1->Draw();
}

int main(int argc, char *argv[]) {
#ifdef RUN
	TApplication *app = new TApplication("app", 0, 0);
#endif
	// cout << "Files count is: " << argc - 1 << endl;


	if(argc > 1) {
		for (int i = 1; i < argc; i++) {
			// cout << "Reading file " << argv[i] << endl;
			PrintCanvas(argv[i]);
		} 
	}


	//TBrowser *b = new TBrowser();
#ifdef RUN
	app->Run();
#endif
	return 0;
}

