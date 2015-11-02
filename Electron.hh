class ElectronMuon;

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
        
        fwlite::TFileService fs = fwlite::TFileService("E.root");
        TFileDirectory dir = fs.mkdir("E");
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
    
    friend class ElectronMuon;
};
