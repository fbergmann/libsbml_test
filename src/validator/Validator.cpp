/**
 * \file    Validator.cpp
 * \brief   Base class for all SBML Validators
 * \author  Ben Bornstein
 *
 * $Id$
 * $Source$
 */
/* Copyright 2005 California Institute of Technology and Japan Science and
 * Technology Corporation.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is
 * provided in the file named "LICENSE.txt" included with this software
 * distribution.  It is also available online at
 * http://sbml.org/software/libsbml/license.html
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */


#include <algorithm>
#include <functional>

#include <sbml/SBMLTypes.h>
#include <sbml/SBMLVisitor.h>

#include <sbml/units/FormulaUnitsData.h>

#include "Constraint.h"
#include "Validator.h"


using namespace std;


//
// NOTE: ConstraintSet, ValidatorConstraints, and ValidatingVisitor used to
// be in separate .cpp and .h files, but in order to link under MSVC6 (the
// compiler doesn't instantiate templates (i.e. generate code), even when
// told explicitly to do so), the classes needed to be combined in a single
// file.
//


// ----------------------------------------------------------------------
// Apply<T> and ConstraintSet<T>
// ----------------------------------------------------------------------


/**
 * Applies a Constraint<T> to an SBML object of type T.
 */
template <typename T>
struct Apply : public unary_function<TConstraint<T>*, void>
{
  Apply (const Model& m, const T& o) : model(m), object(o) { }


  void operator() (TConstraint<T>* constraint)
  {
    constraint->check(model, object);
  }


  const Model& model;
  const T&     object;
};


template <typename T>
class ConstraintSet
{
public:

   ConstraintSet () { }
  ~ConstraintSet () { }


  /**
   * Adds a Constraint to this ConstraintSet.
   */
  void add (TConstraint<T>* c)
  {
    constraints.push_back(c);
  }

  /**
   * Applies all Constraints in this ConstraintSet to the given SBML object
   * of type T.  Constraint violations are logged to Validator.
   */
  void applyTo (const Model& model, const T& object)
  {
    for_each(constraints.begin(), constraints.end(), Apply<T>(model, object));
  }

  /**
   * @return true if this ConstraintSet is empty, false otherwise.
   */
  bool empty () const
  {
    return constraints.empty();
  }


protected:

  std::list< TConstraint<T>* > constraints;


  friend class Validator;
};



// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// ValidatorConstraints
// ----------------------------------------------------------------------

/**
 * ValidatorConstraints maintain a separate list of constraints for each
 * SBML type.  This is done so that constraints may be applied efficiently
 * during the validation process.
 */
struct ValidatorConstraints
{
  ConstraintSet<SBMLDocument>             mSBMLDocument;
  ConstraintSet<Model>                    mModel;
  ConstraintSet<FunctionDefinition>       mFunctionDefinition;
  ConstraintSet<UnitDefinition>           mUnitDefinition;
  ConstraintSet<Unit>                     mUnit;
  ConstraintSet<Compartment>              mCompartment;
  ConstraintSet<Species>                  mSpecies;
  ConstraintSet<Parameter>                mParameter;
  ConstraintSet<Rule>                     mRule;
  ConstraintSet<AlgebraicRule>            mAlgebraicRule;
  ConstraintSet<AssignmentRule>           mAssignmentRule;
  ConstraintSet<RateRule>                 mRateRule;
  ConstraintSet<Reaction>                 mReaction;
  ConstraintSet<KineticLaw>               mKineticLaw;
  ConstraintSet<SimpleSpeciesReference>   mSimpleSpeciesReference;
  ConstraintSet<SpeciesReference>         mSpeciesReference;
  ConstraintSet<ModifierSpeciesReference> mModifierSpeciesReference;
  ConstraintSet<Event>                    mEvent;
  ConstraintSet<EventAssignment>          mEventAssignment;
  ConstraintSet<InitialAssignment>        mInitialAssignment;
  ConstraintSet<Constraint>               mConstraint;
  ConstraintSet<Trigger>                  mTrigger;
  ConstraintSet<Delay>                    mDelay;

