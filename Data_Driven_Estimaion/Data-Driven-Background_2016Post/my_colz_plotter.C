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

void  my_colz_plotter()
{

//  TString proc_Name[] = {"ggjets","gjet","jj"};
    TString proc_Name[] = {"gjet","jj"};
//  TString proc_Name[] = {"ggjets"};

 int nproc = sizeof(proc_Name)/sizeof(proc_Name[0]);

 for (int ii=0;ii<nproc;ii++)
  {

   Float_t lumi=41.5;

   std::cout << proc_Name[ii] << std::endl;

   Float_t weight, tot_wt = 0.0, dipho_mass = -999.9, CMS_hgg_mass = -999.9;
   Float_t dijet_Mjj= -999.9,dijet_leadPt= -999.9,dijet_subleadPt= -999.9,dijet_LeadJPt= -999.9,dijet_SubJPt= -999.9,dijet_leadEta= -999.9,dijet_subleadEta= -999.9, dijet_leadphi= -999.9, dijet_subleadphi = -999.9, dijet_leadE= -999.9, dijet_subleadE=-999.9;
   Float_t dipho_mva=-999.9, dipho_lead_ptoM= -999.9, dipho_sublead_ptoM= -999.9, dipho_leadPt= -999.9, dipho_subleadPt=-999.9, dipho_leadEta=-999.9, dipho_subleadEta=-999.9, dipho_leadPhi=-999.9, dipho_subleadPhi=-999.9, dipho_leadIDMVA= -999.9, dipho_subleadIDMVA= -999.9;
   Float_t dijet_minDRJetPho=-999.9, dipho_lead_genmatch=-999.9, dipho_sublead_genmatch=-999.9;

   TFile *file = TFile::Open("output_"+proc_Name[ii]+"_2016PostVFP.root");

   TString TnTname;
   if(proc_Name[ii] == "Data") TnTname = "tagsDumper/trees/Data_13TeV_VBFTag_2";
   else if (proc_Name[ii] =="ggjets") TnTname = "tagsDumper/trees/dipho_13TeV_VBFTag_2";
   else if (proc_Name[ii] =="gjet") TnTname = "tagsDumper/trees/gjets_13TeV_VBFTag_2";
   else if (proc_Name[ii] =="jj") TnTname = "tagsDumper/trees/qcd_13TeV_VBFTag_2";
   else TnTname="tagsDumper/trees/bkg_13TeV_VBFTag_2";

   TTree *tree = (TTree*)file->Get(TnTname);

   tree->SetBranchAddress("weight", &weight);
   tree->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);

   tree->SetBranchAddress("dipho_lead_ptoM",&dipho_lead_ptoM);
   tree->SetBranchAddress("dipho_sublead_ptoM",&dipho_sublead_ptoM);
   tree->SetBranchAddress("dipho_leadIDMVA",&dipho_leadIDMVA);
   tree->SetBranchAddress("dipho_subleadIDMVA",&dipho_subleadIDMVA);
   tree->SetBranchAddress("dipho_leadPt",&dipho_leadPt);
   tree->SetBranchAddress("dipho_subleadPt",&dipho_subleadPt);
   tree->SetBranchAddress("dipho_leadEta",&dipho_leadEta);
   tree->SetBranchAddress("dipho_subleadEta",&dipho_subleadEta);
   tree->SetBranchAddress("dipho_mva",&dipho_mva);
   tree->SetBranchAddress("dipho_lead_genmatch",&dipho_lead_genmatch);
   tree->SetBranchAddress("dipho_sublead_genmatch",&dipho_sublead_genmatch);


   tree->SetBranchAddress("dijet_minDRJetPho",&dijet_minDRJetPho);
   tree->SetBranchAddress("dijet_Mjj",&dijet_Mjj);
   tree->SetBranchAddress("dijet_leadPt",&dijet_leadPt);
   tree->SetBranchAddress("dijet_subleadPt",&dijet_subleadPt);
   tree->SetBranchAddress("dijet_leadEta", &dijet_leadEta);
   tree->SetBranchAddress("dijet_subleadEta", &dijet_subleadEta);
 

int PPPhotons = 0;
int PFPhotons = 0;
int FPPhotons =0;
int FFPhotons =0;

   TH2F* hist = new TH2F("hist", "",100, -1.0, 1.0, 100, -1.0, 1.0); 
   Long64_t nn = tree->GetEntries();


{
   for(Long64_t j =0; j < nn ; j++)
    {
     tree->GetEntry(j);


//  if ( !(dipho_lead_genmatch==1 && dipho_sublead_genmatch==1) )
 
//Prompt-Prompt

//  if (dipho_lead_genmatch == 1 && dipho_lead_genmatch == 1)

//  if (dipho_lead_genmatch != 1 && dipho_lead_genmatch != 1)

// Prompt-Fake 

   if(!(dipho_lead_genmatch==1 && dipho_sublead_genmatch==1) && (dipho_lead_genmatch==1 || dipho_sublead_genmatch==1))


{
//     if (dipho_leadPt > 35.0 && dipho_subleadPt > 25.0 && dipho_leadIDMVA > -0.9 && dipho_subleadIDMVA > -0.9)

{

if( CMS_hgg_mass > 100 && CMS_hgg_mass < 180 && dipho_lead_ptoM > 0.25 && dipho_sublead_ptoM > 0.20 && fabs(dipho_leadEta) < 2.5 && fabs(dipho_subleadEta) < 2.5 && dijet_leadPt > 30.0 && dijet_subleadPt > 20.0)

{
   if( dipho_leadIDMVA > -0.2  &&  dipho_subleadIDMVA > -0.2) {hist -> Fill(dipho_leadIDMVA, dipho_subleadIDMVA, weight*lumi); PPPhotons++;  }
   else if( dipho_leadIDMVA > -0.2  &&  dipho_subleadIDMVA < -0.2) { hist -> Fill(dipho_leadIDMVA, dipho_subleadIDMVA, weight*lumi); PFPhotons++;}
   else if( dipho_leadIDMVA < -0.2  &&  dipho_subleadIDMVA > -0.2) { hist -> Fill(dipho_leadIDMVA, dipho_subleadIDMVA, weight*lumi); FPPhotons++; }
   else if( dipho_leadIDMVA < -0.2  &&  dipho_subleadIDMVA < -0.2) { hist -> Fill(dipho_leadIDMVA, dipho_subleadIDMVA, weight*lumi); FFPhotons++;}
 }
}    
}    
}
printf("Prompt-Prompt: %d\n", PPPhotons);
printf("Prompt-Fake: %d\n", PFPhotons);
printf("Fake-Prompt: %d\n", FPPhotons);
printf("Fake-Fake: %d\n", FFPhotons);
 
}
                   //ForPlotting
		 //  gStyle->SetPaintTextFormat("4.4f");
                 //  gStyle->SetPalette(51);
		   TCanvas *c1 = new TCanvas("c1", "",648,177,800,702);
                   c1->Range(-1.299663,64.77612,1.387205,215);
		   c1->SetFillColor(0);
		   c1->SetBorderMode(0);
		   c1->SetBorderSize(2);
		   c1->SetLeftMargin(0.1115288);
		   c1->SetRightMargin(0.1441103);
		   c1->SetFrameBorderMode(0);
		   c1->SetFrameBorderMode(0);
		   hist->SetStats(0);
		   hist->SetTitle("");
		   hist->GetYaxis()->SetTitle("sublead photon IDMVA");
		   hist->GetXaxis()->SetTitle("lead photon IDMVA");
                   hist->Draw("COLZ");
                   TLatex *t2a = new TLatex(0.52,0.90,"#bf{CMS} #it{Simulation}                                (13TeV) 2016PostVFP ");
                   t2a->SetNDC();
                   t2a->SetTextFont(42);
                   t2a->SetTextSize(0.04);
                   t2a->SetTextAlign(20);
                   t2a->Draw("same");

    // Create TLine parallel to x-axis
    TLine *lineX = new TLine(-1,-0.2, 1,- 0.2);
    lineX->SetLineColor(kRed);
    lineX->SetLineWidth(3);  // Set the line width to 2 (default is 1)
    lineX->Draw("same");

    // Create TLine parallel to y-axis
    TLine *lineY = new TLine(-0.2, -1,-0.2, 1);
    lineY->SetLineColor(kRed);
    lineY->SetLineWidth(3);  // Set the line width to 3
    lineY->Draw("same");


                   c1->cd();
                   c1->Print("Plots/2D_photon_IDMVA_"+proc_Name[ii]+"_2016PostVFP.png");
                   c1->Print("Plots/2D_photon_IDMVA_"+proc_Name[ii]+"_2016PostVFP.pdf");
		   c1->Draw();
   }//ii 
}


