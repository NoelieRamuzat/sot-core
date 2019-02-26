/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Florent Lamiraux
 * Francois Keith
 * Guilhem Saurel
 *
 * See LICENSE file
 *
 */

#ifndef __SOT_BINARY_INT_TO_UINT_HH__
#define __SOT_BINARY_INT_TO_UINT_HH__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* SOT */
#include <dynamic-graph/entity.h>
#include <sot/core/exception-task.hh>
#include <dynamic-graph/all-signals.h>

/* --------------------------------------------------------------------- */
/* --- API ------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

#if defined (WIN32)
#  if defined (binary_int_to_uint_EXPORTS)
#    define SOTBINARYINTTOUINT_EXPORT __declspec(dllexport)
#  else
#    define SOTBINARYINTTOUINT_EXPORT __declspec(dllimport)
#  endif
#else
#  define SOTBINARYINTTOUINT_EXPORT
#endif

namespace dynamicgraph { namespace sot {
namespace dg = dynamicgraph;

class SOTBINARYINTTOUINT_EXPORT BinaryIntToUint
  : public dg::Entity
{
public:
  static const std::string CLASS_NAME;
  virtual const std::string& getClassName( void ) const { return CLASS_NAME; }

  /* --- SIGNALS ------------------------------------------------------------ */
public:

  dg::SignalPtr< int,int > binaryIntSIN;
  dg::SignalTimeDependent< unsigned,int > binaryUintSOUT;

public:
  BinaryIntToUint( const std::string& name );
  virtual ~BinaryIntToUint() {}

  virtual unsigned& computeOutput( unsigned& res,int time );

  virtual void display( std::ostream& os ) const;
};


} /* namespace sot */} /* namespace dynamicgraph */


#endif
