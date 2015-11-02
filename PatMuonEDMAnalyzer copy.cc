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

#include "DataFormats/PatCandidates/interface/Electron.h"


#include "PhysicsTools/FWLite/interface/TFileService.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h"


  TH1F* electronPt_;
  TH1F* muonPt_;
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
    electronPt_  = dir.make<TH1F>("electronPt"  , "pt"  ,   100,   0., 300.);
    muonPt_  = dir.make<TH1F>("muonPt"  , "pt"  ,   100,   0., 300.);
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
   
        bool final_state_is_electron_muon = true;
        bool final_state_is_electron_electron = false;
        bool final_state_is_muon_muon = false;
        
        bool want_to_select_event_based_on_vertex_cuts_pass = false;
        bool want_to_select_only_opposite_charge_particles = true;
        bool want_to_select_event_based_on_tight_cuts_pass = true;
        bool want_to_select_event_based_on_loose_cuts_pass_matching_with_tight_cuts_pass = true;
        
        bool want_to_fill_pt_of_selected_event = true;
        bool based_on_tight_cuts_pass = true;
        bool based_on_matching_of_tight_cuts_with_loose_cuts = false;

        std::vector<float>* collective_cuts_pt(int, int, edm::EventBase const & );
        int isequal(std::vector<int>* , std::vector<int>* );
        std::vector<int>* collective_cuts(int, int, edm::EventBase const & );
        int event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(int, edm::EventBase const & );
        int event_selection_based_on_only_opposite_charge_particles(int, int, edm::EventBase const & );
        int event_selection_based_on_tight_cuts_particles(int, edm::EventBase const & );
        int event_selection_based_on_vertex_cuts(edm::EventBase const & );
        

      fwlite::Event ev(inFile);
      for(ev.toBegin(); !ev.atEnd(); ++ev, ++ievt){
	edm::EventBase const & event = ev;
	// break loop if maximal number of events is reached 
	if(maxEvents_>0 ? ievt+1>maxEvents_ : false) break;
	// simple event counter
	if(outputEvery_!=0 ? (ievt>0 && ievt%outputEvery_==0) : false) 
	  std::cout << "  processing event: " << (ievt+1) << std::endl;
          
#define electron 11
#define muon 13
#define loose 0
#define tight 1
          
          if (want_to_fill_pt_of_selected_event)
          {
              if(final_state_is_electron_muon || final_state_is_electron_electron)
              {
                  if(based_on_tight_cuts_pass)
                  {
                      if(event_selection_based_on_tight_cuts_particles(electron, event) == 0)
                      {
                          // fill electron pt here
                          std::vector<float>* a = collective_cuts_pt(electron, tight, event);
                          for(unsigned int i=0; i<a->size(); i++)
                          {
                              electronPt_ ->Fill((*a)[i]);
                          }
                      }
                  }
                  if(based_on_matching_of_tight_cuts_with_loose_cuts)
                  {
                      if(event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(electron, event) == 0)
                      {
                          // fill electron pt here
                          std::vector<float>* a = collective_cuts_pt(electron, tight, event);
                          if(isequal(collective_cuts(electron, loose, event), collective_cuts(electron, tight, event)))
                          {
                          for(unsigned int i=0; i<a->size(); i++)
                          {
                              electronPt_ ->Fill((*a)[i]);
                          }
                          }
                      }
                  }
              }
              if(final_state_is_electron_muon || final_state_is_muon_muon)
              {
                  if(based_on_tight_cuts_pass)
                  {
                      if(event_selection_based_on_tight_cuts_particles(muon, event) == 0)
                      {
                          // fill muon pt here
                          std::vector<float>* b = collective_cuts_pt(electron, tight, event);
                          for(unsigned int i=0; i<b->size(); i++)
                          {
                              muonPt_ ->Fill((*b)[i]);
                          }
                      }
                  }
                  if(based_on_matching_of_tight_cuts_with_loose_cuts)
                  {
                      if(event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(muon, event) == 0)
                      {
                          // fill muon pt here
                          std::vector<float>* b = collective_cuts_pt(muon, tight, event);
                          if(isequal(collective_cuts(muon, loose, event), collective_cuts(muon, tight, event)))
                          {
                              for(unsigned int i=0; i<b->size(); i++)
                              {
                                  muonPt_ ->Fill((*b)[i]);
                              }
                          }
                      }
                  }
              }
          }
          
          if (want_to_select_event_based_on_vertex_cuts_pass)
          {
                  if(event_selection_based_on_vertex_cuts(event))
                  {
                      std::cout<<"event "<< (ievt+1) <<" rejected due to failing of vertex cuts" <<std::endl;
                      continue;
                  }
          }
          
          if (want_to_select_only_opposite_charge_particles)
          {
              if(final_state_is_electron_muon)
              {
              if(event_selection_based_on_only_opposite_charge_particles(electron, muon, event))
                  
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to no opposite charge pair found of electron and muon" <<std::endl;
                  continue;
              }
              }
              if(final_state_is_electron_electron)
              {
                  if(event_selection_based_on_only_opposite_charge_particles(electron, electron, event))
                      
                  {
                      std::cout<<"event "<< (ievt+1) <<" rejected due to no opposite charge pair found of electron and electron" <<std::endl;
                      continue;
                  }
              }
              if(final_state_is_muon_muon)
              {
                  if(event_selection_based_on_only_opposite_charge_particles(muon, muon, event))
                      
                  {
                      std::cout<<"event "<< (ievt+1) <<" rejected due to no opposite charge pair found of muon and muon" <<std::endl;
                      continue;
                  }
              }
          }
          
          if (want_to_select_event_based_on_tight_cuts_pass)
          {
              if(final_state_is_electron_muon || final_state_is_electron_electron)
              {
              if(event_selection_based_on_tight_cuts_particles(electron, event))
                  
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to no electron passing the tight cuts" <<std::endl;
                  continue;
              }
              }
              if(final_state_is_electron_muon || final_state_is_muon_muon)
              {
              if(event_selection_based_on_tight_cuts_particles(muon, event))
                  
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to no muon passing the tight cuts" <<std::endl;
                  continue;
              }
              }
          }
          
          if (want_to_select_event_based_on_loose_cuts_pass_matching_with_tight_cuts_pass)
          {
              if(final_state_is_electron_muon || final_state_is_electron_electron)
              {
              if(event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(electron, event))
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to mismatch between loose cuts and tight cuts pass of electron" <<std::endl;
                  continue;
              }
          }
          if(final_state_is_electron_muon || final_state_is_muon_muon)
          {

              if(event_selection_based_on_loose_cuts_pass_matching_with_tight_cuts_pass(muon, event))
                  
              {
                  std::cout<<"event "<< (ievt+1) <<" rejected due to mismatch between loose cuts and tight cuts pass muon" <<std::endl;
                  continue;
              }
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

std::vector<float>* collective_cuts_pt(int particle, int type_of_cut, edm::EventBase const & event)
{
    std::vector<void*>* electronCuts(int, edm::EventBase const & );
    std::vector<void*>* muonCuts(int, edm::EventBase const & );
    
    if(particle == 11){
        std::vector<void*>* e = electronCuts(type_of_cut, event);
        std::vector<float>* pt_of_passed_particle_in_event = (std::vector<float>*) (*e)[1];
        return pt_of_passed_particle_in_event;
    }
    if(particle == 13){
        std::vector<void*>* m = muonCuts(type_of_cut, event);
        std::vector<float>* pt_of_passed_particle_in_event = (std::vector<float>*) (*m)[1];
        return pt_of_passed_particle_in_event;
    }
    return 0;
}

int event_selection_based_on_vertex_cuts(edm::EventBase const & event)
{
    int iszero(std::vector<int>* );
    std::vector<int>* cuts_of_vertices(edm::EventBase const & );
    if ((iszero(cuts_of_vertices(event)))) return 1;//event not select or not pass
    else return 0;//event select or pass
}

std::vector<int>* cuts_of_vertices(edm::EventBase const & event)
{
    std::vector<int>* serial_number_of_passed_vertices_in_event;
    serial_number_of_passed_vertices_in_event = new std::vector<int> ;
    
    double Vtx_Cut_z = 24.0;
    int Vtx_Cut_ndof = 4;
    double Vtx_Cut_rho = 2.0;
    
    // Handle to the z of vertex
    edm::Handle<std::vector<float> > vtxZ;
    event.getByLabel(std::string("vertexInfo:z"), vtxZ);
    // Handle to the dof of vertex
    edm::Handle<std::vector<int> > dof;
    event.getByLabel(std::string("vertexInfo:ndof"), dof);
    // Handle to the rho
    edm::Handle<std::vector<float> > rhoo;
    event.getByLabel(std::string("vertexInfo:rho"), rhoo);
    
    // loop vertex collection and test cut and fill histogram of passed vertex fabs(VertexZ)
    int i = 0;
    
    for(std::vector<float>::const_iterator zz=vtxZ->begin(); zz!=vtxZ->end(); ++zz){
        i++;
        if( fabs(*zz) < Vtx_Cut_z){
            for(std::vector<int>::const_iterator df=dof->begin(); df!=dof->end(); ++df){
                if( (*df) > Vtx_Cut_ndof){
                    for(std::vector<float>::const_iterator ro=rhoo->begin(); ro!=rhoo->end(); ++ro){
                        if( (*ro) < Vtx_Cut_rho){
                            serial_number_of_passed_vertices_in_event->push_back(i);
                 
                        }}
                }}
        }}
    return serial_number_of_passed_vertices_in_event;
}

int event_selection_based_on_only_opposite_charge_particles(int particle1, int particle2, edm::EventBase const & event)
{
    int isopposite(std::vector<void*>* , std::vector<void*>* );
    std::vector<void*>* storing_charge_of_particle(int, edm::EventBase const & );
    if(isopposite(storing_charge_of_particle(particle1, event), storing_charge_of_particle(particle2, event))) return 0; //if select or found opposite pair
    return 1;//if not select or no opposite pair found
}

int isopposite(std::vector<void*>* c, std::vector<void*>* d){
    std::vector<float>* a = (std::vector<float>*) (*c)[1];
    std::vector<float>* b = (std::vector<float>*) (*d)[1];
    for(unsigned int i=0; i<(a->size()); i++)
    {
        for(unsigned int j=0; j<(b->size()); j++)
        {
            if (((*a)[i] * (*b)[j]) < 0) return 1; //if isopposite or found opposite pair
        }
    }
    return 0;
}

std::vector<void*>* storing_charge_of_particle(int particle, edm::EventBase const & event)
    {
        std::vector<void*>* pointer_to_arrays;
        std::vector<int>* serial_number_of_particle_stoted_in_event;
        std::vector<float>* charge_of_particle_in_event;
        
        pointer_to_arrays = new std::vector<void*> ;
        serial_number_of_particle_stoted_in_event = new std::vector<int> ;
        charge_of_particle_in_event = new std::vector<float> ;
        
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
            charge_of_particle_in_event->push_back(*charge);
        }}
        
        if(particle == 13){
            for(std::vector<float>::const_iterator charge=muonCharge->begin(); charge!=muonCharge->end(); ++charge){
                i++;
                serial_number_of_particle_stoted_in_event->push_back(i);
                charge_of_particle_in_event->push_back(*charge);
            }}
        pointer_to_arrays->push_back(serial_number_of_particle_stoted_in_event);
        pointer_to_arrays->push_back(charge_of_particle_in_event);
        
        return pointer_to_arrays;
    }   
  
