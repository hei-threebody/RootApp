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

	int count0, count1, count2, count3, count4, count5, count6 = 0;

	for (Int_t i = 0; i < (Int_t) diag->GetEntries(); i++) {
		diag->GetEntry(i);
		switch ((int)count) {
			case 0:
				count0++; break;
			case 1:
				count1++; break;
			case 2:
				count2++; break;
			case 3:
				count3++; break;
			case 4:
				count4++; break;
			case 5:
				count5++; break;
			case 6:
				count6++; break;
		}
		countHF->Fill(count);
		// cout << count;
	}

	countHF->Draw();
	
	cout<< "BEGINSTATE: \t" << count0 << endl
		<< "AFTER_PHOTON: \t" << count1 << endl
		<< "AFTER_CHARGED: \t" << count2 << endl
		<< "AFTER_PID: \t" << count3 << endl
		<< "AFETR_FIRST_VALID: \t" << count4 << endl
		<< "AFTER_SECOND_VALD: \t" <<count5 << endl
		<< "AFTER_KMFIT: \t" << count6 << endl;		

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

