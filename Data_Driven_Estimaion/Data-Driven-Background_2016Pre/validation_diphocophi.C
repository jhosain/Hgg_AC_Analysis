

using namespace std;


void validation_diphocophi(){

 std::vector<std::string> File_Names = {
		"output_Data_2016PreVFP.root",
                "output_data_driven_bkg_2016PreVFP.root",
                "output_ggjets_2016PreVFP.root",
		"output_gjet_2016PreVFP.root",
  		"output_jj_2016PreVFP.root"
  };

  Double_t lumi = 19.5;


   Float_t weight, wt, tot_wt = 0.0, dipho_mass = -999.9, CMS_hgg_mass = -999.9;
   Float_t dijet_minDRJetPho= -999.9,dijet_Mjj= -999.9,dijet_leadPt= -999.9,dijet_subleadPt= -999.9,dijet_LeadJPt= -999.9,dijet_SubJPt= -999.9,dijet_leadEta= -999.9,dijet_subleadEta= -999.9, dijet_leadphi= -999.9, dijet_subleadphi = -999.9, dijet_leadE= -999.9, dijet_subleadE=-999.9;
   Float_t dipho_lead_ptoM= -999.9, dipho_sublead_ptoM= -999.9, dipho_leadPt= -999.9, dipho_subleadPt=-999.9, dipho_leadEta=-999.9, dipho_subleadEta=-999.9, dipho_leadPhi=-999.9, dipho_subleadPhi=-999.9, dipho_leadIDMVA= -999.9, dipho_subleadIDMVA= -999.9, dipho_lead_genmatch=-999.9, dipho_sublead_genmatch=-999.9;
   Float_t mjj, dipho_mva, dijet_zep, dijet_abs_dEta, dipho_sumpt, dipho_PToM, dipho_cosphi,dijet_leadPhi,  dijet_subleadPhi,dijet_dphi, dijet_dipho_dphi, dijet_dipho_pt, dijet_nj;

 
  TFile *file_[File_Names.size()];
  TH1F *hist_[File_Names.size()];

  
  for (int i=0; i< File_Names.size(); i++){


    file_[i] = TFile::Open(File_Names[i].c_str());
    file_[i]->Print();
    
    TString Tname;

   if(File_Names[i]== "output_Data_2016PreVFP.root") Tname = "tagsDumper/trees/Data_13TeV_VBFTag_2";
   else if (File_Names[i] =="output_ggjets_2016PreVFP.root") Tname = "tagsDumper/trees/dipho_13TeV_VBFTag_2";
   else if (File_Names[i] =="output_gjet_2016PreVFP.root") Tname = "tagsDumper/trees/gjets_13TeV_VBFTag_2";
   else if (File_Names[i] =="output_jj_2016PreVFP.root") Tname = "tagsDumper/trees/qcd_13TeV_VBFTag_2";
   else Tname="tagsDumper/trees/bkg_13TeV_VBFTag_2";


  TTree* tree = (TTree*) file_[i]->Get(Tname);

      tree->SetBranchAddress("weight", &wt);
      tree->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);

      tree->SetBranchAddress("dipho_mass", &dipho_mass);
      tree->SetBranchAddress("dipho_lead_ptoM", &dipho_lead_ptoM );
      tree->SetBranchAddress("dipho_sublead_ptoM", &dipho_sublead_ptoM );
      tree->SetBranchAddress("dipho_leadEta", &dipho_leadEta );
      tree->SetBranchAddress("dipho_subleadEta", &dipho_subleadEta );
      tree->SetBranchAddress("dipho_leadPt", &dipho_leadPt );
      tree->SetBranchAddress("dipho_subleadPt", &dipho_subleadPt );
      tree->SetBranchAddress("dipho_lead_genmatch",&dipho_lead_genmatch);
      tree->SetBranchAddress("dipho_sublead_genmatch",&dipho_sublead_genmatch);
      tree->SetBranchAddress("dipho_leadIDMVA", &dipho_leadIDMVA);
      tree->SetBranchAddress("dipho_subleadIDMVA", &dipho_subleadIDMVA);
      tree->SetBranchAddress("dipho_mva", &dipho_mva);
      tree->SetBranchAddress("dipho_sumpt", &dipho_sumpt);
      tree->SetBranchAddress("dipho_cosphi", &dipho_cosphi);

      tree->SetBranchAddress("dijet_Mjj", &dijet_Mjj);
      tree->SetBranchAddress("dijet_leadEta", &dijet_leadEta);
      tree->SetBranchAddress("dijet_subleadEta", &dijet_subleadEta);
      tree->SetBranchAddress("dijet_leadPhi", &dijet_leadPhi);
      tree->SetBranchAddress("dijet_subleadPhi", &dijet_subleadPhi);
//      tree->SetBranchAddress("dijet_dphi", &dijet_dphi);
      tree->SetBranchAddress("dijet_abs_dEta", &dijet_abs_dEta);
      tree->SetBranchAddress("dijet_zep",&dijet_zep);
      tree->SetBranchAddress("dijet_minDRJetPho",&dijet_minDRJetPho);
      tree->SetBranchAddress("dijet_leadPt",&dijet_leadPt );
      tree->SetBranchAddress("dijet_subleadPt", &dijet_subleadPt );


    hist_[i] = new TH1F("hist", "", 50, 0.0, 1.0 );
    
    int nentries = tree->GetEntries();
    cout<<"nentries "<<nentries<<endl;

    float count = 0.0;
    Long64_t nn = tree->GetEntries();
    for(int j =0; j < nn ; j++)

      {
	tree->GetEntry(j);

       bool isBlindedRegion = (CMS_hgg_mass > 115 && CMS_hgg_mass < 135);
{

if (!isBlindedRegion && CMS_hgg_mass > 100 && CMS_hgg_mass < 180  && dipho_lead_ptoM > 0.33 && dipho_sublead_ptoM > 0.25 && dijet_leadPt > 30.0 && dijet_subleadPt > 30.0 && fabs(dijet_leadEta) < 4.7 && fabs(dijet_subleadEta) < 4.7 && fabs(dipho_leadEta) < 2.5 && fabs(dipho_subleadEta) < 2.5)

  {

if (File_Names[i]=="output_Data_2016PreVFP.root")

{ if (dipho_leadIDMVA > -0.2 && dipho_subleadIDMVA > -0.2) hist_[i]->Fill(dipho_cosphi,1);}
                
else if (File_Names[i]=="output_data_driven_bkg_2016PreVFP.root") {hist_[i]->Fill(dipho_cosphi, wt);}

else if (File_Names[i]=="output_ggjets_2016PreVFP.root") 
{ if (dipho_leadIDMVA > -0.2 && dipho_subleadIDMVA > -0.2) hist_[i]->Fill(dipho_cosphi, wt*lumi);}

//else {if (!(dipho_lead_genmatch==1 && dipho_sublead_genmatch==1) && (dipho_lead_genmatch==1 || dipho_sublead_genmatch==1) && (dipho_leadIDMVA > -0.2 && dipho_subleadIDMVA > -0.2)) {hist_[i]->Fill(dipho_cosphi, wt*lumi);}}
else if (File_Names[i]=="output_jj_2016PreVFP.root")

{if (!(dipho_lead_genmatch==1 && dipho_sublead_genmatch==1) && (dipho_leadIDMVA < -0.2 && dipho_subleadIDMVA < -0.2))
hist_[i]->Fill(dipho_cosphi, wt*lumi);}

else hist_[i]->Fill(dipho_cosphi, wt*lumi);

count++;
	}
      }
}
std::cout << "count" << " : " << count << std::endl; 
   hist_[i]->SetLineWidth(2);   
 
  }

  std::cout << "Integral Data: " << hist_[0]->Integral() << std::endl;
  std::cout << "Integral DD: " << hist_[1]->Integral() << std::endl;
  std::cout << "Integral ggjets: " << hist_[2]->Integral() << std::endl;

  //Stacks
  THStack* stack0 = new THStack("stack0", " ");
  THStack* stack = new THStack("stack", " ");
  THStack* stack1 = new THStack("stack1", " ");
  gStyle->SetLineWidth(2);
  TCanvas *c =new TCanvas("c", "", 0,0,700,800);

  TPad *c1 = new TPad("c1", " ", 0.0, 0.4, 1, 1);
  //  TPad *c1 = new TPad("c1", "", 0.1, 0.1, 0.9, 0.9);

