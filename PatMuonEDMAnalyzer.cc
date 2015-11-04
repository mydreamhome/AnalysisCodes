#include <memory>
#include"stdio.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

#include <TH1F.h>
#include <TROOT.h>
#include <TFile.h>
#include <TSystem.h>

#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/FWLite/interface/AutoLibraryLoader.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "DataFormats/PatCandidates/interface/Electron.h"

#include "PhysicsTools/FWLite/interface/TFileService.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h"
using namespace std;

#include "Electron.hh"
#include "Muon.hh"
#include "ElectronMuon.hh"
#include "ElectronMuonOppChrg.hh"
#include "ElectronMuonExtraLoose.hh"
#include "Met.hh"
#include "ElMuMet.hh"

int main(int argc, char* argv[])
{
  // ----------------------------------------------------------------------
  // First Part: 
  //
  //  * enable the AutoLibraryLoader 
  //  * book the histograms of interest 
  //  * open the input file
  // ----------------------------------------------------------------------

  // load framework libraries
  gSystem->Load( "libFWCoreFWLite" );
  AutoLibraryLoader::enable();

  // initialize command line parser
    optutl::CommandLineParser parser ("Analyze FWLite Histograms");

  // set defaults
  parser.stringValue  ("outputFile" ) = "analyzeEdmTuple.root";

  // parse arguments
  parser.parseArguments (argc, argv);

    std::string outputFile_ = parser.stringValue("outputFile");
  std::vector<std::string> inputFiles_ = parser.stringVector("inputFiles");
  // book a set of histograms
    fwlite::TFileService fs = fwlite::TFileService(outputFile_.c_str());
    TFileDirectory dir = fs.mkdir("analyzePatMuon");

    //calling classes
    Electron obe;
    obe.setData(inputFiles_[0].c_str());
  //  obe.fillHisto(outputFile_.c_str());
    //obe.printData(0,"Primary Events information.");
    Electron obfe1(obe.selectData1());
    Electron obfe2(obe.selectData2());
    //obfe.printData(0,"Filltered Events information.");
    
    Muon obm;
    obm.setData(inputFiles_[0].c_str());
  //  obm.fillHisto(outputFile_.c_str());
   // obm.printData(0,"Primary Events information for MUON.");
    Muon obfm1(obm.selectData1());
    Muon obfm2(obm.selectData2());
    //obfm.printData(0,"Filltered Events information for MUON.");
    
    ElectronMuon em;
    ElectronMuon em2e;
    ElectronMuon em2mu;
    em.setData1(obfe1,obfm1);
    em2e.setData2(obfe2);
    em2mu.setData3(obfm2);
    em.fillHisto(outputFile_.c_str(), "electronMuononeTeoneTm", 1);
    em2e.fillHisto(outputFile_.c_str(), "electronMuononeTeoneTm2e", 2);
    em2mu.fillHisto(outputFile_.c_str(), "electronMuononeTeoneTm2mu", 3);
    
    ElectronMuonOppChrg emopp;
    ElectronMuonOppChrg emopp2e;
    ElectronMuonOppChrg emopp2mu;
    emopp.setData(em);
    emopp2e.setData(em2e);
    emopp2mu.setData(em2mu);
    emopp.fillHisto(outputFile_.c_str(), "electronMuonOppositeCharge", 1);
    emopp2e.fillHisto(outputFile_.c_str(), "electronMuonOppositeCharge2e", 2);
    emopp2mu.fillHisto(outputFile_.c_str(), "electronMuonOppositeCharge2mu", 3);
    
    ElectronMuonExtraLoose emel;
    ElectronMuonExtraLoose emel2e;
    ElectronMuonExtraLoose emel2mu;
    emel.setData1(emopp,obe,obm);
    emel2e.setData2(emopp2e,obe);
    emel2mu.setData3(emopp2mu,obm);
    emel.fillHisto(outputFile_.c_str(), "electronMuonExtraloose", 1);
    emel2e.fillHisto(outputFile_.c_str(), "electronMuonExtraloose2e", 2 );
    emel2mu.fillHisto(outputFile_.c_str(), "electronMuonExtraloose2mu", 3);
    
    Met obmet;
    obmet.setData(inputFiles_[0].c_str());
   // obmet.fillHisto(outputFile_.c_str());
   // obmet.printData(0);
    Met obfmet(obmet.selectData());
    
    ElectronMuonMet obEMM;
    ElectronMuonMet obEMM2e;
    ElectronMuonMet obEMM2mu;
    obEMM.setData(emel,obmet);
    obEMM2e.setData(emel2e,obfmet);
    obEMM2mu.setData(emel2mu,obfmet);
    obEMM.fillHisto(outputFile_.c_str(), "met", 1);
    obEMM2e.fillHisto(outputFile_.c_str(), "met2e", 2);
    obEMM2mu.fillHisto(outputFile_.c_str(), "met2mu", 3);
    
    return 0;
}

                        


