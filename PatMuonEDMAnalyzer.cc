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

class Electron
{
    struct CUT
    {
        bool   etac,ptc,dxyc,vetoc,mhitsc,isoc,all;
    };
    struct DATA
    {
        
        float  eta,pt,dxy,veto,mhits,iso,charge;
        CUT    loose,tight;
    };
    
    vector<vector<DATA>*>*  v;
    
public:
    Electron()
    {
        v = new vector<vector<DATA>*>;
    }
    Electron(vector<vector<DATA>*>* uv)
    {
        
        v=uv;
    }
    
    void setData(const char* fname)
    {
        TFile* inFile = TFile::Open(fname);
        
        if(!inFile)
        {
            cout<<"Input Root File not open in electron class for processing"<<endl;
            return;
        }
        
        fwlite::Event ev(inFile);
        int evtID=0;
        
        for(ev.toBegin(); !ev.atEnd(); ++ev, evtID++)
        {
            edm::EventBase const & event = ev;
            
            // Handle to the electron pt
            edm::Handle<std::vector<float> > electronPt;
            event.getByLabel(std::string("electrons:elPt"), electronPt);
            // Handle to the electron eta
            edm::Handle<std::vector<float> > electronEta;
            event.getByLabel(std::string("electrons:elEta"), electronEta);
            // Handle to the electron impact parameter
            edm::Handle<std::vector<float> > electronDxy;
            event.getByLabel(std::string("electrons:elDxy"), electronDxy);
            // Handle to the electron veto
            edm::Handle<std::vector<float> > electronisVeto;
            event.getByLabel(std::string("electrons:elisVeto"), electronisVeto);
            // Handle to the electron missing hits
            edm::Handle<std::vector<float> > electronmissHits;
            event.getByLabel(std::string("electrons:elmissHits"), electronmissHits);
            // Handle to the electron isolation of cone of radius 0.04
            edm::Handle<std::vector<float> > electronIso03;
            event.getByLabel(std::string("electrons:elIso03"), electronIso03);
            // Handle to the electron charge
            edm::Handle<std::vector<float> > electronCharge;
            event.getByLabel(std::string("electrons:elCharge"), electronCharge);
            
            
            vector<DATA>* dv = new vector<DATA>;
            DATA d;
            
            for(unsigned int i=0;i<electronPt->size();i++)
            {
                d.pt = electronPt->at(i);
                d.eta = electronEta->at(i);
                d.dxy = electronDxy->at(i);
                d.veto = electronisVeto->at(i);
                d.mhits = electronmissHits->at(i);
                d.iso  = electronIso03->at(i);
                d.charge = electronCharge->at(i);
                
                dv->push_back(d);
                
            }
            
          
            v->push_back(dv);
            
        }
        inFile->Close();
        
        setCuts();
        
        return;
    }
    
    void printData(int p,string msg)

    {
        vector<DATA>* dv;
        DATA d;
	int te=0;
	int tevt=0;
        
        cout<<msg<<endl;
        
        for(unsigned int i=0; i < v->size(); i++)
        {
            dv=v->at(i);
//cout<<i<<","<<dv->size()<<endl;
	if(dv->size()!=0)tevt++;
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
               if(p==1 || p==0) cout<<"Event ID:"<<i<<", Electron ID:"<<j<<","<<" Pt:"<<d.pt<<", Eta:"<<d.eta<<", DXY:"<<d.dxy<<", Veto:"<<d.veto<<", MHits:"<<d.mhits<<", ISO:"<<d.iso<<", charge:"<<d.charge<<endl;
                
                if(p==2||p==0)
                {
                    cout<<"TCEvent ID:"<<i<<", Electron ID:"<<j<<","<<" Ptc:"<<d.tight.ptc<<", Etac:"<<d.tight.etac<<", DXYc:"<<d.tight.dxyc<<", Vetoc:"<<d.tight.vetoc<<", MHitsc:"<<d.tight.mhitsc<<", ISOc:"<<d.tight.isoc<<",allc:"<<d.tight.all<<endl;
                }
                if(p==3 || p==0)
                {
                    cout<<"LCEvent ID:"<<i<<", Electron ID:"<<j<<","<<" Ptc:"<<d.loose.ptc<<", Etac:"<<d.loose.etac<<", DXYc:"<<d.loose.dxyc<<", Vetoc:"<<d.loose.vetoc<<", MHitsc:"<<d.loose.mhitsc<<", ISOc:"<<d.loose.isoc<<",allc:"<<d.loose.all<<endl;
                }
		te++;
            }
            
        }
        
