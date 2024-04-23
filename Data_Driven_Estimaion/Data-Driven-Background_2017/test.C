#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TFile.h"
#include "TH1F.h"

void test()
{
    TFile* final_file = TFile::Open("EB_leading_fakefactor.root", "RECREATE");
    TFile *fgj = TFile::Open("Histogram_gjet_fakefactor.root");
    TFile *fjj = TFile::Open("Histogram_jj_fakefactor.root");

    TH1F *hjj_pp = (TH1F*)fjj->Get("h_pp_EB_leading");
    TH1F *hjj_fp = (TH1F*)fjj->Get("h_fp_EB_leading");
    TH1F *hgj_pp = (TH1F*)fgj->Get("h_pp_EB_leading");
    TH1F *hgj_fp = (TH1F*)fgj->Get("h_fp_EB_leading");

    // Clone histograms to use as numerator and denominator for TEfficiency
    TH1F *num = (TH1F*)hgj_pp->Clone("num");
    TH1F *denom = (TH1F*)hgj_fp->Clone("denom");
    num->Add(hjj_pp);
    denom->Add(hjj_fp);

    if (TEfficiency::CheckConsistency(*num, *denom)) {
        TEfficiency* eff = new TEfficiency(*num, *denom);
        TGraphAsymmErrors* graph = eff->CreateGraph();

        gStyle->SetLineWidth(2);
        TCanvas *c1 = new TCanvas("c1", " ", 0, 0, 800, 700);
        c1->SetGridx();
        c1->SetGridy();

        graph->SetTitle("");
        graph->SetMarkerColor(kOrange+10);
        graph->SetLineColor(kOrange+10);
        graph->SetLineWidth(2);
        graph->GetXaxis()->SetTitle("p_{T}^{#gamma_{1}} [GeV]");
        graph->GetYaxis()->SetTitle("Fake factor");
        graph->Draw("AP");

        // Additional canvas settings and drawing text
        // ...

        final_file->cd();
        graph->Write("EB_leading_fakefactor_eff");
        c1->Print("Plots/EB_leading_fakefactor_2017_eff.png");
        c1->Print("Plots/EB_leading_fakefactor_2017_eff.pdf");

        final_file->Close();
    } else {
        std::cerr << "Error: Histograms are not consistent and cannot be used to calculate efficiency." << std::endl;
    }
}

