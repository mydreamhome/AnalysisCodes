//class Electron;
//class Muon;
class ElectronMuon;
class ElectronMuonExtraLoose;

class ElectronMuonOppChrg
{
    
  /*  struct CUTE
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
    */
    
    struct DATA{
        int evtID,eID,mID;
        float ech,mch,electronPt,electronEta,electronPhi,muonPt,muonEta,muonPhi;
    };
    
    vector<DATA>*  v;
    
public:
    ElectronMuonOppChrg()
    {
        v= new vector<DATA>;
    }
    
    vector<DATA>* setData(ElectronMuon& em)
    {
     //   unsigned int feemm = (fe.v->size() < fm.v->size())?fe.v->size():fm.v->size();
        int events = 0;
            DATA emd;
            for(unsigned int i=0;i<em.v->size();i++)
            {
                int c =0 ;
                if( (((em.v)->at(i)).ech * ((em.v)->at(i)).mch) < 0 )
                    {
                        emd.evtID=((em.v)->at(i)).evtID;
                        emd.eID=((em.v)->at(i)).eID;
                        emd.mID=((em.v)->at(i)).mID;
                        emd.ech=((em.v)->at(i)).ech;
                        emd.mch=((em.v)->at(i)).mch;
                        emd.electronPt=((em.v)->at(i)).electronPt;
                        emd.electronEta=((em.v)->at(i)).electronEta;
                        emd.electronPhi=((em.v)->at(i)).electronPhi;
                        emd.muonPt=((em.v)->at(i)).muonPt;
                        emd.muonEta=((em.v)->at(i)).muonEta;
                        emd.muonPhi=((em.v)->at(i)).muonPhi;
                        events++;
                        c++;
 
                    }
                if(c == 1)
                {
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
 
    ~ElectronMuonOppChrg()
    {
        delete v;
        v=0;
    }
    friend class ElectronMuonExtraLoose;
};
