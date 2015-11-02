class Vertex
{
    struct DATA
    {
        
        float  Vtx_z, Vtx_rho;
        int Vtx_ndof;
        bool   Vtx_zc, Vtx_ndofc, Vtx_rhoc;
    };
    
    vector<vector<DATA>*>  v;
    
public:
    Vertex()
    {
        
    }
    
    void setData(const char* fname)
    {
        TFile* inFile = TFile::Open(fname);
        
        if(!inFile)
        {
            cout<<"Input Root File not open for processing"<<endl;
            return;
        }
        
        fwlite::Event ev(inFile);
        int evtID=0;
        
        for(ev.toBegin(); !ev.atEnd(); ++ev, evtID++)
        {
            edm::EventBase const & event = ev;
            
            // Handle to the z of vertex
            edm::Handle<std::vector<float> > vtxZ;
            event.getByLabel(std::string("vertexInfo:z"), vtxZ);
            // Handle to the dof of vertex
            edm::Handle<std::vector<int> > dof;
            event.getByLabel(std::string("vertexInfo:ndof"), dof);
            // Handle to the rho
            edm::Handle<std::vector<float> > rhoo;
            event.getByLabel(std::string("vertexInfo:rho"), rhoo);
            
            vector<DATA>* dv = new vector<DATA>;
            DATA d;
            
            for(unsigned int i=0;i<MetPt->size();i++)
            {
                d.Vtx_z = vtxZ->at(i);
                d.Vtx_ndof = dof->at(i);
                d.Vtx_rho = rhoo->at(i);

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
                if(p==1 || p==0) cout<<"Event ID:"<<i<<", Vertex ID:"<<j<<","<<" Vtx_z:"<<d.Vtx_z<<","<<" Vtx_ndof:"<<d.Vtx_ndof<<","<<" Vtx_rho:"<<d.Vtx_rho<<endl;
                
                if(p==2||p==0)
                    cout<<"Event ID:"<<i<<", Vertex ID:"<<j<<","<<" Vtx_zc:"<<d.Vtx_zc<<","<<" Vtx_ndofc:"<<d.Vtx_ndofc<<","<<" Vtx_rhoc:"<<d.Vtx_rhoc<<endl;
                if(d.all){
                  if(p==3||p==0) cout<<"cuts passed Event ID:"<<i<<", Vertex ID:"<<j<<","<<" Vtx_zc:"<<d.Vtx_zc<<","<<" Vtx_ndofc:"<<d.Vtx_ndofc<<","<<" Vtx_rhoc:"<<d.Vtx_rhoc<<endl;
                }
            }
        }
        return;
    }
    
   /* void fillHisto(const char* outputFile)
    {
        vector<DATA>* dv;
        DATA d;
        
        fwlite::TFileService fs = fwlite::TFileService(outputFile);
        TFileDirectory dir = fs.mkdir("vertex.root");
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
    }*/
    void setCuts()
    {
        
        vector<DATA>* dv;
        
        float Vtx_Cut_z = 24.0;
        int Vtx_Cut_ndof = 4;
        float Vtx_Cut_rho = 2.0;
        
        for(unsigned int i=0; i < v.size(); i++)
        {
            dv=v.at(i);
            for(unsigned int j=0;j<dv->size();j++)
            {
                DATA& d=dv->at(j);
                d.Vtx_zc = (d.Vtx_z < Vtx_Cut_z)?true:false;
                d.Vtx_ndofc = (d.Vtx_ndof > Vtx_Cut_ndof)?true:false;
                d.Vtx_rhoc = (d.Vtx_rho < Vtx_Cut_rho)?true:false;
            }
            
            
        }
        return;
    }
    
};
