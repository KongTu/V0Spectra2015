#include "fitting.h"

using namespace std;

TSystem->Load("libRooFit");

using namespace RooFit;

void SpectraProducerIntegratedRapidity(){

    gStyle->SetErrorX(0);

/*
Getting the 3D histograms, and store in a 1D 3dimentional histogram:
 */

    TH3D* ksHist[8];
    TH3D* laHist[8];
    TH3D* xiHist[8];
    TH1D* eventHist[8];

/**
 * 4 MB datasets:
 */

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_0_35_JAN26_2015.root");
    ksHist[0] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[0] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[0] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[0] = (TH1D*)file1->Get("ana/eventNumber");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_35_60_JAN26_2015.root");
    ksHist[1] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[1] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[1] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[1] = (TH1D*)file1->Get("ana/eventNumber");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_60_90_JAN26_2015.root");
    ksHist[2] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[2] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[2] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[2] = (TH1D*)file1->Get("ana/eventNumber");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_90_120_JAN26_2015.root");
    ksHist[3] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[3] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[3] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[3] = (TH1D*)file1->Get("ana/eventNumber");


/**
 * 4 HM datasets:
 */

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_120_150_JAN26_2015.root");
    ksHist[4] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[4] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[4] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[4] = (TH1D*)file1->Get("ana/eventNumber");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_150_185_JAN26_2015.root");
    ksHist[5] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[5] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[5] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[5] = (TH1D*)file1->Get("ana/eventNumber");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_185_220_JAN26_2015.root");
    ksHist[6] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[6] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[6] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[6] = (TH1D*)file1->Get("ana/eventNumber");

    TFile* file1 = new TFile("/Users/kongkong/2014Research/ROOT_file/new_pPb_sample/Pbp/Pbp_rereco_220plus_JAN26_2015.root");
    ksHist[7] = (TH3D*)file1->Get("ana/InvMass_ks_underlying");
    laHist[7] = (TH3D*)file1->Get("ana/InvMass_la_underlying");
    xiHist[7] = (TH3D*)file1->Get("ana/XiDaughter");

    eventHist[7] = (TH1D*)file1->Get("ana/eventNumber");
        
    TH1D* ks_HM[8][5][26];
    TH1D* la_HM[8][5][20];
    TH1D* xi_HM[8][5][20];

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

                ksHistName << "ks1_";
                ksHistName << mult;
                ksHistName << "_";
                ksHistName << rpy;
                ksHistName << "_";
                ksHistName << pt;

                ks_HM[mult][rpy][pt] = ksHist[mult]->ProjectionZ( ksHistName.str().c_str(),rpybins[rpy]+1,rpybins[rpy+1],ks_pTbinsBound[pt]+1,ks_pTbinsBound[pt+1] );

            }

            for ( pt = 0; pt < 20; pt++){

                laHistName.str("");
                xiHistName.str("");

                laHistName << "la1_";
                laHistName << mult;
                laHistName << "_";
                laHistName << rpy;
                laHistName << "_";
                laHistName << pt;

                xiHistName << "xi1_";
                xiHistName << mult;
                xiHistName << "_";
                xiHistName << rpy;
                xiHistName << "_";
                xiHistName << pt;

                
                la_HM[mult][rpy][pt] = laHist[mult]->ProjectionZ( laHistName.str().c_str(),rpybins[rpy]+1,rpybins[rpy+1],la_pTbinsBound[pt]+1,la_pTbinsBound[pt+1] );
                xi_HM[mult][rpy][pt] = xiHist[mult]->ProjectionZ( xiHistName.str().c_str(),rpybins[rpy]+1,rpybins[rpy+1],la_pTbinsBound[pt]+1,la_pTbinsBound[pt+1] );
            }
        }
    }


/*
This is Pb - p efficiency table:::::::
 */
    TFile* t1 = new TFile("/Users/kongkong/2015Research/Efficiency/pPb2013/files/Pbp_table/EPOS_Pbp_30M_JAN_26_v4_2015.root");

    TH2D* hnew1 = (TH2D*)t1->Get("ks_eff");
    TH2D* hnew2 = (TH2D*)t1->Get("la_eff");

    double ks_eff_Pbp[5][26];
    double la_eff_Pbp[5][20];

    double ks_eff_Pbp_err[5][26];
    double la_eff_Pbp_err[5][20];

    for (rpy = 0; rpy < 5; rpy++){
        
        for (pt = 0; pt < 26; pt++){
            
            ks_eff_Pbp[rpy][pt] = hnew1->GetBinContent(5-rpy,pt+1);
                ks_eff_Pbp_err[rpy][pt] = hnew1->GetBinError(5-rpy,pt+1);
        }

        for (pt = 0; pt < 20; pt++){

            la_eff_Pbp[rpy][pt] = hnew2->GetBinContent(5-rpy,pt+1);
                la_eff_Pbp_err[rpy][pt] = hnew2->GetBinError(5-rpy,pt+1);
        }
    }

/*
Start to fit all histograms to obtain the eff_corr yields:
 */

    double ks_HM_yield_Pbp[8][5][26];
    double la_HM_yield_Pbp[8][5][20];

    double ks_HM_pTyield_Pbp[8][26];
    double la_HM_pTyield_Pbp[8][20];

    double temp_ks_err_Pbp[8][5];
    double temp_la_err_Pbp[8][5];

    double num_ks_err_Pbp[8][26];
    double num_la_err_Pbp[8][20];

    TCanvas* c1 = new TCanvas();



    for(mult = 0; mult < 8; mult++){

        for(pt = 0; pt < 26; pt++){

            ks_HM_pTyield_Pbp[mult][pt] = 0.0;
        }

        for(pt = 0; pt < 20; pt++){

            la_HM_pTyield_Pbp[mult][pt] = 0.0;
        }
    }

