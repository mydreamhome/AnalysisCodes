#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

#include <TH1F.h>
#include <TROOT.h>
#include <TFile.h>
#include <TSystem.h>

#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/FWLite/interface/AutoLibraryLoader.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "PhysicsTools/FWLite/interface/TFileService.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h"


int main(int argc, char* argv[])
{
    bool electronTightCuts(int);
    bool muonTightCuts(int);
    bool VertexCuts(int);
    
    
    
    
  // ----------------------------------------------------------------------
  // First Part: 
  //
  //  * enable the AutoLibraryLoader 
  //  * book the histograms of interest 
  //  * open the input file
  // ----------------------------------------------------------------------

  // load framework libraries
  gSystem->Load( "libFWCoreFWLite" );
  AutoLibraryLoader::enable();

  // initialize command line parser
  optutl::CommandLineParser parser ("Analyze FWLite Histograms");

  // set defaults
  parser.integerValue ("maxEvents"  ) = 1000;
  parser.integerValue ("outputEvery") =   10;
  parser.stringValue  ("outputFile" ) = "analyzeEdmTuple.root";

  // parse arguments
  parser.parseArguments (argc, argv);
  int maxEvents_ = parser.integerValue("maxEvents");
  unsigned int outputEvery_ = parser.integerValue("outputEvery");
  std::string outputFile_ = parser.stringValue("outputFile");
  std::vector<std::string> inputFiles_ = parser.stringVector("inputFiles");

  // book a set of histograms
  fwlite::TFileService fs = fwlite::TFileService(outputFile_.c_str());
  TFileDirectory dir = fs.mkdir("analyzePatMuon");
  TH1F* muonPt_  = dir.make<TH1F>("muonPt"  , "pt"  ,   100,   0., 300.);
  TH1F* muonEta_ = dir.make<TH1F>("muonEta" , "eta" ,   100,  -3.,   3.);
  TH1F* muonPhi_ = dir.make<TH1F>("muonPhi" , "phi" ,   100,  -5.,   5.);  

  // loop the events
  int ievt=0;  
  for(unsigned int iFile=0; iFile<inputFiles_.size(); ++iFile){
    // open input file (can be located on castor)
    TFile* inFile = TFile::Open(inputFiles_[iFile].c_str());
    if( inFile ){
      // ----------------------------------------------------------------------
      // Second Part: 
      //
      //  * loop the events in the input file 
      //  * receive the collections of interest via fwlite::Handle
      //  * fill the histograms
      //  * after the loop close the input file
      // ----------------------------------------------------------------------      
      fwlite::Event ev(inFile);
      for(ev.toBegin(); !ev.atEnd(); ++ev, ++ievt){
	edm::EventBase const & event = ev;
	// break loop if maximal number of events is reached 
	if(maxEvents_>0 ? ievt+1>maxEvents_ : false) break;
	// simple event counter
	if(outputEvery_!=0 ? (ievt>0 && ievt%outputEvery_==0) : false) 
	  std::cout << "  processing event: " << ievt << std::endl;
          
          
          //call functions here
          

	// Handle to the muon pt
	edm::Handle<std::vector<float> > muonPt;
	event.getByLabel(std::string("patMuonAnalyzer:pt"), muonPt);
	// loop muon collection and fill histograms
	for(std::vector<float>::const_iterator mu1=muonPt->begin(); mu1!=muonPt->end(); ++mu1){
	  muonPt_ ->Fill( *mu1 );
	}
	// Handle to the muon eta
	edm::Handle<std::vector<float> > muonEta;
	event.getByLabel(std::string("patMuonAnalyzer:eta"), muonEta);
	for(std::vector<float>::const_iterator mu1=muonEta->begin(); mu1!=muonEta->end(); ++mu1){
	  muonEta_ ->Fill( *mu1 );
	}
	// Handle to the muon phi
	edm::Handle<std::vector<float> > muonPhi;
	event.getByLabel(std::string("patMuonAnalyzer:phi"), muonPhi);
	for(std::vector<float>::const_iterator mu1=muonPhi->begin(); mu1!=muonPhi->end(); ++mu1){
	  muonPhi_ ->Fill( *mu1 );
	}
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
      }  
      // close input file
      inFile->Close();
    }
    // break loop if maximal number of events is reached:
    // this has to be done twice to stop the file loop as well
    if(maxEvents_>0 ? ievt+1>maxEvents_ : false) break;
  }
  return 0;
}



//Define Functions here

