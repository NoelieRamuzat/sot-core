/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Francois Keith
 * Joseph Mirabel
 * Rohan Budhiraja
 *
 * See LICENSE file
 *
 */

#include <sot/core/integrator-euler.hh>
#include <sot/core/factory.hh>

using namespace dynamicgraph::sot;
using namespace dynamicgraph;

#define SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN_EULER(sotClassType,sotSigType,sotCoefType,className)   \
  template<>                                                                                \
  std::string sotClassType<sotSigType,sotCoefType>::                                        \
  getTypeName( void ) { return #sotSigType; }                                               \
  template<>                                                                                \
  const std::string sotClassType<sotSigType,sotCoefType>::CLASS_NAME = className;           \
  template<>                                                                                \
  const std::string& sotClassType<sotSigType,sotCoefType>::                                 \
  getClassName( void ) const { return CLASS_NAME; }                                         \
  extern "C" {                                                                              \
    Entity *regFunction##_##sotSigType##_##sotCoefType( const std::string& objname )        \
    {                                                                                       \
      return new sotClassType<sotSigType,sotCoefType>( objname );                           \
    }                                                                                       \
    EntityRegisterer                                                                        \
    regObj##_##sotSigType##_##sotCoefType(sotClassType<sotSigType,sotCoefType>::CLASS_NAME, \
                          &regFunction##_##sotSigType##_##sotCoefType );                    \
  }

using namespace std;
namespace dynamicgraph { 
  namespace sot {
    SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN_EULER(IntegratorEuler,double,double,
				       "IntegratorEulerDoubleDouble")
    SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN_EULER(IntegratorEuler,Vector,Matrix,
				       "IntegratorEulerVectorMatrix")
    SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN_EULER(IntegratorEuler,Vector,double,
				       "IntegratorEulerVectorDouble")

    template class IntegratorEuler<double,double>;
    template class IntegratorEuler<Vector,double>;
    template class IntegratorEuler<Vector,Matrix>;
  } // namespace sot
} // namespace dynamicgraph
