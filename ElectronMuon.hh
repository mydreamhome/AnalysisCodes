class Electron;
class Muon;
class ElectronMuonOppChrg;

class ElectronMuon
{
    
    struct CUTE
    {
        bool   etac,ptc,dxyc,vetoc,mhitsc,isoc,scEtac,fullSigmaEtaEtac,dEtaInc,dPhiInc,HoverEc,ooEmooPc,d0c,dzc,all;
    };
    struct DATAE
    {
        
        float  eID,phi,eta,pt,dxy,veto,mhits,iso,charge,scEta,fullSigmaEtaEta,dEtaIn,dPhiIn,HoverE,ooEmooP,d0,dz;
        CUTE    loose,tight;
    };
    struct CUTM
    {
        bool   particleFlowc,globalMuonc,trackerMuonc,etac,ptc,isoc,all;
    };
    struct DATAM
    {
        
        float  mID,particleFlow,globalMuon,trackerMuon,eta,pt,iso,charge,phi;
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
    
    vector<DATA>* setData1(Electron& fe,Muon& fm)
    {
        int events = 0;
        for(unsigned int i=0;i<fe.v->size();i++)//loop over all events
        {
            int c=0;

            vector<DATAE>* edv = (vector<DATAE>*)fe.v->at(i); //pointer to electron's collection(1st electron) in a particular event
            vector<DATAM>* mdv = (vector<DATAM>*)fm.v->at(i);
            
            if(edv->size()!=1 || mdv->size()!=1)continue;
            
            DATA emd;

                    if( edv->size()==1 && mdv->size()==1)
                    {
                        DATAE e = edv->at(0);
                        DATAM m = mdv->at(0);
                        
                        emd.evtID=i;
                        emd.eID=e.eID;
                        emd.mID=m.mID;
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

            if(c==1)
            {
                events++;
                v->push_back(emd);
               // cout<<"Selected (on basis of opposite charge of electron & muon) EventID: "<<emd.evtID<<" ,EID: "<<emd.eID<<" ,MID "<<emd.mID<<" ,EC: "<<emd.ech<<" ,MC: "<<emd.mch<<endl;
                
            }
        }
        cout<<"Total number of events having only one tight electron and only one tight muon: " << events <<endl;
        return v;
    }
    
    vector<DATA>* setData2(Electron& fe)
    {
        int events = 0;
        for(unsigned int i=0;i<fe.v->size();i++)//loop over all events
        {
            int c=0;
            
            vector<DATAE>* edv = (vector<DATAE>*)fe.v->at(i); //pointer to electron's collection(1st electron) in a particular event
            
            if(edv->size()!=2)continue;
            
            DATA emd;
            if( edv->size()==2)
            {
                DATAE e1 = edv->at(0);
                DATAE e2 = edv->at(1);
                
                        emd.evtID=i;
                        emd.eID=e1.eID;
                        emd.mID=e2.eID;
                        emd.ech=e1.charge;
                        emd.mch=e2.charge;
                        emd.electronPt=e1.pt;
                        emd.electronEta=e1.eta;
                        emd.electronPhi=e1.phi;
                        emd.muonPt=e2.pt;
                        emd.muonEta=e2.eta;
                        emd.muonPhi=e2.phi;
                        
                        c++;
            }
            if(c==1)
            {
                events++;
                v->push_back(emd);
                // cout<<"Selected (on basis of opposite charge of electron & muon) EventID: "<<emd.evtID<<" ,EID: "<<emd.eID<<" ,MID "<<emd.mID<<" ,EC: "<<emd.ech<<" ,MC: "<<emd.mch<<endl;
                
            }
        }
        cout<<"Total number of events having only two tight electrons: " << events <<endl;
        return v;
    }
  
    vector<DATA>* setData3(Muon& fm)
    {
        int events = 0;
        for(unsigned int i=0;i<fm.v->size();i++)//loop over all events
        {
            vector<DATAM>* mdv = (vector<DATAM>*)fm.v->at(i); //pointer to electron's collection(1st electron) in a particular event
            
            if(mdv->size()!=2)continue;
            
            int c=0;
            DATA emd;
            if( mdv->size()==2)
            {
                DATAM m1 = mdv->at(0);
                DATAM m2 = mdv->at(1);
                
                emd.evtID=i;
                emd.eID=m1.mID;
                emd.mID=m2.mID;
                emd.ech=m1.charge;
                emd.mch=m2.charge;
                emd.electronPt=m1.pt;
                emd.electronEta=m1.eta;
                emd.electronPhi=m1.phi;
                emd.muonPt=m2.pt;
                emd.muonEta=m2.eta;
                emd.muonPhi=m2.phi;
                
                c++;
            }
            if(c==1)
            {
                events++;
                v->push_back(emd);
                // cout<<"Selected (on basis of opposite charge of electron & muon) EventID: "<<emd.evtID<<" ,EID: "<<emd.eID<<" ,MID "<<emd.mID<<" ,EC: "<<emd.ech<<" ,MC: "<<emd.mch<<endl;
                
            }
        }
        cout<<"Total number of events having only two tight muons: " << events <<endl;
        return v;
    }
 
    void fillHisto(const char* outputFile, const char* fileName,int Case)
    {
        DATA d;
        char fName[70];
        
        sprintf(fName,"%s.root",fileName);
        
        fwlite::TFileService fs = fwlite::TFileService(fName);
        TFileDirectory dir = fs.mkdir(fileName);
        
        TH1F* electronPt_ = 0;
        TH1F* electronEta_ = 0;
        TH1F* electronPhi_ = 0;
        
        TH1F* muonPt_ = 0;
        TH1F* muonEta_ = 0;
        TH1F* muonPhi_ = 0;
        
        if(Case==1 || Case==2)
        {
            electronPt_  = dir.make<TH1F>("electronPt_"  , "pt"  ,   100,   0., 400.);
            electronEta_  = dir.make<TH1F>("electronEta_"  , "eta"  ,   100,   -3.0, 3.0);
            electronPhi_  = dir.make<TH1F>("electronPhi_"  , "phi"  ,   100,  -3.5, 3.5);
        }
        if(Case==1 || Case==3)
        {
            muonPt_  = dir.make<TH1F>("muonPt_"  ,"pt"  ,   100,   0., 400.);
            muonEta_  = dir.make<TH1F>("muonEta_"  ,"eta"  ,   100,   -3.0, 3.0);
            muonPhi_  = dir.make<TH1F>("muonPhi_"  , "phi"  ,   100,  -3.5, 3.5);
        }
        
        for(unsigned int i=0; i < v->size(); i++)
        {
            d=v->at(i);
            if(Case==1)
            {
                electronPt_->Fill(d.electronPt);
                electronEta_->Fill(d.electronEta);
                electronPhi_->Fill(d.electronPhi);
                muonPt_->Fill(d.muonPt);
                muonEta_->Fill(d.muonEta);
                muonPhi_->Fill(d.muonPhi);
            }
            if(Case==2)
            {
                electronPt_->Fill(d.electronPt);
                electronEta_->Fill(d.electronEta);
                electronPhi_->Fill(d.electronPhi);
                
                electronPt_->Fill(d.muonPt);
                electronEta_->Fill(d.muonEta);
                electronPhi_->Fill(d.muonPhi);
                
            }
            
            if(Case==3)
            {
                muonPt_->Fill(d.electronPt);
                muonEta_->Fill(d.electronEta);
                muonPhi_->Fill(d.electronPhi);
                
                muonPt_->Fill(d.muonPt);
                muonEta_->Fill(d.muonEta);
                muonPhi_->Fill(d.muonPhi);
                
            }
        }
        return;
    }
    
    ~ElectronMuon()
    {
        delete v;
        v=0;
    }
    friend class ElectronMuonOppChrg;
};