int* electronTightPtCut(double);
int* electronTightPtCut(double Electron_Tight_Cut_pt)
{
    int i = 0;
   // static int number_of_passed_electron_in_particular_event[100];
    int* = number_of_passed_electron_in_particular_event = new int[100];
    
    // Handle to the electron pt
    edm::Handle<std::vector<float> > electronPt;
    event.getByLabel(std::string("electron:pt"), electronPt);
    
    // loop electron collection and test cut and fill histogram of passed electrons pt and tell index number of passed electrons
    int = 0;
    for(std::vector<float>::const_iterator elPt=electronPt->begin(); elPt!=electronPt->end(); ++elPt){
        if( (*elPt) > Electron_Tight_Cut_pt){
                                            i++;
                                // electronPt_ ->Fill( *elPt );
        }
    }
    number_of_passed_electron_in_particular_event[ev] = i;
    return number_of_passed_electron_in_particular_event;
}

int* Paricle_Cut(double, char*, char*, char*);
int* Paricle_Cut(double Cut_Value, char* Handle_Name, char* Module_Name, char* Label_Name)
{
    
    
    vector< vector<int> > ID_number_of_passed_particles_in_particular_event;
    
    for (int i = 0; i < 10; i++) {
        vector<int> row; // Create an empty row
        for (int j = 0; j < 20; j++) {
            row.push_back(i * j); // Add an element (column) to the row
        }
        ID_number_of_passed_particles_in_particular_event.push_back(row); // Add the row to the main vector
    }
    
    
    
    
    
    int* = number_of_passed_particles_in_particular_event = new int[100];
    // OR can do: static int number_of_passed_particles_in_particular_event[100];
    
    // Handle to the module label
    edm::Handle<std::vector<float> > Handle_Name;
    event.getByLabel(std::string("Module_Name:Label_Name"), Handle_Name);
    
    // loop electron collection and test cut and fill histogram of passed electrons pt and tell index number of passed electrons
    int i = 0;
    int k = 0;
    for(std::vector<float>::const_iterator j=Handle_Name->begin(); j!=Handle_Name->end(); ++j){
        k++;
        if( (*j) > Cut_Value){
            i++;
            // Handle_Name_ ->Fill( *j );
            ID_number_of_passed_particles_in_particular_event[ev][i] = k;
        }
    }
    return ID_number_of_passed_particles_in_particular_event;
}



int* Paricle_Cut(double, char*, char*, char*);
int* Paricle_Cut(double Cut_Value, char* Handle_Name, char* Module_Name, char* Label_Name)
{
    int* number_of_passed_particles_in_particular_event = new int[100];
    // OR can do: static int number_of_passed_particles_in_particular_event[100];
    
    // Handle to the module label
    edm::Handle<std::vector<float> > Handle_Name;
    event.getByLabel(std::string("Module_Name:Label_Name"), Handle_Name);
    
    // loop electron collection and test cut and fill histogram of passed electrons pt and tell index number of passed electrons
    int i = 0;
    for(std::vector<float>::const_iterator j=Handle_Name->begin(); j!=Handle_Name->end(); ++j){
        if( (*j) > Cut_Value){
            i++;
            // Handle_Name_ ->Fill( *j );
        }
    }
    number_of_passed_particles_in_particular_event[ev] = i;
    return number_of_passed_particles_in_particular_event;
}

int* Paricle_Cut(double, char*, char*, char*);
int* Paricle_Cut(double Cut_Value, char* Handle_Name, char* Module_Name, char* Label_Name)
{
    int* number_of_passed_particles_in_particular_event = new int[100];
    // OR can do: static int number_of_passed_particles_in_particular_event[100];
    
    int* Cut_Passed_Paricles(double Cut_Value, char* Handle_Name, char* Module_Name, char* Label_Name);
    
    
    number_of_passed_particles_in_particular_event[ev] = i;
    return number_of_passed_particles_in_particular_event;
}

int* Cut_Passed_Paricles(double, char*, char*, char*);
int* Cut_Passed_Paricles(double Cut_Value, char* Handle_Name, char* Module_Name, char* Label_Name)
{
    // Handle to the module label
    edm::Handle<std::vector<float> > Handle_Name;
    event.getByLabel(std::string("Module_Name:Label_Name"), Handle_Name);
    
    // loop electron collection and test cut and fill histogram of passed electrons pt and tell index number of passed electrons
    int i = 0;
    
    
    for(std::vector<float>::const_iterator j=Handle_Name->begin(); j!=Handle_Name->end(); ++j){
        if( (*j) > Cut_Value){
            i++;
            // Handle_Name_ ->Fill( *j );
        }
    }
    
    
    return
}


for(std::vector<float>::const_iterator j=Handle_Name->begin(); j!=Handle_Name->end(); ++j){
    if( (*j) > Cut_Value){
        i++;
        // Handle_Name_ ->Fill( *j );
    }
}


















