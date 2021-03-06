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

	int count0(0), count1(0), count2(0), count3(0), count4(0), count5(0);

	// cout << count0 << count1 << count2 << count3 << count5 << count6 << endl;
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
		}
		countHF->Fill(count);
		// cout << count;
	}

	countHF->Draw();

	cout<< "BEGINSTATE: \t" << count0 << endl
		<< "AFTER_CHARGED: \t" << count1 << endl
		<< "AFTER_PHOTON: \t" << count2 << endl
		<< "AFTER_PID: \t" << count3 << endl
		<< "AFTER_VERTEX: \t" << count4 << endl
		<< "AFTER_KMFIT: \t" <<count5 << endl;
    //

	cout << "efficiency: " << (double)count5/count0 << endl;
	c1->Draw();
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

