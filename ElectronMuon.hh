class Electron;
class Muon;
class ElectronMuonExtraLoose;

class ElectronMuon
{
    
    struct CUTE
    {
        bool   etac,ptc,dxyc,vetoc,mhitsc,isoc,all;
    };
    struct DATAE
    {
        
        float  eta,pt,dxy,veto,mhits,iso,charge;
        CUTE    loose,tight;
    };
    struct CUTM
    {
        bool   particleFlowc,globalMuonc,trackerMuonc,etac,ptc,isoc,all;
    };
    struct DATAM
    {
        
        float  particleFlow,globalMuon,trackerMuon,eta,pt,iso,charge;
        CUTM    loose,tight;
    };
    
    
    struct DATA{
        int evtID,eID,mID;
        float ech,mch;
    };
    
    vector<DATA>*  v;
    
public:
    ElectronMuon()
    {
        
        v= new vector<DATA>;
    }
    
    vector<DATA>* setData(Electron& fe,Muon& fm)
    {
        unsigned int feemm = (fe.v->size() < fm.v->size())?fe.v->size():fm.v->size();
        
        for(unsigned int i=0;i<feemm;i++)//loop over all events
        {
            
            vector<DATAE>* edv = (vector<DATAE>*)fe.v->at(i); //pointer to electron's collection(1st electron) in a particular event
            vector<DATAM>* mdv = (vector<DATAM>*)fm.v->at(i);
            
            if(edv->size()==0 || mdv->size()==0)continue;
            
            int c=0;
            DATA emd;
            for(unsigned int j=0;j<edv->size();j++)
            {
                DATAE e = edv->at(j);
                
                for(unsigned int k=0;k<mdv->size();k++)
                {
                    DATAM m = mdv->at(j);
                    
                    if( (e.charge * m.charge) < 0 )
                    {
                        emd.evtID=i;
                        emd.eID=j;
                        emd.mID=k;
                        emd.ech=e.charge;
                        emd.mch=m.charge;
                        c++;
                    }
                }
            }
            if(c==1)
            {
                v->push_back(emd);
                cout<<"Selected (on basis of opposite charge of electron & muon) EventID: "<<emd.evtID<<" ,EID: "<<emd.eID<<" ,MID "<<emd.mID<<" ,EC: "<<emd.ech<<" ,MC: "<<emd.mch<<endl;
                
            }
        }
        return v;
    }
    
   /* void fillHisto(const char* outputFile)
    {
        vector<DATA>* dv;
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService("electronMuonevtID.root");
        TFileDirectory dir = fs.mkdir("electronMuonevtID");
        TH1F* electronMuonPt_  = dir.make<TH1F>("electronMuonevtID_"  , "evtID"  ,   100,   0., 100.);
        
        for(unsigned int i=0; i < v->size(); i++)
        {
            DATA emd;
            
            emd = v->at(i);
            electronMuonevtID_->Fill(emd.evtID);
        }
        return;
    }*/
 
    ~ElectronMuon()
    {
        delete v;
        v=0;
    }
    friend class ElectronMuonExtraLoose;
};