//  c1->Range(83.74603,-0.6226295,185.0794,1.646546);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(1);
//  c1->SetLogy();
  c1->SetTickx(1);
  c1->SetTicky(1);
  c1->SetBottomMargin(0.01);
  c1->SetFrameBorderMode(0);
  c1->Draw();
  c1->cd();

  //Data
  hist_[0]->SetMarkerStyle(20);
  hist_[0]->SetMarkerSize(1.0); 
  hist_[0]->SetMarkerColor(1);

  stack0->Add(hist_[0],"AP");

  gStyle->SetOptStat(0);


  //MC gg
  hist_[2]->SetFillColor(kOrange+1);
  hist_[2]->SetFillStyle(1001);
  stack->Add(hist_[2],"hist");

  //Data-Driven QCD
  hist_[1]->SetFillColor(kCyan);
  hist_[1]->SetFillStyle(1001);
  stack->Add(hist_[1],"hist");


  //Data-driven +MC gg 
  TH1F *DD_MC = (TH1F*)hist_[1]->Clone();
  DD_MC->Add(hist_[2]);
  std::cout << "Integral DD+MC: " << DD_MC->Integral() << std::endl;

  //Full MC 
  TH1F *MC = (TH1F*)hist_[2]->Clone();
  MC->Add(hist_[3]);
  MC->Add(hist_[4]);
  MC->SetLineColor(kRed);
  MC->SetFillStyle(0);
  Float_t ymax = MC->GetMaximum();
  stack1->Add(MC,"hist");
  
  //Draw data, DD+MC, MC
  
  stack->Draw(" ");
  stack0->Draw("same");
  stack1->Draw("nostack same");

  stack->SetMaximum(ymax*1.5);
  stack->SetMinimum(0.0);
  stack->GetYaxis()->SetTitle("Events");
  stack->GetYaxis()->SetTitleSize(20);
  stack->GetYaxis()->SetTitleFont(43);
  stack->GetYaxis()->SetLabelFont(43);
  stack->GetYaxis()->SetLabelSize(15);
  stack->GetYaxis()->SetTitleOffset(1.5);

  
  TLegend *legend = new TLegend(0.56, 0.65, 0.87, 0.89);
  legend->SetTextFont(42);
  legend->SetLineColor(0);
  legend->SetTextSize(0.025);
  legend->AddEntry(hist_[0],"Data", "lp");
  legend->AddEntry(hist_[1],"Data_Driven", "f");
  legend->AddEntry(hist_[2],"#gamma#gamma + jets", "f");
  legend->AddEntry(MC,"MC( #gamma#gamma + #gammaj + jj)", "f");
  legend->Draw();

   
  TLatex *tl = new TLatex(0.53,0.9," #bf{CMS} #it{Preliminary}                          19.5 fb^{-1} (13 TeV) 2016PreVFP");
  tl->SetNDC();
  tl->SetTextFont(42);
  tl->SetTextSize(0.04);
  tl->SetTextAlign(20);
  tl->Draw("same");
  c->cd();


