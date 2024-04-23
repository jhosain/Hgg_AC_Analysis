from ROOT import TMVA
from ROOT import TCut,TFile,TTree,TChain, TMath

#Define channel
#signalCP="SM"
gen= "minlo"
JetCategory= "2" # Jet categorisation 0,1,2 jets
datadriven= True
sel="threeclass_CPodd_even_datdrivenQCD_diphobkg_vbf"

signalWeight=1.0
backgroundWeight=1.0

fout=TFile("TMVA_Hgg_"+sel+".root","RECREATE")

#Output of the factory
factory=TMVA.Factory("TMVAClassification_",fout,"!V:!Silent:Color:DrawProgressBar:Transformations=I;P;G:AnalysisType=multiclass") #Classification ->Multiclass
dataloader=TMVA.DataLoader("dataset")
dataloader.SetWeightExpression("weight");

#Input features to TMVA

#Di-photon variablesp
#dataloader.AddVariable("dipho_sumpt","F") #
dataloader.AddVariable("dipho_cosphi","F")

#dataloader.AddVariable("dipho_leadPt","F") #
dataloader.AddVariable("dipho_leadEta","F")
#dataloader.AddVariable("dipho_leadPhi","F")
dataloader.AddVariable("dipho_lead_ptoM","F")
dataloader.AddSpectator("dipho_mass","F")

#dataloader.AddVariable("dipho_subleadPt","F") #
dataloader.AddVariable("dipho_subleadEta","F")
#dataloader.AddVariable("dipho_subleadPhi","F")
dataloader.AddVariable("dipho_sublead_ptoM","F")

#Jet variables
##dataloader.AddVariable("dijet_Mjj","F")
#dataloader.AddVariable("dijet_centrality","F") #
dataloader.AddVariable("dijet_zep","F")

#dataloader.AddVariable("dijet_abs_dEta","F")
##dataloader.AddVariable("dijet_dphi","F")
##dataloader.AddVariable("cos_dijet_dipho_dphi","F") # bugged
dataloader.AddVariable("dijet_minDRJetPho", "F")

dataloader.AddVariable("dijet_leadEta","F")
dataloader.AddVariable("dijet_leadPt","F")
dataloader.AddVariable("dijet_subleadEta","F")
dataloader.AddVariable("dijet_subleadPt","F")

#dataloader.AddVariable("has3Jet","F") 

#Auxiliary variables
pho_theta1 = "2 * atan(exp(-dipho_leadEta))"
pho_theta2 = "2 * atan(exp(-dipho_subleadEta))"
jet_theta1 = "2 * atan(exp(-dijet_leadEta))"
jet_theta2 = "2 * atan(exp(-dijet_subleadEta))"

dipho_cosomega     = "(cos("+pho_theta1 +")*cos("+pho_theta2+")+sin("+pho_theta1+")*sin("+pho_theta2+")*cos(dipho_leadPhi-dipho_subleadPhi))"
dijet_cosomega     = "(cos("+jet_theta1 +")*cos("+jet_theta2+")+sin("+jet_theta1+")*sin("+jet_theta2+")*cos(dijet_leadPhi-dijet_subleadPhi))"
pho1_jet1_cosomega = "(cos("+pho_theta1 +")*cos("+jet_theta1+")+sin("+pho_theta1+")*sin("+jet_theta1+")*cos(dipho_leadPhi-dijet_leadPhi))"
pho1_jet2_cosomega = "(cos("+pho_theta1 +")*cos("+jet_theta2+")+sin("+jet_theta1+")*sin("+jet_theta2+")*cos(dipho_leadPhi-dijet_subleadPhi))"
pho2_jet1_cosomega = "(cos("+pho_theta2 +")*cos("+jet_theta1+")+sin("+pho_theta2+")*sin("+jet_theta1+")*cos(dipho_subleadPhi-dijet_leadPhi))"
pho2_jet2_cosomega = "(cos("+pho_theta2 +")*cos("+jet_theta2+")+sin("+jet_theta2+")*sin("+jet_theta2+")*cos(dipho_subleadPhi-dijet_subleadPhi))"

dipho_weight   = "(dipho_leadPt*dipho_subleadPt)/dipho_sumpt**2"
dijet_weight   = "(dijet_leadPt*dijet_subleadPt)/(dijet_leadPt**2+dijet_subleadPt**2+2*dijet_leadPt*dijet_subleadPt*cos(dijet_leadPhi-dijet_subleadPhi))"

