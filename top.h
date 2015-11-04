//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 13 22:42:32 2015 by ROOT version 5.34/18
// from TTree Events/
// found on file: B2GEDMNtuple.root
//////////////////////////////////////////////////////////

#ifndef top_h
#define top_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxfloats_vertexInfo_chi_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elCharge_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elD0_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elDxy_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elDz_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elE_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elEA_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elEta_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elHoE_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elIso03_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elIso03db_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elKey_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elMass_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elPhi_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elY_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_eldEtaIn_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_eldPhiIn_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elfull5x5siee_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elhasMatchedConVeto_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elisEB_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elisLoose_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elisMedium_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elisTight_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elisVeto_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elmissHits_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elooEmooP_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elrho_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elscEta_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elsumChargedHadronPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elsumNeutralHadronEt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elsumPUPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_electrons_elsumPhotonEt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muCharge_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muD0_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muD0err_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muDxy_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muDxyerr_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muDz_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muDzerr_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muE_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muEta_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muGenMuonCharge_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muGenMuonE_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muGenMuonEta_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muGenMuonPhi_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muGenMuonPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muGenMuonY_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muGlbTrkNormChi2_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muInTrkNormChi2_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsGlobalMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsHighPtMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsLooseMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsMediumMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsPFMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsSoftMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsTightMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIsTrackerMuon_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muIso04_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muKey_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muMass_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muNumberMatchedStations_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muNumberOfPixelLayers_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muNumberTrackerLayers_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muNumberValidMuonHits_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muNumberValidPixelHits_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muPhi_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muSumChargedHadronPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muSumNeutralHadronPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muSumPUPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muSumPhotonPt_b2gEDMNtuples = 1;
const Int_t kMaxfloats_muons_muY_b2gEDMNtuples = 1;
const Int_t kMaxfloats_vertexInfo_rho_b2gEDMNtuples = 1;
const Int_t kMaxfloats_vertexInfo_z_b2gEDMNtuples = 1;
const Int_t kMaxints_vertexInfo_ndof_b2gEDMNtuples = 1;

