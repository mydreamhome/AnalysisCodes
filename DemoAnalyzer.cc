// -*- C++ -*-
//
// Package:    DemoAnalyzer
// Class:      DemoAnalyzer
// 
/**\class DemoAnalyzer DemoAnalyzer.cc Demo/DemoAnalyzer/src/DemoAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Priyanka Priyanka,,,
//         Created:  Wed Jun 17 12:51:14 CEST 2015
// $Id$
//
//


// system include files
#include <memory>
#include <vector>

// user include files
//always
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

//optional always
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

//for histogram plots
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"

//for electrons
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"

//
// class declaration
//

class DemoAnalyzer : public edm::EDAnalyzer { //Defining class named DemoAnalyzer & inheriting another class named EDAnalyzer(defined in edm namespace) in this DemoAnalyzer class
    //defines extra variables here
public:
  explicit DemoAnalyzer(const edm::ParameterSet&); //Defining constructor of DemoAnalyzer class(whose I/P is reference to another class named ParameterSet(Defined in edm namespace))
  ~DemoAnalyzer(); //destructor

   // static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
    
private: //Defining private variables of this DemoAnalyzer class
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
   // virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  //  virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
    
    // ----------member data ---------------------------
    TTree* t; //pointer to tree
    TFile* f; //pointer to file
    
    //my type for defining all quantities example: define all histogram's quantity here
std::vector<int> size;
    std::vector<int> charge;
    std::vector<double> pt;
    std::vector<double> eta;
    std::vector<double> phi;
    std::vector<double> mass;

	std::vector<double> px;
	std::vector<double> py;
	std::vector<double> pz;
	std::vector<double> energy;
std::vector<double> HbyE;
	std::vector<double> dEtaIn;
	std::vector<double> dPhiIn;
	std::vector<double> sigmaIEtaIEta;
	std::vector<double> EbyPin;
	std::vector<double> fbrem;
	std::vector<double> E_P;
	std::vector<double> dxy;
	std::vector<double> dz;
	std::vector<double> dr03TkSumPt;
	std::vector<double> dr03EcalRecHitSumEt;
	std::vector<double> dr03HcalTowerSumEt;
	std::vector<double> ecalEnergy;
	std::vector<double> trackMomentumAtVtx;
};


DemoAnalyzer::DemoAnalyzer(const edm::ParameterSet& iConfig){
    
}


DemoAnalyzer::~DemoAnalyzer(){

}

//
// member functions of DemoAnalyzer class
//

// ------------ method called to for each event  ------------
void
DemoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  using reco::GsfElectronCollection ;
  Handle<GsfElectronCollection> electrons;
  iEvent.getByLabel("gsfElectrons", electrons);
    
    if( electrons->size() == 2) {
        size.push_back(electrons->size());
        std::cout << "number of electrons = "<< electrons->size() << std::endl;
        size.push_back(electron->size());
for(GsfElectronCollection::const_iterator el = electrons->begin(); el != electrons->end(); ++el){

            charge.push_back(el->charge());
            pt.push_back(el->pt());
            eta.push_back(el->eta());
            phi.push_back(el->phi());
            mass.push_back(el->mass());
	    energy.push_back(el->energy());
//	    HbyE.push_back(el->HbyE());
//	    dEtaIn.push_back(el->dEtaIn());
//	    dPhiIn.push_back(el->dPhiIn());
//	    sigmaIEtaIEta.push_back(el->sigmaIEtaIEta());
//	    EbyPin.push_back(el->EbyPin());
	    fbrem.push_back(el->fbrem());
	    dr03TkSumPt.push_back(el->dr03TkSumPt());
	    dr03EcalRecHitSumEt.push_back(el->dr03EcalRecHitSumEt());
	    dr03HcalTowerSumEt.push_back(el->dr03HcalTowerSumEt());

    
}
        t->Fill();
        charge.clear();
        pt.clear();
        eta.clear();
        phi.clear();
        mass.clear();
	energy.clear();
//	HbyE.clear();
//	dEtaIn.clear();
//	dPhiIn.clear();
//	sigmaIEtaIEta.clear();
//	EbyPin.clear();
	fbrem.clear();
	dr03TkSumPt.clear();
	dr03EcalRecHitSumEt.clear();
	dr03HcalTowerSumEt.clear();
    }
    size.clear();
}


// ------------ method called once each job just before starting event loop  ------------
void 
DemoAnalyzer::beginJob()
{
    f=new TFile ("electron.root","RECREATE");
    t= new TTree("electron_variables","");
    
//    TBranch *mybranch = t->Branch();
    t->Branch("size",&size);
    t->Branch("charge",&charge);
    t->Branch("pt",&pt);
    t->Branch("eta",&eta);
    t->Branch("phi",&phi);
    t->Branch("mass",&mass);
    t->Branch("energy",&energy);
//t->Branch("HbyE",&HbyE);
//t->Branch("dEtaIn",&dEtaIn);
//t->Branch("dPhiIn",&dPhiIn);
//t->Branch("sigmaIEtaIEta",&sigmaIEtaIEta);
//t->Branch("EbyP_in",&EbyPin);
t->Branch("fbrem",&fbrem);
t->Branch("dr03TkSumPt",&dr03TkSumPt);
t->Branch("dr03EcalRecHitSumEt",&dr03EcalRecHitSumEt);
t->Branch("dr03HcalTowerSumEt",&dr03HcalTowerSumEt);
    
    std::cout<<"begin job"<<std::endl;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
DemoAnalyzer::endJob() {
    std::cout<<"end job"<<std::endl;
    f->Write();
}

// ------------ method called when starting to processes a run  ------------
void
DemoAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
    std::cout<<"begin Run"<<std::endl;
}

// ------------ method called when ending the processing of a run  ------------
void
DemoAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
    std::cout<<"end Run"<<std::endl;
}
/*
// ------------ method called when starting to processes a luminosity block  ------------
void
DemoAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
    std::cout<<"begin Luminosity Block"<<std::endl;
}

// ------------ method called when ending the processing of a luminosity block  ------------
void
DemoAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
    std::cout<<"end Luminosity Block"<<std::endl;
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
DemoAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
    //The following says we do not know what parameters are allowed so do no validation
    // Please change this to state exactly what you do use, even if it is no parameters
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}*/

//define this as a plug-in
DEFINE_FWK_MODULE(DemoAnalyzer);

