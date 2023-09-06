#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCut.h"
#include "TPaveText.h"
#include "TGaxis.h"
#include "TProfile.h"
#include "TCut.h"
#include <iostream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void fakefactor_EE_sub()
{

   TFile* final_file = TFile::Open("EE_subleading_fakefactor.root", "RECREATE");

    TFile *fdt = TFile::Open("Histogram_Data_fakefactor.root");
    TFile *fgg = TFile::Open("Histogram_ggjets_fakefactor.root");

    TH1F *hdt1 = (TH1F*)fdt->Get("h_pp_EE_subleading");
    TH1F *hgg1 = (TH1F*)fgg->Get("h_pp_EE_subleading");
    
    TH1F *hdt2 = (TH1F*)fdt->Get("h_pf_EE_subleading");
    TH1F *hgg2 = (TH1F*)fgg->Get("h_pf_EE_subleading");
    
    hdt1 ->Add(hgg1, -1);
    hdt2 ->Add(hgg2, -1);
    
    hdt1->Divide(hdt2);

   gStyle->SetLineWidth(2);
   TCanvas *c1 =new TCanvas("c1", " ", 0, 0,800,700);
   c1->Range(83.74603,-0.6226295,185.0794,1.646546);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   //c1->SetLogy();
   c1->SetGridx();
   c1->SetGridy();
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.160401);
   c1->SetRightMargin(0.05012531);
   c1->SetFrameBorderMode(0);
   c1->Draw();

   float ymax = hdt1->GetMaximum();
   hdt1->SetTitle("");
   hdt1->SetStats(0);
   hdt1->SetLineWidth(2);
   hdt1->SetFillColor(kOrange);
   hdt1->SetFillStyle(3325);
   hdt1->SetLineColor(kRed);
   hdt1->Draw("HIST");
   hdt1->GetYaxis()->SetRangeUser(0.0 , ymax*1.2);

   TLatex *t2a = new TLatex(0.54,0.91," #bf{CMS} #it{Simulation}                                 (13 TeV)");
   t2a->SetNDC();
   t2a->SetTextFont(42);
   t2a->SetTextSize(0.04);
   t2a->SetTextAlign(20);
   t2a->Draw("same");

   hdt1->SetName("EE_subleading_fakefactor");
   
   final_file->Write();
   final_file->cd();
   hdt1->Write();
   final_file->Close();
//   c1->Print("Plots/png/Non_Log_dipho_dijet_mva.png");
//   c1->Print("Plots/pdf/Non_Log_dipho_dijet_mva.pdf");


}