int event_selection_based_on_tight_cuts_particles(int particle, edm::EventBase const & event)
    {
        int iszero(std::vector<int>* );
        std::vector<int>* collective_cuts(int, int, edm::EventBase const & );
        if ((iszero(collective_cuts(particle, 1, event)))) return 1;//event not select or not pass
        else return 0;//event select or pass
    }
int iszero(std::vector<int>* a)
    {
        for(unsigned int i=0; i<(a->size()); i++)
        {
            if ((*a)[i] != 0) return 0;
        }
        return 1;
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

std::vector<int>* collective_cuts(int particle, int type_of_cut, edm::EventBase const & event)
{
    std::vector<void*>* electronCuts(int, edm::EventBase const & );
    std::vector<void*>* muonCuts(int, edm::EventBase const & );

    if(particle == 11){
        std::vector<void*>* e = electronCuts(type_of_cut, event);
        std::vector<int>* serial_number_of_passed_particle_in_event = (std::vector<int>*) (*e)[0];
        return serial_number_of_passed_particle_in_event;
    }
    if(particle == 13){
        std::vector<void*>* m = muonCuts(type_of_cut, event);
        std::vector<int>* serial_number_of_passed_particle_in_event = (std::vector<int>*) (*m)[0];
        return serial_number_of_passed_particle_in_event;
    }
    return 0;
}

std::vector<void*>* electronCuts(int type_of_cut, edm::EventBase const & event)
{
    std::vector<void*>* pointer_to_arrays;
    std::vector<int>* serial_number_of_passed_particle_in_event;
    std::vector<float>* pt_of_passed_particle_in_event;
    
    pointer_to_arrays = new std::vector<void*> ;
    serial_number_of_passed_particle_in_event = new std::vector<int> ;
    pt_of_passed_particle_in_event = new std::vector<float> ;
    
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
                                                    pt_of_passed_particle_in_event->push_back(*pt);
                                                    // electronPt_ ->Fill( *pt );

                                                }}
                                        }}
                                }}
                        }}
                }}
        }}
    pointer_to_arrays->push_back(serial_number_of_passed_particle_in_event);
    pointer_to_arrays->push_back(pt_of_passed_particle_in_event);
    
    return pointer_to_arrays;
}

std::vector<void*>* muonCuts(int type_of_cut, edm::EventBase const & event){
    std::vector<void*>* pointer_to_arrays;
    std::vector<int>* serial_number_of_passed_particle_in_event;
    std::vector<float>* pt_of_passed_particle_in_event;

    pointer_to_arrays = new std::vector<void*> ;
    serial_number_of_passed_particle_in_event = new std::vector<int>() ;
    pt_of_passed_particle_in_event = new std::vector<float> ;
    
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
                                                    pt_of_passed_particle_in_event->push_back(*pt);
                                                   // muonPt_ ->Fill( *pt );
                                                }}
                                        }}
                                }}
                        }}
                }}
        }}
    pointer_to_arrays->push_back(serial_number_of_passed_particle_in_event);
    pointer_to_arrays->push_back(pt_of_passed_particle_in_event);
    
    return pointer_to_arrays;
}