    	cout<<"Total electrons:"<<te<<" Total non empty events:"<<tevt<<endl;
return;    
}
    vector<vector<DATA>*>* selectData()
    {
        vector<DATA>* dv;
        DATA d;

        vector<vector<DATA>*>* fv = new vector<vector<DATA>*>;

        for(unsigned int i=0; i < v->size(); i++)
        {
            vector<DATA>* fdv= new vector<DATA>;
            
            dv=v->at(i);
            
            bool isEventSelected=true;
            int tightCount=0;
            
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                
                if(d.tight.all)tightCount++;
                
                if(!(  (d.tight.all==true && d.loose.all==true)  || (d.tight.all==false && d.loose.all==false) ))
                {
                   // cout<<i<<" Reject1\n";
                    isEventSelected=false;
                    break;
                }
                    
            }
            
            if(tightCount==0){isEventSelected=false;//cout<<i<<" Reject2\n";
		}
            //-----------------------
            if(isEventSelected)
            {
                
                for(unsigned int j=0;j<dv->size();j++)
                {
                    d=dv->at(j);
                    
                   
                    if(d.tight.all==true && d.loose.all==true)
                    {
                        //cout<<"SEventID:"<<i<<"SElectronID:"<<j<<endl;
                        fdv->push_back(d);
                    }
                    
                }
                
            }
            //-------------------------
            fv->push_back(fdv);
        }
        return fv;
    }
    void fillHisto(const char* outputFile)
    {
        vector<DATA>* dv;
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService(outputFile);
        TFileDirectory dir = fs.mkdir("analyzePatMuon");
        TH1F* electronPt_  = dir.make<TH1F>("electronPt_"  , "pt"  ,   100,   0., 400.);
        
        for(unsigned int i=0; i < v->size(); i++)
        {
            dv=v->at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                if(d.tight.all)
                electronPt_->Fill(d.pt);
                
            }
            
            
        }
        return;
    }
    void setCuts()
    {
        
        vector<DATA>* dv;
        
        
       float tElectron_Cut_pt = 20.0;
       float tElectron_Cut_eta = 2.5;
       float tTransverse_Impact_Parameter_Cut = 0.04;
       float tPassing_Conversion_Veto_Electron_Cut = 1;
        
       float tElectron_Missing_Hits_Cut = 0;
       float tElectron_Relative_Isolation_Cut = 0.15;
       
        
        
        float lElectron_Cut_pt = 10.0;
        float lElectron_Cut_eta = 2.5;
        float lTransverse_Impact_Parameter_Cut = 0.04;
        float lPassing_Conversion_Veto_Electron_Cut = 1;
        
        float lElectron_Missing_Hits_Cut = 0;
        float lElectron_Relative_Isolation_Cut = 0.15;
        
        for(unsigned int i=0; i < v->size(); i++)
        {
            dv=v->at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                DATA& d=dv->at(j);
                
                d.tight.ptc = (d.pt > tElectron_Cut_pt)?true:false;
                d.tight.etac = (fabs( d.eta )< tElectron_Cut_eta)?true:false;
                d.tight.dxyc = (d.dxy < tTransverse_Impact_Parameter_Cut)?true:false;
                d.tight.vetoc = (d.veto == tPassing_Conversion_Veto_Electron_Cut)?true:false;
                d.tight.mhitsc = (d.mhits == tElectron_Missing_Hits_Cut)?true:false;
                d.tight.isoc   = (d.iso < tElectron_Relative_Isolation_Cut)?true:false;
                d.tight.all = d.tight.ptc && d.tight.etac && d.tight.dxyc && d.tight.vetoc && d.tight.mhitsc && d.tight.isoc;
                
                
                d.loose.ptc = (d.pt > lElectron_Cut_pt)?true:false;
                d.loose.etac = (fabs( d.eta )< lElectron_Cut_eta)?true:false;
                d.loose.dxyc = (d.dxy < lTransverse_Impact_Parameter_Cut)?true:false;
                d.loose.vetoc = (d.veto == lPassing_Conversion_Veto_Electron_Cut)?true:false;
                d.loose.mhitsc = (d.mhits == lElectron_Missing_Hits_Cut)?true:false;
                d.loose.isoc   = (d.iso < lElectron_Relative_Isolation_Cut)?true:false;
                d.loose.all = d.loose.ptc && d.loose.etac && d.loose.dxyc && d.loose.vetoc && d.loose.mhitsc && d.loose.isoc;
                
            }
        }
        return;
    }
    
    ~Electron()
    {
        delete v;
        v=0;
    }
};

