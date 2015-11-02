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
using namespace std;


#include "Electron.hh"
#include "Muon.hh"
#include "ElectronMuon.hh"
#include "ElectronMuonExtraLoose.hh"

#include "Met.hh"

class ElectronMuonMet
{
    struct MetDATA
    {
        
        float  pt;
        bool   ptc;
    };

	struct DATA{
		int evtID;
		float metPt;

	};

	vector<DATA>* v;
public:
	ElectronMuonMet()
	{
		v = new vector<DATA>;
	}

    vector<DATA>* setData(ElectronMuonExtraLoose& emel, Met& met)
    {
        int rejected_met = 0;
        for(unsigned int i=0;i<emel.v->size();i++)
        {
            int evtID=((emel.v)->at(i)).evtID;
            vector<MetDATA>* dv = (vector<MetDATA>*) met.v.at(evtID);
	 
	   for(unsigned int j=0;j<dv->size();j++)
            {
                MetDATA metd =(MetDATA) dv->at(j);
               if(metd.ptc==true)
                                {
                                    DATA d ={evtID,metd.pt};
                                    v->push_back(d);
                                    cout<<"MET:EventID"<<evtID<<", MetID:"<<j<<"PT:"<<metd.pt<<", ptc:"<<metd.ptc<<endl;
                                }
               else rejected_met++;
            }
            
        }
        cout<<"total number of rejected events due to no met passing cut"<<rejected_met<<endl;
        return v;
    }
    
    void fillHisto(const char* outputFile)
    {
      //  vector<DATA>* dv;
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService("met.root");
        TFileDirectory dir = fs.mkdir("met");
        TH1F* metPt_  = dir.make<TH1F>("metPt_"  , "pt"  ,   100,   0., 400.);
        
        for(unsigned int i=0; i < v->size(); i++)
        {
                d=v->at(i);
                metPt_->Fill(d.metPt);
            
        }
        return;
    }
    
    ~ElectronMuonMet()
    {
        delete v;
        v=0;
    }
};

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
 // parser.integerValue ("maxEvents"  ) = 1000;
//  parser.integerValue ("outputEvery") =   10;
  parser.stringValue  ("outputFile" ) = "analyzeEdmTuple.root";

  // parse arguments
  parser.parseArguments (argc, argv);
 // int maxEvents_ = parser.integerValue("maxEvents");
  //unsigned int outputEvery_ = parser.integerValue("outputEvery");
  std::string outputFile_ = parser.stringValue("outputFile");
  std::vector<std::string> inputFiles_ = parser.stringVector("inputFiles");

  // book a set of histograms
    fwlite::TFileService fs = fwlite::TFileService(outputFile_.c_str());
    TFileDirectory dir = fs.mkdir("analyzePatMuon");

 // TH1F* muonEta_ = dir.make<TH1F>("muonEta" , "eta" ,   100,  -3.,   3.);
 // TH1F* muonPhi_ = dir.make<TH1F>("muonPhi" , "phi" ,   100,  -5.,   5.);

  // loop the events
 // int ievt=0;  

    Electron obe;
    

    obe.setData(inputFiles_[0].c_str());
    obe.fillHisto(outputFile_.c_str());
    
   //obe.printData(0,"Primary Events information.");
    
    
    
    Electron obfe(obe.selectData());
 
    //obfe.printData(0,"Filltered Events information.");
    
    
    Muon obm;
    obm.setData(inputFiles_[0].c_str());
    obm.fillHisto(outputFile_.c_str());
    
   // obm.printData(0,"Primary Events information for MUON.");
    
    
    Muon obfm(obm.selectData());
    //obfm.printData(0,"Filltered Events information for MUON.");
    
    ElectronMuon em;
    em.setData(obfe,obfm);
    
    ElectronMuonExtraLoose emel;
    emel.setData(em,obe,obm);
    
    Met obmet;
    obmet.setData(inputFiles_[0].c_str());
   // obmet.fillHisto(outputFile_.c_str());
    
    obmet.printData(0);
    
    
    ElectronMuonMet obEMM;
    
    obEMM.setData(emel,obmet);
    obEMM.fillHisto(outputFile_.c_str());

    
    return 0;
    
    ////////////////
}
/*

        int total_number_of_selected_events =0;
        std::vector<int> selected_event_number;
   
        bool final_state_is_electron_muon = true;
        bool final_state_is_electron_electron = false;
        bool final_state_is_muon_muon = false;
        
        bool want_to_select_event_based_on_vertex_cuts_pass = true;
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
        
        
	// break loop if maximal number of events is reached 
	if(maxEvents_>0 ? ievt+1>maxEvents_ : false) break;
	// simple event counter
	if(outputEvery_!=0 ? (ievt>0 && ievt%outputEvery_==0) : false) 
	  std::cout << "  processing event: " << (ievt+1) << std::endl;
        std::cout << " event number : " << (ievt+1) << std::endl;  
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
                             // electronPt_ ->Fill((*a)[i]);
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
                             // electronPt_ ->Fill((*a)[i]);
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
                          std::vector<float>* b = collective_cuts_pt(muon, tight, event);
                          for(unsigned int i=0; i<b->size(); i++)
                          {
                             // muonPt_ ->Fill((*b)[i]);
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
                                //  muonPt_ ->Fill((*b)[i]);
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
         // std::cout<<"selected event is: "<<(ievt+1)<<std::endl;
          total_number_of_selected_events++;
      }*/
        
 /*       std::cout<<"total number of selected events "<<total_number_of_selected_events<<std::endl;
        
        // close input file
        inFile->Close();
    }
      // break loop if maximal number of events is reached:
      // this has to be done twice to stop the file loop as well
      if(maxEvents_>0 ? ievt+1>maxEvents_ : false) break;
  }
    return 0;
}*/
/*
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
    for(unsigned int i=0;i<(vtxZ->size());i++){
        if((vtxZ)->at(i) < Vtx_Cut_z){
            if((dof->at(i)) > Vtx_Cut_ndof){
                if((rhoo)->at(i) < Vtx_Cut_rho){
                    serial_number_of_passed_vertices_in_event->push_back((i+1));
                }}}}
   
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

int event_selection_based_on_tight_cuts_particles(int particle, edm::EventBase const & event)
    {
        int iszero(std::vector<int>* );
        std::vector<int>* collective_cuts(int, int, edm::EventBase const & );
        if ((iszero(collective_cuts(particle, 1, event)))) return 1;//event not select or not pass
        else return 0;//event select or pass
    }

int iszero(std::vector<int>* a)
{
    if(a->size() == 0) return 1;
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
}*/

                        
                        


