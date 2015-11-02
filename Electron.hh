class ElectronMuon;
class ElectronMuonExtraLoose;

class Electron
{
    struct CUT
    {
        bool   etac,ptc,dxyc,vetoc,mhitsc,isoc,scEtac,fullSigmaEtaEtac,dEtaInc,dPhiInc,HoverEc,ooEmooPc,d0c,dzc,all;
    };
    struct DATA
    {
        
        float  phi,eta,pt,dxy,veto,mhits,iso,charge,scEta,fullSigmaEtaEta,dEtaIn,dPhiIn,HoverE,ooEmooP,d0,dz;
        CUT    loose,tight;
    };
    
    vector<vector<DATA>*>* v;
    
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
            cout<<"Input Root File not opened for processing in electron class "<<endl;
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
            // Handle to the electron eta
            edm::Handle<std::vector<float> > electronPhi;
            event.getByLabel(std::string("electrons:elPhi"), electronPhi);
            // Handle to the electron impact parameter
            edm::Handle<std::vector<float> > electronDxy;
            event.getByLabel(std::string("electrons:elDxy"), electronDxy);
            // Handle to the electron veto
            edm::Handle<std::vector<float> > electronisVeto;
            event.getByLabel(std::string("electrons:elisVeto"), electronisVeto);
            // Handle to the electron missing hits
            edm::Handle<std::vector<float> > electronmissHits;
            event.getByLabel(std::string("electrons:elmissHits"), electronmissHits);
            // Handle to the electron isolation of cone of radius 0.03
            edm::Handle<std::vector<float> > electronIso03;
            event.getByLabel(std::string("electrons:elIso03"), electronIso03);
            // Handle to the electron charge
            edm::Handle<std::vector<float> > electronCharge;
            event.getByLabel(std::string("electrons:elCharge"), electronCharge);
            
            
            // Handle to the electron electronSCeta
            edm::Handle<std::vector<float> > electronSCeta;
            event.getByLabel(std::string("electrons:elscEta"), electronSCeta);
            // Handle to the electron electronfullSigmaEtaEta
            edm::Handle<std::vector<float> > electronfullSigmaEtaEta;
            event.getByLabel(std::string("electrons:elfull5x5siee"), electronfullSigmaEtaEta);
            // Handle to the electron electrondEtaIn
            edm::Handle<std::vector<float> > electrondEtaIn;
            event.getByLabel(std::string("electrons:eldEtaIn"), electrondEtaIn);
            // Handle to the electron electrondPhiIn
            edm::Handle<std::vector<float> > electrondPhiIn;
            event.getByLabel(std::string("electrons:eldPhiIn"), electrondPhiIn);
            // Handle to the electron electronHOverE
            edm::Handle<std::vector<float> > electronHOverE;
            event.getByLabel(std::string("electrons:elHoE"), electronHOverE);
            // Handle to the electron electronooEmooP
            edm::Handle<std::vector<float> > electronooEmooP;
            event.getByLabel(std::string("electrons:elooEmooP"), electronooEmooP);
            // Handle to the electron electronD0
            edm::Handle<std::vector<float> > electronD0;
            event.getByLabel(std::string("electrons:elD0"), electronD0);
            // Handle to the electron electronDz
            edm::Handle<std::vector<float> > electronDz;
            event.getByLabel(std::string("electrons:elDz"), electronDz);
            
            vector<DATA>* dv = new vector<DATA>;
            DATA d;