class Muon
{
    struct CUT
    {
        bool   particleFlowc,globalMuonc,trackerMuonc,etac,ptc,isoc,all;
    };
    struct DATA
    {
        
        float  particleFlow,globalMuon,trackerMuon,eta,pt,iso,charge;
        CUT    loose,tight;
    };
    
    vector<vector<DATA>*>*  v;
    
public:
    Muon()
    {
        v = new vector<vector<DATA>*>;
    }
    Muon(vector<vector<DATA>*>* uv)
    {
        
        v=uv;
    }
    
    
    void setData(const char* fname)
    {
        TFile* inFile = TFile::Open(fname);
        
        if(!inFile)
        {
            cout<<"Input Root File not open in muon class for processing"<<endl;
            return;
        }
        
        fwlite::Event ev(inFile);
        int evtID=0;
        
        for(ev.toBegin(); !ev.atEnd(); ++ev, evtID++)
        {
            edm::EventBase const & event = ev;
            
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
            // Handle to the muon charge
            edm::Handle<std::vector<float> > muonCharge;
            event.getByLabel(std::string("muons:muCharge"), muonCharge);
            
            vector<DATA>* dv = new vector<DATA>;
            DATA d;
            
            for(unsigned int i=0;i<muonPt->size();i++)
            {
                d.particleFlow = ParticleFlow->at(i);
                d.globalMuon = GlobalMuon->at(i);
                d.trackerMuon = TrackerMuon->at(i);
                d.pt = muonPt->at(i);
                d.eta = muonEta->at(i);
                d.iso  = muonIso04->at(i);
                d.charge = muonCharge->at(i);
                
                dv->push_back(d);
                               
            }
            
            
            v->push_back(dv);
            
        }
        inFile->Close();
        
        setCuts();
        
        return;
    }
    
    void printData(int p,string msg)
    {
        vector<DATA>* dv;
        DATA d;
        int tmu=0;
        int tevt=0;
        
        cout<<msg<<endl;
        for(unsigned int i=0; i < v->size(); i++)
        {
            dv=v->at(i);
            //cout<<i<<","<<dv->size()<<endl;
            if(dv->size()!=0)tevt++;
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                if(p==1 || p==0) cout<<"Event ID:"<<i<<", Muon ID:"<<j<<","<<" ParticleFlow:"<<d.particleFlow<<", GlobalMuon:"<<d.globalMuon<<", trackerMuon:"<<d.trackerMuon<<", Pt:"<<d.pt<<", Eta:"<<d.eta<<", ISO:"<<d.iso<<", charge:"<<d.charge<<endl;
                
                if(p==2||p==0)
                {
                    cout<<"TCEvent ID:"<<i<<", Muon ID:"<<j<<","<<" ParticleFlowc:"<<d.tight.particleFlowc<<", GlobalMuonc:"<<d.tight.globalMuonc<<", trackerMuonc:"<<d.tight.trackerMuonc<<", Ptc:"<<d.tight.ptc<<", Etac:"<<d.tight.etac<<", ISOc:"<<d.tight.isoc<<",allc:"<<d.loose.all<<endl;
                }
                if(p==3||p==0)
                {
                    cout<<"LCEvent ID:"<<i<<", Muon ID:"<<j<<","<<" ParticleFlowc:"<<d.tight.particleFlowc<<", GlobalMuonc:"<<d.tight.globalMuonc<<", trackerMuonc:"<<d.tight.trackerMuonc<<", Ptc:"<<d.tight.ptc<<", Etac:"<<d.tight.etac<<", ISOc:"<<d.tight.isoc<<",allc:"<<d.loose.all<<endl;
                }
                tmu++;
            }
            
        }
        
