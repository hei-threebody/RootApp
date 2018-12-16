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

// #define RUN 1
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
	TTree *PrSth = (TTree *) f->Get("PrSth");

	Double_t lmdmas, lmdmasbar, sigmas, sigmasbar;
	PrSth->SetBranchAddress("lmdmas", &lmdmas);
	PrSth->SetBranchAddress("lmdmasbar", &lmdmasbar);
	PrSth->SetBranchAddress("sigmas", &sigmas);
	PrSth->SetBranchAddress("sigmasbar", &sigmasbar);
	TH1F *lmdmasHF    = new TH1F("lmdmas", "#lambda invariant mass", 100, 1.08, 1.18);
	TH1F *lmdmasbarHF = new TH1F("lmdmasbar", "#bar{#lambda} invariant mass", 100, 1.08, 1.18);
	TH1F *sigmasHF  = new TH1F("sigmas", "#Sigma^{0}(#lambda + #gamma) invariant mass", 100, 1.1, 1.7);
	TH1F *sigmasbarHF  = new TH1F("sigmasbar", "#Sigma^{0}(#bar{#lambda} + #gamma) invariant mass", 100, 1.08, 1.3);

	for (Int_t i = 0; i < (Int_t) PrSth->GetEntries(); i++) {
		cout << i << endl;
		PrSth->GetEntry(i);
		if (lmdmas == 0) continue;
		lmdmasHF->Fill(lmdmas);
		lmdmasbarHF->Fill(lmdmasbar);
		sigmasHF->Fill(sigmas);
		sigmasbarHF->Fill(sigmasbar);

	}

	//hs.Add(lmdmasHF);
	//hs.Add(lmdmasbarHF);
	//hs.Add(sigmasbarHF);

	//hs.Draw("nostack");
	//hs.Print("hs.pdf");
	//
	c1->cd(1);
	lmdmasHF->Draw();
	c1->cd(2);
	lmdmasbarHF->Draw();
	c1->cd(3);
	sigmasHF->Draw();
	c1->cd(4);
	sigmasbarHF->Draw();
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
			cout << "Reading file " << argv[i] << endl;
			PrintCanvas(argv[i]);
		}
	}


	//TBrowser *b = new TBrowser();
#ifdef RUN
	app->Run();
#endif
	return 0;
}

// end of time
