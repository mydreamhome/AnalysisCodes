class ElectronMuonMet
{
    struct MetDATA
    {
        
        float  pt;
        bool   ptc;
    };

	struct DATA{
		int evtID;
		float metPt;

	};

	vector<DATA>* v;
public:
	ElectronMuonMet()
	{
		v = new vector<DATA>;
	}

    
    void setData(ElectronMuon& em,Met& met)
    {
        for(unsigned int i=0;i<em.v->size();i++)
        {
            int evtID=((em.v)->at(i)).evtID;
            vector<MetDATA>* dv = (vector<MetDATA>*) met.v.at(evtID);
            
	    
	int metc=0;
		
            for(unsigned int j=0;j<dv->size();j++)
            {
                MetDATA metd =(MetDATA) dv->at(j);
               if(metd.ptc==true)metc++;
		// cout<<"MET:EventID"<<evtID<<", MetID:"<<j<<"PT:"<<metd.pt<<", ptc:"<<metd.ptc<<endl;
            }
	  
	   if(metc==2)
		{
	   for(unsigned int j=0;j<dv->size();j++)
            {
                MetDATA metd =(MetDATA) dv->at(j);
               if(metd.ptc==true)
		{
			DATA d ={evtID,metd.pt};
			v->push_back(d);
 		cout<<"MET:EventID"<<evtID<<", MetID:"<<j<<"PT:"<<metd.pt<<", ptc:"<<metd.ptc<<endl;
        	}     
	}
 	}           
            
        }
    }
};