TPad* c2 = new TPad("c2", "c2", 0.0, 0.2, 1.0, 0.4);

  c2->SetTickx(1);
  c2->SetTicky(1);
  c2->SetBottomMargin(0.01);
  c2->SetTopMargin(0.005);
  c2->SetGridy();
  c2->Draw();
  c2->cd();
    
  // cout<< c1->GetX1()<<" "<<  "0 "<< c1->GetX2() <<' '<<  c1->GetY1() <<endl;

  //  c2->SetPad(c1->GetX1(), 0, c1->GetX2(), c1->GetY1());

 
  TH1F *rp = (TH1F*)DD_MC->Clone("rp");
  rp->Divide(hist_[0]);
  rp->SetStats(0);
  rp->SetMarkerStyle(20);
  rp->SetLineColor(kBlack);
  rp->SetMinimum(0);
  rp->SetMaximum(2);
  rp->GetYaxis()->SetNdivisions(505);
  rp->GetYaxis()->SetTitleSize(20);
  rp->GetYaxis()->SetTitleFont(43);
  rp->GetYaxis()->SetTitleOffset(1.5);
  rp->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  rp->GetYaxis()->SetLabelSize(15);
  rp->GetYaxis()->SetTitle("MC+DD/Data");
  rp->GetXaxis()->SetTitle("m_{#gamma#gamma}");
  rp->GetXaxis()->SetTitleSize(20);
  rp->GetXaxis()->SetTitleFont(43);
  rp->GetXaxis()->SetTitleOffset(4.);
  rp->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  rp->GetXaxis()->SetLabelSize(15);
  rp->Draw("ep");

//  TLine *l=new TLine(-1.0,1.0,1.0,1.0);
//  l->SetLineColor(kBlack);
//  l->Draw("same");

   c->cd();

TPad* c3 = new TPad("c3", "c3", 0.0, 0.0, 1.0, 0.2);

  c3->SetTickx(1);
  c3->SetTicky(1);
  c3->SetTopMargin(0.02);
  c3->SetBottomMargin(0.3);
//  c3->SetBottomMargin(0.01);
//  c2->SetTopMargin(0);
  c3->SetGridy();
  c3->Draw();
  c3->cd();
  c3->SetPad(c2->GetX1(), 0, c2->GetX2(), c2->GetY1());

  TH1F *rp1 = (TH1F*)MC->Clone("rp");
  rp1->Divide(hist_[0]);
  rp1->SetStats(0);
  rp1->SetMarkerStyle(20);
  rp1->SetMarkerColor(kBlue);
  rp1->SetLineColor(kBlue);
  rp1->SetMinimum(0);
  rp1->SetMaximum(2);
  rp1->GetYaxis()->SetNdivisions(505);
  rp1->GetYaxis()->SetTitleSize(20);
  rp1->GetYaxis()->SetTitleFont(43);
  rp1->GetYaxis()->SetTitleOffset(1.5);
  rp1->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  rp1->GetYaxis()->SetLabelSize(15);
  rp1->GetYaxis()->SetTitle("MC/Data");
  rp1->GetXaxis()->SetTitle("dipho_cosphi");
  rp1->GetXaxis()->SetTitleSize(20);
  rp1->GetXaxis()->SetTitleFont(43);
  rp1->GetXaxis()->SetTitleOffset(4.);
  rp1->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  rp1->GetXaxis()->SetLabelSize(15);
  rp1->Draw("ep");

//  TLine *l1=new TLine(1.0,1.0,1.0,1.0);
//  l1->SetLineColor(kBlack);
//  l1->Draw("same");

 c->Print("Plots/validation_dipho_cosphi.png");
 c->Print("Plots/validation_dipho_cosphi.pdf"); 

}

