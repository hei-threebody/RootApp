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
// #include "RooRealVar.h"


using namespace std;
// using namespace RooFit;

void PrintRootInfo(char * s) {
    TFile *f = new TFile(s);

    TTree *kmfit = (TTree *) f->Get("kmfit");
    TTree *charged = (TTree *) f->Get("charged");

    TTree *num = (TTree *) f->Get("num");

    Double_t lamd, lamdbar, sigma0, sigma1;
    Double_t count7;
    Double_t  count;

    kmfit->SetBranchAddress("lamd", &lamd);
    kmfit->SetBranchAddress("lamdbar", &lamdbar);
    kmfit->SetBranchAddress("sigma0", &sigma0);
    kmfit->SetBranchAddress("sigma1", &sigma1);

    charged->SetBranchAddress("count7", &count7);

    num->SetBranchAddress("count", &count);

    int Count0 = 0;
    int Count1 = 0;

    for (int i = 0; i < charged->GetEntries(); i++) {
        charged->GetEntry(i);

    }



    for (int i = 0; i < kmfit->GetEntries(); i++) {
        kmfit->GetEntry(i);
        if (lamd == 0) {
            Count0++;
        }  else {
            Count1++;
            cout << "lamd: " << lamd << endl;
            cout << "lamdbar: " << lamdbar << endl;
            cout << "sigma0: " << sigma0 << endl;
            cout << "sigma1: " << sigma1 << endl;
            // cout << lamd << endl;
        }
    }

    int Count_0 = 0;
    int Count_1 = 0;
    int Count_2 = 0;
    int Count_3 = 0;
    int Count_4 = 0;
    int Count_5 = 0;
    int Count_6 = 0;

    for (int i = 0; i < num->GetEntries(); i++) {
        num->GetEntry(i);

        if (count == 0) {
            Count_0++;
        } else if (count == 1) {
            Count_1++;
        } else if (count == 2) {
            Count_2++;
        } else if (count == 3) {
            Count_3++;
        } else if (count == 4) {
            Count_4++;
        } else if (count == 5) {
            Count_5++;
        } else if (count == 6) {
            Count_6++;
        }
    }


        cout << "entries: " << num->GetEntries() << endl;
        cout << "BEGINSTATE: " << Count_0 << endl;
        cout << "AFTER_PHOTO: " << Count_1 << endl;
        cout << "AFTER_CHARGED: " << Count_2 << endl;
        cout << "AFTER_PID: " << Count_3 << endl;
        cout << "AFTER_FIRST_VALID: " << Count_4 << endl;
        cout << "AFTER_SECOND_VALID: " << Count_5 << endl;
        cout << "AFTER_KMFIT: " << Count_6 << endl;
        // delete f, t;
    }

    int main(int argc, char *argv[]) {
        // TApplication *app = new TApplication("app", 0, 0);

        // cout << "Files count is: " << argc - 1 << endl;

        if(argc > 1) {
            for (int i = 1; i < argc; i++) {
                // cout << "Reading file " << argv[i] << endl;
                PrintRootInfo(argv[i]);
            }
        }

        // cout << "Initialing TBrowser" << endl;
        // TBrowser *b = new TBrowser();
        // app->Run();
        return 0;
    }

