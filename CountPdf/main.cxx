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

void CountPdf(char *s) {
	TFile *f = new TFile(s);
	//THStack hs("hs", "test stacked histograms");
	TCanvas *c1 = new TCanvas("c1", "c1", 2000, 2000);
	// c1->Divide(2, 2);
	TTree *diag = (TTree *) f->Get("diag");
	Double_t count;
	
	diag->SetBranchAddress("count", &count);

	TH1F *countHF = new TH1F("count", "Diagnostic Count", 6, 0, 6);

	for (Int_t i = 0; i < (Int_t) diag->GetEntries(); i++) {
		diag->GetEntry(i);
		countHF->Fill(count);
		// cout << count;
	}

	countHF->Draw();

	// c1->Draw();
	c1->Print("count.pdf");
}

int main(int argc, char *argv[]) {
#ifdef RUN
	TApplication *app = new TApplication("app", 0, 0);
#endif
	// cout << "Files count is: " << argc - 1 << endl;


	if(argc > 1) {
		for (int i = 1; i < argc; i++) {
			// cout << "Reading file " << argv[i] << endl;
			CountPdf(argv[i]);
		} 
	}


	//TBrowser *b = new TBrowser();
#ifdef RUN
	app->Run();
#endif
	return 0;
}