            for(unsigned int i=0;i<electronPt->size();i++)
            {
                d.pt = electronPt->at(i);
                d.eta = electronEta->at(i);
                d.phi = electronPhi->at(i);
                d.dxy = electronDxy->at(i);
                d.veto = electronisVeto->at(i);
                d.mhits = electronmissHits->at(i);
                d.iso  = electronIso03->at(i);
                d.charge = electronCharge->at(i);
                
                d.scEta = electronSCeta->at(i);
                d.fullSigmaEtaEta = electronfullSigmaEtaEta->at(i);
                d.dEtaIn = electrondEtaIn->at(i);
                d.dPhiIn = electrondPhiIn->at(i);
                d.HoverE = electronHOverE->at(i);
                d.ooEmooP = electronooEmooP->at(i);
                d.d0 = electronD0->at(i);
                d.dz = electronDz->at(i);
                
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
        int events =0;
        int totalTightelectrons =0;

        for(unsigned int i=0; i < v->size(); i++)
        {
            int elctron_number = 0;
            vector<DATA>* fdv= new vector<DATA>;
            
            dv=v->at(i);
            
            bool isEventSelected=false;
            int tightCount=0;
            
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                
                if(d.tight.all)
                {
                    totalTightelectrons++;
                elctron_number = j;
                  tightCount++;
                }
            }
            
            if(tightCount==1){isEventSelected=true;//cout<<i<<" Reject2"<<endl;
            }
            //-----------------------
            if(isEventSelected)
            {
                events++;
                    d=dv->at(elctron_number);
                
                      //  cout<<"Selected (on basis of only 1 tight electron) EventID: "<<i<<"  S ElectronID: "<<elctron_number<<endl;
                        fdv->push_back(d);
                    // only fill one tight electron's information

            }
            //-------------------------
            fv->push_back(fdv);
        }
        cout<<"Total number of tight electrons: "<< totalTightelectrons <<endl;
        cout<<"Total number of events having only one tight electron: "<< events <<endl;
        return fv;
    }
    
    void fillHisto(const char* outputFile)
    {
        vector<DATA>* dv;
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService("tight_electron.root");
        TFileDirectory dir = fs.mkdir("tight_electron");
        TH1F* electronPt_  = dir.make<TH1F>("electronPt_"  , "pt"  ,   100,   0., 400.);
        TH1F* exactlyOneelectronPt_  = dir.make<TH1F>("exactlyOneelectronPt_"  , "pt"  ,   100,   0., 400.);
        TH1F* exactlyOneelectronEta_  = dir.make<TH1F>("exactlyOneelectronEta_"  , "eta"  ,   100,   -3.0, 3.0);
        TH1F* exactlyOneelectronPhi_  = dir.make<TH1F>("exactlyOneelectronPhi_"  , "phi"  ,   100,  -3.5, 3.5);

        for(unsigned int i=0; i < v->size(); i++)
        {
            dv=v->at(i);
            int tightCount=0;
            int elctron_number = 0;
            for(unsigned int j=0;j<dv->size();j++)
            {
                d=dv->at(j);
                if(d.tight.all)
                {
                    electronPt_->Fill(d.pt);
                    elctron_number = j;
                    tightCount++;
                }
                
            }
            if(tightCount==1)
            {
                 d=dv->at(elctron_number);
                exactlyOneelectronPt_->Fill(d.pt);
                exactlyOneelectronEta_->Fill(d.eta);
                exactlyOneelectronPhi_->Fill(d.phi);
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
        
        float bscEta = 1.479;
        float btfullSigmaEtaEta = 0.0101;
        float btdEtaIn = 0.0095;
        float btdPhiIn = 0.0291;
        float btHoverE = 0.0372;
        float btooEmooP = 0.0174;
        float btd0 = 0.0144;
        float btdz = 0.323;

        float blfullSigmaEtaEta = 0.0105;
        float bldEtaIn = 0.00976;
        float bldPhiIn = 0.0929;
        float blHoverE = 0.0765;
        float blooEmooP = 0.184;
        float bld0 = 0.0227;
        float bldz = 0.379;
        
        float escEta = 2.5;
        float etfullSigmaEtaEta = 0.0287;
        float etdEtaIn = 0.00762;
        float etdPhiIn = 0.0439;
        float etHoverE = 0.0544;
        float etooEmooP = 0.01;
        float etd0 = 0.0377;
        float etdz = 0.571;
        
        float elfullSigmaEtaEta = 0.0318;
        float eldEtaIn = 0.00952;
        float eldPhiIn = 0.181;
        float elHoverE = 0.0824;
        float elooEmooP = 0.125;
        float eld0 = 0.242;
        float eldz = 0.921;
        
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
                d.tight.scEtac = (fabs(d.scEta) < escEta)?true:false;
                
                if(fabs(d.scEta) <= bscEta)
                {
                d.tight.fullSigmaEtaEtac = (d.fullSigmaEtaEta < btfullSigmaEtaEta)?true:false;
                d.tight.dEtaInc = (d.dEtaIn < btdEtaIn)?true:false;
                d.tight.dPhiInc = (d.dPhiIn < btdPhiIn)?true:false;
                d.tight.HoverEc = (d.HoverE < btHoverE)?true:false;
                d.tight.ooEmooPc = (d.ooEmooP < btooEmooP)?true:false;
                d.tight.d0c = (fabs(d.d0) < btd0)?true:false;
                d.tight.dzc = (fabs(d.dz) < btdz)?true:false;
                }
                if(fabs(d.scEta) > bscEta && fabs(d.scEta) < escEta)
                {
                d.tight.fullSigmaEtaEtac = (d.fullSigmaEtaEta < etfullSigmaEtaEta)?true:false;
                d.tight.dEtaInc = (d.dEtaIn < etdEtaIn)?true:false;
                d.tight.dPhiInc = (d.dPhiIn < etdPhiIn)?true:false;
                d.tight.HoverEc = (d.HoverE < etHoverE)?true:false;
                d.tight.ooEmooPc = (d.ooEmooP < etooEmooP)?true:false;
                d.tight.d0c = (fabs(d.d0) < etd0)?true:false;
                d.tight.dzc = (fabs(d.dz) < etdz)?true:false;
                }
                
                d.tight.all = d.tight.ptc && d.tight.etac && d.tight.dxyc && d.tight.vetoc && d.tight.mhitsc && d.tight.isoc && d.tight.scEtac && d.tight.fullSigmaEtaEtac && d.tight.dEtaInc && d.tight.dPhiInc && d.tight.HoverEc && d.tight.ooEmooPc && d.tight.d0c && d.tight.dzc;
                
                d.loose.ptc = (d.pt > lElectron_Cut_pt)?true:false;
                d.loose.etac = (fabs( d.eta )< lElectron_Cut_eta)?true:false;
                d.loose.dxyc = (d.dxy < lTransverse_Impact_Parameter_Cut)?true:false;
                d.loose.vetoc = (d.veto == lPassing_Conversion_Veto_Electron_Cut)?true:false;
                d.loose.mhitsc = (d.mhits == lElectron_Missing_Hits_Cut)?true:false;
                d.loose.isoc   = (d.iso < lElectron_Relative_Isolation_Cut)?true:false;
                d.loose.scEtac = (fabs(d.scEta) < escEta)?true:false;

                if(fabs(d.scEta) <= bscEta)
                {
                    d.loose.fullSigmaEtaEtac = (d.fullSigmaEtaEta < blfullSigmaEtaEta)?true:false;
                    d.loose.dEtaInc = (d.dEtaIn < bldEtaIn)?true:false;
                    d.loose.dPhiInc = (d.dPhiIn < bldPhiIn)?true:false;
                    d.loose.HoverEc = (d.HoverE < blHoverE)?true:false;
                    d.loose.ooEmooPc = (d.ooEmooP < blooEmooP)?true:false;
                    d.loose.d0c = (fabs(d.d0) < bld0)?true:false;
                    d.loose.dzc = (fabs(d.dz) < bldz)?true:false;
                }
                if(fabs(d.scEta) > bscEta && fabs(d.scEta) < escEta)
                {
                    d.loose.fullSigmaEtaEtac = (d.fullSigmaEtaEta < elfullSigmaEtaEta)?true:false;
                    d.loose.dEtaInc = (d.dEtaIn < eldEtaIn)?true:false;
                    d.loose.dPhiInc = (d.dPhiIn < eldPhiIn)?true:false;
                    d.loose.HoverEc = (d.HoverE < elHoverE)?true:false;
                    d.loose.ooEmooPc = (d.ooEmooP < elooEmooP)?true:false;
                    d.loose.d0c = (fabs(d.d0) < eld0)?true:false;
                    d.loose.dzc = (fabs(d.dz) < eldz)?true:false;
                }
                
                d.loose.all = d.loose.ptc && d.loose.etac && d.loose.dxyc && d.loose.vetoc && d.loose.mhitsc && d.loose.isoc && d.loose.scEtac && d.loose.fullSigmaEtaEtac && d.loose.dEtaInc && d.loose.dPhiInc && d.loose.HoverEc && d.loose.ooEmooPc && d.loose.d0c && d.loose.dzc;
                
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
    friend class ElectronMuonExtraLoose;
};