#FWM di-photon
#dataloader.AddVariable("dipho_H_0T :="+dipho_weight ,                                     "dipho_H_0T" ,"F") #
dataloader.AddVariable("dipho_H_1T :="+dipho_weight+"*"          +dipho_cosomega          ,"dipho_H_1T" ,"F") #
dataloader.AddVariable("dipho_H_2T :="+dipho_weight+"* 0.5 *(3 *"+dipho_cosomega+"**2 -1)","dipho_H_2T" ,"F") #

#FWM di-jet
#dataloader.AddVariable("dijet_H_0T :="+dijet_weight ,                                     "dijet_H_0T" ,"F") 
#dataloader.AddVariable("dijet_H_1T :="+dijet_weight+"*"          +dijet_cosomega          ,"dijet_H_1T" ,"F") 
#dataloader.AddVariable("dijet_H_2T :="+dijet_weight+"* 0.5 *(3 *"+dijet_cosomega+"**2 -1)","dijet_H_2T" ,"F") 

dataloader.AddVariable("dijet_cosphi :=cos(dijet_leadPhi-dijet_subleadPhi)","dijet_cosphi" ,"F") 
dataloader.AddVariable("dijet_cosomega :="+dijet_cosomega,"dijet_cosomega" ,"F") 

#Reading ntuple with preselection cuts applied
inputfile_ggH_SM_2016Pre     = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_Pre_2016/Signal/output_GluGluHToGGPlusTwoJets_SM_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2016PreVFP.root", "READ")
inputfile_ggH_SM_2016Post     = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_Post_2016/Signal/output_GluGluHToGGPlusTwoJets_SM_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2016PostVFP.root", "READ")
inputfile_ggH_SM_2017     = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_2017/Signal/output_GluGluHToGGPlusTwoJets_SM_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2017.root", "READ")
inputfile_ggH_SM_2018     = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_2018/Signal/output_GluGluHToGGPlusTwoJets_SM_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2018.root", "READ")

inputfile_ggH_CPodd_2016Pre  = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_Pre_2016/Signal//output_GluGluHToGGPlusTwoJets_CPodd_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2016PreVFP.root", "READ")
inputfile_ggH_CPodd_2016Post  = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_Post_2016/Signal//output_GluGluHToGGPlusTwoJets_CPodd_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2016PostVFP.root", "READ")
inputfile_ggH_CPodd_2017  = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_2017/Signal//output_GluGluHToGGPlusTwoJets_CPodd_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2017.root", "READ")
inputfile_ggH_CPodd_2018  = TFile.Open("/afs/cern.ch/user/j/jhossain/eos/Hgg_AC_analysis/Prod_Ntuples_2024/Prod_2018/Signal//output_GluGluHToGGPlusTwoJets_CPodd_M125_TuneCP5_13TeV-amcatnlopowheg-"+gen+"-pythia8_2018.root", "READ")

inputfile_bkg_2016Pre = TFile.Open("output_data_driven_qcdbkg_diphoreweighted_2016PreVFP.root", "READ")
inputfile_bkg_2016Post = TFile.Open("output_data_driven_qcdbkg_diphoreweighted_2016PostVFP.root", "READ")
inputfile_bkg_2017 = TFile.Open("output_data_driven_qcdbkg_diphoreweighted_2017.root", "READ")
inputfile_bkg_2018 = TFile.Open("output_data_driven_qcdbkg_diphoreweighted_2018.root", "READ")

inputfile_vbf_2016Pre  = TFile.Open("output_vbf_Reweighted_2016PreVFP.root", "READ")
inputfile_vbf_2016Post  = TFile.Open("output_vbf_Reweighted_2016PostVFP.root", "READ")
inputfile_vbf_2017  = TFile.Open("output_vbf_Reweighted_2017.root", "READ")
inputfile_vbf_2018  = TFile.Open("output_vbf_Reweighted_2018.root", "READ")

ggH_SMTree_2016Pre       = inputfile_ggH_SM_2016Pre.Get     ("tagsDumper/trees/ggh_SM_13TeV_VBFTag_"+JetCategory)
ggH_SMTree_2016Post       = inputfile_ggH_SM_2016Post.Get     ("tagsDumper/trees/ggh_SM_13TeV_VBFTag_"+JetCategory)
ggH_SMTree_2017       = inputfile_ggH_SM_2017.Get     ("tagsDumper/trees/ggh_SM_13TeV_VBFTag_"+JetCategory)
ggH_SMTree_2018       = inputfile_ggH_SM_2018.Get     ("tagsDumper/trees/ggh_SM_13TeV_VBFTag_"+JetCategory)

