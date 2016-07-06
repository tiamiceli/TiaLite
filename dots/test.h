/**
 * \file test.h
 *
 * \ingroup dots
 * 
 * \brief Class def header for a class test
 *
 * @author miceli
 */

/** \addtogroup dots

    @{*/

#ifndef LARLITE_TEST_H
#define LARLITE_TEST_H

#include "Analysis/ana_base.h"

namespace larlite {
  /**
     \class test
     User custom analysis class made by SHELL_USER_NAME
   */
  class test : public ana_base{
  
  public:

    /// Default constructor
    test(){ _name="test"; _fout=0;}

    /// Default destructor
    virtual ~test(){}

    /** IMPLEMENT in test.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in test.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in test.cc! 
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
