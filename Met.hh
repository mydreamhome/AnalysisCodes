class ElectronMuonMet;

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
    friend class ElectronMuonMet;
};