ggH_CPoddTree_2016Pre     = inputfile_ggH_CPodd_2016Pre.Get  ("tagsDumper/trees/ggh_CPodd_13TeV_VBFTag_"+JetCategory)
ggH_CPoddTree_2016Post    = inputfile_ggH_CPodd_2016Post.Get  ("tagsDumper/trees/ggh_CPodd_13TeV_VBFTag_"+JetCategory)
ggH_CPoddTree_2017    = inputfile_ggH_CPodd_2017.Get  ("tagsDumper/trees/ggh_CPodd_13TeV_VBFTag_"+JetCategory)
ggH_CPoddTree_2018    = inputfile_ggH_CPodd_2018.Get  ("tagsDumper/trees/ggh_CPodd_13TeV_VBFTag_"+JetCategory)

backgroundTree_2016Pre    = inputfile_bkg_2016Pre.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)
backgroundTree_2016Post   = inputfile_bkg_2016Post.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)
backgroundTree_2017   = inputfile_bkg_2017.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)
backgroundTree_2018   = inputfile_bkg_2018.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)

vbfTree_2016Pre           = inputfile_vbf_2016Pre.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)
vbfTree_2016Post          = inputfile_vbf_2016Post.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)
vbfTree_2017          = inputfile_vbf_2017.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)
vbfTree_2018     = inputfile_vbf_2018.Get  ("tagsDumper/trees/bkg_13TeV_VBFTag_"+JetCategory)

#Memory allocation
fout.cd()

ggH_SMTree_2016Pre.Write()
ggH_SMTree_2016Post.Write()
ggH_SMTree_2017.Write()
ggH_SMTree_2018.Write()

ggH_CPoddTree_2016Pre.Write()
ggH_CPoddTree_2016Post.Write()
ggH_CPoddTree_2017.Write()
ggH_CPoddTree_2018.Write()

backgroundTree_2016Pre.Write()
backgroundTree_2016Post.Write()
backgroundTree_2017.Write()
backgroundTree_2018.Write()

vbfTree_2016Pre.Write()
vbfTree_2016Post.Write()
vbfTree_2017.Write()
vbfTree_2018.Write()

#Preselection kinematic
presel_dipho_eta= "abs(dipho_leadEta) < 2.5 && abs(dipho_subleadEta) < 2.5 && (abs(dipho_leadEta) < 1.44 || abs(dipho_leadEta) > 1.57) && (abs(dipho_subleadEta) < 1.44 || abs(dipho_subleadEta) > 1.57)" 
#presel_dipho_mass="(dipho_mass>135 || dipho_mass<115) " #blinding policy
presel_dipho_mass="(CMS_hgg_mass>135 || CMS_hgg_mass<115) "
presel_dipho_ptOverM="dipho_lead_ptoM > 0.25 && dipho_sublead_ptoM > 0.2 "
presel_dijet_eta="fabs(dijet_leadEta) < 4.7 && fabs(dijet_subleadEta) < 4.7 && dijet_abs_dEta > 0.0"# &&  dijet_minDRJetPho > 0.4"
presel_dijet_pt="dijet_leadPt > 30 && dijet_subleadPt > 20  && CMS_hgg_mass>100 &&  CMS_hgg_mass<180" #dijet_leadPt > 40 

#presel = presel_dipho_eta+"&&"+presel_dipho_mass+"&&"+presel_dipho_ptOverM+"&&"+presel_dijet_eta+"&&"+presel_dijet_pt #"&&"+ presel_dipho_MVA
presel = presel_dipho_eta+"&&"+presel_dipho_ptOverM+"&&"+presel_dijet_eta+"&&"+presel_dijet_pt 
presel_MVA_loose = " dipho_leadIDMVA > -0.9 && dipho_subleadIDMVA > -0.9 " #

#Signal and background selection
sgcut=TCut(presel )#+ "&& " + presel_MVA_loose ) #pp+ "&& " + presel_MVA_pp )
bgcut=TCut(presel  + "&& " + presel_dipho_mass ) #+ "&& " + presel_MVA_loose )#+ "&& " + presel_MVA_pp ) #+ "&&" + presel_MVA_pp ) # train in the signal region
#signalTree.Print()

#Add signal and bkg separate trees
dataloader.AddTree(ggH_SMTree_2016Pre   ,   "Signal"   ,  signalWeight,     sgcut, "Training and Testing")
dataloader.AddTree(ggH_SMTree_2016Post   ,   "Signal"   ,  signalWeight,     sgcut, "Training and Testing")
dataloader.AddTree(ggH_SMTree_2017   ,   "Signal"   ,  signalWeight,     sgcut, "Training and Testing")
dataloader.AddTree(ggH_SMTree_2018   ,   "Signal"   ,  signalWeight,     sgcut, "Training and Testing")
 