class top {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   edm::EventAuxiliary *EventAuxiliary;
   vector<edm::StoredProductProvenance> *EventProductProvenance;
   vector<edm::Hash<1> > *EventSelections;
   vector<unsigned short> *BranchListIndexes;
 //edm::Wrapper<vector<float> > *floats_vertexInfo_chi_b2gEDMNtuples_;
   Bool_t          floats_vertexInfo_chi_b2gEDMNtuples_present;
   vector<float>   floats_vertexInfo_chi_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elCharge_b2gEDMNtuples_;
   Bool_t          floats_electrons_elCharge_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elCharge_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elD0_b2gEDMNtuples_;
   Bool_t          floats_electrons_elD0_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elD0_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elDxy_b2gEDMNtuples_;
   Bool_t          floats_electrons_elDxy_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elDxy_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elDz_b2gEDMNtuples_;
   Bool_t          floats_electrons_elDz_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elDz_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elE_b2gEDMNtuples_;
   Bool_t          floats_electrons_elE_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elE_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elEA_b2gEDMNtuples_;
   Bool_t          floats_electrons_elEA_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elEA_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elEta_b2gEDMNtuples_;
   Bool_t          floats_electrons_elEta_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elEta_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elHoE_b2gEDMNtuples_;
   Bool_t          floats_electrons_elHoE_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elHoE_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elIso03_b2gEDMNtuples_;
   Bool_t          floats_electrons_elIso03_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elIso03_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elIso03db_b2gEDMNtuples_;
   Bool_t          floats_electrons_elIso03db_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elIso03db_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elKey_b2gEDMNtuples_;
   Bool_t          floats_electrons_elKey_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elKey_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elMass_b2gEDMNtuples_;
   Bool_t          floats_electrons_elMass_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elMass_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elPhi_b2gEDMNtuples_;
   Bool_t          floats_electrons_elPhi_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elPhi_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elPt_b2gEDMNtuples_;
   Bool_t          floats_electrons_elPt_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elY_b2gEDMNtuples_;
   Bool_t          floats_electrons_elY_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elY_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_eldEtaIn_b2gEDMNtuples_;
   Bool_t          floats_electrons_eldEtaIn_b2gEDMNtuples_present;
   vector<float>   floats_electrons_eldEtaIn_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_eldPhiIn_b2gEDMNtuples_;
   Bool_t          floats_electrons_eldPhiIn_b2gEDMNtuples_present;
   vector<float>   floats_electrons_eldPhiIn_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elfull5x5siee_b2gEDMNtuples_;
   Bool_t          floats_electrons_elfull5x5siee_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elfull5x5siee_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_;
   Bool_t          floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elisEB_b2gEDMNtuples_;
   Bool_t          floats_electrons_elisEB_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elisEB_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elisLoose_b2gEDMNtuples_;
   Bool_t          floats_electrons_elisLoose_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elisLoose_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elisMedium_b2gEDMNtuples_;
   Bool_t          floats_electrons_elisMedium_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elisMedium_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elisTight_b2gEDMNtuples_;
   Bool_t          floats_electrons_elisTight_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elisTight_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elisVeto_b2gEDMNtuples_;
   Bool_t          floats_electrons_elisVeto_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elisVeto_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elmissHits_b2gEDMNtuples_;
   Bool_t          floats_electrons_elmissHits_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elmissHits_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elooEmooP_b2gEDMNtuples_;
   Bool_t          floats_electrons_elooEmooP_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elooEmooP_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elrho_b2gEDMNtuples_;
   Bool_t          floats_electrons_elrho_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elrho_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elscEta_b2gEDMNtuples_;
   Bool_t          floats_electrons_elscEta_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elscEta_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_;
   Bool_t          floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_;
   Bool_t          floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elsumPUPt_b2gEDMNtuples_;
   Bool_t          floats_electrons_elsumPUPt_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elsumPUPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_electrons_elsumPhotonEt_b2gEDMNtuples_;
   Bool_t          floats_electrons_elsumPhotonEt_b2gEDMNtuples_present;
   vector<float>   floats_electrons_elsumPhotonEt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muCharge_b2gEDMNtuples_;
   Bool_t          floats_muons_muCharge_b2gEDMNtuples_present;
   vector<float>   floats_muons_muCharge_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muD0_b2gEDMNtuples_;
   Bool_t          floats_muons_muD0_b2gEDMNtuples_present;
   vector<float>   floats_muons_muD0_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muD0err_b2gEDMNtuples_;
   Bool_t          floats_muons_muD0err_b2gEDMNtuples_present;
   vector<float>   floats_muons_muD0err_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muDxy_b2gEDMNtuples_;
   Bool_t          floats_muons_muDxy_b2gEDMNtuples_present;
   vector<float>   floats_muons_muDxy_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muDxyerr_b2gEDMNtuples_;
   Bool_t          floats_muons_muDxyerr_b2gEDMNtuples_present;
   vector<float>   floats_muons_muDxyerr_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muDz_b2gEDMNtuples_;
   Bool_t          floats_muons_muDz_b2gEDMNtuples_present;
   vector<float>   floats_muons_muDz_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muDzerr_b2gEDMNtuples_;
   Bool_t          floats_muons_muDzerr_b2gEDMNtuples_present;
   vector<float>   floats_muons_muDzerr_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muE_b2gEDMNtuples_;
   Bool_t          floats_muons_muE_b2gEDMNtuples_present;
   vector<float>   floats_muons_muE_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muEta_b2gEDMNtuples_;
   Bool_t          floats_muons_muEta_b2gEDMNtuples_present;
   vector<float>   floats_muons_muEta_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muGenMuonCharge_b2gEDMNtuples_;
   Bool_t          floats_muons_muGenMuonCharge_b2gEDMNtuples_present;
   vector<float>   floats_muons_muGenMuonCharge_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muGenMuonE_b2gEDMNtuples_;
   Bool_t          floats_muons_muGenMuonE_b2gEDMNtuples_present;
   vector<float>   floats_muons_muGenMuonE_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muGenMuonEta_b2gEDMNtuples_;
   Bool_t          floats_muons_muGenMuonEta_b2gEDMNtuples_present;
   vector<float>   floats_muons_muGenMuonEta_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muGenMuonPhi_b2gEDMNtuples_;
   Bool_t          floats_muons_muGenMuonPhi_b2gEDMNtuples_present;
   vector<float>   floats_muons_muGenMuonPhi_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muGenMuonPt_b2gEDMNtuples_;
   Bool_t          floats_muons_muGenMuonPt_b2gEDMNtuples_present;
   vector<float>   floats_muons_muGenMuonPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muGenMuonY_b2gEDMNtuples_;
   Bool_t          floats_muons_muGenMuonY_b2gEDMNtuples_present;
   vector<float>   floats_muons_muGenMuonY_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_;
   Bool_t          floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_present;
   vector<float>   floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muInTrkNormChi2_b2gEDMNtuples_;
   Bool_t          floats_muons_muInTrkNormChi2_b2gEDMNtuples_present;
   vector<float>   floats_muons_muInTrkNormChi2_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsGlobalMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsGlobalMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsGlobalMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsHighPtMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsHighPtMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsHighPtMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsLooseMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsLooseMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsLooseMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsMediumMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsMediumMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsMediumMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsPFMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsPFMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsPFMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsSoftMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsSoftMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsSoftMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsTightMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsTightMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsTightMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIsTrackerMuon_b2gEDMNtuples_;
   Bool_t          floats_muons_muIsTrackerMuon_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIsTrackerMuon_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muIso04_b2gEDMNtuples_;
   Bool_t          floats_muons_muIso04_b2gEDMNtuples_present;
   vector<float>   floats_muons_muIso04_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muKey_b2gEDMNtuples_;
   Bool_t          floats_muons_muKey_b2gEDMNtuples_present;
   vector<float>   floats_muons_muKey_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muMass_b2gEDMNtuples_;
   Bool_t          floats_muons_muMass_b2gEDMNtuples_present;
   vector<float>   floats_muons_muMass_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muNumberMatchedStations_b2gEDMNtuples_;
   Bool_t          floats_muons_muNumberMatchedStations_b2gEDMNtuples_present;
   vector<float>   floats_muons_muNumberMatchedStations_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_;
   Bool_t          floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_present;
   vector<float>   floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_;
   Bool_t          floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_present;
   vector<float>   floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muNumberTrackerLayers_b2gEDMNtuples_;
   Bool_t          floats_muons_muNumberTrackerLayers_b2gEDMNtuples_present;
   vector<float>   floats_muons_muNumberTrackerLayers_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muNumberValidMuonHits_b2gEDMNtuples_;
   Bool_t          floats_muons_muNumberValidMuonHits_b2gEDMNtuples_present;
   vector<float>   floats_muons_muNumberValidMuonHits_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muNumberValidPixelHits_b2gEDMNtuples_;
   Bool_t          floats_muons_muNumberValidPixelHits_b2gEDMNtuples_present;
   vector<float>   floats_muons_muNumberValidPixelHits_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muPhi_b2gEDMNtuples_;
   Bool_t          floats_muons_muPhi_b2gEDMNtuples_present;
   vector<float>   floats_muons_muPhi_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muPt_b2gEDMNtuples_;
   Bool_t          floats_muons_muPt_b2gEDMNtuples_present;
   vector<float>   floats_muons_muPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muSumChargedHadronPt_b2gEDMNtuples_;
   Bool_t          floats_muons_muSumChargedHadronPt_b2gEDMNtuples_present;
   vector<float>   floats_muons_muSumChargedHadronPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_;
   Bool_t          floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_present;
   vector<float>   floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muSumPUPt_b2gEDMNtuples_;
   Bool_t          floats_muons_muSumPUPt_b2gEDMNtuples_present;
   vector<float>   floats_muons_muSumPUPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muSumPhotonPt_b2gEDMNtuples_;
   Bool_t          floats_muons_muSumPhotonPt_b2gEDMNtuples_present;
   vector<float>   floats_muons_muSumPhotonPt_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_muons_muY_b2gEDMNtuples_;
   Bool_t          floats_muons_muY_b2gEDMNtuples_present;
   vector<float>   floats_muons_muY_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_vertexInfo_rho_b2gEDMNtuples_;
   Bool_t          floats_vertexInfo_rho_b2gEDMNtuples_present;
   vector<float>   floats_vertexInfo_rho_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<float> > *floats_vertexInfo_z_b2gEDMNtuples_;
   Bool_t          floats_vertexInfo_z_b2gEDMNtuples_present;
   vector<float>   floats_vertexInfo_z_b2gEDMNtuples_obj;
 //edm::Wrapper<vector<int> > *ints_vertexInfo_ndof_b2gEDMNtuples_;
   Bool_t          ints_vertexInfo_ndof_b2gEDMNtuples_present;
   vector<int>     ints_vertexInfo_ndof_b2gEDMNtuples_obj;