        cout<<"Total muons:"<<tmu<<" Total non empty events:"<<tevt<<endl;
        return;
    }
    vector<vector<DATA>*>* selectData()
    {
        vector<DATA>* dv;
        DATA d;
        
        vector<vector<DATA>*>* fv = new vector<vector<DATA>*>;
        
        for(unsigned int i=0; i < v->size(); i++)
        {
            vector<DATA>* fdv= new vector<DATA>;
            
            dv=v->at(i);
            
            bool isEventSelected=true;
            int tightCount=0;
            
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                
                if(d.tight.all)tightCount++;
                
                if(!(  (d.tight.all==true && d.loose.all==true)  || (d.tight.all==false && d.loose.all==false) ))
                {
                    // cout<<i<<" Reject1\n";
                    isEventSelected=false;
                    break;
                }
                
            }
            
            if(tightCount==0){isEventSelected=false;//cout<<i<<" Reject2\n";
            }
            //-----------------------
            if(isEventSelected)
            {
                
                for(unsigned int j=0;j<dv->size();j++)
                {
                    d=dv->at(j);
                    
                    
                    if(d.tight.all==true && d.loose.all==true)
                    {
                        //cout<<"SEventID:"<<i<<"SElectronID:"<<j<<endl;
                        fdv->push_back(d);
                    }
                    
                }
                
            }
            //-------------------------
            fv->push_back(fdv);
        }
        return fv;
    }

    void fillHisto(const char* outputFile)
    {
        vector<DATA>* dv;
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService(outputFile);
        TFileDirectory dir = fs.mkdir("analyzePatMuon");
        TH1F* muonPt_  = dir.make<TH1F>("muonPt_"  , "pt"  ,   100,   0., 400.);
        
        for(unsigned int i=0; i < v->size(); i++)
        {
            dv=v->at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                if(d.tight.all)muonPt_->Fill(d.pt);
            }
            
            
        }
        return;
    }
    
        
        
        
    void setCuts()
    {
        
        vector<DATA>* dv;
        
        int tParticle_Flow_Muon_Cut = 1;
        int tGlobal_Muon_Cut = 1;
        int tTracker_Muon_Cut = 1;
        float tMuon_Tight_Cut_pt = 20.0;
        float tMuon_Tight_Cut_eta = 2.4;
        float tMuon_Relative_Isolation_Cut = 0.20;
        
        int lParticle_Flow_Muon_Cut = 1;
        int lGlobal_Muon_Cut = 1;
        int lTracker_Muon_Cut = 1;
        float lMuon_Tight_Cut_pt = 20.0;
        float lMuon_Tight_Cut_eta = 2.4;
        float lMuon_Relative_Isolation_Cut = 0.20;
    
        for(unsigned int i=0; i < v->size(); i++)
        {
            dv=v->at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                DATA& d=dv->at(j);
                
                d.tight.particleFlowc = (d.particleFlow == tParticle_Flow_Muon_Cut)?true:false;
                d.tight.globalMuonc = (d.globalMuon == tGlobal_Muon_Cut)?true:false;
                d.tight.trackerMuonc = (d.trackerMuon == tTracker_Muon_Cut)?true:false;
                d.tight.ptc = (d.pt > tMuon_Tight_Cut_pt)?true:false;
                d.tight.etac = (fabs( d.eta ) < tMuon_Tight_Cut_eta)?true:false;
                d.tight.isoc = (d.iso < tMuon_Relative_Isolation_Cut)?true:false;
d.tight.all = d.tight.particleFlowc && d.tight.globalMuonc && d.tight.trackerMuonc && d.tight.ptc && d.tight.etac && d.tight.isoc;

                d.loose.particleFlowc = (d.particleFlow == lParticle_Flow_Muon_Cut)?true:false;
                d.loose.globalMuonc = (d.globalMuon == lGlobal_Muon_Cut)?true:false;
                d.loose.trackerMuonc = (d.trackerMuon == lTracker_Muon_Cut)?true:false;
                d.loose.ptc = (d.pt > lMuon_Tight_Cut_pt)?true:false;
                d.loose.etac = (fabs( d.eta ) < lMuon_Tight_Cut_eta)?true:false;
                d.loose.isoc = (d.iso < lMuon_Relative_Isolation_Cut)?true:false;
d.loose.all = d.loose.particleFlowc && d.loose.globalMuonc && d.loose.trackerMuonc && d.loose.ptc && d.loose.etac && d.loose.isoc;
            }
        }
        
        return;
    }
   ~Muon()
    {
        
        delete v;
        v=0;
    }
};

