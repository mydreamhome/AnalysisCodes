class Electron;
class Muon;
class ElectronMuon;
class ElectronMuonMet;

class ElectronMuonExtraLoose
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
    
    
  /*  struct DATAEM{
        int evtID,eID,mID;
        float ech,mch;
    };
   */
    struct DATA
    {
        int evtID,eID,mID;
        float ech,mch;
    };
    
    vector<DATA>*  v;
    
public:
    ElectronMuonExtraLoose()
    {
        
        v= new vector<DATA>;
    }
    
    vector<DATA>* setData(ElectronMuon& em, Electron& elect, Muon& mu)
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
                     cout<<evtID<<" RejectE"<<endl<<endl<<endl;
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
                cout<<"Selected (on basis of extra loose electrons & muons) EventID: "<<evtID<<", electronID:"<<emelc.eID<<", muonID:"<<emelc.mID<<", electronCharge:"<<emelc.ech<<", muonCharge:"<<emelc.mch<<endl;
            
            v->push_back(emelc);
       		 }
        }
        cout<<"total number of sselected events due to extra loose cuts : "<<sselected_events<<endl;
        cout<<"total number of rejected events due to extra loose cuts : "<<rejected_event<<endl;
        return v;
    }
    
    
    ~ElectronMuonExtraLoose()
    {
        delete v;
        v=0;
    }
    friend class ElectronMuonMet;
};
