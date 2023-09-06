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

void histomaker()
{

Float_t lumi = 1.0;

TString proc_Name[] = {"Data","ggjets"};

int nproc = sizeof(proc_Name)/sizeof(proc_Name[0]);

 for (int ii=0;ii<nproc;ii++)
  {
   std::cout << proc_Name[ii] << "          " ;

   TFile* final_file = TFile::Open("Histogram_"+proc_Name[ii]+"_fakefactor.root", "RECREATE");

   Float_t weight, tot_wt = 0.0, dipho_mass = -999.9;
   Float_t dijet_LeadJPt= -999.9,dijet_SubJPt= -999.9,dijet_leadEta= -999.9,dijet_subleadEta= -999.9, dijet_leadphi= -999.9, dijet_subleadphi = -999.9, dijet_leadE= -999.9, dijet_subleadE=-999.9;
   Float_t dipho_leadPt= -999.9, dipho_subleadPt=-999.9, dipho_leadEta=-999.9, dipho_subleadEta=-999.9, dipho_leadPhi=-999.9, dipho_subleadPhi=-999.9, dipho_leadIDMVA= -999.9, dipho_subleadIDMVA= -999.9;
   Float_t mjj;

   TFile *file = TFile::Open("output_"+proc_Name[ii]+".root");

   TString TnTname;
   if(proc_Name[ii] == "Data") TnTname = "tagsDumper/trees/Data_13TeV_VBFTag_2";
   else TnTname = "tagsDumper/trees/bkg_13TeV_VBFTag_2";

   Float_t dipho_mva;
   Float_t dipho_pt; 
  
   TTree *tree = (TTree*)file->Get(TnTname);
  
   tree->SetBranchAddress("weight", &weight);
   tree->SetBranchAddress("CMS_hgg_mass", &dipho_mass);
   tree->SetBranchAddress("dipho_mva",&dipho_mva);
   
   tree->SetBranchAddress("dipho_leadIDMVA",&dipho_leadIDMVA);
   tree->SetBranchAddress("dipho_subleadIDMVA",&dipho_subleadIDMVA);
   tree->SetBranchAddress("dipho_leadPt",&dipho_leadPt);
   tree->SetBranchAddress("dipho_subleadPt",&dipho_subleadPt);
   tree->SetBranchAddress("dipho_leadEta",&dipho_leadEta);
   tree->SetBranchAddress("dipho_subleadEta",&dipho_subleadEta);

   //List of Histograms

   Double_t BINS[] = {0,30.0,50.0,100.0,200.0};
   const int nBINS = sizeof(BINS)/sizeof(BINS[0])-1;


   TH1F *h_pp_EB_leading = new TH1F("h_pp_EB_leading","h_pp_EB_leading", nBINS, BINS);
   TH1F *h_pp_EB_subleading = new TH1F("h_pp_EB_subleading","h_pp_EB_subleading", nBINS, BINS);
   TH1F *h_pp_EE_leading = new TH1F("h_pp_EE_leading","h_pp_EE_leading", nBINS, BINS);
   TH1F *h_pp_EE_subleading = new TH1F("h_pp_EE_subleading","h_pp_EE_subleading", nBINS, BINS);

   TH1F *h_pf_EB_leading = new TH1F("h_pf_EB_leading","h_pf_EB_leading", nBINS, BINS);
   TH1F *h_pf_EB_subleading = new TH1F("h_pf_EB_subleading","h_pf_EB_subleading", nBINS, BINS);
   TH1F *h_pf_EE_leading = new TH1F("h_pf_EE_leading","h_pf_EE_leading", nBINS, BINS);
   TH1F *h_pf_EE_subleading = new TH1F("h_pf_EE_subleading","h_pf_EE_subleading", nBINS, BINS);

   TH1F *h_fp_EB_leading = new TH1F("h_fp_EB_leading","h_fp_EB_leading", nBINS, BINS);
   TH1F *h_fp_EB_subleading = new TH1F("h_fp_EB_subleading","h_fp_EB_subleading", nBINS, BINS);
   TH1F *h_fp_EE_leading = new TH1F("h_fp_EE_leading","h_fp_EE_leading", nBINS, BINS);
   TH1F *h_fp_EE_subleading = new TH1F("h_fp_EE_subleading","h_fp_EE_subleading", nBINS, BINS);

   TH1F *h_ff_EB_leading = new TH1F("h_ff_EB_leading","h_ff_EB_leading", nBINS, BINS);
   TH1F *h_ff_EB_subleading = new TH1F("h_ff_EB_subleading","h_ff_EB_subleading", nBINS, BINS);
   TH1F *h_ff_EE_leading = new TH1F("h_ff_EE_leading","h_ff_EE_leading", nBINS, BINS);
   TH1F *h_ff_EE_subleading = new TH1F("h_ff_EE_subleading","h_ff_EE_subleading", nBINS, BINS);

 
   float count = 0.0;
 
   Long64_t nn = tree->GetEntries();

   for(Long64_t j =0; j < nn ; j++)
    {
     tree->GetEntry(j);
     
     if(proc_Name[ii] == "Data") lumi = 1.0;
     else lumi = 41.5;
 
     if(dipho_leadPt > 200.0) dipho_leadPt = 199.0;
     if(dipho_subleadPt > 200.0) dipho_subleadPt = 199.0;
     if(dipho_mass < 115.0 || dipho_mass > 135.0) {
    
     if( dipho_leadIDMVA > -0.2  &&  dipho_subleadIDMVA > -0.2) { if(fabs(dipho_leadEta) < 1.5 )  h_pp_EB_leading->Fill(dipho_leadPt, weight * lumi);  
                                                                  if(fabs(dipho_leadEta) > 1.5)   h_pp_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                        	  if(fabs(dipho_subleadEta) < 1.5 )  h_pp_EB_subleading->Fill(dipho_subleadPt, weight * lumi);  
                                                        	  if(fabs(dipho_subleadEta) > 1.5)   h_pp_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                }
     if( dipho_leadIDMVA > -0.2  &&  dipho_subleadIDMVA < -0.2) { if(fabs(dipho_leadEta) < 1.5 )  h_pf_EB_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_leadEta) > 1.5)   h_pf_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) < 1.5 )  h_pf_EB_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) > 1.5)   h_pf_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
								}
     if( dipho_leadIDMVA < -0.2  &&  dipho_subleadIDMVA > -0.2) { if(fabs(dipho_leadEta) < 1.5 )  h_fp_EB_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_leadEta) > 1.5)   h_fp_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) < 1.5 )  h_fp_EB_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) > 1.5)   h_fp_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
								}
     if( dipho_leadIDMVA < -0.2  &&  dipho_subleadIDMVA < -0.2) { if(fabs(dipho_leadEta) < 1.5 )  h_ff_EB_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_leadEta) > 1.5)   h_ff_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) < 1.5 )  h_ff_EB_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) > 1.5)   h_ff_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
     								}
     }

     count++;
 
    }
    

    final_file->Write();
    final_file->cd();  
    h_pp_EB_leading->Write();
    h_pp_EE_leading->Write();
    h_pf_EB_leading->Write();
    h_pf_EE_leading->Write();
    h_fp_EB_leading->Write();
    h_fp_EE_leading->Write();
    h_ff_EB_leading->Write();
    h_ff_EE_leading->Write();

    h_pp_EB_subleading->Write();
    h_pp_EE_subleading->Write();
    h_pf_EB_subleading->Write();
    h_pf_EE_subleading->Write();
    h_fp_EB_subleading->Write();
    h_fp_EE_subleading->Write();
    h_ff_EB_subleading->Write();
    h_ff_EE_subleading->Write();

    final_file->Close();
  }
}