class Met
{
    struct DATA
    {
        
        float  pt;
        bool   ptc;
    };
    
    vector<vector<DATA>*>  v;
    
public:
    Met()
    {
        
    }
    
    void setData(const char* fname)
    {
        TFile* inFile = TFile::Open(fname);
        
        if(!inFile)
        {
            cout<<"Input Root File not open for processing\n";
            return;
        }
        
        fwlite::Event ev(inFile);
        int evtID=0;
        
        for(ev.toBegin(); !ev.atEnd(); ++ev, evtID++)
        {
            edm::EventBase const & event = ev;
            
            edm::Handle<std::vector<float> > MetPt;
            event.getByLabel(std::string("met:metPt"), MetPt);
            
            vector<DATA>* dv = new vector<DATA>;
            DATA d;
            
            for(unsigned int i=0;i<MetPt->size();i++)
            {
                d.pt = MetPt->at(i);
                
                dv->push_back(d);
                
            }
            
            
            v.push_back(dv);
            
        }
        inFile->Close();
        
        setCuts();
        
        return;
    }
    
    void printData(int p)
    {
        vector<DATA>* dv;
        DATA d;
        
        for(unsigned int i=0; i < v.size(); i++)
        {
            dv=v.at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                if(p==1 || p==0) cout<<"Event ID:"<<i<<", Met ID:"<<j<<","<<" Pt:"<<d.pt<<endl;
                
                if(p==2||p==0)
                    cout<<"Event ID:"<<i<<", Met ID:"<<j<<","<<" Ptc:"<<d.ptc<<endl;
                if(d.ptc){
                  if(p==3||p==0) cout<<"Event ID:"<<i<<", Met ID:"<<j<<","<<" Ptc:"<<d.ptc<<endl;
                }
            }
        }
        return;
    }
    
    void fillHisto(const char* outputFile)
    {
        vector<DATA>* dv;
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService(outputFile);
        TFileDirectory dir = fs.mkdir("analyzePatMuon");
        TH1F* MetPt_  = dir.make<TH1F>("MetPt_"  , "pt"  ,   100,   0., 400.);
        
        for(unsigned int i=0; i < v.size(); i++)
        {
            dv=v.at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                if(d.ptc)
                    MetPt_->Fill(d.pt);
                
            }
            
        }
        return;
    }
    void setCuts()
    {
        
        vector<DATA>* dv;
        
        
        float Met_Cut_pt = 50.0;
        
        for(unsigned int i=0; i < v.size(); i++)
        {
            dv=v.at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                DATA& d=dv->at(j);
                d.ptc = (d.pt > Met_Cut_pt)?true:false;
                
            }
            
            
        }
        return;
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

    /*Electron obe;
    

    obe.setData(inputFiles_[0].c_str());
    obe.fillHisto(outputFile_.c_str());
    
   obe.printData(0,"Primary Events information.");
    
    
    
    Electron obfe(obe.selectData());
 
    obfe.printData(0,"Filltered Events information.");
    
    obe.selectData();
    */
    
    Muon obm;
    obm.setData(inputFiles_[0].c_str());
    obm.fillHisto(outputFile_.c_str());
    
    obm.printData(0,"Primary Events information for MUON.");
    
    
    Muon obfm(obm.selectData());
    obfm.printData(0,"Filltered Events information for MUON.");
    
    Met obmet;
    obmet.setData(inputFiles_[0].c_str());
    obmet.fillHisto(outputFile_.c_str());
    
    obmet.printData(0);
    
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

                        
                        


