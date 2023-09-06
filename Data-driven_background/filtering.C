void filtering()
{
  Float_t lumi =              1;
  Float_t cross_Section_ggH = 48.5800 ;
  Float_t cross_Section_qqH = 3.7820;
  Float_t BR_Hgg =            0.00227;
  //TString fIn[] = {"DATA","JJHiggs0Mf05ph0ToGG_M125_TuneCP5_13TeV-JHUGenV7011-pythia8","JJHiggs0MToGG_M125_TuneCP5_13TeV-JHUGenV7011-pythia8","JJHiggs0PMToGG_M125_TuneCP5_13TeV-JHUGenV7011-pythia8"};
  //TString fIn[] = {"VBFHiggs0PHToGG_M125_TuneCP5_13TeV-JHUGenV7011-pythia8","VBFHiggs0Mf05ph0ToGG_M125_TuneCP5_13TeV-JHUGenV7011-pythia8","VBFHiggs0MToGG_M125_TuneCP5_13TeV-JHUGenV7011-pythia8"};
  //TString fIn[] = {"GluGluHToGG_M125_TuneCP5_13TeV-amcatnloFXFX-pythia8"};
  //TString fIn[] = {"VBFHToGG_M-125_TuneCP5_13TeV-powheg-pythia8","GluGluHToGG_M-125_TuneCP5_13TeV-powheg-pythia8"};
  //TString fIn[] = {"Data","ggjets"};
  TString fIn[] = {"gjets","jj"};
  int nprocs = sizeof(fIn)/sizeof(fIn[0]);
for(int i = 0 ; i < nprocs; i++ )
{
   std::cout <<  "processing: output_"  << fIn[i]	 << ".root" << std::endl;
   TString treename;
   if(fIn[i] == "ggjets")  treename = "bkg";
   else  treename = "bkg";
   std::cout << "Processing trees :  tagsDumper/trees/" << treename  << "_13TeV_VBFTag_2" << std::endl;   



   TFile *f = TFile::Open("output_" + fIn[i]+".root");
   TFile *fileout = new TFile("output_" + fIn[i]+"_skimmed.root","recreate");
   TString treename_output = treename + "_13TeV_VBFTag_2";

   TTree *Tout = new TTree( treename_output, treename_output );
   Float_t         weight_;
   Float_t         CMS_hgg_mass_;
   Float_t         dZ_;
   Float_t         dijet_leadPt_;
   Float_t         dijet_subleadPt_;
   Float_t         dijet_leadEta_;
   Float_t         dijet_subleadEta_;
   Float_t         dijet_leadPhi_, dijet_subleadPhi_;
   Float_t         dijet_Zep_, dijet_Mjj_, dijet_dphi_, dijet_dipho_dphi_, dijet_minDRJetPho_;
   Float_t         D0minus_, dijet_dipho_pt_, dipho_PToM_, dipho_cosphi_, dipho_Eta_;
   Float_t         cos_thetaH_;
   Float_t         dipho_leadPt_, dipho_subleadPt_, dipho_leadEta_, dipho_subleadEta_, dipho_leadPhi_, dipho_subleadPhi_;
   Float_t         dipho_pt_;
   Float_t         dipho_mva_;

   Tout->Branch("weight", &weight_, "weight/F");
   Tout->Branch("CMS_hgg_mass", &CMS_hgg_mass_, "CMS_hgg_mass/F");
   Tout->Branch("dZ", &dZ_, "dZ/F");

   Tout->Branch("dipho_leadPt",     &dipho_leadPt_,     "dipho_leadPt/F");
   Tout->Branch("dipho_subleadPt",  &dipho_subleadPt_,  "dipho_subleadPt/F");
   Tout->Branch("dipho_leadEta",    &dipho_leadEta_,    "dipho_leadEta/F");
   Tout->Branch("dipho_subleadEta", &dipho_subleadEta_, "dipho_subleadEta/F");
   Tout->Branch("dipho_leadPhi",    &dipho_leadPhi_,    "dipho_leadPhi/F");
   Tout->Branch("dipho_subleadPhi", &dipho_subleadPhi_, "dipho_subleadPhi/F");

   Tout->Branch("dijet_leadPt", &dijet_leadPt_, "dijet_leadPt/F");
   Tout->Branch("dijet_subleadPt", &dijet_subleadPt_, "dijet_subleadPt/F");
   Tout->Branch("dijet_leadEta", &dijet_leadEta_, "dijet_leadEta/F");
   Tout->Branch("dijet_subleadEta", &dijet_subleadEta_, "dijet_subleadEta/F");
   Tout->Branch("dijet_leadPhi", &dijet_leadPhi_, "dijet_leadPhi/F");
   Tout->Branch("dijet_subleadPhi", &dijet_subleadPhi_, "dijet_subleadPhi/F");
   //Reconstructed variables
   Tout->Branch("dipho_pt", &dipho_pt_, "dipho_pt_/F");
   Tout->Branch("dipho_mva", &dipho_mva_, "dipho_mva/F");
   /*
   Tout->Branch("dijet_Zep", &dijet_Zep_, "dijet_Zep/F");
   Tout->Branch("dijet_Mjj", &dijet_Mjj_, "dijet_Mjj/F");
   Tout->Branch("dijet_dphi", &dijet_dphi_, "dijet_dphi/F");
   Tout->Branch("dijet_dipho_dphi", &dijet_dipho_dphi_, "dijet_dipho_dphi/F");
   Tout->Branch("dijet_minDRJetPho", &dijet_minDRJetPho_, "dijet_minDRJetPho/F");
   Tout->Branch("D0minus" , &D0minus_ , "D0minus/F");
   Tout->Branch("dijet_dipho_pt" , &dijet_dipho_pt_ , "dijet_dipho_pt/F");
   Tout->Branch("dipho_PToM" , &dipho_PToM_ , "dipho_PToM/F");
   Tout->Branch("dipho_cosphi", &dipho_cosphi_ ,"dipho_cosphi/F");
   Tout->Branch("dipho_Eta", &dipho_Eta_ ,"dipho_Eta/F");
   Tout->Branch("cos_thetaH", &cos_thetaH_ ,"cos_thetaH/F");
*/

   Float_t         weight;
   Float_t         CMS_hgg_mass;
   Float_t         dZ;
   Float_t         dipho_lead_ptoM;
   Float_t         dipho_sublead_ptoM;
   Float_t         dijet_leadPt;
   Float_t         dijet_subleadPt;
   Float_t         dijet_leadEta;
   Float_t         dijet_subleadEta;
   Float_t         dijet_leadPhi, dijet_subleadPhi;
   Float_t         dijet_Zep, dijet_Mjj, dijet_dphi, dijet_dipho_dphi, dijet_minDRJetPho;
   Float_t         D0minus, dijet_dipho_pt, dipho_PToM, dipho_cosphi;
   Float_t         dipho_leadPt, dipho_leadEta, dipho_leadPhi;
   Float_t         dipho_subleadPt, dipho_subleadEta, dipho_subleadPhi;
   Float_t         cos_thetaH;
   Float_t         dijet_nj; 
   Float_t         dipho_mva;
   Float_t         dipho_leadIDMVA;
   Float_t         dipho_subleadIDMVA;

   TBranch        *b_weight;   //!
   TBranch        *b_CMS_hgg_mass;   //!
   TBranch        *b_dZ;
   TBranch        *b_dipho_lead_ptoM;
   TBranch        *b_dipho_sublead_ptoM;
   TBranch        *b_dijet_leadEta;   //!
   TBranch        *b_dijet_subleadEta;   //!
   TBranch        *b_dijet_leadPt;   //!
   TBranch        *b_dijet_subleadPt;   //!
   TBranch        *b_dijet_leadPhi;   //!
   TBranch        *b_dijet_subleadPhi;   //!
   TBranch        *b_dijet_Zep  , *b_dijet_Mjj, *b_dijet_dphi, *b_dijet_dipho_dphi, *b_dijet_minDRJetPho;
   TBranch        *b_D0minus, *b_dipho_PToM , *b_dijet_dipho_pt, *b_dipho_cosphi;
   TBranch        *b_dipho_leadPt, *b_dipho_leadEta, *b_dipho_leadPhi;
   TBranch        *b_dipho_subleadPt, *b_dipho_subleadEta, *b_dipho_subleadPhi;
   TBranch        *b_cos_thetaH;
   TBranch        *b_dijet_nj;
   TBranch        *b_dipho_mva;
   TBranch        *b_dipho_leadIDMVA;
   TBranch        *b_dipho_subleadIDMVA;


   TTree *fChain;
   fChain = (TTree*)f->Get("tagsDumper/trees/" + treename + "_13TeV_VBFTag_2");
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass, &b_CMS_hgg_mass);
   fChain->SetBranchAddress("dZ", &dZ, &b_dZ);
   fChain->SetBranchAddress("dipho_lead_ptoM", &dipho_lead_ptoM, &b_dipho_lead_ptoM);
   fChain->SetBranchAddress("dipho_sublead_ptoM", &dipho_sublead_ptoM, &b_dipho_sublead_ptoM);
   //4 momentum of photons
   fChain->SetBranchAddress("dipho_leadEta", &dipho_leadEta, &b_dipho_leadEta);
   fChain->SetBranchAddress("dipho_subleadEta", &dipho_subleadEta, &b_dipho_subleadEta);
   fChain->SetBranchAddress("dipho_leadPt", &dipho_leadPt, &b_dipho_leadPt);
   fChain->SetBranchAddress("dipho_subleadPt", &dipho_subleadPt, &b_dipho_subleadPt);
   fChain->SetBranchAddress("dipho_leadPhi", &dipho_leadPhi, &b_dipho_leadPhi);
   fChain->SetBranchAddress("dipho_subleadPhi", &dipho_subleadPhi, &b_dipho_subleadPhi);
   fChain->SetBranchAddress("dipho_leadIDMVA", &dipho_leadIDMVA, &b_dipho_leadIDMVA);
   fChain->SetBranchAddress("dipho_subleadIDMVA", &dipho_subleadIDMVA, &b_dipho_subleadIDMVA);
   //4-momentum of the jets
   fChain->SetBranchAddress("dijet_leadEta", &dijet_leadEta, &b_dijet_leadEta);
   fChain->SetBranchAddress("dijet_subleadEta", &dijet_subleadEta, &b_dijet_subleadEta);
   fChain->SetBranchAddress("dijet_leadPt", &dijet_leadPt, &b_dijet_leadPt);
   fChain->SetBranchAddress("dijet_subleadPt", &dijet_subleadPt, &b_dijet_subleadPt);
   fChain->SetBranchAddress("dijet_leadPhi", &dijet_leadPhi, &b_dijet_leadPhi);
   fChain->SetBranchAddress("dijet_subleadPhi", &dijet_subleadPhi, &b_dijet_subleadPhi);	   
   //kinematic distributions
   fChain->SetBranchAddress("dijet_Zep", &dijet_Zep, &b_dijet_Zep);
   fChain->SetBranchAddress("dijet_Mjj", &dijet_Mjj, &b_dijet_Mjj);
   fChain->SetBranchAddress("dijet_dphi", &dijet_dphi, &b_dijet_dphi);
   fChain->SetBranchAddress("dijet_dipho_dphi", &dijet_dipho_dphi, &b_dijet_dipho_dphi);
   fChain->SetBranchAddress("dijet_minDRJetPho", &dijet_minDRJetPho, &b_dijet_minDRJetPho);                           
   fChain->SetBranchAddress("D0minus", &D0minus, &b_D0minus);
   fChain->SetBranchAddress("dijet_dipho_pt", &dijet_dipho_pt, &b_dijet_dipho_pt);
   fChain->SetBranchAddress("dipho_PToM", &dipho_PToM, &b_dipho_PToM);
   fChain->SetBranchAddress("dipho_cosphi", &dipho_cosphi, &b_dipho_cosphi);
   fChain->SetBranchAddress("dijet_nj", &dijet_nj, &b_dijet_nj);
   fChain->SetBranchAddress("dipho_mva", &dipho_mva, &b_dipho_mva);

   /*
   fChain->SetBranchAddress("", &, &b_);
   fChain->SetBranchAddress("", &, &b_);
   fChain->SetBranchAddress("", &, &b_);
   fChain->SetBranchAddress("", &, &b_);
   fChain->SetBranchAddress("", &, &b_);
   */

   //
   //

   int nentries = fChain->GetEntries();
   cout<<"nentries "<<nentries<<endl;
   

   for (int ij=0; ij<nentries; ij++) {
     fChain->GetEntry(ij);
     if( dipho_leadIDMVA > -0.2 && dipho_subleadIDMVA > -0.2 )
     {
        if( fIn[i] == "Data" ) { weight_ = weight*1; }
	else {weight_ =  weight * 41.5;}
	CMS_hgg_mass_ = CMS_hgg_mass;
        dijet_Zep_ = dijet_Zep; 
	dijet_Mjj_ = dijet_Mjj;
	dijet_dphi_ = dijet_dphi;
	dijet_dipho_dphi_ = dijet_dipho_dphi;
	dijet_minDRJetPho_ = dijet_minDRJetPho;
	D0minus_ = D0minus;	
	dipho_leadPt_ = dipho_leadPt;  dipho_subleadPt_ = dipho_subleadPt; 
	dipho_leadEta_ = dipho_leadEta; dipho_subleadEta_= dipho_subleadEta; 
	dipho_leadPhi_ = dipho_leadPhi; dipho_subleadPhi_= dipho_subleadPhi;

        dijet_leadPt_ = dijet_leadPt;  dijet_subleadPt_ = dijet_subleadPt;
        dijet_leadEta_ = dijet_leadEta; dijet_subleadEta_= dijet_subleadEta;
        dijet_leadPhi_ = dijet_leadPhi; dijet_subleadPhi_= dijet_subleadPhi;


	dijet_dipho_pt_ = dijet_dipho_pt;
	dipho_PToM_ = dipho_PToM;
	dipho_cosphi_ = dipho_cosphi;

	TLorentzVector G1, G2;
	G1.SetPtEtaPhiM(dipho_leadPt, dipho_leadEta, dipho_leadPhi, 0.0); G2.SetPtEtaPhiM(dipho_subleadPt, dipho_subleadEta, dipho_subleadPhi, 0.0);
        dipho_Eta_ = (G1 + G2).Eta();
	dipho_pt_  = (G1 + G2).Pt();
	//cout << dipho_pt_ << "\t" << dipho_PToM_ * CMS_hgg_mass << endl;
        cos_thetaH_ = cos((G1 + G2).Theta());
	dipho_mva_ = dipho_mva;

	if ( fIn[i] == "Data" ) {     dZ_= 0; }
	else {dZ_= dZ;}

	Tout->Fill();
     }
   }
   f->Close();
   fileout->cd();
   fileout->Write();
   fileout->Close();
}
}
