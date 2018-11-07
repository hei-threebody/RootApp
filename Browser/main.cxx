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


using namespace std;
using namespace RooFit;

int main(int argc, char *argv[]) {
    TApplication *app = new TApplication("app", 0, 0);

    cout << "Files count is: " << argc - 1 << endl;

    if(argc > 1) {
        TFile *argf[argc];
        for (int i = 1; i < argc; i++) {
            cout << "Reading file " << argv[i] << endl;
            argf[i-1] = new TFile(argv[i]);
        } 
    }
    // TFile *f = new TFile("PrSth.root");

    cout << "Initialing TBrowser" << endl;
    TBrowser *b = new TBrowser();
    app->Run();
    return 0;
}