   // List of branches
   TBranch        *b_EventAuxiliary;   //!
   TBranch        *b_EventProductProvenance;   //!
   TBranch        *b_EventSelections;   //!
   TBranch        *b_BranchListIndexes;   //!
   TBranch        *b_floats_vertexInfo_chi_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_vertexInfo_chi_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elCharge_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elCharge_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elD0_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elD0_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elDxy_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elDxy_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elDz_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elDz_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elE_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elE_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elEA_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elEA_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elEta_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elEta_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elHoE_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elHoE_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elIso03_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elIso03_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elIso03db_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elIso03db_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elKey_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elKey_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elMass_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elMass_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elPhi_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elPhi_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elY_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elY_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_eldEtaIn_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_eldEtaIn_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_eldPhiIn_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_eldPhiIn_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elfull5x5siee_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elfull5x5siee_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elisEB_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elisEB_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elisLoose_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elisLoose_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elisMedium_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elisMedium_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elisTight_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elisTight_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elisVeto_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elisVeto_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elmissHits_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elmissHits_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elooEmooP_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elooEmooP_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elrho_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elrho_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elscEta_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elscEta_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elsumPUPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elsumPUPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_electrons_elsumPhotonEt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_electrons_elsumPhotonEt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muCharge_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muCharge_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muD0_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muD0_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muD0err_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muD0err_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muDxy_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muDxy_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muDxyerr_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muDxyerr_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muDz_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muDz_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muDzerr_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muDzerr_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muE_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muE_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muEta_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muEta_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muGenMuonCharge_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muGenMuonCharge_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muGenMuonE_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muGenMuonE_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muGenMuonEta_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muGenMuonEta_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muGenMuonPhi_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muGenMuonPhi_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muGenMuonPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muGenMuonPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muGenMuonY_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muGenMuonY_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muInTrkNormChi2_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muInTrkNormChi2_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsGlobalMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsGlobalMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsHighPtMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsHighPtMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsLooseMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsLooseMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsMediumMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsMediumMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsPFMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsPFMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsSoftMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsSoftMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsTightMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsTightMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIsTrackerMuon_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIsTrackerMuon_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muIso04_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muIso04_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muKey_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muKey_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muMass_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muMass_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muNumberMatchedStations_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muNumberMatchedStations_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muNumberTrackerLayers_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muNumberTrackerLayers_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muNumberValidMuonHits_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muNumberValidMuonHits_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muNumberValidPixelHits_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muNumberValidPixelHits_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muPhi_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muPhi_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muSumChargedHadronPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muSumChargedHadronPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muSumPUPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muSumPUPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muSumPhotonPt_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muSumPhotonPt_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_muons_muY_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_muons_muY_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_vertexInfo_rho_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_vertexInfo_rho_b2gEDMNtuples_obj;   //!
   TBranch        *b_floats_vertexInfo_z_b2gEDMNtuples_present;   //!
   TBranch        *b_floats_vertexInfo_z_b2gEDMNtuples_obj;   //!
   TBranch        *b_ints_vertexInfo_ndof_b2gEDMNtuples_present;   //!
   TBranch        *b_ints_vertexInfo_ndof_b2gEDMNtuples_obj;   //!

