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

/* SOT */
#include <sot/core/task-abstract.hh>
#include <sot/core/pool.hh>

using namespace dynamicgraph::sot;
using namespace dynamicgraph;


/* --------------------------------------------------------------------- */
/* --- CLASS ----------------------------------------------------------- */
/* --------------------------------------------------------------------- */


TaskAbstract::
TaskAbstract( const std::string& n )
  :Entity(n)
  ,memoryInternal(NULL)
  ,taskSOUT( "sotTaskAbstract("+n+")::output(vector)::task" )
  ,jacobianSOUT( "sotTaskAbstract("+n+")::output(matrix)::jacobian" )
{
  taskRegistration();
  signalRegistration( taskSOUT<<jacobianSOUT );
}


void TaskAbstract::
taskRegistration( void )
{
  PoolStorage::getInstance()->registerTask(name,this);
}
