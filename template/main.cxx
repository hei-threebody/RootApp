#include <iostream>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"

#include "RooRealVar.h"
#include "RooGaussian.h"
#include "RooDataSet.h"
#include "RooPlot.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
// #include "RooRealVar.h"

#define RUN 0

using namespace std;
using namespace RooFit;

void DealWithFile(char *s) {
	TFile *f = new TFile(s);

}
int main(int argc, char *argv[]) {
#ifdef RUN
	TApplication *app = new TApplication("app", 0, 0);
#endif

    if(argc > 1) {
        TFile *argf[argc];
        for (int i = 1; i < argc; i++) {
            // cout << "Reading file " << argv[i] << endl;
            DealWithFile(argv[i]);
        } 
    }
	
    // TBrowser *b = new TBrowser();
#ifdef RUN
	app->Run();
#endif
    return 0;
}

