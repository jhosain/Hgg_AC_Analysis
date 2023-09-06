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

void qcdfraction_pf()
{

  TString proc_Name[] = {"EB","EE"};
  
  int nproc = sizeof(proc_Name)/sizeof(proc_Name[0]);
  for (int ii=0;ii<nproc;ii++)
   {

    TFile* final_file = TFile::Open(proc_Name[ii]+"_PF_qcdfraction.root", "RECREATE");

    TFile *fdt = TFile::Open("Histogram_Data_fakefactor.root");
    TFile *fgg = TFile::Open("Histogram_ggjets_fakefactor.root");

    TH1F *hdt1 = (TH1F*)fdt->Get("h_pf_" + proc_Name[ii] +"_leading");
    TH1F *hgg1 = (TH1F*)fgg->Get("h_pf_" + proc_Name[ii] +"_leading");
    
    TH1F *hdt2 = (TH1F*)fdt->Get("h_pf_" + proc_Name[ii] +"_subleading");
    TH1F *hgg2 = (TH1F*)fgg->Get("h_pf_" + proc_Name[ii] +"_subleading");
    
    TH1* hdt1_ = (TH1*)hdt1->Clone();
    TH1* hdt2_ = (TH1*)hdt2->Clone();

    hdt1 ->Add(hgg1, -1);
    hdt2 ->Add(hgg2, -1);
    
    hdt1->Divide(hdt1_);
    hdt2->Divide(hdt2_);

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
   hdt1->GetXaxis()->SetTitle("p_{T} [GeV]");
   hdt1->GetYaxis()->SetTitle("QCD fraction");
   hdt1->GetXaxis()->SetTitleOffset(0.84);
   hdt1->GetXaxis()->SetTitleSize(0.05);
   hdt1->GetYaxis()->SetTitleSize(0.05);
   hdt1->SetTitle("");
   hdt1->SetStats(0);
   hdt1->SetLineWidth(2);
   hdt1->SetLineColor(kOrange+10);
   hdt1->Draw("LP");
   hdt1->GetYaxis()->SetRangeUser(0.0 , 2.0);

   hdt2->SetLineWidth(2);
   hdt2->SetLineColor(kAzure+1);
   hdt2->Draw("LP,SAME");


   TLatex *t2a = new TLatex(0.54,0.91," #bf{CMS} #it{Simulation}                                             (13 TeV)");
   t2a->SetNDC();
   t2a->SetTextFont(42);
   t2a->SetTextSize(0.04);
   t2a->SetTextAlign(20);
   t2a->Draw("same");

   TString eta;
   if(proc_Name[ii]  == "EB") eta = "EB: |#eta^{#gamma}| < 1.5";
   else eta =  "EE: |#eta^{#gamma}| > 1.5";

   TLatex * text_proc = new TLatex(0.20,0.80,eta);
   text_proc->SetNDC();
   text_proc->SetTextFont(42);
   text_proc->SetTextSize(0.04);
   text_proc->SetTextColor(kBlack);
   text_proc->Draw("same");
 
   TLatex * text_proc2 = new TLatex(0.20,0.74,"PF");
   text_proc2->SetNDC();
   text_proc2->SetTextFont(42);
   text_proc2->SetTextSize(0.04);
   text_proc2->SetTextColor(kBlack);
   text_proc2->Draw("same");


  TLegend *legend1 = new TLegend(0.55, 0.65, 0.90, 0.85);
  legend1->SetTextFont(42);
  legend1->SetLineColor(0);
  legend1->SetTextSize(0.04);
  legend1->SetFillColor(0);
  legend1->SetFillStyle(0);
  legend1->AddEntry(hdt1, "Leading", "l");
  legend1->AddEntry(hdt2, "Sub-leading","l");
  legend1->Draw();


   c1->Print("Plots/png/QCDFraction_PF_"+ proc_Name[ii] + ".png");
//   c1->Print("Plots/png/QCDFraction_PF_"+ proc_Name[ii] + ".pdf");

   final_file->Write();
   final_file->cd();
   hdt1->SetName("leading_"+ proc_Name[ii] + "_PF_qcdfraction");
   hdt2->SetName("subleading_"+ proc_Name[ii] + "_PF_qcdfraction");
   hdt1->Write();
   hdt2->Write();
   final_file->Close();
   }
}
