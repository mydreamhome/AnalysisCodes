#define top_cxx
#include "top.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void top::Loop()
{
    //   In a ROOT session, you can do:
    //      Root > .L top.C
    //      Root > top t
    //      Root > t.GetEntry(12); // Fill t data members with entry number 12
    //      Root > t.Show();       // Show values of entry 12
    //      Root > t.Show(16);     // Read and show values of entry 16
    //      Root > t.Loop();       // Loop on all entries
    //
    
    //     This is the loop skeleton where:
    //    jentry is the global entry number in the chain
    //    ientry is the entry number in the current Tree
    //  Note that the argument to GetEntry must be:
    //    jentry for TChain::GetEntry
    //    ientry for TTree::GetEntry and TBranch::GetEntry
    //
    //       To read only selected branches, Insert statements like:
    // METHOD1:
    //    fChain->SetBranchStatus("*",0);  // disable all branches
    //    fChain->SetBranchStatus("branchname",1);  // activate branchname
    // METHOD2: replace line
    //    fChain->GetEntry(jentry);       //read all branches
    //by  b_branchname->GetEntry(ientry); //read only this branch
    if (fChain == 0) return;
    
    //Initializing various parameters here
    double Vtx_Cut_z = 24.0;
    int Vtx_Cut_ndof = 4;
    double Vtx_Cut_rho = 2.0;
    
    double Electron_Tight_Cut_pt = 20.0;
    double Electron_Tight_Cut_eta = 2.5;
    double Transverse_Impact_Parameter_Cut = 0.04;
    int Passing_Conversion_Veto_Electron_Cut = 1;
    
    int Electron_Missing_Hits_Cut = 0;
    double Electron_Relative_Isolation_Cut = 0.15;
    
    int Particle_Flow_Muon_Cut = 1;
    int Global_Muon_Cut = 1;
    int Tracker_Muon_Cut = 1;
    double Muon_Tight_Cut_pt = 20.0;
    double Muon_Tight_Cut_eta = 2.4;
    double Muon_Relative_Isolation_Cut = 0.20;
    
    //Define Output Root file here
    TFile* file = new TFile("Macro.root", "RECREATE");
    TTree* tree = new TTree("Final_variables","");

    std::vector<double> elpt;
    std::vector<double> mupt;

    tree->Branch("elpt",&elpt);
    tree->Branch("mupt",&mupt);


    //Define Histograms here
 //   TH1D *h_electronpt = new TH1D("electronpt","electronpt",100,0,150);
 //   TH1D *h_muonpt = new TH1D("muonpt","muonpt",100,0,150);
    
    //Define Functions here
    bool top::electronTightCuts(int n)
    {
        bool electronPass = false;
        double transverse_momentum = floats_electrons_elPt_b2gEDMNtuples_obj->at(n);
        double Eta = floats_electrons_elEta_b2gEDMNtuples_obj->at(n);
        double Dxy = floats_electrons_elDxy_b2gEDMNtuples_obj->at(n);
        int PassingConversionVeto = floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_obj->at(n);
        int ElectronMissHit = floats_electrons_elmissHits_b2gEDMNtuples_obj->at(n);
        double RelIso = floats_electrons_elIso03_b2gEDMNtuples_obj->at(n);
        
        if( transverse_momentum>Electron_Tight_Cut_pt && fabs(Eta)<Electron_Tight_Cut_eta && Dxy<Transverse_Impact_Parameter_Cut && PassingConversionVeto ==Passing_Conversion_Veto_Electron_Cut && ElectronMissHit==Electron_Missing_Hits_Cut && RelIso<Electron_Relative_Isolation_Cut ){
            electronPass = true;
        }
        return electronPass;
    }
    
    bool top::muonTightCuts(int n)
    {
        bool muonPass = false;
        int ParticleFlowMuon = floats_muons_muIsPFMuon_b2gEDMNtuples_obj->at(n);
        int GlobalMuon = floats_muons_muIsGlobalMuon_b2gEDMNtuples_obj->at(n);
        int TrackerMuon = floats_muons_muIsTrackerMuon_b2gEDMNtuples_obj->at(n);
        double transverse_momentum = floats_muons_muPt_b2gEDMNtuples_obj->at(n);
        double Eta = floats_muons_muEta_b2gEDMNtuples_obj->at(n);
        double RelIso = floats_muons_muIso04_b2gEDMNtuples_obj->at(n);
        
        if( ParticleFlowMuon==Particle_Flow_Muon_Cut && GlobalMuon==Global_Muon_Cut && TrackerMuon==Tracker_Muon_Cut && transverse_momentum>Muon_Tight_Cut_pt && fabs(Eta)<Muon_Tight_Cut_eta && RelIso<Muon_Relative_Isolation_Cut ){
            muonPass = true;
        }
        return muonPass;
    }
    
    bool top::VertexCuts(int n)
    {
        bool VertexPass = false;
        double VertexZ = floats_vertexInfo_z_b2gEDMNtuples_obj->at(n);
        int VertexDof = ints_vertexInfo_ndof_b2gEDMNtuples_obj->at(n);
        double VertexRho = floats_vertexInfo_rho_b2gEDMNtuples_obj->at(n);
        
        if( fabs(VertexZ)<Vtx_Cut_z && VertexDof>=Vtx_Cut_ndof && VertexRho<Vtx_Cut_rho ){
            VertexPass = true;
        }
        return VertexPass;
    }
    
    // Start code:
    Long64_t nentries = fChain->GetEntriesFast();
    cout << "no. of entries " << nentries << endl;
    Long64_t nbytes = 0, nb = 0;
    
    for (Long64_t jentry=0; jentry < nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        
        
        for(int i=0;i<floats_vertexInfo_z_b2gEDMNtuples_obj->size();i++){
        
        bool Pass_Vertex = VertexCuts(i);
    if(Pass_Vertex){
            for(int j=0;j<floats_electrons_elCharge_b2gEDMNtuples_obj->size();j++){
                                    bool Pass_Electron = electronTightCuts(j);
                                if(Pass_Electron){
                    
                                                    // Fill Electron Histograms Here
                                                       elpt.push_back(j->elpt());

                                                  }
                                                }
            
            for(int mu1=0;mu1<floats_muons_muCharge_b2gEDMNtuples_obj->size();mu1++){
                                     bool Pass_Muon = muonTightCuts(mu1);
                                 if(Pass_Muon){
                                     // Fill Muon Histogram Here
                                     mupt.push_back(k->mupt());
                    
                                     for(int mu2=0;mu2<floats_muons_muCharge_b2gEDMNtuples_obj->size();mu2++){
                                         if(mu2>mu1){ // prevents double counting
                                             if( mu1->charge()*mu2->charge()<0 ){ // check only muon pairs of unequal charge
                                         bool Pass_Muon = muonTightCuts(mu2);
                                         if(Pass_Muon){

                                                     // Fill Muon Histogram Here
                                                        mupt.push_back(k->mupt());
                                     
                                                }
                                                                                    }
                        }
                                                                            }
        
        tree->Fill();
        elpt.clear();
        mupt.clear();
        
                                                                }
    
// Draw Histo Here.
file->Write();
    
}
