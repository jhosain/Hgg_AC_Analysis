
using namespace std;


void histo_draw(){

  std::vector<std::string> File_Names = {

                "output_Data_2017.root",
                "output_data_driven_bkg_2017.root",
//                "output_ggjets_2017.root",
//                "output_gjet_2017.root",
//                "output_jj_2017.root"


  };


  Double_t lumi = 1;
//  Bool_t vbf_exl = true;

Float_t  wt,  CMS_hgg_mass, vbfDNN_psm, vbfDNN_pbsm,dipho_leadIDMVA, dipho_subleadIDMVA, dipho_PToM_vbfmva, dijet_mva, dijet_mva_prob_VBF, dijet_mva_prob_ggH, dijet_mva_prob_bkg, dipho_dijet_MVA, dipho_mva, dijet_leadPUMVA, dijet_subleadPUMVA, vbfMvaResult_prob_bkg, vbfMvaResult_prob_ggH, vbfMvaResult_prob_VBF, dipho_leadPt, dipho_subleadPt, dipho_mass, mjj,  dijet_Mjj, dijet_zep,  dijet_leadPt, dijet_subleadPt, dijet_minDRJetPho, dijet_centrality, dijet_dphi, dipho_lead_ptoM, dipho_sublead_ptoM, dijet_dipho_dphi_trunc, dijet_abs_dEta , vbfDnnResult_prob_ggH, vbfDnnResult_prob_VBF,  DCP, D_CP_ggH, D_CP_VBF, D_PS_VBF, D_PS_ggH,D0minus,D0hplus, D0_minus_ggH,  jet1_qgtag, jet2_qgtag,dijet_nj, jet3_pt, dijet_prodEta, dijet_leadEta, dijet_subleadEta;

  TFile *file_[File_Names.size()];
  TH1F *hist_[File_Names.size()];

  
  for (int i=0; i< File_Names.size(); i++){

    file_[i] = TFile::Open(File_Names[i].c_str());
    file_[i]->Print();
    
    TString Tname;
    
   if(File_Names[i]== "output_Data_2017.root") Tname = "tagsDumper/trees/Data_13TeV_VBFTag_2";
   else if (File_Names[i] =="output_ggjets_2017.root") Tname = "tagsDumper/trees/dipho_13TeV_VBFTag_2";
   else if (File_Names[i] =="output_gjet_2017.root") Tname = "tagsDumper/trees/gjet_13TeV_VBFTag_2";
   else if (File_Names[i] =="output_jj_2017.root") Tname = "tagsDumper/trees/qcd_13TeV_VBFTag_2";
   else Tname="tagsDumper/trees/bkg_13TeV_VBFTag_2";

    

TTree* tree = (TTree*) file_[i]->Get(Tname);

      tree->SetBranchAddress("weight", &wt);
      tree->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);

      tree->SetBranchAddress("dipho_mass", &dipho_mass);
      tree->SetBranchAddress("dipho_lead_ptoM", &dipho_lead_ptoM ); 
      tree->SetBranchAddress("dipho_sublead_ptoM", &dipho_sublead_ptoM ); 

      tree->SetBranchAddress("dijet_Mjj", &dijet_Mjj);
      tree->SetBranchAddress("dijet_nj", &dijet_nj);
      tree->SetBranchAddress("dijet_prodEta", &dijet_prodEta);
      tree->SetBranchAddress("dijet_leadEta", &dijet_leadEta);
      tree->SetBranchAddress("dijet_subleadEta", &dijet_subleadEta);
      tree->SetBranchAddress("dijet_abs_dEta", &dijet_abs_dEta);
      tree->SetBranchAddress("dijet_dipho_dphi_trunc",&dijet_dipho_dphi_trunc);    
      tree->SetBranchAddress("dijet_leadPt",&dijet_leadPt );  
      tree->SetBranchAddress("dijet_subleadPt", &dijet_subleadPt ); 
      tree->SetBranchAddress("dijet_dphi",&dijet_dphi);
      tree->SetBranchAddress("dijet_minDRJetPho",&dijet_minDRJetPho);
      tree->SetBranchAddress("dijet_centrality",&dijet_centrality);
      tree->SetBranchAddress("dijet_zep",&dijet_zep);
      tree->SetBranchAddress("dijet_leadEta",&dijet_leadEta);
      tree->SetBranchAddress("dijet_subleadEta",&dijet_subleadEta);

      tree->SetBranchAddress("jet1_qgtag", &jet1_qgtag);
      tree->SetBranchAddress("jet2_qgtag", &jet2_qgtag);
      tree->SetBranchAddress("jet3_pt", &jet3_pt);


      tree->SetBranchAddress("dipho_leadIDMVA", &dipho_leadIDMVA);
      tree->SetBranchAddress("dipho_subleadIDMVA", &dipho_subleadIDMVA);
      tree->SetBranchAddress("dipho_PToM_vbfmva", &dipho_PToM_vbfmva);
      tree->SetBranchAddress("dijet_mva", &dijet_mva);
      tree->SetBranchAddress("dijet_mva_prob_VBF", &dijet_mva_prob_VBF);
      tree->SetBranchAddress("dijet_mva_prob_ggH", &dijet_mva_prob_ggH);
      tree->SetBranchAddress("dijet_mva_prob_bkg", &dijet_mva_prob_bkg);
      tree->SetBranchAddress("dipho_dijet_MVA", &dipho_dijet_MVA);
      tree->SetBranchAddress("dipho_mva", &dipho_mva);
      tree->SetBranchAddress("dijet_leadPUMVA", &dijet_leadPUMVA);
      tree->SetBranchAddress("dijet_subleadPUMVA", &dijet_subleadPUMVA);
      tree->SetBranchAddress("vbfMvaResult_prob_bkg", &vbfMvaResult_prob_bkg);
      tree->SetBranchAddress("vbfMvaResult_prob_ggH", &vbfMvaResult_prob_ggH);
      tree->SetBranchAddress("vbfMvaResult_prob_VBF", &vbfMvaResult_prob_VBF);

      tree->SetBranchAddress("vbfDNN_psm", &vbfDNN_psm);
      tree->SetBranchAddress("vbfDNN_pbsm", &vbfDNN_pbsm);


      tree->SetBranchAddress("D_CP_ggH", &D_CP_ggH);
      tree->SetBranchAddress("D0_minus_ggH", &D0_minus_ggH);
      tree->SetBranchAddress("D0minus", &D0minus);


    hist_[i] = new TH1F("hist", "", 50,0.0,0.0);

  
    Long64_t nn = tree->GetEntries();
    for(int j =0; j < nn ; j++)


      {
	tree->GetEntry(j);
  
//	if ( CMS_hgg_mass > 100 && CMS_hgg_mass < 180 && dipho_lead_ptoM > 0.33 && dipho_sublead_ptoM > 0.25 && dijet_leadPt > 40.0 && dijet_subleadPt > 30.0 && fabs(dijet_leadEta) < 4.7 && fabs(dijet_subleadEta) < 4.7 && dipho_leadIDMVA > -0.2 && dipho_subleadIDMVA > -0.2 ) 
    
           {
		hist_[i]->Fill(dijet_Mjj,wt);	 
       	   }
 	
      }

  //  hist_[i]->Scale(1.0/hist_[i]->Integral());
    hist_[i]->SetLineWidth(2);   
 
  }


  gStyle->SetLineWidth(2);
  TCanvas *c1 =new TCanvas("c1", " ", 0, 0,600,500);
 
  c1->Range(83.74603,-0.6226295,185.0794,1.646546);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
