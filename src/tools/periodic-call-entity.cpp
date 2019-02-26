/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Florent Lamiraux
 * Francois Bleibel
 * Guilhem Saurel
 * Nicolas Mansard
 * Thomas Moulard
 *
 * See LICENSE file
 *
 */

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* --- SOT --- */
#include <sot/core/periodic-call-entity.hh>
#include <dynamic-graph/pool.h>
#include <sot/core/debug.hh>
#include <sot/core/factory.hh>

using namespace std;
using namespace dynamicgraph::sot;


DYNAMICGRAPH_FACTORY_ENTITY_PLUGIN(PeriodicCallEntity,"PeriodicCallEntity");

/* --------------------------------------------------------------------- */
/* --- CLASS ----------------------------------------------------------- */
/* --------------------------------------------------------------------- */



PeriodicCallEntity::
PeriodicCallEntity( const string& fName )
  : Entity( fName )
  ,PeriodicCall()
  ,triger( "Tracer("+fName+")::triger" )
  ,trigerOnce( "Tracer("+fName+")::trigerOnce" )
{
  signalRegistration( triger << trigerOnce );

  triger.setFunction( boost::bind(&PeriodicCallEntity::trigerCall,this,_1,_2) );
  trigerOnce.setFunction( boost::bind(&PeriodicCallEntity::trigerOnceCall,
				      this,_1,_2) );

}

int& PeriodicCallEntity::
trigerCall( int& dummy,const int & time )
{
  run(time);
  return dummy;
}
int& PeriodicCallEntity::
trigerOnceCall( int& dummy,const int & time )
{
  run( time );
  clear();
  return dummy;
}


/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */
/* --------------------------------------------------------------------- */


void PeriodicCallEntity::
display( std::ostream& os ) const
{
  os << "PeriodicCallEntity <"<<name<<"> ";
  PeriodicCall::display( os );
}
