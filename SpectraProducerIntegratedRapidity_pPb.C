#include "fitting.h"

using namespace std;

TSystem->Load("libRooFit");

using namespace RooFit;

void SpectraProducerIntegratedRapidity_pPb(){

    gStyle->SetErrorX(0);

    TH3D* ksHist_pPb[8];
    TH3D* laHist_pPb[8];
    TH3D* xiHist_pPb[8];

/**
 * 4 MB datasets:
 */

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/MBreverse_TH3D_Nov10_0_35_2014.root");
    ksHist_pPb[0] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[0] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[0] = (TH3D*)file1->Get("ana/XiDaughter");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/MBreverse_TH3D_Nov10_35_60_2014.root");
    ksHist_pPb[1] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[1] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[1] = (TH3D*)file1->Get("ana/XiDaughter");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/MBreverse_TH3D_Nov10_60_90_2014.root");
    ksHist_pPb[2] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[2] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[2] = (TH3D*)file1->Get("ana/XiDaughter");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/MBreverse_TH3D_Nov10_90_120_2014.root");
    ksHist_pPb[3] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[3] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[3] = (TH3D*)file1->Get("ana/XiDaughter");


/**
 * 4 HM datasets:
 */

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/HMreverse_TH3D_Nov10_120_150_2014.root");
    ksHist_pPb[4] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[4] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[4] = (TH3D*)file1->Get("ana/XiDaughter");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/HMreverse_TH3D_Nov10_150_185_2014.root");
    ksHist_pPb[5] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[5] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[5] = (TH3D*)file1->Get("ana/XiDaughter");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/HMreverse_TH3D_Nov10_185_220_2014.root");
    ksHist_pPb[6] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[6] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[6] = (TH3D*)file1->Get("ana/XiDaughter");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/HMreverse_TH3D_Nov10_220plus_2014.root");
    ksHist_pPb[7] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist_pPb[7] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist_pPb[7] = (TH3D*)file1->Get("ana/XiDaughter");
      
    TH1D* ks_HM_pPb[8][5][26];
    TH1D* la_HM_pPb[8][5][20];
    TH1D* xi_HM_pPb[8][5][20];

    double ks_pTbinsBound[27] = {1,3,4,5,6,7,8,9,10,12,14,16,18,20,22,24,26,28,30,34,38,42,46,50,56,66,90};
    double ks_ptbins[27] = {0.1,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.4,3.8,4.2,4.6,5.0,5.6,6.6,9.0};
    double ks_binwidth[26] = {0.2,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.4,0.4,0.4,0.4,0.4,0.6,1.0,2.4};
    double ks_ptbincenter[26] = {0.2,0.35,0.45,0.55,0.65,0.75,0.85,0.95,1.1,1.3,1.5,1.7,1.9,2.1,2.3,2.5,2.7,2.9,3.2,3.6,4.0,4.4,4.8,5.3,6.1,7.8};

    double la_pTbinsBound[21] = {6,8,10,12,14,16,18,20,22,24,26,28,30,34,38,42,46,50,56,66,90};
    double la_ptbins[21] = {0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.4,3.8,4.2,4.6,5.0,5.6,6.6,9.0};
    double la_ptbincenter[20] = {0.65,0.85,1.1,1.3,1.5,1.7,1.9,2.1,2.3,2.5,2.7,2.9,3.2,3.6,4.0,4.4,4.8,5.3,6.1,7.8};
    double la_binwidth[20] = {0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.4,0.4,0.4,0.4,0.4,0.6,1.0,2.4};
    
    double rpybins[6] = {11,20,27,35,42,49};
    double rpybinwidth[5] = {0.9.0.7,0.8,0.7,0.7};

    stringstream ksHistName;
    stringstream laHistName;
    stringstream xiHistName;

    for (int mult = 0; mult < 8; mult++){

        for (int rpy = 0; rpy < 5; rpy++){

            for (int pt = 0; pt < 26; pt++){
                
                ksHistName.str("");

                ksHistName << "ks2_";
                ksHistName << mult;
                ksHistName << "_";
                ksHistName << rpy;
                ksHistName << "_";
                ksHistName << pt;

                ks_HM_pPb[mult][rpy][pt] = ksHist_pPb[mult]->ProjectionZ( ksHistName.str().c_str(),rpybins[rpy]+1,rpybins[rpy+1],ks_pTbinsBound[pt]+1,ks_pTbinsBound[pt+1] );

            }

            for ( pt = 0; pt < 20; pt++){

                laHistName.str("");
                xiHistName.str("");

                laHistName << "la2_";
                laHistName << mult;
                laHistName << "_";
                laHistName << rpy;
                laHistName << "_";
                laHistName << pt;

                xiHistName << "xi2_";
                xiHistName << mult;
                xiHistName << "_";
                xiHistName << rpy;
                xiHistName << "_";
                xiHistName << pt;

                
                la_HM_pPb[mult][rpy][pt] = laHist_pPb[mult]->ProjectionZ( laHistName.str().c_str(),rpybins[rpy]+1,rpybins[rpy+1],la_pTbinsBound[pt]+1,la_pTbinsBound[pt+1] );
                xi_HM_pPb[mult][rpy][pt] = xiHist_pPb[mult]->ProjectionZ( xiHistName.str().c_str(),rpybins[rpy]+1,rpybins[rpy+1],la_pTbinsBound[pt]+1,la_pTbinsBound[pt+1] );
            }
        }
    }


/*
This is p - Pb efficiency table::::::::
 */

    TFile* t2 = new TFile("/Users/kongkong/2015Research/Efficiency/pPb2013/files/pPb_table/EPOS_pPb_30M_JAN_26_v4_2015.root");

    TH2D* hnew3 = (TH2D*)t2->Get("ks_eff");
    TH2D* hnew4 = (TH2D*)t2->Get("la_eff");

    double ks_eff_pPb[5][26];
    double la_eff_pPb[5][20];

    double ks_eff_pPb_err[5][26];
    double la_eff_pPb_err[5][20];

    for (rpy = 0; rpy < 5; rpy++){
        
        for (pt = 0; pt < 26; pt++){
            
            ks_eff_pPb[rpy][pt] = hnew3->GetBinContent(rpy+1,pt+1);
                ks_eff_pPb_err[rpy][pt] = hnew3->GetBinError(rpy+1,pt+1);
        }

        for (pt = 0; pt < 20; pt++){

            la_eff_pPb[rpy][pt] = hnew4->GetBinContent(rpy+1,pt+1);
                la_eff_pPb_err[rpy][pt] = hnew4->GetBinError(rpy+1,pt+1);
        }
    }


/*
pPb fitting:
 */

    double ks_HM_yield_pPb[8][5][26];
    double la_HM_yield_pPb[8][5][20];

    double ks_HM_pTyield_pPb[8][26];
    double la_HM_pTyield_pPb[8][20];

    double temp_ks_err_pPb[8][5];
    double temp_la_err_pPb[8][5];

    double num_ks_err_pPb[8][26];
    double num_la_err_pPb[8][20];

    TCanvas* c1 = new TCanvas();

    for(mult = 0; mult < 8; mult++){

        for(pt = 0; pt < 26; pt++){

            ks_HM_pTyield_pPb[mult][pt] = 0.0;
        }

        for(pt = 0; pt < 20; pt++){

            la_HM_pTyield_pPb[mult][pt] = 0.0;
        }
    }

c1->Print("la_fit_pPb.pdf[");

    for (pt = 0; pt < 26; pt++){
    
        for (mult = 0; mult < 8; mult++){

            for (rpy = 0; rpy < 5; rpy++){

                ks_HM_yield_pPb[mult][rpy][pt] = ks_YieldCal( ks_HM_pPb[mult][rpy][pt] );

                double ksYield_err = sqrt( ks_HM_yield_pPb[mult][rpy][pt] );
                
                    /*
                    This is the error on the yield for each mult, each rpy and each pT:
                     */               
                    temp_ks_err_pPb[mult][rpy] = errorCal_num( ks_HM_yield_pPb[mult][rpy][pt], ksYield_err, ks_eff_pPb[rpy][pt], ks_eff_pPb_err[rpy][pt] );

                        ks_HM_yield_pPb[mult][rpy][pt] = ks_HM_yield_pPb[mult][rpy][pt]/ks_eff_pPb[rpy][pt];

                            //summing over all the rpy bins:
                                ks_HM_pTyield_pPb[mult][pt] = ks_HM_yield_pPb[mult][rpy][pt] + ks_HM_pTyield_pPb[mult][pt];

            }

            num_ks_err_pPb[mult][pt] = errorCal_sum(temp_ks_err_pPb[mult][0],temp_ks_err_pPb[mult][1],temp_ks_err_pPb[mult][2],temp_ks_err_pPb[mult][3],temp_ks_err_pPb[mult][4],0.0);
            
        }
    }

    for (pt = 0; pt < 20; pt++){
    
        for (mult = 0; mult < 8; mult++){

            for (rpy = 0; rpy < 5; rpy++){

                
                la_HM_pPb[mult][rpy][pt]->Add( xi_HM_pPb[mult][rpy][pt], -1);
                    la_HM_yield_pPb[mult][rpy][pt] = la_YieldCal( la_HM_pPb[mult][rpy][pt] );

                    c1->Print("la_fit_pPb.pdf");
                    
                double laYield_err = sqrt( la_HM_yield_pPb[mult][rpy][pt] );
                    temp_la_err_pPb[mult][rpy] = errorCal_num( la_HM_yield_pPb[mult][rpy][pt], laYield_err, la_eff_pPb[rpy][pt], la_eff_pPb_err[rpy][pt] );

                        la_HM_yield_pPb[mult][rpy][pt] = la_HM_yield_pPb[mult][rpy][pt]/la_eff_pPb[rpy][pt];

                        //summing over all the rpy bins:
                            la_HM_pTyield_pPb[mult][pt] = la_HM_yield_pPb[mult][rpy][pt] + la_HM_pTyield_pPb[mult][pt];

            }

            num_la_err_pPb[mult][pt] = errorCal_sum(temp_la_err_pPb[mult][0],temp_la_err_pPb[mult][1],temp_la_err_pPb[mult][2],temp_la_err_pPb[mult][3],temp_la_err_pPb[mult][4],0.0);

        }
    }

    c1->Print("la_fit_pPb.pdf]");

    TH1D* ksSpectra[8];
    TH1D* laSpectra[8];

    double ks_ptbins_histo[28] = {0.0,0.1,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.4,3.8,4.2,4.6,5.0,5.6,6.6,9.0};
    double la_ptbins_histo[22] = {0.0,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.4,3.8,4.2,4.6,5.0,5.6,6.6,9.0};

    for (mult = 0; mult < 8; mult++){
       
        ksHistName.str("");
        laHistName.str("");
     
        ksHistName << "ksSpectra_pPb_";
        ksHistName << mult+1;
        
        laHistName << "laSpectra_pPb_";
        laHistName << mult+1;
      
        ksSpectra[mult] = new TH1D(ksHistName.str().c_str(),ksHistName.str().c_str(),27,ks_ptbins_histo);
        laSpectra[mult] = new TH1D(laHistName.str().c_str(),laHistName.str().c_str(),21,la_ptbins_histo);
        
        for (pt = 0; pt < 26; pt++){

            ksSpectra[mult]->SetBinContent(pt+2, ks_HM_pTyield_pPb[mult][pt] );
            ksSpectra[mult]->SetBinError(pt+2, num_ks_err_pPb[mult][pt] );

        }

        for (pt = 0; pt < 20; pt++){

            laSpectra[mult]->SetBinContent(pt+2, la_HM_pTyield_pPb[mult][pt] );
            laSpectra[mult]->SetBinError(pt+2, num_la_err_pPb[mult][pt] );
           
        }

        
    }

    TFile f1("../files/8MultSpectra_pPbSide_EPOS_30M_FullRpy_test_v7_26ksbins_pt.root","new");
    
    for( mult = 0; mult < 8; mult++){

        ksSpectra[mult]->Write();
        laSpectra[mult]->Write();
       
    }




}
