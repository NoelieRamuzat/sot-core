/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Florent Lamiraux
 * Francois Bleibel
 * Francois Keith
 * Olivier Stasse
 * Pierre Gergondet
 * Thomas Moulard
 *
 * See LICENSE file
 *
 */

#include <sot/core/fir-filter.hh>
#include <sot/core/factory.hh>

using dynamicgraph::Vector;
using dynamicgraph::EntityRegisterer;
using dynamicgraph::Entity;

#define SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN(sotClassType,sotSigType,sotCoefType,id,className) \
  template<>								\
  std::string sotClassType<sotSigType,sotCoefType>::			\
  getTypeName( void ) { return #sotSigType; }				\
									\
  template<>								\
  const std::string sotClassType<sotSigType,sotCoefType>::CLASS_NAME	\
  = std::string(className)+"_"+#sotSigType+","+#sotCoefType+"_";	\
									\
  template<>								\
  const std::string& sotClassType<sotSigType,sotCoefType>::		\
  getClassName( void ) const { return CLASS_NAME; }				\
extern "C" {								\
  Entity *regFunction##_##id ( const std::string& objname )		\
  {									\
    return new sotClassType<sotSigType,sotCoefType>( objname );	\
  }									\
  EntityRegisterer reg##_##id					\
  ( std::string(className)+"_"+#sotSigType+"_"+#sotCoefType,	\
    &regFunction##_##id );					\
}

namespace dynamicgraph {
  namespace sot {
    using dynamicgraph::command::Value;
    using dynamicgraph::command::Command;

    SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN(FIRFilter,double,double,double_double,"FIRFilter")
    SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN(FIRFilter,Vector,double,vec_double,"FIRFilter")
    SOT_FACTORY_TEMPLATE_ENTITY_PLUGIN(FIRFilter,Vector,Matrix,vec_mat,"FIRFilter")

    template<>
    void FIRFilter<Vector, double>::reset_signal( Vector& res, const Vector& sample )
    {
  res.resize(sample.size());
  res.fill(0);
}

template<>
void FIRFilter<Vector, Matrix>::reset_signal( Vector& res, const Vector& sample )
{
  res.resize(sample.size());
  res.fill(0);
}

  } // namespace sot
} // namespace dynamicgraph

#include <sot/core/fir-filter-impl.hh>


#ifdef WIN32
#define DEFINE_SPECIFICATION(sotClassType,sotSigType,sotCoefType)	\
  sotClassType##sotSigType##sotCoefType::sotClassType##sotSigType##sotCoefType(const std::string& name):			\
  sotClassType<sotSigType,sotCoefType> (name) {};			\

namespace dynamicgraph {
  namespace sot {
typedef double Double;
    typedef Value dynamicgraph::command::Value;
    DEFINE_SPECIFICATION(FIRFilter,Double,Double)
    DEFINE_SPECIFICATION(FIRFilter,Vector,Double)
    DEFINE_SPECIFICATION(FIRFilter,Vector,Matrix)
  } // namespace sot
} // namespace dynamicgraph
#endif //WIN32
