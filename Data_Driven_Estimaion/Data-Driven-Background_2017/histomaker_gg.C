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

void histomaker_gg()
{
 
 Float_t lumi = 41.5;

 TString proc_Name[] = {"ggjets"};

 int nproc = sizeof(proc_Name)/sizeof(proc_Name[0]);

 for (int ii=0;ii<nproc;ii++)
  {
   std::cout << proc_Name[ii] << "          " ;

   TFile* final_file = TFile::Open("Histogram_"+proc_Name[ii]+"_fakefactor.root", "RECREATE");

   Float_t weight, tot_wt = 0.0, dipho_mass = -999.9, CMS_hgg_mass = -999.9;
   Float_t dijet_minDRJetPho= -999.9,dijet_Mjj= -999.9,dijet_leadPt= -999.9,dijet_subleadPt= -999.9,dijet_LeadJPt= -999.9,dijet_SubJPt= -999.9,dijet_leadEta= -999.9,dijet_subleadEta= -999.9, dijet_leadphi= -999.9, dijet_subleadphi = -999.9, dijet_leadE= -999.9, dijet_subleadE=-999.9;
   Float_t dipho_lead_ptoM= -999.9, dipho_sublead_ptoM= -999.9, dipho_leadPt= -999.9, dipho_subleadPt=-999.9, dipho_leadEta=-999.9, dipho_subleadEta=-999.9, dipho_leadPhi=-999.9, dipho_subleadPhi=-999.9, dipho_leadIDMVA= -999.9, dipho_subleadIDMVA= -999.9, dipho_lead_genmatch=-999.9, dipho_sublead_genmatch=-999.9;
   Float_t mjj, dipho_mva;

   TFile *file = TFile::Open("output_"+proc_Name[ii]+"_2017.root");

   TString TnTname;
   if(proc_Name[ii] == "Data") TnTname = "tagsDumper/trees/Data_13TeV_VBFTag_2";
   else if (proc_Name[ii] =="ggjets") TnTname = "tagsDumper/trees/dipho_13TeV_VBFTag_2";
   else if (proc_Name[ii] =="gjet") TnTname = "tagsDumper/trees/gjet_13TeV_VBFTag_2";
   else if (proc_Name[ii] =="jj") TnTname = "tagsDumper/trees/qcd_13TeV_VBFTag_2";
   else TnTname="tagsDumper/trees/bkg_13TeV_VBFTag_2";
  
   TTree *tree = (TTree*)file->Get(TnTname);
  
   tree->SetBranchAddress("weight", &weight);
   tree->SetBranchAddress("CMS_hgg_mass", &dipho_mass);
   tree->SetBranchAddress("dipho_mva",&dipho_mva);

   tree->SetBranchAddress("dipho_lead_ptoM",&dipho_lead_ptoM);
   tree->SetBranchAddress("dipho_sublead_ptoM",&dipho_sublead_ptoM);
   tree->SetBranchAddress("dipho_leadIDMVA",&dipho_leadIDMVA);
   tree->SetBranchAddress("dipho_subleadIDMVA",&dipho_subleadIDMVA);
   tree->SetBranchAddress("dipho_leadPt",&dipho_leadPt);
   tree->SetBranchAddress("dipho_subleadPt",&dipho_subleadPt);
   tree->SetBranchAddress("dipho_leadEta",&dipho_leadEta);
   tree->SetBranchAddress("dipho_subleadEta",&dipho_subleadEta);
   tree->SetBranchAddress("dipho_lead_genmatch",&dipho_lead_genmatch);
   tree->SetBranchAddress("dipho_sublead_genmatch",&dipho_sublead_genmatch);


   tree->SetBranchAddress("dijet_Mjj",&dijet_Mjj);
   tree->SetBranchAddress("dijet_leadPt",&dijet_leadPt);
   tree->SetBranchAddress("dijet_subleadPt",&dijet_subleadPt);
   tree->SetBranchAddress("dijet_minDRJetPho",&dijet_minDRJetPho);

   Double_t BINS[] = {0.0,30.0,50.0,70.0,1000.00};
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
  
{
//## Photon Preselction
   if (dipho_leadPt > 35.0 && dipho_subleadPt > 25.0 && dipho_leadIDMVA > -0.9 && dipho_subleadIDMVA > -0.9)
{     
//### VBF loose preselction to increase the statistics
     if( CMS_hgg_mass > 100 && CMS_hgg_mass < 180 && dipho_lead_ptoM > 0.25 && dipho_sublead_ptoM > 0.20 && fabs(dipho_leadEta) < 2.5 && fabs(dipho_subleadEta) < 2.5 && dijet_leadPt > 30.0 && dijet_subleadPt > 20.0)

     if(dipho_leadPt > 1000.0) dipho_leadPt =999.00;
     if(dipho_subleadPt > 1000.0) dipho_subleadPt = 999.00;
     
{  
     if( dipho_leadIDMVA > -0.2  &&  dipho_subleadIDMVA > -0.2) { if(fabs(dipho_leadEta) < 1.4442 )  h_pp_EB_leading->Fill(dipho_leadPt, weight * lumi);  
                                                                  if(fabs(dipho_leadEta) > 1.566 )   h_pp_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                        	  if(fabs(dipho_subleadEta) < 1.4442 )  h_pp_EB_subleading->Fill(dipho_subleadPt, weight * lumi);  
                                                        	  if(fabs(dipho_subleadEta) > 1.566 )   h_pp_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                }
     if( dipho_leadIDMVA > -0.2  &&  dipho_subleadIDMVA < -0.2) { if(fabs(dipho_leadEta) < 1.4442 )  h_pf_EB_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_leadEta) > 1.566 )   h_pf_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) < 1.4442 )  h_pf_EB_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) > 1.566 )   h_pf_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
								}
     if( dipho_leadIDMVA < -0.2 &&  dipho_subleadIDMVA > -0.2) { if(fabs(dipho_leadEta) < 1.4442 )  h_fp_EB_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_leadEta) > 1.566 )   h_fp_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) < 1.4442 )  h_fp_EB_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) > 1.566 )   h_fp_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
								}
     if( dipho_leadIDMVA < -0.2  &&  dipho_subleadIDMVA < -0.2) { if(fabs(dipho_leadEta) < 1.4442 )  h_ff_EB_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_leadEta) > 1.566 )   h_ff_EE_leading->Fill(dipho_leadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) < 1.4442 )  h_ff_EB_subleading->Fill(dipho_subleadPt, weight * lumi);
                                                                  if(fabs(dipho_subleadEta) > 1.566 )   h_ff_EE_subleading->Fill(dipho_subleadPt, weight * lumi);
     								}
     }
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
