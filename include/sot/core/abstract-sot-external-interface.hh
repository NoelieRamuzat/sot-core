/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Francois Keith
 * Olivier Stasse
 * Rohan Budhiraja
 *
 * See LICENSE file
 *
 */

#ifndef ABSTRACT_SOT_EXTERNAL_INTERFACE_HH
#define ABSTRACT_SOT_EXTERNAL_INTERFACE_HH

#include <vector>
#include <map>
#include <string>
#include <sot/core/api.hh>

namespace dynamicgraph {
  namespace sot {

    class SOT_CORE_EXPORT NamedVector
    {

    private:
      std::string name_;
      std::vector<double> values_;

    public:
      NamedVector() {}
      ~NamedVector() {}

      const std::string & getName() const
      { return name_;}

      void setName(const std::string & aname)
      { name_ = aname;}

      const std::vector<double> & getValues() const
      { return values_;}

      void setValues(const std::vector<double> & values)
      { values_ = values;}

    };
    typedef NamedVector SensorValues;
    typedef NamedVector ControlValues;

    class SOT_CORE_EXPORT AbstractSotExternalInterface
    {
    public:

      AbstractSotExternalInterface(){}

      virtual ~AbstractSotExternalInterface(){}

      virtual void setupSetSensors(std::map<std::string,SensorValues> &sensorsIn)=0;
      
      virtual void nominalSetSensors(std::map<std::string, SensorValues> &sensorsIn)=0;

      virtual void cleanupSetSensors(std::map<std::string,SensorValues> &sensorsIn)=0;

      virtual void getControl(std::map<std::string,ControlValues> &)=0;
      virtual void setSecondOrderIntegration(void)=0;
      virtual void setNoIntegration(void)=0;
    };
  }
}

typedef dynamicgraph::sot::AbstractSotExternalInterface * createSotExternalInterface_t();
typedef void destroySotExternalInterface_t (dynamicgraph::sot::AbstractSotExternalInterface *);

#endif
