/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Florent Lamiraux
 * Francois Bleibel
 * Francois Keith
 * Guilhem Saurel
 * Pierre Gergondet
 * Rohan Budhiraja
 * Thomas Moulard
 *
 * See LICENSE file
 *
 */

#include <sot/core/vector-constant.hh>
#include <sot/core/factory.hh>

#include "../src/matrix/vector-constant-command.h"

using namespace std;
using namespace dynamicgraph::sot;
using namespace dynamicgraph;

DYNAMICGRAPH_FACTORY_ENTITY_PLUGIN(VectorConstant,"VectorConstant");



/* --------------------------------------------------------------------- */
/* --- VECTOR ---------------------------------------------------------- */
/* --------------------------------------------------------------------- */
VectorConstant::
VectorConstant( const std::string& name )
  :Entity( name )
  ,rows(0),color(0.)
  ,SOUT( "sotVectorConstant("+name+")::output(vector)::sout" )
{
  SOUT.setDependencyType( TimeDependency<int>::BOOL_DEPENDENT );
  signalRegistration( SOUT );

  //
  // Commands
  //
  // Resize
  std::string docstring;
  docstring = "    \n"
    "    Resize the vector and fill with value stored in color field.\n"
    "      Input\n"
    "        unsigned size.\n"
    "\n";
  addCommand("resize",
	     new command::vectorConstant::Resize(*this, docstring));
  // set
  docstring = "    \n"
    "    Set value of output signal\n"
    "    \n"
    "      input:\n"
    "        - a vector\n"
    "    \n";
  addCommand("set",
	     new ::dynamicgraph::command::Setter<VectorConstant, dynamicgraph::Vector>
	     (*this, &VectorConstant::setValue, docstring));
}

void VectorConstant::
setValue(const dynamicgraph::Vector& inValue)
{
  SOUT.setConstant(inValue);
}