//  c1->SetLogy();
  c1->SetGridx();
  c1->SetGridy();
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetLeftMargin(0.160401);
  c1->SetRightMargin(0.05012531);
  c1->SetFrameBorderMode(0);
  c1->Draw(" ");
 

 // hist_[0]->SetAxisRange(0.0,1.0,"Y");
  hist_[0]->GetYaxis()->SetTitle("a.u");
  hist_[0]->GetXaxis()->SetTitle("dipho_mva");
  hist_[0]->SetStats(0);

  hist_[0]->GetYaxis()->SetLabelSize(0.045);
  hist_[0]->GetXaxis()->SetLabelSize(0.045);

  hist_[0]->SetFillColor(kAzure);
  hist_[1]->SetFillColor(kMagenta);
//  hist_[2]->SetFillColor(kOrange);
//  hist_[3]->SetLineColor(7);
//  hist_[4]->SetLineColor(2);
//  hist_[5]->SetLineColor(1);

  hist_[0]->Draw("HIST");
  hist_[1]->Draw("HIST,SAME");
//  hist_[2]->Draw("HIST,SAME");
//  hist_[3]->Draw("HIST,SAME");
//  hist_[4]->Draw("HIST,SAME");
//  hist_[5]->Draw("LP,SAME");

  TLegend *legend = new TLegend(0.6, 0.7, 0.9, 0.9);
  legend->SetTextFont(20);
  // legend->SetLineColor(0);
 // legend->SetTextSize(0.025);
  legend->AddEntry(hist_[0],"ggfhgg_SM", "f");
  legend->AddEntry(hist_[1],"ggfhgg_BSM", "f");
//  legend->AddEntry(hist_[2],"ggfhgg_mix", "f");
 // legend->AddEntry(hist_[3],"ggh", "l");
 // legend->AddEntry(hist_[4],"vbf", "l");
//  legend->AddEntry(hist_[5],"Data", "el");
  legend->Draw("SAME");

   
  TLatex *tl = new TLatex(0.53,0.9," #bf{CMS} #it{Preliminary}                          41.5 fb^{-1} (13 TeV) ");
  tl->SetNDC();
  tl->SetTextFont(42);
  tl->SetTextSize(0.04);
  tl->SetTextAlign(20);
  tl->Draw("Same");

//  c1->Print("dijet_abs_dEta.png");
//  c1->Print("D_CP_ggH.pdf"); 
 

}