dataloader.AddTree(ggH_CPoddTree_2016Pre,   "ggh_CPodd",  signalWeight,     sgcut, "Training and Testing")
dataloader.AddTree(ggH_CPoddTree_2016Post,   "ggh_CPodd",  signalWeight,     sgcut, "Training and Testing")
dataloader.AddTree(ggH_CPoddTree_2017,   "ggh_CPodd",  signalWeight,     sgcut, "Training and Testing")
dataloader.AddTree(ggH_CPoddTree_2018,   "ggh_CPodd",  signalWeight,     sgcut, "Training and Testing")
   
dataloader.AddTree(backgroundTree_2016Pre, "Background",  backgroundWeight, bgcut, "Training and Testing" )
dataloader.AddTree(backgroundTree_2016Post, "Background",  backgroundWeight, bgcut, "Training and Testing" )
dataloader.AddTree(backgroundTree_2017, "Background",  backgroundWeight, bgcut, "Training and Testing" )
dataloader.AddTree(backgroundTree_2018, "Background",  backgroundWeight, bgcut, "Training and Testing" )

dataloader.AddTree(vbfTree_2016Pre,        "Background",  backgroundWeight, sgcut, "Training and Testing" )
dataloader.AddTree(vbfTree_2016Post,        "Background",  backgroundWeight, sgcut, "Training and Testing" )
dataloader.AddTree(vbfTree_2017,        "Background",  backgroundWeight, sgcut, "Training and Testing" )
dataloader.AddTree(vbfTree_2018,        "Background",  backgroundWeight, sgcut, "Training and Testing" )


#Prepare methods
dataloader.PrepareTrainingAndTestTree("","SplitMode=Random:nTrain_Signal=1478442:nTrain_Background=2693593:nTrain_ggH_CPodd=1422132") #70% of total events 
factory.BookMethod(dataloader,TMVA.Types.kBDT,"BDT_Xgrad_multiclass_CPodd_threeclass_VBF",   "!H:!V:MaxDepth=3:NTrees=800:UseRandomisedTrees=False:BoostType=Grad:NegWeightTreatment=Pray" ) #default
#factory.BookMethod(dataloader,TMVA.Types.kBDT,"BDT_Xgrad_IgnoreNegWeightsInTraining",   "!H:!V:MaxDepth=3:NTrees=800:UseRandomisedTrees=False:BoostType=Grad:NegWeightTreatment=IgnoreNegWeightsInTraining" ) 

factory.TrainAllMethods()
factory.TestAllMethods()
factory.EvaluateAllMethods()

fout.Close()

#Default settings BDT
#NTrees=800:
#MinNodeSize=2:
#MaxDepth=-1:
#BoostType=Grad:
#UseBaggedBoost=False:
#GradBaggingFraction=0.5:
#Shrinkage=0.1:
#SeparationType=GiniIndex: #MisClassificationError
#nCuts=20:
#UseYesNoLeaf=False:
#UseRandomisedTrees=True:
#DoBoostMonitor=True

#factory.BookMethod(dataloader,TMVA.Types.kBDT,"BDT_Adaboost","MaxDepth=3:NTrees=800:UseRandomisedTrees=True:BoostType=AdaBoost" ) #default
#factory.BookMethod(dataloader,TMVA.Types.kBDT,"BDT_RandFalse","MaxDepth=3:NTrees=800:UseRandomisedTrees=False" ) #default
#factory.BookMethod(TMVA.Types.kBDT,"BDTU","VarTransform=U:PruneMethod=CostComplexity:PruneStrength=-1" )

'''
presel_MVA_pp = " dipho_leadIDMVA > -0.2 && dipho_subleadIDMVA > -0.2 " #Signal region 
presel_MVA_ff = " dipho_leadIDMVA < -0.4 && dipho_subleadIDMVA < -0.4 " #fake-fake QCD-like 
presel_MVA_pf = " dipho_leadIDMVA > -0.2 && dipho_subleadIDMVA < -0.4 " #fake-prompt jet+photon
presel_MVA_fp = " dipho_leadIDMVA < -0.4 && dipho_subleadIDMVA > -0.2 " 
presel_MVA_bkg = "("+ presel_MVA_ff + "||"+ presel_MVA_pf + "||"+ presel_MVA_fp + ")" 
'''
