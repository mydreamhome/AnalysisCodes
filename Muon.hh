class ElectronMuon;

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
    
    friend class ElectronMuon;
};

