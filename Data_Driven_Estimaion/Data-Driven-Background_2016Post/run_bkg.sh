root -l -e '.x my_colz_plotter.C' -e '.x my_colz_plotter_gg.C' -e '.q' &> my_colz_plotter_log &

root -l -e '.x histomaker.C' -e '.q' 

root -l -e '.x fakefactor_EB.C' -e '.x fakefactor_EE.C' -e '.x fakefactor_EB_sub.C' -e '.x fakefactor_EE_sub.C' -e '.x qcdfraction_EB.C' -e '.x qcdfraction_EE.C' -e '.x qcdfraction_EB_sub.C'  -e '.x qcdfraction_EE_sub.C' -e '.q' 

root -l -e '.x Eff_qcdfraction_EB.C' -e '.x Eff_qcdfraction_EE.C' -e '.x Eff_qcdfraction_EB_sub.C' -e '.x Eff_qcdfraction_EE_sub.C' -e '.q'

rm weight_fakefactor_inclusive.root 
rm weight_qcdfraction_inclusive.root 

hadd -f weight_fakefactor_inclusive.root EB_leading_fakefactor.root EB_subleading_fakefactor.root EE_leading_fakefactor.root EE_subleading_fakefactor.root

hadd -f weight_qcdfraction_inclusive.root leading_EB_FP_qcdfraction.root leading_EE_FP_qcdfraction.root subleading_EB_PF_qcdfraction.root subleading_EE_PF_qcdfraction.root

root -l -e '.x WeightedTreeMaker.C'  -e	'.q'

root -l -e '.x validation_diphomass.C' -e '.x validation_ptom1.C' -e '.x validation_ptom2.C' -e '.x validation_dijetzep.C' -e '.x validation_dijetPt1.C' -e '.x validation_dijetPt2.C' -e '.x validation_dijetEta1.C' -e '.x validation_dijetEta2.C' -e '.x validation_dijetDR.C' -e '.x validation_diphocophi'  -e '.x validation_diphoeta1.C' -e '.x validation_diphoeta2.C'  -e '.x validation_diphomva.C' -e '.x validation_dijetMjj.C' -e '.x .q' &> validation_log &