  void add (VConstraint* c);
};


/**
 * Adds the given Contraint to the appropriate ConstraintSet.
 */
void
ValidatorConstraints::add (VConstraint* c)
{
  if (dynamic_cast< TConstraint<SBMLDocument>* >(c))
  {
    mSBMLDocument.add( static_cast< TConstraint<SBMLDocument>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Model>* >(c))
  {
    mModel.add( static_cast< TConstraint<Model>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<FunctionDefinition>* >(c))
  {
    mFunctionDefinition.add
    (
      static_cast< TConstraint<FunctionDefinition>* >(c)
    );
    return;
  }

  if (dynamic_cast< TConstraint<UnitDefinition>* >(c))
  {
    mUnitDefinition.add( static_cast< TConstraint<UnitDefinition>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Unit>* >(c))
  {
    mUnit.add( static_cast< TConstraint<Unit>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Compartment>* >(c))
  {
    mCompartment.add( static_cast< TConstraint<Compartment>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Species>* >(c))
  {
    mSpecies.add( static_cast< TConstraint<Species>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Parameter>* >(c))
  {
    mParameter.add( static_cast< TConstraint<Parameter>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Rule>* >(c))
  {
    mRule.add( static_cast< TConstraint<Rule>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<AlgebraicRule>* >(c))
  {
    mAlgebraicRule.add( static_cast< TConstraint<AlgebraicRule>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<AssignmentRule>* >(c))
  {
    mAssignmentRule.add( static_cast< TConstraint<AssignmentRule>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<RateRule>* >(c))
  {
    mRateRule.add( static_cast< TConstraint<RateRule>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Reaction>* >(c))
  {
    mReaction.add( static_cast< TConstraint<Reaction>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<KineticLaw>* >(c))
  {
    mKineticLaw.add( static_cast< TConstraint<KineticLaw>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<SimpleSpeciesReference>* >(c))
  {
    mSimpleSpeciesReference.add
    (
      static_cast< TConstraint<SimpleSpeciesReference>* >(c)
    );
    /* forces constraints to be applied to modifiers */
    mModifierSpeciesReference.add
    (
      static_cast< TConstraint<ModifierSpeciesReference>* >(c)
    );
    return;
  }

  if (dynamic_cast< TConstraint<SpeciesReference>* >(c))
  {
    mSpeciesReference.add
    (
      static_cast< TConstraint<SpeciesReference>* >(c)
    );
    /* forces constraints to be applied to modifiers */
    mModifierSpeciesReference.add
    (
      static_cast< TConstraint<ModifierSpeciesReference>* >(c)
    );
    return;
  }

  if (dynamic_cast< TConstraint<ModifierSpeciesReference>* >(c))
  {
    mModifierSpeciesReference.add
    (
      static_cast< TConstraint<ModifierSpeciesReference>* >(c)
    );
    return;
  }

  if (dynamic_cast< TConstraint<Event>* >(c))
  {
    mEvent.add( static_cast< TConstraint<Event>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<EventAssignment>* >(c))
  {
    mEventAssignment.add( static_cast< TConstraint<EventAssignment>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<InitialAssignment>* >(c))
  {
    mInitialAssignment.add( static_cast< TConstraint<InitialAssignment>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Constraint>* >(c))
  {
    mConstraint.add( static_cast< TConstraint<Constraint>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Trigger>* >(c))
  {
    mTrigger.add( static_cast< TConstraint<Trigger>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Delay>* >(c))
  {
    mDelay.add( static_cast< TConstraint<Delay>* >(c) );
    return;
  }
}

// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// ValidatingVisitor
// ----------------------------------------------------------------------


/**
 * An SBMLVisitor visits each object in an SBML object tree, calling the
 * appropriate visit() method for the object visited.
 *
 * A ValidatingVisitor overrides each visit method to validate the given
 * SBML object.
 */
class ValidatingVisitor: public SBMLVisitor
{
public:

  ValidatingVisitor (Validator& v, const Model& m) : v(v), m(m) { }


  void visit (const SBMLDocument& x)
  {
    v.mConstraints->mSBMLDocument.applyTo(m, x);
  }


  void visit (const Model& x)
  {
    v.mConstraints->mModel.applyTo(m, x);
  }


  void visit (const KineticLaw& x)
  {
    v.mConstraints->mKineticLaw.applyTo(m, x);
  }


  /*
   * Visit methods should return true if the more objects of the given type
   * should be visited and false otherwise.
   *
   * For example, it doesn't make sense to keep visiting additional
   * FunctionDefinition objects in the SBML object tree if no
   * FunctionDefinition constraints have been added to the validator. ...
   */

  bool visit (const FunctionDefinition& x)
  {
    v.mConstraints->mFunctionDefinition.applyTo(m, x);
    return !v.mConstraints->mFunctionDefinition.empty();
  }


  /*
   * ... In this case, even if there are no UnitDefinitionConstraints,
   * UnitDefinitions will still need to be visited to ensure that
   * subordinate Unit objects are visited.  If no UnitDefinition or Unit
   * constraints exist, then its okay to skip further UnitDefinitions.
   */

  bool visit (const UnitDefinition& x)
  {
    v.mConstraints->mUnitDefinition.applyTo(m, x);

    return
      !v.mConstraints->mUnitDefinition.empty() ||
      !v.mConstraints->mUnit          .empty();
  }


  bool visit (const Unit& x)
  {
    v.mConstraints->mUnit.applyTo(m, x);
    return !v.mConstraints->mUnit.empty();
  }


  bool visit (const Compartment &x)
  {
    v.mConstraints->mCompartment.applyTo(m, x);
    return !v.mConstraints->mCompartment.empty();
  }


  bool visit (const Species& x)
  {
    v.mConstraints->mSpecies.applyTo(m, x);
    return !v.mConstraints->mSpecies.empty();
  }


  bool visit (const Parameter& x)
  {
    v.mConstraints->mParameter.applyTo(m, x);
    return !v.mConstraints->mParameter.empty();
  }


  bool visit (const Rule& x)
  {
    v.mConstraints->mRule.applyTo(m, x);
    return true;
  }


  bool visit (const AlgebraicRule& x)
  {
    visit( static_cast<const Rule&>(x) );
    v.mConstraints->mAlgebraicRule.applyTo(m, x);

    return true;
  }


  bool visit (const AssignmentRule& x)
  {
    visit( static_cast<const Rule&>(x) );
    v.mConstraints->mAssignmentRule.applyTo(m, x);

    return true;
  }


  bool visit (const RateRule& x)
  {
    visit( static_cast<const Rule&>(x) );
    v.mConstraints->mRateRule.applyTo(m, x);

    return true;
  }


  bool visit (const Reaction& x)
  {
    v.mConstraints->mReaction.applyTo(m, x);
    return true;
  }


  bool visit (const SimpleSpeciesReference& x)
  {
    v.mConstraints->mSimpleSpeciesReference.applyTo(m, x);
    return true;
  }


  bool visit (const SpeciesReference& x)
  {
    visit( static_cast<const SimpleSpeciesReference&>(x) );
    v.mConstraints->mSpeciesReference.applyTo(m, x);

    return
      !v.mConstraints->mSimpleSpeciesReference.empty() ||
      !v.mConstraints->mSpeciesReference      .empty();
  }


  bool visit (const ModifierSpeciesReference& x)
  {
    visit( static_cast<const SimpleSpeciesReference&>(x) );
    v.mConstraints->mModifierSpeciesReference.applyTo(m, x);

    return
      !v.mConstraints->mSimpleSpeciesReference  .empty() ||
      !v.mConstraints->mModifierSpeciesReference.empty();
  }


  bool visit (const Event& x)
  {
    v.mConstraints->mEvent.applyTo(m, x);

    return
      !v.mConstraints->mEvent          .empty() ||
      !v.mConstraints->mEventAssignment.empty();
  }


  bool visit (const EventAssignment& x)
  {
    v.mConstraints->mEventAssignment.applyTo(m, x);
    return !v.mConstraints->mEventAssignment.empty();
  }

  bool visit (const InitialAssignment& x)
  {
    v.mConstraints->mInitialAssignment.applyTo(m, x);
    return !v.mConstraints->mInitialAssignment.empty();
  }

  bool visit (const Constraint& x)
  {
    v.mConstraints->mConstraint.applyTo(m, x);
    return !v.mConstraints->mConstraint.empty();
  }

  bool visit (const Trigger& x)
  {
    v.mConstraints->mTrigger.applyTo(m, x);
    return !v.mConstraints->mTrigger.empty();
  }

  bool visit (const Delay& x)
  {
    v.mConstraints->mDelay.applyTo(m, x);
    return !v.mConstraints->mDelay.empty();
  }


protected:

  Validator&   v;
  const Model& m;
};


// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// Validator
// ----------------------------------------------------------------------


Validator::Validator (const std::string& category) : mCategory(category)
{
  mConstraints = new ValidatorConstraints();
}


Validator::~Validator ()
{
  delete mConstraints;
}


/**
 * Adds the given Contraint to this validator.
 */
void
Validator::addConstraint (VConstraint* c)
{
  mConstraints->add(c);
}


/**
 * Clears the Validator's list of messages.
 *
 * If you are validating multiple SBML documents with the same Validator,
 * call this method after you have processed the list of messages from the
 * last Validation run and before validating the next document.
 */
void
Validator::clearMessages ()
{
  mMessages.clear();
}


/**
 * @return the category covered by this Validator.  A category is a
 * string, similiar in spirit to an XML namespace, which partitions error
 * messages to prevent id conflicts.  Example categories include:
 *
 *   http://sbml.org/validator/consistency
 *   http://sbml.org/validator/consistency/units
 *   http://sbml.org/validator/compatibility/L1
 */
const std::string
Validator::getCategory () const
{
  return mCategory;
}


/**
 * @return a list of messages logged during validation.
 */
const std::list<XMLError>&
Validator::getMessages () const
{
  return mMessages;
}


/**
 * Adds the given message to this list of Validators messages.
 */
void
Validator::logMessage (const XMLError& msg)
{
  mMessages.push_back(msg);
}


/**
 * Validates the given SBMLDocument.  Error messages logged during
 * validation may be retrieved via <code>getMessages()</code>.
 *
 * @return the number of validation errors that occurred.
 */
unsigned int
Validator::validate (const SBMLDocument& d)
{
  using namespace std;
  Model* m = const_cast<SBMLDocument&>(d).getModel();
  

  if (m != NULL)
  {
    /* create list of formula units for validation */
    if (!m->isWrittenFormulaUnitsData())
      m->createListFormulaUnitsData();

    ValidatingVisitor vv(*this, *m);
    d.accept(vv);
  }

  return mMessages.size();
}


/**
 * Validates the given SBMLDocument.  Error messages logged during
 * validation may be retrieved via <code>getMessages()</code>.
 *
 * @return the number of validation errors that occurred.
 */
unsigned int
Validator::validate (const std::string& filename)
{
  SBMLReader    reader;
  SBMLDocument& d = *reader.readSBML(filename);


  for (int n = 0; n < d.getNumErrors(); ++n)
  {
    logMessage( *d.getError(n) );
  }

  return validate(d);
}

// ----------------------------------------------------------------------
