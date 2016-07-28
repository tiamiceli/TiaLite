#ifndef LARLITE_ANAOFDAVIDCLUSTERS_CXX
#define LARLITE_ANAOFDAVIDCLUSTERS_CXX

#include "anaOfDavidClusters.h"

namespace larlite {
    
    bool anaOfDavidClusters::initialize() {
        
        //
        // This function is called in the beggining of event loop
        // Do all variable initialization you wish to do here.
        // If you have a histogram to fill in the event loop, for example,
        // here is a good place to create one on the heap (i.e. "new TH1D").
        //
        e=0;
        
        return true;
    }
    
    bool anaOfDavidClusters::analyze(storage_manager* storage) {
        
        //
        // Do your event-by-event analysis here. This function is called for
        // each event in the loop. You have "storage" pointer which contains
        // event-wise data. To see what is available, check the "Manual.pdf":
        //
        // http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
        //
        // Or you can refer to Base/DataFormatConstants.hh for available data type
        // enum values. Here is one example of getting PMT waveform collection.
        //
        // event_fifo* my_pmtfifo_v = (event_fifo*)(storage->get_data(DATA::PMFIFO));
        //
        // if( event_fifo )
        //
        //   std::cout << "Event ID: " << my_pmtfifo_v->event_id() << std::endl;
        //
        
        //get clusters and associated hits
        
        auto clusters = storage->get_data<event_cluster>("rawcluster");
        if (!clusters) {
            print(larlite::msg::kERROR, __FUNCTION__, Form("Did not find specified data product 'rawcluster'!"));
            return false;
        }
        if (!clusters->size()) {
            print(larlite::msg::kERROR, __FUNCTION__, Form("Zero reconstructed clusters in this event!"));
            return false;
        }
        
        event_hit* hits = nullptr;
        auto const& ass_info = storage->find_one_ass(clusters->id(),hits,clusters->id().second);
        if (!hits) {
            std::cerr << "Did not find: hits!" << std::endl;
            return false;
        }
        if (hits->empty()) {
            std::cout << "hits empty" << std::endl;
            return false;
        }
        
        
        
        // loop over clusters!
        for(size_t iclus = 0; iclus < clusters->size(); ++iclus)
        {
            //iclus is index of this cluster
            cout << "cluster " << iclus << " has " << clusters->at(iclus).NHits()
            << " hits with peak times:" << endl;
            
            //loop over the hits in this cluster
            for (auto const& asstd_hit_idx : ass_info.at(iclus)){
                auto const this_hit = hits->at(asstd_hit_idx);
                
                cout<< "  " << this_hit.PeakTime() << endl;
            }
            
            
            
        }//clusters
        
        e++;
        return true;
    }
    
    bool anaOfDavidClusters::finalize() {
        
        // This function is called at the end of event loop.
        // Do all variable finalization you wish to do here.
        // If you need, you can store your ROOT class instance in the output
        // file. You have an access to the output file through "_fout" pointer.
        //
        // Say you made a histogram pointer h1 to store. You can do this:
        //
        // if(_fout) { _fout->cd(); h1->Write(); }
        //
        // else 
        //   print(MSG::ERROR,__FUNCTION__,"Did not find an output file pointer!!! File not opened?");
        //
        
        return true;
    }
    
}
#endif
