#include<iostream>

using namespace std;

class Electron
{
	double pt,eta;
	int eid,id,f;

};

vector<Electron>*::getElectrons()
{

Electron e;
vector<Electron>* v=new vector<Electron>;

for(int i=1;i<=100;i++)
{

	for(int j=1;j<=rand()%5;j++)
	{
		e.pt=(rand()%100)/1.3;
		e.eta=(rand()%200)/1.8;
		e.id=j;
		e.eid=i;

		if(isPass(e))e.f=1;
		else e.f=0;

			v->push_back(e);			
		}		
	}
}

return v;
}

int isPass(Electron e)
{
	if(e.eta > 0)
	return 0;


return 1;
}


void fillElectrons(vector<Electron>* v)
{

	Th1
	for(int i=0;i<v->size();i++)
	{


	}
	

}
