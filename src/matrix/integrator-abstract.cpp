/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Florent Lamiraux
 * Francois Bleibel
 * Francois Keith
 * Joseph Mirabel
 * Pierre Gergondet
 * Rohan Budhiraja
 * Thomas Moulard
 *
 * See LICENSE file
 *
 */

#include <sot/core/integrator-abstract.hh>

// This ends the specialization part.
// Note that on WIN32, the specialization has to be realized 
//  before the declaration of the general model. 
#include <sot/core/integrator-abstract-impl.hh>

#ifdef WIN32
  IntegratorAbstractDouble::IntegratorAbstractDouble( const std::string& name ) : 
		IntegratorAbstract<double,double> (name) {}

  IntegratorAbstractVector::IntegratorAbstractVector( const std::string& name ) : 
		IntegratorAbstract<dynamicgraph::Vector,dynamicgraph::Matrix> (name) {}

  IntegratorAbstractVector::IntegratorAbstractVectorDouble( const std::string& name ) : 
		IntegratorAbstract<dynamicgraph::Vector,double> (name) {}
#endif

