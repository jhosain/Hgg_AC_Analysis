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

void Eff_qcdfraction_EB()
{


//    TFile* final_file = TFile::Open("Eff_leading_EB_FP_qcdfraction.root", "RECREATE");

    TFile *fgg = TFile::Open("Histogram_ggjets_fakefactor.root");
    TFile *fgj = TFile::Open("Histogram_gjet_fakefactor.root");
    TFile *fjj = TFile::Open("Histogram_jj_fakefactor.root");

    TH1F *hgg_pf = (TH1F*)fgg->Get("h_pf_EB_leading");
    TH1F *hgg_fp = (TH1F*)fgg->Get("h_fp_EB_leading");
    TH1F *hgj_pf = (TH1F*)fgj->Get("h_pf_EB_leading");
    TH1F *hgj_fp = (TH1F*)fgj->Get("h_fp_EB_leading");
    TH1F *hjj_pf = (TH1F*)fjj->Get("h_pf_EB_leading");
    TH1F *hjj_fp = (TH1F*)fjj->Get("h_fp_EB_leading");
   

    TH1* nom = (TH1*)hgj_fp->Clone();
    TH1* denom = (TH1*)hgj_fp->Clone();

    nom->Add(hjj_fp);
    denom->Add(hgg_fp);
    denom->Add(hjj_fp);
      

   TH1F* numeratorHist = (TH1F*)nom->Clone();
   TH1F* denominatorHist = (TH1F*)denom->Clone();

   TEfficiency* eff = new TEfficiency(*numeratorHist, *denominatorHist);
   TGraphAsymmErrors* num = eff->CreateGraph();



   gStyle->SetLineWidth(2);
   TCanvas *c1 =new TCanvas("c1", " ", 0, 0,800,700);
   c1->Range(83.74603,-0.6226295,185.0794,1.646546);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
//   c1->SetLogy();
   c1->SetGridx();
   c1->SetGridy();
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.160401);
   c1->SetRightMargin(0.05012531);
   c1->SetFrameBorderMode(0);
   c1->Draw();

//   float ymax = num->GetMaximum();
   num->GetXaxis()->SetTitle("p_{T}^{#gamma1} [GeV]");
   num->GetYaxis()->SetTitle("QCD fraction");
   num->GetXaxis()->SetTitleOffset(0.84);
   num->GetXaxis()->SetTitleSize(0.05);
   num->GetYaxis()->SetTitleSize(0.05);
   num->SetTitle("");
//   num->SetStats(0);
   num->SetLineWidth(2);
   num->SetLineColor(kOrange+10);
   num->Draw("AP");
   num->GetYaxis()->SetRangeUser(0.0 , 1.5);


   TLatex *t2a = new TLatex(0.54,0.91," #bf{CMS} #it{Simulation}                                              (13 TeV) 2017");
   t2a->SetNDC();
   t2a->SetTextFont(42);
   t2a->SetTextSize(0.04);
   t2a->SetTextAlign(20);
   t2a->Draw("same");

   TString eta;
   eta = "EB: |#eta^{#gamma}| < 1.4442";

   TLatex * text_proc = new TLatex(0.20,0.80,eta);
   text_proc->SetNDC();
   text_proc->SetTextFont(42);
   text_proc->SetTextSize(0.04);
   text_proc->SetTextColor(kBlack);
   text_proc->Draw("same");
 
   TLatex * text_proc2 = new TLatex(0.20,0.74,"FP#rightarrowPP");
   text_proc2->SetNDC();
   text_proc2->SetTextFont(42);
   text_proc2->SetTextSize(0.04);
   text_proc2->SetTextColor(kBlack);
   text_proc2->Draw("same");

/*
  TLegend *legend1 = new TLegend(0.55, 0.65, 0.90, 0.85);
  legend1->SetTextFont(42);
  legend1->SetLineColor(0);
  legend1->SetTextSize(0.04);
  legend1->SetFillColor(0);
  legend1->SetFillStyle(0);
  legend1->AddEntry(num, "Leading", "l");
  legend1->Draw();
*/

//   c1->Print("Plots/png/QCDFraction_PF_"+ proc_Name[ii] + ".png");
//   c1->Print("Plots/png/QCDFraction_PF_"+ proc_Name[ii] + ".pdf");

//   final_file->Write();
//   final_file->cd();
//   num->SetName("Eff_leading_EB_FP_qcdfraction");
//   num->Write();
//   final_file->Close();
   
}
