class Electron;
class Muon;
class ElectronMuonOppChrg;
class ElectronMuonMet;

class ElectronMuonExtraLoose
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
    
    
  /*  struct DATAEM{
        int evtID,eID,mID;
        float ech,mch;
    };
   */
    struct DATA
    {
        int evtID,eID,mID;
        float ech,mch,electronPt,electronEta,electronPhi,muonPt,muonEta,muonPhi;
    };
    
    vector<DATA>*  v;
    
public:
    ElectronMuonExtraLoose()
    {
        
        v= new vector<DATA>;
    }
    
    vector<DATA>* setData(ElectronMuonOppChrg& em, Electron& elect, Muon& mu)
    {
        vector<DATAE>* dve;
        vector<DATAM>* dvm;
        int rejected_event = 0;
        int sselected_events = 0;
        for(unsigned int i=0;i<em.v->size();i++)
        {
            int evtID=((em.v)->at(i)).evtID;
            dve = (vector<DATAE>*) elect.v->at(evtID);
            dvm = (vector<DATAM>*) mu.v->at(evtID);
            
            bool isEventSelected=true;
            
            for(unsigned int j=0;j<dve->size();j++)
            {
             DATAE d;
                d=dve->at(j);
                
                if(!((d.tight.all==true && d.loose.all==true)  || (d.tight.all==false && d.loose.all==false)))
                {
                     //cout<<evtID<<" RejectE"<<endl<<endl<<endl;
                    rejected_event++;
                    isEventSelected=false;
                    break;
                }
                
            }
            
            for(unsigned int j=0;j<dvm->size();j++)
            {
             	DATAM d;
                d=dvm->at(j);
                
                if(!((d.tight.all==true && d.loose.all==true)  || (d.tight.all==false && d.loose.all==false)))
                {
                     cout<<evtID<<" RejectM"<<endl<<endl<<endl;
                    rejected_event++;
                    isEventSelected=false;
                    break;
                }
                
            }
           
            if (isEventSelected)
             {
                 sselected_events++;
               // ElectronMuon dvem = em;
                DATA emelc;
               //  emelc = dvem.v->at(0);
                 
               		  emelc.evtID = em.v->at(i).evtID;
                       emelc.eID = em.v->at(i).eID;
                       emelc.mID = em.v->at(i).mID;
                       emelc.ech = em.v->at(i).ech;
                       emelc.mch = em.v->at(i).mch;
                 emelc.electronPt=em.v->at(i).electronPt;
                 emelc.electronEta=em.v->at(i).electronEta;
                 emelc.electronPhi=em.v->at(i).electronPhi;
                 emelc.muonPt=em.v->at(i).muonPt;
                 emelc.muonEta=em.v->at(i).muonEta;
                 emelc.muonPhi=em.v->at(i).muonPhi;

               // cout<<"Selected (on basis of extra loose electrons & muons) EventID: "<<evtID<<", electronID:"<<emelc.eID<<", muonID:"<<emelc.mID<<", electronCharge:"<<emelc.ech<<", muonCharge:"<<emelc.mch<<endl;
          
            v->push_back(emelc);
       		 }
        }
        cout<<"total number of sselected events due to extra loose cuts : "<<sselected_events<<endl;
        cout<<"total number of rejected events due to extra loose cuts : "<<rejected_event<<endl;
        return v;
    }
   
    void fillHisto(const char* outputFile)
    {
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService("electronMuonExtraloose.root");
        TFileDirectory dir = fs.mkdir("electronMuonExtraloose");
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
    
    ~ElectronMuonExtraLoose()
    {
        delete v;
        v=0;
    }
    friend class ElectronMuonMet;
};