c1->Print("la_fit_Pbp.pdf[");

    for (pt = 0; pt < 26; pt++){
    
        for (mult = 0; mult < 8; mult++){

            for (rpy = 0; rpy < 5; rpy++){

                ks_HM_yield_Pbp[mult][rpy][pt] = ks_YieldCal( ks_HM[mult][rpy][pt] );

                double ksYield_err = sqrt( ks_HM_yield_Pbp[mult][rpy][pt] );
                
                    /*
                    This is the error on the yield for each mult, each rpy and each pT:
                     */               
                    temp_ks_err_Pbp[mult][rpy] = errorCal_num( ks_HM_yield_Pbp[mult][rpy][pt], ksYield_err, ks_eff_Pbp[rpy][pt], ks_eff_Pbp_err[rpy][pt] );

                        ks_HM_yield_Pbp[mult][rpy][pt] = ks_HM_yield_Pbp[mult][rpy][pt]/ks_eff_Pbp[rpy][pt];

                            //summing over all the rpy bins:
                                ks_HM_pTyield_Pbp[mult][pt] = ks_HM_yield_Pbp[mult][rpy][pt] + ks_HM_pTyield_Pbp[mult][pt];

            }

            num_ks_err_Pbp[mult][pt] = errorCal_sum(temp_ks_err_Pbp[mult][0],temp_ks_err_Pbp[mult][1],temp_ks_err_Pbp[mult][2],temp_ks_err_Pbp[mult][3],temp_ks_err_Pbp[mult][4],0.0);
            
        }
    }

    for (pt = 0; pt < 20; pt++){
    
        for (mult = 0; mult < 8; mult++){

            for (rpy = 0; rpy < 5; rpy++){

                
                la_HM[mult][rpy][pt]->Add( xi_HM[mult][rpy][pt], -1);
                    la_HM_yield_Pbp[mult][rpy][pt] = la_YieldCal( la_HM[mult][rpy][pt] );

                    c1->Print("la_fit_Pbp.pdf");
                    
                double laYield_err = sqrt( la_HM_yield_Pbp[mult][rpy][pt] );
                    temp_la_err_Pbp[mult][rpy] = errorCal_num( la_HM_yield_Pbp[mult][rpy][pt], laYield_err, la_eff_Pbp[rpy][pt], la_eff_Pbp_err[rpy][pt] );

                        la_HM_yield_Pbp[mult][rpy][pt] = la_HM_yield_Pbp[mult][rpy][pt]/la_eff_Pbp[rpy][pt];

                        //summing over all the rpy bins:
                            la_HM_pTyield_Pbp[mult][pt] = la_HM_yield_Pbp[mult][rpy][pt] + la_HM_pTyield_Pbp[mult][pt];

            }

            num_la_err_Pbp[mult][pt] = errorCal_sum(temp_la_err_Pbp[mult][0],temp_la_err_Pbp[mult][1],temp_la_err_Pbp[mult][2],temp_la_err_Pbp[mult][3],temp_la_err_Pbp[mult][4],0.0);

        }
    }

    c1->Print("la_fit_Pbp.pdf]");

/*
**************************************
 */

    TH1D* ksSpectra[8];
    TH1D* laSpectra[8];
    TH1D* ratioHist[8];

    stringstream ratioHistName;

    double ks_ptbins_histo[28] = {0.0,0.1,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.4,3.8,4.2,4.6,5.0,5.6,6.6,9.0};
    double la_ptbins_histo[22] = {0.0,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.4,3.8,4.2,4.6,5.0,5.6,6.6,9.0};

    for (mult = 0; mult < 8; mult++){
       
        ksHistName.str("");
        laHistName.str("");
        ratioHistName.str("");

        ksHistName << "ksSpectra_vtx_";
        ksHistName << mult+1;
        
        laHistName << "laSpectra_vtx_";
        laHistName << mult+1;

        ratioHistName << "ratio_vtx_";
        ratioHistName << mult+1;
      
        ksSpectra[mult] = new TH1D(ksHistName.str().c_str(),ksHistName.str().c_str(),27,ks_ptbins_histo);
        laSpectra[mult] = new TH1D(laHistName.str().c_str(),laHistName.str().c_str(),21,la_ptbins_histo);
        ratioHist[mult] = new TH1D(ratioHistName.str().c_str(),ratioHistName.str().c_str(),21,la_ptbins_histo);

        for (pt = 0; pt < 26; pt++){

            ksSpectra[mult]->SetBinContent(pt+2, ks_HM_pTyield_Pbp[mult][pt] );
            ksSpectra[mult]->SetBinError(pt+2, num_ks_err_Pbp[mult][pt] );

        }

        for (pt = 0; pt < 20; pt++){

            laSpectra[mult]->SetBinContent(pt+2, la_HM_pTyield_Pbp[mult][pt] );
            laSpectra[mult]->SetBinError(pt+2, num_la_err_Pbp[mult][pt] );
           
        }

        
    }


    TFile f1("../files/8MultSpectra_PbpSide_EPOS_30M_FullRpy_test_v7_26ksbins_pt.root","new");
    
    for( mult = 0; mult < 8; mult++){

        ksSpectra[mult]->Write();
        laSpectra[mult]->Write();
       
    }
        


}