/*
 * Copyright 2010, CNRS/AIST
 * Copyright 2011-2019 LAAS, CNRS
 *
 * Florent Lamiraux
 * Rohan Budhiraja
 *
 * See LICENSE file
 *
 */

#ifndef __SOT_Control_PD_HH__
#define __SOT_Control_PD_HH__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* Matrix */
#include <dynamic-graph/linear-algebra.h>
namespace dg = dynamicgraph;

/* SOT */
#include <dynamic-graph/signal-time-dependent.h>
#include <dynamic-graph/signal-ptr.h>
#include <dynamic-graph/entity.h>


/* --------------------------------------------------------------------- */
/* --- API ------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

#if defined (WIN32) 
#  if defined (control_pd_EXPORTS)
#    define ControlPD_EXPORT __declspec(dllexport)
#  else  
#    define ControlPD_EXPORT  __declspec(dllimport)
#  endif 
#else
#  define ControlPD_EXPORT
#endif

namespace dynamicgraph {
  namespace sot {

  /* --------------------------------------------------------------------- */
  /* --- CLASS ----------------------------------------------------------- */
  /* --------------------------------------------------------------------- */

  class ControlPD_EXPORT ControlPD
    : public Entity
    {

    public: /* --- CONSTRUCTOR ---- */

      ControlPD( const std::string & name );

    public: /* --- INIT --- */

      void init( const double& step);

    public: /* --- CONSTANTS --- */

      /* Default values. */
      static const double TIME_STEP_DEFAULT;   // = 0.001

    public: /* --- ENTITY INHERITANCE --- */
      static const std::string CLASS_NAME;
      virtual void display( std::ostream& os ) const; 
      virtual const std::string& getClassName( void ) const { return CLASS_NAME; }


    protected: 
  
      /* Parameters of the torque-control function: 
       * tau = kp * (qd-q) + kd* (dqd-dq) */
      double TimeStep;
      double _dimension;

    public:  /* --- SIGNALS --- */

      SignalPtr<dg::Vector,int> KpSIN;
      SignalPtr<dg::Vector,int> KdSIN;
      SignalPtr<dg::Vector,int> positionSIN;
      SignalPtr<dg::Vector,int> desiredpositionSIN;
      SignalPtr<dg::Vector,int> velocitySIN;
      SignalPtr<dg::Vector,int> desiredvelocitySIN;
      SignalTimeDependent<dg::Vector,int> controlSOUT;

    protected:

      double& setsize(int dimension);
      dg::Vector& computeControl( dg::Vector& tau,int t );

    };



} // namespace sot
} // namespace dynamicgraph



#endif // #ifndef __SOT_Control_PD_HH__
