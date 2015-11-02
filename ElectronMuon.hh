class Electron;
class Muon;
class ElectronMuonExtraLoose;

class ElectronMuon
{
    
    struct CUTE
    {
        bool   etac,ptc,dxyc,vetoc,mhitsc,isoc,scEtac,fullSigmaEtaEtac,dEtaInc,dPhiInc,HoverEc,ooEmooPc,d0c,dzc,all;
    };
    struct DATAE
    {
        
        float  phi,eta,pt,dxy,veto,mhits,iso,charge,scEta,fullSigmaEtaEta,dEtaIn,dPhiIn,HoverE,ooEmooP,d0,dz;
        CUTE    loose,tight;
    };
    struct CUTM
    {
        bool   particleFlowc,globalMuonc,trackerMuonc,etac,ptc,isoc,all;
    };
    struct DATAM
    {
        
        float  particleFlow,globalMuon,trackerMuon,eta,pt,iso,charge,phi;
        CUTM    loose,tight;
    };
    
    
    struct DATA{
        int evtID,eID,mID;
        float ech,mch,electronPt,electronEta,electronPhi,muonPt,muonEta,muonPhi;
    };
    
    vector<DATA>*  v;
    
public:
    ElectronMuon()
    {
        v= new vector<DATA>;
    }
    
    vector<DATA>* setData(Electron& fe,Muon& fm)
    {
     //   unsigned int feemm = (fe.v->size() < fm.v->size())?fe.v->size():fm.v->size();
        int events = 0;
        for(unsigned int i=0;i<fe.v->size();i++)//loop over all events
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
                        emd.electronPt=e.pt;
                        emd.electronEta=e.eta;
                        emd.electronPhi=e.phi;
                        emd.muonPt=m.pt;
                        emd.muonEta=m.eta;
                        emd.muonPhi=m.phi;
                        
                        c++;
                    }
                }
            }
            if(c==1)
            {
                events++;
                v->push_back(emd);
               // cout<<"Selected (on basis of opposite charge of electron & muon) EventID: "<<emd.evtID<<" ,EID: "<<emd.eID<<" ,MID "<<emd.mID<<" ,EC: "<<emd.ech<<" ,MC: "<<emd.mch<<endl;
                
            }
        }
        cout<<"Total number of events having ooposite charge only one tight electron and only one tight muon: " << events <<endl;
        return v;
    }
  
    void fillHisto(const char* outputFile)
    {
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService("electronMuonOppositeCharge.root");
        TFileDirectory dir = fs.mkdir("electronMuonOppositeCharge");
        TH1F* electronPt_  = dir.make<TH1F>("electronPt_"  , "pt"  ,   100,   0., 400.);
        TH1F* electronEta_  = dir.make<TH1F>("electronEta_"  , "eta"  ,   100,   -3.0, 3.0);
        TH1F* electronPhi_  = dir.make<TH1F>("electronPhi_"  , "phi"  ,   100,  -3.5, 3.5);
        TH1F* muonPt_  = dir.make<TH1F>("muonPt_"  ,"pt"  ,   100,   0., 400.);
        TH1F* muonEta_  = dir.make<TH1F>("muonEta_"  ,"eta"  ,   100,   -3.0, 3.0);
        TH1F* muonPhi_  = dir.make<TH1F>("muonPhi_"  , "phi"  ,   100,  -3.5, 3.5);

        for(unsigned int i=0; i < v->size(); i++)
        {
            d=v->at(i);
            electronPt_->Fill(d.electronPt);
            electronEta_->Fill(d.electronEta);
            electronPhi_->Fill(d.electronPhi);
            muonPt_->Fill(d.muonPt);
            muonEta_->Fill(d.muonEta);
            muonPhi_->Fill(d.muonPhi);
        }
        return;
    }
 
    ~ElectronMuon()
    {
        delete v;
        v=0;
    }
    friend class ElectronMuonExtraLoose;
};
