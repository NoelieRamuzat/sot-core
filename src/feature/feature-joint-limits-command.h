/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Florent Lamiraux
 *
 * See LICENSE file
 *
 */

#ifndef FEATURE_JOINT_LIMITS_COMMAND_H
 #define FEATURE_JOINT_LIMITS_COMMAND_H

 #include <boost/assign/list_of.hpp>

 #include <dynamic-graph/command.h>
 #include <dynamic-graph/command-setter.h>
 #include <dynamic-graph/command-getter.h>

namespace dynamicgraph { namespace sot {
  namespace command {
    namespace featureJointLimits {
      using ::dynamicgraph::command::Command;
      using ::dynamicgraph::command::Value;
      
      // Command Actuate
      class Actuate : public Command
      {
      public:
	virtual ~Actuate() {}
	/// Create command and store it in Entity
	/// \param entity instance of Entity owning this command
	/// \param docstring documentation of the command
      Actuate(FeatureJointLimits& entity, const std::string& docstring) :
	Command(entity, std::vector<Value::Type>(), docstring)
	  {
	  }
	virtual Value doExecute()
	{
	  FeatureJointLimits& fjl = static_cast<FeatureJointLimits&>(owner());
	  Flags fl( 63 ); //0x0000003f = 00000000000000000000000000111111
	  fjl.selectionSIN =  (! fl);
	  // return void
	  return Value();
	}
      }; // class Actuate
    } // namespace featureJointLimits
  } // namespace command
} /* namespace sot */} /* namespace dynamicgraph */

#endif //FEATURE_JOINT_LIMITS_COMMAND_H