   top(TTree *tree=0);
   virtual ~top();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef top_cxx
top::top(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("B2GEDMNtuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("B2GEDMNtuple.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

top::~top()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t top::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t top::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void top::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EventAuxiliary = 0;
   EventProductProvenance = 0;
   EventSelections = 0;
   BranchListIndexes = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventAuxiliary", &EventAuxiliary, &b_EventAuxiliary);
   fChain->SetBranchAddress("EventProductProvenance", &EventProductProvenance, &b_EventProductProvenance);
   fChain->SetBranchAddress("EventSelections", &EventSelections, &b_EventSelections);
   fChain->SetBranchAddress("BranchListIndexes", &BranchListIndexes, &b_BranchListIndexes);
   fChain->SetBranchAddress("floats_vertexInfo_chi_b2gEDMNtuples.present", &floats_vertexInfo_chi_b2gEDMNtuples_present, &b_floats_vertexInfo_chi_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_vertexInfo_chi_b2gEDMNtuples.obj", &floats_vertexInfo_chi_b2gEDMNtuples_obj, &b_floats_vertexInfo_chi_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elCharge_b2gEDMNtuples.present", &floats_electrons_elCharge_b2gEDMNtuples_present, &b_floats_electrons_elCharge_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elCharge_b2gEDMNtuples.obj", &floats_electrons_elCharge_b2gEDMNtuples_obj, &b_floats_electrons_elCharge_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elD0_b2gEDMNtuples.present", &floats_electrons_elD0_b2gEDMNtuples_present, &b_floats_electrons_elD0_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elD0_b2gEDMNtuples.obj", &floats_electrons_elD0_b2gEDMNtuples_obj, &b_floats_electrons_elD0_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elDxy_b2gEDMNtuples.present", &floats_electrons_elDxy_b2gEDMNtuples_present, &b_floats_electrons_elDxy_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elDxy_b2gEDMNtuples.obj", &floats_electrons_elDxy_b2gEDMNtuples_obj, &b_floats_electrons_elDxy_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elDz_b2gEDMNtuples.present", &floats_electrons_elDz_b2gEDMNtuples_present, &b_floats_electrons_elDz_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elDz_b2gEDMNtuples.obj", &floats_electrons_elDz_b2gEDMNtuples_obj, &b_floats_electrons_elDz_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elE_b2gEDMNtuples.present", &floats_electrons_elE_b2gEDMNtuples_present, &b_floats_electrons_elE_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elE_b2gEDMNtuples.obj", &floats_electrons_elE_b2gEDMNtuples_obj, &b_floats_electrons_elE_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elEA_b2gEDMNtuples.present", &floats_electrons_elEA_b2gEDMNtuples_present, &b_floats_electrons_elEA_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elEA_b2gEDMNtuples.obj", &floats_electrons_elEA_b2gEDMNtuples_obj, &b_floats_electrons_elEA_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elEta_b2gEDMNtuples.present", &floats_electrons_elEta_b2gEDMNtuples_present, &b_floats_electrons_elEta_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elEta_b2gEDMNtuples.obj", &floats_electrons_elEta_b2gEDMNtuples_obj, &b_floats_electrons_elEta_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elHoE_b2gEDMNtuples.present", &floats_electrons_elHoE_b2gEDMNtuples_present, &b_floats_electrons_elHoE_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elHoE_b2gEDMNtuples.obj", &floats_electrons_elHoE_b2gEDMNtuples_obj, &b_floats_electrons_elHoE_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elIso03_b2gEDMNtuples.present", &floats_electrons_elIso03_b2gEDMNtuples_present, &b_floats_electrons_elIso03_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elIso03_b2gEDMNtuples.obj", &floats_electrons_elIso03_b2gEDMNtuples_obj, &b_floats_electrons_elIso03_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elIso03db_b2gEDMNtuples.present", &floats_electrons_elIso03db_b2gEDMNtuples_present, &b_floats_electrons_elIso03db_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elIso03db_b2gEDMNtuples.obj", &floats_electrons_elIso03db_b2gEDMNtuples_obj, &b_floats_electrons_elIso03db_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elKey_b2gEDMNtuples.present", &floats_electrons_elKey_b2gEDMNtuples_present, &b_floats_electrons_elKey_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elKey_b2gEDMNtuples.obj", &floats_electrons_elKey_b2gEDMNtuples_obj, &b_floats_electrons_elKey_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elMass_b2gEDMNtuples.present", &floats_electrons_elMass_b2gEDMNtuples_present, &b_floats_electrons_elMass_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elMass_b2gEDMNtuples.obj", &floats_electrons_elMass_b2gEDMNtuples_obj, &b_floats_electrons_elMass_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elPhi_b2gEDMNtuples.present", &floats_electrons_elPhi_b2gEDMNtuples_present, &b_floats_electrons_elPhi_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elPhi_b2gEDMNtuples.obj", &floats_electrons_elPhi_b2gEDMNtuples_obj, &b_floats_electrons_elPhi_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elPt_b2gEDMNtuples.present", &floats_electrons_elPt_b2gEDMNtuples_present, &b_floats_electrons_elPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elPt_b2gEDMNtuples.obj", &floats_electrons_elPt_b2gEDMNtuples_obj, &b_floats_electrons_elPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elY_b2gEDMNtuples.present", &floats_electrons_elY_b2gEDMNtuples_present, &b_floats_electrons_elY_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elY_b2gEDMNtuples.obj", &floats_electrons_elY_b2gEDMNtuples_obj, &b_floats_electrons_elY_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_eldEtaIn_b2gEDMNtuples.present", &floats_electrons_eldEtaIn_b2gEDMNtuples_present, &b_floats_electrons_eldEtaIn_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_eldEtaIn_b2gEDMNtuples.obj", &floats_electrons_eldEtaIn_b2gEDMNtuples_obj, &b_floats_electrons_eldEtaIn_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_eldPhiIn_b2gEDMNtuples.present", &floats_electrons_eldPhiIn_b2gEDMNtuples_present, &b_floats_electrons_eldPhiIn_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_eldPhiIn_b2gEDMNtuples.obj", &floats_electrons_eldPhiIn_b2gEDMNtuples_obj, &b_floats_electrons_eldPhiIn_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elfull5x5siee_b2gEDMNtuples.present", &floats_electrons_elfull5x5siee_b2gEDMNtuples_present, &b_floats_electrons_elfull5x5siee_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elfull5x5siee_b2gEDMNtuples.obj", &floats_electrons_elfull5x5siee_b2gEDMNtuples_obj, &b_floats_electrons_elfull5x5siee_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elhasMatchedConVeto_b2gEDMNtuples.present", &floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_present, &b_floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elhasMatchedConVeto_b2gEDMNtuples.obj", &floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_obj, &b_floats_electrons_elhasMatchedConVeto_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elisEB_b2gEDMNtuples.present", &floats_electrons_elisEB_b2gEDMNtuples_present, &b_floats_electrons_elisEB_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elisEB_b2gEDMNtuples.obj", &floats_electrons_elisEB_b2gEDMNtuples_obj, &b_floats_electrons_elisEB_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elisLoose_b2gEDMNtuples.present", &floats_electrons_elisLoose_b2gEDMNtuples_present, &b_floats_electrons_elisLoose_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elisLoose_b2gEDMNtuples.obj", &floats_electrons_elisLoose_b2gEDMNtuples_obj, &b_floats_electrons_elisLoose_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elisMedium_b2gEDMNtuples.present", &floats_electrons_elisMedium_b2gEDMNtuples_present, &b_floats_electrons_elisMedium_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elisMedium_b2gEDMNtuples.obj", &floats_electrons_elisMedium_b2gEDMNtuples_obj, &b_floats_electrons_elisMedium_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elisTight_b2gEDMNtuples.present", &floats_electrons_elisTight_b2gEDMNtuples_present, &b_floats_electrons_elisTight_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elisTight_b2gEDMNtuples.obj", &floats_electrons_elisTight_b2gEDMNtuples_obj, &b_floats_electrons_elisTight_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elisVeto_b2gEDMNtuples.present", &floats_electrons_elisVeto_b2gEDMNtuples_present, &b_floats_electrons_elisVeto_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elisVeto_b2gEDMNtuples.obj", &floats_electrons_elisVeto_b2gEDMNtuples_obj, &b_floats_electrons_elisVeto_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elmissHits_b2gEDMNtuples.present", &floats_electrons_elmissHits_b2gEDMNtuples_present, &b_floats_electrons_elmissHits_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elmissHits_b2gEDMNtuples.obj", &floats_electrons_elmissHits_b2gEDMNtuples_obj, &b_floats_electrons_elmissHits_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elooEmooP_b2gEDMNtuples.present", &floats_electrons_elooEmooP_b2gEDMNtuples_present, &b_floats_electrons_elooEmooP_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elooEmooP_b2gEDMNtuples.obj", &floats_electrons_elooEmooP_b2gEDMNtuples_obj, &b_floats_electrons_elooEmooP_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elrho_b2gEDMNtuples.present", &floats_electrons_elrho_b2gEDMNtuples_present, &b_floats_electrons_elrho_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elrho_b2gEDMNtuples.obj", &floats_electrons_elrho_b2gEDMNtuples_obj, &b_floats_electrons_elrho_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elscEta_b2gEDMNtuples.present", &floats_electrons_elscEta_b2gEDMNtuples_present, &b_floats_electrons_elscEta_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elscEta_b2gEDMNtuples.obj", &floats_electrons_elscEta_b2gEDMNtuples_obj, &b_floats_electrons_elscEta_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elsumChargedHadronPt_b2gEDMNtuples.present", &floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_present, &b_floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elsumChargedHadronPt_b2gEDMNtuples.obj", &floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_obj, &b_floats_electrons_elsumChargedHadronPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples.present", &floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_present, &b_floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples.obj", &floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_obj, &b_floats_electrons_elsumNeutralHadronEt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elsumPUPt_b2gEDMNtuples.present", &floats_electrons_elsumPUPt_b2gEDMNtuples_present, &b_floats_electrons_elsumPUPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elsumPUPt_b2gEDMNtuples.obj", &floats_electrons_elsumPUPt_b2gEDMNtuples_obj, &b_floats_electrons_elsumPUPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_electrons_elsumPhotonEt_b2gEDMNtuples.present", &floats_electrons_elsumPhotonEt_b2gEDMNtuples_present, &b_floats_electrons_elsumPhotonEt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_electrons_elsumPhotonEt_b2gEDMNtuples.obj", &floats_electrons_elsumPhotonEt_b2gEDMNtuples_obj, &b_floats_electrons_elsumPhotonEt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muCharge_b2gEDMNtuples.present", &floats_muons_muCharge_b2gEDMNtuples_present, &b_floats_muons_muCharge_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muCharge_b2gEDMNtuples.obj", &floats_muons_muCharge_b2gEDMNtuples_obj, &b_floats_muons_muCharge_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muD0_b2gEDMNtuples.present", &floats_muons_muD0_b2gEDMNtuples_present, &b_floats_muons_muD0_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muD0_b2gEDMNtuples.obj", &floats_muons_muD0_b2gEDMNtuples_obj, &b_floats_muons_muD0_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muD0err_b2gEDMNtuples.present", &floats_muons_muD0err_b2gEDMNtuples_present, &b_floats_muons_muD0err_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muD0err_b2gEDMNtuples.obj", &floats_muons_muD0err_b2gEDMNtuples_obj, &b_floats_muons_muD0err_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muDxy_b2gEDMNtuples.present", &floats_muons_muDxy_b2gEDMNtuples_present, &b_floats_muons_muDxy_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muDxy_b2gEDMNtuples.obj", &floats_muons_muDxy_b2gEDMNtuples_obj, &b_floats_muons_muDxy_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muDxyerr_b2gEDMNtuples.present", &floats_muons_muDxyerr_b2gEDMNtuples_present, &b_floats_muons_muDxyerr_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muDxyerr_b2gEDMNtuples.obj", &floats_muons_muDxyerr_b2gEDMNtuples_obj, &b_floats_muons_muDxyerr_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muDz_b2gEDMNtuples.present", &floats_muons_muDz_b2gEDMNtuples_present, &b_floats_muons_muDz_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muDz_b2gEDMNtuples.obj", &floats_muons_muDz_b2gEDMNtuples_obj, &b_floats_muons_muDz_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muDzerr_b2gEDMNtuples.present", &floats_muons_muDzerr_b2gEDMNtuples_present, &b_floats_muons_muDzerr_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muDzerr_b2gEDMNtuples.obj", &floats_muons_muDzerr_b2gEDMNtuples_obj, &b_floats_muons_muDzerr_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muE_b2gEDMNtuples.present", &floats_muons_muE_b2gEDMNtuples_present, &b_floats_muons_muE_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muE_b2gEDMNtuples.obj", &floats_muons_muE_b2gEDMNtuples_obj, &b_floats_muons_muE_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muEta_b2gEDMNtuples.present", &floats_muons_muEta_b2gEDMNtuples_present, &b_floats_muons_muEta_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muEta_b2gEDMNtuples.obj", &floats_muons_muEta_b2gEDMNtuples_obj, &b_floats_muons_muEta_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muGenMuonCharge_b2gEDMNtuples.present", &floats_muons_muGenMuonCharge_b2gEDMNtuples_present, &b_floats_muons_muGenMuonCharge_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muGenMuonCharge_b2gEDMNtuples.obj", &floats_muons_muGenMuonCharge_b2gEDMNtuples_obj, &b_floats_muons_muGenMuonCharge_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muGenMuonE_b2gEDMNtuples.present", &floats_muons_muGenMuonE_b2gEDMNtuples_present, &b_floats_muons_muGenMuonE_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muGenMuonE_b2gEDMNtuples.obj", &floats_muons_muGenMuonE_b2gEDMNtuples_obj, &b_floats_muons_muGenMuonE_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muGenMuonEta_b2gEDMNtuples.present", &floats_muons_muGenMuonEta_b2gEDMNtuples_present, &b_floats_muons_muGenMuonEta_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muGenMuonEta_b2gEDMNtuples.obj", &floats_muons_muGenMuonEta_b2gEDMNtuples_obj, &b_floats_muons_muGenMuonEta_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muGenMuonPhi_b2gEDMNtuples.present", &floats_muons_muGenMuonPhi_b2gEDMNtuples_present, &b_floats_muons_muGenMuonPhi_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muGenMuonPhi_b2gEDMNtuples.obj", &floats_muons_muGenMuonPhi_b2gEDMNtuples_obj, &b_floats_muons_muGenMuonPhi_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muGenMuonPt_b2gEDMNtuples.present", &floats_muons_muGenMuonPt_b2gEDMNtuples_present, &b_floats_muons_muGenMuonPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muGenMuonPt_b2gEDMNtuples.obj", &floats_muons_muGenMuonPt_b2gEDMNtuples_obj, &b_floats_muons_muGenMuonPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muGenMuonY_b2gEDMNtuples.present", &floats_muons_muGenMuonY_b2gEDMNtuples_present, &b_floats_muons_muGenMuonY_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muGenMuonY_b2gEDMNtuples.obj", &floats_muons_muGenMuonY_b2gEDMNtuples_obj, &b_floats_muons_muGenMuonY_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muGlbTrkNormChi2_b2gEDMNtuples.present", &floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_present, &b_floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muGlbTrkNormChi2_b2gEDMNtuples.obj", &floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_obj, &b_floats_muons_muGlbTrkNormChi2_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muInTrkNormChi2_b2gEDMNtuples.present", &floats_muons_muInTrkNormChi2_b2gEDMNtuples_present, &b_floats_muons_muInTrkNormChi2_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muInTrkNormChi2_b2gEDMNtuples.obj", &floats_muons_muInTrkNormChi2_b2gEDMNtuples_obj, &b_floats_muons_muInTrkNormChi2_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsGlobalMuon_b2gEDMNtuples.present", &floats_muons_muIsGlobalMuon_b2gEDMNtuples_present, &b_floats_muons_muIsGlobalMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsGlobalMuon_b2gEDMNtuples.obj", &floats_muons_muIsGlobalMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsGlobalMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsHighPtMuon_b2gEDMNtuples.present", &floats_muons_muIsHighPtMuon_b2gEDMNtuples_present, &b_floats_muons_muIsHighPtMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsHighPtMuon_b2gEDMNtuples.obj", &floats_muons_muIsHighPtMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsHighPtMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsLooseMuon_b2gEDMNtuples.present", &floats_muons_muIsLooseMuon_b2gEDMNtuples_present, &b_floats_muons_muIsLooseMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsLooseMuon_b2gEDMNtuples.obj", &floats_muons_muIsLooseMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsLooseMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsMediumMuon_b2gEDMNtuples.present", &floats_muons_muIsMediumMuon_b2gEDMNtuples_present, &b_floats_muons_muIsMediumMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsMediumMuon_b2gEDMNtuples.obj", &floats_muons_muIsMediumMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsMediumMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsPFMuon_b2gEDMNtuples.present", &floats_muons_muIsPFMuon_b2gEDMNtuples_present, &b_floats_muons_muIsPFMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsPFMuon_b2gEDMNtuples.obj", &floats_muons_muIsPFMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsPFMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsSoftMuon_b2gEDMNtuples.present", &floats_muons_muIsSoftMuon_b2gEDMNtuples_present, &b_floats_muons_muIsSoftMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsSoftMuon_b2gEDMNtuples.obj", &floats_muons_muIsSoftMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsSoftMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsTightMuon_b2gEDMNtuples.present", &floats_muons_muIsTightMuon_b2gEDMNtuples_present, &b_floats_muons_muIsTightMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsTightMuon_b2gEDMNtuples.obj", &floats_muons_muIsTightMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsTightMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIsTrackerMuon_b2gEDMNtuples.present", &floats_muons_muIsTrackerMuon_b2gEDMNtuples_present, &b_floats_muons_muIsTrackerMuon_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIsTrackerMuon_b2gEDMNtuples.obj", &floats_muons_muIsTrackerMuon_b2gEDMNtuples_obj, &b_floats_muons_muIsTrackerMuon_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muIso04_b2gEDMNtuples.present", &floats_muons_muIso04_b2gEDMNtuples_present, &b_floats_muons_muIso04_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muIso04_b2gEDMNtuples.obj", &floats_muons_muIso04_b2gEDMNtuples_obj, &b_floats_muons_muIso04_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muKey_b2gEDMNtuples.present", &floats_muons_muKey_b2gEDMNtuples_present, &b_floats_muons_muKey_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muKey_b2gEDMNtuples.obj", &floats_muons_muKey_b2gEDMNtuples_obj, &b_floats_muons_muKey_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muMass_b2gEDMNtuples.present", &floats_muons_muMass_b2gEDMNtuples_present, &b_floats_muons_muMass_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muMass_b2gEDMNtuples.obj", &floats_muons_muMass_b2gEDMNtuples_obj, &b_floats_muons_muMass_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muNumberMatchedStations_b2gEDMNtuples.present", &floats_muons_muNumberMatchedStations_b2gEDMNtuples_present, &b_floats_muons_muNumberMatchedStations_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muNumberMatchedStations_b2gEDMNtuples.obj", &floats_muons_muNumberMatchedStations_b2gEDMNtuples_obj, &b_floats_muons_muNumberMatchedStations_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muNumberOfPixelLayers_b2gEDMNtuples.present", &floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_present, &b_floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muNumberOfPixelLayers_b2gEDMNtuples.obj", &floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_obj, &b_floats_muons_muNumberOfPixelLayers_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples.present", &floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_present, &b_floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples.obj", &floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_obj, &b_floats_muons_muNumberOfValidTrackerHits_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muNumberTrackerLayers_b2gEDMNtuples.present", &floats_muons_muNumberTrackerLayers_b2gEDMNtuples_present, &b_floats_muons_muNumberTrackerLayers_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muNumberTrackerLayers_b2gEDMNtuples.obj", &floats_muons_muNumberTrackerLayers_b2gEDMNtuples_obj, &b_floats_muons_muNumberTrackerLayers_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muNumberValidMuonHits_b2gEDMNtuples.present", &floats_muons_muNumberValidMuonHits_b2gEDMNtuples_present, &b_floats_muons_muNumberValidMuonHits_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muNumberValidMuonHits_b2gEDMNtuples.obj", &floats_muons_muNumberValidMuonHits_b2gEDMNtuples_obj, &b_floats_muons_muNumberValidMuonHits_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muNumberValidPixelHits_b2gEDMNtuples.present", &floats_muons_muNumberValidPixelHits_b2gEDMNtuples_present, &b_floats_muons_muNumberValidPixelHits_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muNumberValidPixelHits_b2gEDMNtuples.obj", &floats_muons_muNumberValidPixelHits_b2gEDMNtuples_obj, &b_floats_muons_muNumberValidPixelHits_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muPhi_b2gEDMNtuples.present", &floats_muons_muPhi_b2gEDMNtuples_present, &b_floats_muons_muPhi_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muPhi_b2gEDMNtuples.obj", &floats_muons_muPhi_b2gEDMNtuples_obj, &b_floats_muons_muPhi_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muPt_b2gEDMNtuples.present", &floats_muons_muPt_b2gEDMNtuples_present, &b_floats_muons_muPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muPt_b2gEDMNtuples.obj", &floats_muons_muPt_b2gEDMNtuples_obj, &b_floats_muons_muPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muSumChargedHadronPt_b2gEDMNtuples.present", &floats_muons_muSumChargedHadronPt_b2gEDMNtuples_present, &b_floats_muons_muSumChargedHadronPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muSumChargedHadronPt_b2gEDMNtuples.obj", &floats_muons_muSumChargedHadronPt_b2gEDMNtuples_obj, &b_floats_muons_muSumChargedHadronPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muSumNeutralHadronPt_b2gEDMNtuples.present", &floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_present, &b_floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muSumNeutralHadronPt_b2gEDMNtuples.obj", &floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_obj, &b_floats_muons_muSumNeutralHadronPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muSumPUPt_b2gEDMNtuples.present", &floats_muons_muSumPUPt_b2gEDMNtuples_present, &b_floats_muons_muSumPUPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muSumPUPt_b2gEDMNtuples.obj", &floats_muons_muSumPUPt_b2gEDMNtuples_obj, &b_floats_muons_muSumPUPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muSumPhotonPt_b2gEDMNtuples.present", &floats_muons_muSumPhotonPt_b2gEDMNtuples_present, &b_floats_muons_muSumPhotonPt_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muSumPhotonPt_b2gEDMNtuples.obj", &floats_muons_muSumPhotonPt_b2gEDMNtuples_obj, &b_floats_muons_muSumPhotonPt_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_muons_muY_b2gEDMNtuples.present", &floats_muons_muY_b2gEDMNtuples_present, &b_floats_muons_muY_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_muons_muY_b2gEDMNtuples.obj", &floats_muons_muY_b2gEDMNtuples_obj, &b_floats_muons_muY_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_vertexInfo_rho_b2gEDMNtuples.present", &floats_vertexInfo_rho_b2gEDMNtuples_present, &b_floats_vertexInfo_rho_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_vertexInfo_rho_b2gEDMNtuples.obj", &floats_vertexInfo_rho_b2gEDMNtuples_obj, &b_floats_vertexInfo_rho_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("floats_vertexInfo_z_b2gEDMNtuples.present", &floats_vertexInfo_z_b2gEDMNtuples_present, &b_floats_vertexInfo_z_b2gEDMNtuples_present);
   fChain->SetBranchAddress("floats_vertexInfo_z_b2gEDMNtuples.obj", &floats_vertexInfo_z_b2gEDMNtuples_obj, &b_floats_vertexInfo_z_b2gEDMNtuples_obj);
   fChain->SetBranchAddress("ints_vertexInfo_ndof_b2gEDMNtuples.present", &ints_vertexInfo_ndof_b2gEDMNtuples_present, &b_ints_vertexInfo_ndof_b2gEDMNtuples_present);
   fChain->SetBranchAddress("ints_vertexInfo_ndof_b2gEDMNtuples.obj", &ints_vertexInfo_ndof_b2gEDMNtuples_obj, &b_ints_vertexInfo_ndof_b2gEDMNtuples_obj);
   Notify();
}

Bool_t top::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void top::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t top::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef top_cxx