int* electronCuts(double, char*, char*, char*);
int* electronCuts(double Cut_Value, char* Handle_Name, char* Module_Name, char* Label_Name)
{
    int* = number_of_passed_particles_in_particular_event = new int[100];
    // OR can do: static int number_of_passed_particles_in_particular_event[100];
    
    // Handle to the module label
    edm::Handle<std::vector<float> > Handle_Name;
    event.getByLabel(std::string("Module_Name:Label_Name"), Handle_Name);
    
    // loop electron collection and test cut and fill histogram of passed electrons pt and tell index number of passed electrons
    int i = 0;
    for(std::vector<float>::const_iterator j=Handle_Name->begin(); j!=Handle_Name->end(); ++j){
        if( (*j) > Cut_Value){
            i++;
            // Handle_Name_ ->Fill( *j );
        }
    }
    number_of_passed_particles_in_particular_event[ev] = i;
    return number_of_passed_particles_in_particular_event;
}


//Define Functions here
bool electronCuts(int n)
bool electronCuts(int n)
{
    bool electronPass = false;
    
    double Electron_Cut_pt = 20.0;
    double Electron_Cut_eta = 2.5;
    double Transverse_Impact_Parameter_Cut = 0.04;
    int Passing_Conversion_Veto_Electron_Cut = 1;
    
    int Electron_Missing_Hits_Cut = 0;
    double Electron_Relative_Isolation_Cut = 0.15;
    
    // Handle to the electron pt
    edm::Handle<std::vector<float> > electronPt;
    event.getByLabel(std::string("electrons:elPt"), electronPt);
    // Handle to the electron eta
    edm::Handle<std::vector<float> > electronEta;
    event.getByLabel(std::string("electrons:elEta"), electronEta);
    // Handle to the electron pt
    edm::Handle<std::vector<float> > electronDxy;
    event.getByLabel(std::string("electrons:elDxy"), electronDxy);
    // Handle to the electron pt
    edm::Handle<std::vector<float> > electronisVeto;
    event.getByLabel(std::string("electrons:elisVeto"), electronisVeto);
    // Handle to the electron pt
    edm::Handle<std::vector<float> > electronmissHits;
    event.getByLabel(std::string("electrons:elmissHits"), electronmissHits);
    // Handle to the electron pt
    edm::Handle<std::vector<float> > electronIso03;
    event.getByLabel(std::string("electrons:elIso03"), electronIso03);
    
for(std::vector<float>::const_iterator pt=electronPt->begin(); pt!=electronPt->end(); ++pt){
    if( (*pt) > Electron_Cut_pt){
       // electronPt_ ->Fill( *pt );
for(std::vector<float>::const_iterator eta=electronEta->begin(); eta!=electronEta->end(); ++eta){
      if( (*eta) > Electron_Cut_eta){
     //  electronEta_ ->Fill( *eta );
for(std::vector<float>::const_iterator Dxy=electronDxy->begin(); Dxy!=electronDxy->end(); ++Dxy){
      if( (*Dxy) > Transverse_Impact_Parameter_Cut){
    // electronDxy_ ->Fill( *Dxy );
for(std::vector<float>::const_iterator isVeto=electronisVeto->begin(); isVeto!=electronisVeto->end(); ++isVeto){
     if( (*isVeto) > Electron_Cut_pt){
        // electronisVeto_ ->Fill( *isVeto );
for(std::vector<float>::const_iterator missHits=electronmissHits->begin(); missHits!=electronmissHits->end(); ++missHits){
        if( (*missHits) > Electron_Cut_pt){
            // electronmissHits_ ->Fill( *missHits );
for(std::vector<float>::const_iterator Iso03=electronIso03->begin(); Iso03!=electronIso03->end(); ++Iso03){
            if( (*Iso03) > Electron_Cut_pt){
            // electronIso03_ ->Fill( *Iso03 );
  
          
              
            }}
        }}
     }}
      }}
      }}
    }}
    
           
       }
        

    
    
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


bool muonTightCuts(int n)
{
    bool muonPass = false;
    
    int Particle_Flow_Muon_Cut = 1;
    int Global_Muon_Cut = 1;
    int Tracker_Muon_Cut = 1;
    double Muon_Tight_Cut_pt = 20.0;
    double Muon_Tight_Cut_eta = 2.4;
    double Muon_Relative_Isolation_Cut = 0.20;
    
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

bool VertexCuts(int n)
{
    bool VertexPass = false;
    
    double Vtx_Cut_z = 24.0;
    int Vtx_Cut_ndof = 4;
    double Vtx_Cut_rho = 2.0;
    
    double VertexZ = floats_vertexInfo_z_b2gEDMNtuples_obj->at(n);
    int VertexDof = ints_vertexInfo_ndof_b2gEDMNtuples_obj->at(n);
    double VertexRho = floats_vertexInfo_rho_b2gEDMNtuples_obj->at(n);
    
    if( fabs(VertexZ)<Vtx_Cut_z && VertexDof>=Vtx_Cut_ndof && VertexRho<Vtx_Cut_rho ){
        VertexPass = true;
    }
    return VertexPass;
}








