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

//#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"


#include "PhysicsTools/FWLite/interface/TFileService.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h"

optutl::CommandLineParser parser ("Analyze FWLite Histograms");

  std::string outputFile_ = parser.stringValue("outputFile");

  fwlite::TFileService fs = fwlite::TFileService(outputFile_.c_str());

  TFileDirectory dir = fs.mkdir("analyzePatMuon");

  TH1F* electronPt_  = dir.make<TH1F>("electronPt"  , "pt"  ,   100,   0., 300.);
  TH1F* muonPt_  = dir.make<TH1F>("muonPt"  , "pt"  ,   100,   0., 300.);
int main(int argc, char* argv[])
{
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

  // set defaults
  parser.integerValue ("maxEvents"  ) = 1000;
  parser.integerValue ("outputEvery") =   10;
  parser.stringValue  ("outputFile" ) = "analyzeEdmTuple.root";

  // parse arguments
  parser.parseArguments (argc, argv);
  int maxEvents_ = parser.integerValue("maxEvents");
  unsigned int outputEvery_ = parser.integerValue("outputEvery");


  std::vector<std::string> inputFiles_ = parser.stringVector("inputFiles");

  // book a set of histograms

 // TH1F* muonEta_ = dir.make<TH1F>("muonEta" , "eta" ,   100,  -3.,   3.);
 // TH1F* muonPhi_ = dir.make<TH1F>("muonPhi" , "phi" ,   100,  -5.,   5.);

    std::cout<<"selected events are:"<<std::endl;

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
    int total_number_of_selected_events =0;
        std::vector<int> selected_event_number;
        
        int event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(int, edm::EventBase const & );
        int event_selection_based_on_only_opposite_charge_particles(int, int, edm::EventBase const & );

        
        bool want_to_select_event_based_on_loose_cuts_pass_matching_with_tight_cuts_pass = true;
        bool want_to_select_only_opposite_charge_particles = true;

      fwlite::Event ev(inFile);
      for(ev.toBegin(); !ev.atEnd(); ++ev, ++ievt){
	edm::EventBase const & event = ev;
	// break loop if maximal number of events is reached 
	if(maxEvents_>0 ? ievt+1>maxEvents_ : false) break;
	// simple event counter
	if(outputEvery_!=0 ? (ievt>0 && ievt%outputEvery_==0) : false) 
	  std::cout << "  processing event: " << (ievt+1) << std::endl;
          
          //call functions here
          
         // bool want_to_select_event_based_on_collective_type_of_Cuts_Passed_of_a_Particle = true;
         // bool want_to_select_event_based_on_tight_Cuts_Passed_of_a_Particle = true;
         // bool want_to_select_event_based_on_loose_Cuts_Passed_of_a_Particle = false;
         // bool want_to_select_only_opposite_charge_particles = true;
          
#define electron 11
#define muon 13
          
          //int event_selection_based_on_tight_Cuts_Passed(int);
        //  int event_selection_based_on_loose_Cuts_Passed(int);
         // int event_selection_based_on_only_opposite_charge_particles(int, int);
          
          if (want_to_select_event_based_on_loose_cuts_pass_matching_with_tight_cuts_pass)
          {
              if(event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(electron, event))
                  
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to mismatch between loose cuts and tight cuts pass "<< electron <<std::endl;
                  continue;
              }
              if(event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(muon, event))
                  
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to mismatch between loose cuts and tight cuts pass "<< muon <<std::endl;
                  continue;
              }
          }
          
          if (want_to_select_only_opposite_charge_particles)
          {
              if(event_selection_based_on_only_opposite_charge_particles(electron, muon, event))
                  
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to no opposite charge pair found of "<< electron <<" and "<< muon <<std::endl;
                  continue;
              }
          }

          selected_event_number.push_back((ievt+1));
          std::cout<<"selected event is: "<<(ievt+1)<<std::endl;
          total_number_of_selected_events++;
      }
        
        std::cout<<"total number of selected events "<<total_number_of_selected_events<<std::endl;
        
        // close input file
        inFile->Close();
    }
      // break loop if maximal number of events is reached:
      // this has to be done twice to stop the file loop as well
      if(maxEvents_>0 ? ievt+1>maxEvents_ : false) break;
  }
    return 0;
}
int event_selection_based_on_only_opposite_charge_particles(int particle1, int particle2, edm::EventBase const & event){
{
#define negative 0
#define positive 1
    
    int isopposite(std::vector<int>* , std::vector<int>* );
    std::vector<int>* storing_charge_of_particular_particle(int, edm::EventBase const & );
    if(isopposite(storing_charge_of_particle(particle1, type_of_charge, event), storing_charge_of_particle(particle2, type_of_charge, event))) return 0; //if select or found opposite pair
    return 1;//if not select or no opposite pair found
}

int isopposite(std::vector<int>* a, std::vector<int>* b)
{
    for(unsigned int i=0; i<(a->size()); i++)
    {
        for(unsigned int j=0; j<(b->size()); j++)
        {
        if (((*a)[i] * (*b)[j]) < 0) return 1; //if isopposite or found opposite pair
        }
    }
    return 0;
}
std::vector<int>* storing_charge_of_particle(int particle, int type_of_charge, edm::EventBase const & event)
    {
        std::vector<int>* serial_number_of_particle_stoted_in_event;
        serial_number_of_particle_stoted_in_event = new std::vector<int> ;
        
        // Handle to the electron charge
        edm::Handle<std::vector<float> > electronCharge;
        event.getByLabel(std::string("electrons:elCharge"), electronCharge);
        // Handle to the muon charge
        edm::Handle<std::vector<float> > muonCharge;
        event.getByLabel(std::string("muons:muCharge"), muonCharge);

        // loop electron, muon collection and fill histogram of electrons and muons charge and tell index number of electrons and muons
        int i = 0;
        
        if(particle == 11){
        for(std::vector<float>::const_iterator charge=electronCharge->begin(); charge!=electronCharge->end(); ++charge){
            i++;
            serial_number_of_particle_stoted_in_event->push_back(i);
        }}
        
        
        
        
        if(particle == 13){
            for(std::vector<float>::const_iterator charge=muonCharge->begin(); charge!=muonCharge->end(); ++charge){
                i++;
                serial_number_of_particle_stoted_in_event->push_back(i);
            }}
        return serial_number_of_particle_stoted_in_event;
    }
    
    
            
            

    
    
    
    
   
    
    
    
int event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(int particle, edm::EventBase const & event)
{
    int loose_cuts_pass_matching_with_tight_cuts_pass(int, edm::EventBase const & );
    int iszero(std::vector<int>* );
    std::vector<int>* collective_cuts(int, int, edm::EventBase const & );
    if ((iszero(collective_cuts(particle, 1, event)))) return 1;//event not select
    if(loose_cuts_pass_matching_with_tight_cuts_pass(particle, event)) return 0;//event select
    return 1;//if not select or not matches
}

int iszero(std::vector<int>* a){
    for(unsigned int i=0; i<(a->size()); i++)
    {
        if ((*a)[i] != 0) return 0;
    }
    return 1;
}

int loose_cuts_pass_matching_with_tight_cuts_pass(int particle, edm::EventBase const & event){
#define loose 0
#define tight 1
    
    int isequal(std::vector<int>* , std::vector<int>* );
    std::vector<int>* collective_cuts(int, int, edm::EventBase const & );
    if(isequal(collective_cuts(particle, loose, event), collective_cuts(particle, tight, event))) return 1; //if matches
    else return 0;//if not matches
}

int isequal(std::vector<int>* a, std::vector<int>* b)
{
    if(a->size() != b->size()) return 0;
    for(unsigned int i=0; i<(a->size()); i++)
    {
        if ((*a)[i] != (*b)[i]) return 0;
    }
    return 1;
}

std::vector<int>* collective_cuts(int particle, int type_of_cut, edm::EventBase const & event){
    std::vector<int>* electronCuts(int, edm::EventBase const & );
    std::vector<int>* muonCuts(int, edm::EventBase const & );
    if(particle == 11) return electronCuts(type_of_cut, event);
    if(particle == 13) return muonCuts(type_of_cut, event);
    return 0;
}

std::vector<int>* electronCuts(int type_of_cut, edm::EventBase const & event)
{
    std::vector<int>* serial_number_of_passed_particle_in_event;
    serial_number_of_passed_particle_in_event = new std::vector<int> ;
    
    double Electron_Cut_pt = 0.0;
    double Electron_Cut_eta = 0.0;
    double Transverse_Impact_Parameter_Cut = 0.0;
    int Passing_Conversion_Veto_Electron_Cut = 0;
    
    int Electron_Missing_Hits_Cut = 0;
    double Electron_Relative_Isolation_Cut = 0.0;
    
    if(type_of_cut == 1)
    {
         Electron_Cut_pt = 20.0;
         Electron_Cut_eta = 2.5;
         Transverse_Impact_Parameter_Cut = 0.04;
         Passing_Conversion_Veto_Electron_Cut = 1;
        
         Electron_Missing_Hits_Cut = 0;
         Electron_Relative_Isolation_Cut = 0.15;
    }
    if(type_of_cut == 0)
    {
        Electron_Cut_pt = 10.0;
        Electron_Cut_eta = 2.5;
        Transverse_Impact_Parameter_Cut = 0.04;
        Passing_Conversion_Veto_Electron_Cut = 1;
        
        Electron_Missing_Hits_Cut = 0;
        Electron_Relative_Isolation_Cut = 0.15;
    }
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
    
    // loop electron collection and test cut and fill histogram of passed electrons pt and tell index number of passed electrons
    int i = 0;
    
    for(std::vector<float>::const_iterator pt=electronPt->begin(); pt!=electronPt->end(); ++pt){
        i++;
        if( (*pt) > Electron_Cut_pt){
            // electronPt_ ->Fill( *pt );
            for(std::vector<float>::const_iterator eta=electronEta->begin(); eta!=electronEta->end(); ++eta){
                if( (*eta) < Electron_Cut_eta){
                    //  electronEta_ ->Fill( *eta );
                    for(std::vector<float>::const_iterator Dxy=electronDxy->begin(); Dxy!=electronDxy->end(); ++Dxy){
                        if( (*Dxy) < Transverse_Impact_Parameter_Cut){
                            // electronDxy_ ->Fill( *Dxy );
                            for(std::vector<float>::const_iterator isVeto=electronisVeto->begin(); isVeto!=electronisVeto->end(); ++isVeto){
                                if( (*isVeto) == Passing_Conversion_Veto_Electron_Cut){
                                    // electronisVeto_ ->Fill( *isVeto );
                                    for(std::vector<float>::const_iterator missHits=electronmissHits->begin(); missHits!=electronmissHits->end(); ++missHits){
                                        if( (*missHits) == Electron_Missing_Hits_Cut){
                                            // electronmissHits_ ->Fill( *missHits );
                                            for(std::vector<float>::const_iterator Iso03=electronIso03->begin(); Iso03!=electronIso03->end(); ++Iso03){
                                                if( (*Iso03) < Electron_Relative_Isolation_Cut){
                                                    serial_number_of_passed_particle_in_event->push_back(i);
                                                    // cut_passed_electrons ->Fill( *Iso03 );
                                                     electronPt_ ->Fill( *pt );

                                                }}
                                        }}
                                }}
                        }}
                }}
        }}
    return serial_number_of_passed_particle_in_event;
}

std::vector<int>* muonCuts(int type_of_cut, edm::EventBase const & event)
{
    std::vector<int>* serial_number_of_passed_particle_in_event;
    serial_number_of_passed_particle_in_event = new std::vector<int> ;
    
    int Particle_Flow_Muon_Cut = 0;
    int Global_Muon_Cut = 0;
    int Tracker_Muon_Cut = 0;
    double Muon_Tight_Cut_pt = 0.0;
    double Muon_Tight_Cut_eta = 0.0;
    double Muon_Relative_Isolation_Cut = 0.0;
    
    if(type_of_cut == 1)
    {
         Particle_Flow_Muon_Cut = 1;
         Global_Muon_Cut = 1;
         Tracker_Muon_Cut = 1;
         Muon_Tight_Cut_pt = 20.0;
         Muon_Tight_Cut_eta = 2.4;
         Muon_Relative_Isolation_Cut = 0.20;
    }
    if(type_of_cut == 0)
    {
        Particle_Flow_Muon_Cut = 1;
        Global_Muon_Cut = 1;
        Tracker_Muon_Cut = 1;
        Muon_Tight_Cut_pt = 10.0;
        Muon_Tight_Cut_eta = 2.5;
        Muon_Relative_Isolation_Cut = 0.20;
    }
    // Handle to the muon ParticleFlow
    edm::Handle<std::vector<float> > ParticleFlow;
    event.getByLabel(std::string("muons:muIsPFMuon"), ParticleFlow);
    // Handle to the muon GlobalMuon
    edm::Handle<std::vector<float> > GlobalMuon;
    event.getByLabel(std::string("muons:muIsGlobalMuon"), GlobalMuon);
    // Handle to the muon TrackerMuon
    edm::Handle<std::vector<float> > TrackerMuon;
    event.getByLabel(std::string("muons:muIsTrackerMuon"), TrackerMuon);
    // Handle to the muon muonPt
    edm::Handle<std::vector<float> > muonPt;
    event.getByLabel(std::string("muons:muPt"), muonPt);
    // Handle to the muon muonEta
    edm::Handle<std::vector<float> > muonEta;
    event.getByLabel(std::string("muons:muEta"), muonEta);
    // Handle to the muon muonIso04
    edm::Handle<std::vector<float> > muonIso04;
    event.getByLabel(std::string("muons:muIso04"), muonIso04);
    
    // loop muon collection and test cut and fill histogram of passed muons pt and tell index number of passed muons
    int i = 0;
    
    for(std::vector<float>::const_iterator pf=ParticleFlow->begin(); pf!=ParticleFlow->end(); ++pf){
        i++;
        if( (*pf) == Particle_Flow_Muon_Cut){
            for(std::vector<float>::const_iterator gm=GlobalMuon->begin(); gm!=GlobalMuon->end(); ++gm){
                if( (*gm) == Global_Muon_Cut){
                    for(std::vector<float>::const_iterator tm=TrackerMuon->begin(); tm!=TrackerMuon->end(); ++tm){
                        if( (*tm) == Tracker_Muon_Cut){
                            for(std::vector<float>::const_iterator pt=muonPt->begin(); pt!=muonPt->end(); ++pt){
                                if( (*pt) > Muon_Tight_Cut_pt){
                                    for(std::vector<float>::const_iterator eta=muonEta->begin(); eta!=muonEta->end(); ++eta){
                                        if( (*eta) < Muon_Tight_Cut_eta){
                                            for(std::vector<float>::const_iterator Iso04=muonIso04->begin(); Iso04!=muonIso04->end(); ++Iso04){
                                                if( (*Iso04) < Muon_Relative_Isolation_Cut){
                                                    serial_number_of_passed_particle_in_event->push_back(i);
                                                    muonPt_ ->Fill( *pt );
                                                }}
                                        }}
                                }}
                        }}
                }}
        }}
    return serial_number_of_passed_particle_in_event;
}












