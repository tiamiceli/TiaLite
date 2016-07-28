/**
 * \file anaOfDavidClusters.h
 *
 * \ingroup dots
 * 
 * \brief Class def header for a class anaOfDavidClusters
 *
 * @author miceli
 */

/** \addtogroup dots

    @{*/

#ifndef LARLITE_ANAOFDAVIDCLUSTERS_H
#define LARLITE_ANAOFDAVIDCLUSTERS_H

#include "Analysis/ana_base.h"
#include "DataFormat/cluster.h"
#include "DataFormat/hit.h"


#include <iostream>
using namespace std;

namespace larlite {
  /**
     \class anaOfDavidClusters
     User custom analysis class made by SHELL_USER_NAME
   */
  class anaOfDavidClusters : public ana_base{
  
  public:
      int e; //event number
    /// Default constructor
    anaOfDavidClusters(){ _name="anaOfDavidClusters"; _fout=0;}

    /// Default destructor
    virtual ~anaOfDavidClusters(){}

    /** IMPLEMENT in anaOfDavidClusters.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in anaOfDavidClusters.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in anaOfDavidClusters.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

  protected:
    
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
