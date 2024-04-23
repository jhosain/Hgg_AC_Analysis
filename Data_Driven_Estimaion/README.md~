# Data Driven Background Estimation

## VBF Method

I method that reuse data from a control region to model the prompt-fake and fake-fake backgrounds by inverting the photon-ID requirement for the leading and sub-leading photons. These control regions benefit from a large number of QCD-like events from recorded data.

Three main regions can then be defined: 
#### Signal region (N_pp): 
Regions passing the tight photon IDMVA (dipho_leadIDMVA > -0.2 & dipho_subleadIDMVA > -0.2), mainly populated by signal and prompt-prompt processes.
#### Control regions (N_pf and N_fp): 
Prompt-fake, fake-prompt and fake-fake regions. where prompt is defined by requiring dipho_leadIDMVA > -0.2 & fake dipho_subleadIDMVA < -0.2
#### Mass side band : 
Data event passing the VBF pre-selection cuts in the mass range of 100-180 GeV excluding the [115, 135]GeV region. This regions used to validate the QCD estimate from inverted photon IDMVA data.

## Running the Code

```
root -l -q histomaker.C
root -l -q fakefactor.C 
root -l -q qcdfraction.C
root -l -q WeightedTreeMaker.C

```
