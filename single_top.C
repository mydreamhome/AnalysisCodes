single_top(){
TFile *f = new TFile("B2GEDMNtuple.root");// root file that u get after running demoanalyzer
TTree *t1 = (TTree*)f->Get("Events");// this is the name of tree into the root file
t1->MakeClass("top");// u can change the name top by whatever u want
}
