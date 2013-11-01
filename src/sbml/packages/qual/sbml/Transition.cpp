/**
 * @file:   Transition.cpp
 * @brief:  Implementation of the Transition class
 * @author: Generated by autocreate code
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#include <sbml/packages/qual/sbml/Transition.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>


using namespace std;


LIBSBML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Transition with the given level, version, and package version.
 */
Transition::Transition (unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
   ,mId ("")
   ,mName ("")
   ,mInputs (level, version, pkgVersion)
   ,mOutputs (level, version, pkgVersion)
   ,mFunctionTerms (level, version, pkgVersion)
{
  // set an SBMLNamespaces derived object of this package
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));

  // connect to child objects
  connectToChild();
}


/*
 * Creates a new Transition with the given QualPkgNamespaces object.
 */
Transition::Transition (QualPkgNamespaces* qualns)
  : SBase(qualns)
   ,mId ("")
   ,mName ("")
   ,mInputs (qualns)
   ,mOutputs (qualns)
   ,mFunctionTerms (qualns)
{
  // set the element namespace of this object
  setElementNamespace(qualns->getURI());

  // connect to child objects
  connectToChild();

  // load package extensions bound with this object (if any) 
  loadPlugins(qualns);
}


/*
 * Copy constructor for Transition.
 */
Transition::Transition (const Transition& orig)
  : SBase(orig)
{
  if (&orig == NULL)
  {
    throw SBMLConstructorException("Null argument to copy constructor");
  }
  else
  {
    mId  = orig.mId;
    mName  = orig.mName;
    mInputs  = orig.mInputs;
    mOutputs  = orig.mOutputs;
    mFunctionTerms  = orig.mFunctionTerms;

    // connect to child objects
    connectToChild();
  }
}


/*
 * Assignment for Transition.
 */
Transition&
Transition::operator=(const Transition& rhs)
{
  if (&rhs == NULL)
  {
    throw SBMLConstructorException("Null argument to assignment");
  }
  else if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId  = rhs.mId;
    mName  = rhs.mName;
    mInputs  = rhs.mInputs;
    mOutputs  = rhs.mOutputs;
    mFunctionTerms  = rhs.mFunctionTerms;

    // connect to child objects
    connectToChild();
  }
  return *this;
}


/*
 * Clone for Transition.
 */
Transition*
Transition::clone () const
{
  return new Transition(*this);
}


/*
 * Destructor for Transition.
 */
Transition::~Transition ()
{
}


SBase* 
Transition::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;
  SBase* obj = mInputs.getElementBySId(id);
  if (obj != NULL) {
    return obj;
  }
  obj = mOutputs.getElementBySId(id);
  if (obj != NULL) {
    return obj;
  }
  obj = mFunctionTerms.getElementBySId(id);
  return obj;
}


SBase*
Transition::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;

  if (mInputs.getMetaId() == metaid) return &mInputs;
  if (mOutputs.getMetaId() == metaid) return &mOutputs;
  if (mFunctionTerms.getMetaId() == metaid) return &mFunctionTerms;
  
  if (mFunctionTerms.isSetDefaultTerm() == true &&
    mFunctionTerms.getDefaultTerm()->getMetaId() == metaid)
  {
    return mFunctionTerms.getDefaultTerm();
  }

  SBase* obj = mInputs.getElementByMetaId(metaid);
  if (obj != NULL) {
    return obj;
  }
  obj = mOutputs.getElementByMetaId(metaid);
  if (obj != NULL) {
    return obj;
  }
  obj = mFunctionTerms.getElementByMetaId(metaid);
  return obj;
}


/*
 * Returns the value of the "id" attribute of this Transition.
 */
const std::string&
Transition::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this Transition.
 */
const std::string&
Transition::getName() const
{
  return mName;
}


/*
 * Returns true/false if id is set.
 */
bool
Transition::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
Transition::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
Transition::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
Transition::setName(const std::string& name)
{
  if (&(name) == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mName = name;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets id and returns value indicating success.
 */
int
Transition::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets name and returns value indicating success.
 */
int
Transition::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the  "ListOfInputs" in this Transition object.
 */
const ListOfInputs*
Transition::getListOfInputs() const
{
  return &mInputs;
}


/*
 * Returns the  "ListOfInputs" in this Transition object.
 */
ListOfInputs*
Transition::getListOfInputs()
{
  return &mInputs;
}


/*
 * Removes the nth Input from the ListOfInputs.
 */
Input*
Transition::removeInput(unsigned int n)
{
  return mInputs.remove(n);
}


/*
 * Removes the a Input with given id from the ListOfInputs.
 */
Input*
Transition::removeInput(const std::string& sid)
{
  return mInputs.remove(sid);
}


/*
 * Return the nth Input in the ListOfInputs within this Transition.
 */
Input*
Transition::getInput(unsigned int n)
{
  return mInputs.get(n);
}


/*
 * Return the nth Input in the ListOfInputs within this Transition.
 */
const Input*
Transition::getInput(unsigned int n) const
{
  return mInputs.get(n);
}


/*
 * Return a Input from the ListOfInputs by id.
 */
Input*
Transition::getInput(const std::string& sid)
{
  return mInputs.get(sid);
}


/*
 * Return a Input from the ListOfInputs by id.
 */
const Input*
Transition::getInput(const std::string& sid) const
{
  return mInputs.get(sid);
}


/*
 * Return a Input from the ListOfInputs by qualitativeSpecies.
 */
Input*
Transition::getInputBySpecies(const std::string& sid)
{
  return mInputs.getBySpecies(sid);
}


/*
 * Return a Input from the ListOfInputs by qualitativeSpecies.
 */
const Input*
Transition::getInputBySpecies(const std::string& sid) const
{
  return mInputs.getBySpecies(sid);
}


/**
 * Adds a copy the given "Input" to this Transition.
 */
int 
Transition::addInput(const Input* i)
{
  if (i == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (!(i->hasRequiredAttributes()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != i->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != i->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const SBase *>(i)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (i->isSetId() 
       && (getListOfInputs()->get(i->getId())) != NULL)
  {
    // an object with this id already exists
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mInputs.append(i);

    return LIBSBML_OPERATION_SUCCESS;
  }
}


  /**
   * Get the number of Input objects in this Transition.
   *
   * @return the number of Input objects in this Transition
   */
unsigned int 
Transition::getNumInputs() const
{
  return mInputs.size();
}


/**
 * Creates a new Output object, adds it to this Transitions
 * ListOfOutputs and returns the Output object created. 
 */
Input* 
Transition::createInput()
{
  Input* i = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    i = new Input(qualns);
  }
  catch (...)
  {
    /* here we do not create a default object as the level/version must
     * match the parent object
     *
     * so do nothing
     */
  }
  
  if (i != NULL) mInputs.appendAndOwn(i);

  return i;

}


/*
 * Returns the  "ListOfOutputs" in this Transition object.
 */
const ListOfOutputs*
Transition::getListOfOutputs() const


{
  return &mOutputs;
}


/*
 * Returns the  "ListOfOutputs" in this Transition object.
 */
ListOfOutputs*
Transition::getListOfOutputs()
{
  return &mOutputs;
}


/*
 * Removes the nth Output from the ListOfOutputs.
 */
Output*
Transition::removeOutput(unsigned int n)
{
  return mOutputs.remove(n);
}


/*
 * Removes the a Output with given id from the ListOfOutputs.
 */
Output*
Transition::removeOutput(const std::string& sid)
{
  return mOutputs.remove(sid);
}


/*
 * Return the nth Output in the ListOfOutputs within this Transition.
 */
Output*
Transition::getOutput(unsigned int n)
{
  return mOutputs.get(n);
}


/*
 * Return the nth Output in the ListOfOutputs within this Transition.
 */
const Output*
Transition::getOutput(unsigned int n) const
{
  return mOutputs.get(n);
}


/*
 * Return a Output from the ListOfOutputs by id.
 */
Output*
Transition::getOutput(const std::string& sid)
{
  return mOutputs.get(sid);
}


/*
 * Return a Output from the ListOfOutputs by id.
 */
const Output*
Transition::getOutput(const std::string& sid) const
{
  return mOutputs.get(sid);
}


/*
 * Return a Output from the ListOfOutputs by qualitativeSpecies.
 */
Output*
Transition::getOutputBySpecies(const std::string& sid)
{
  return mOutputs.getBySpecies(sid);
}


/*
 * Return a Output from the ListOfOutputs by qualitativeSpecies.
 */
const Output*
Transition::getOutputBySpecies(const std::string& sid) const
{
  return mOutputs.getBySpecies(sid);
}


/**
 * Adds a copy the given "Output" to this Transition.
 */
int 
Transition::addOutput(const Output* i)
{
  if (i == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (!(i->hasRequiredAttributes()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != i->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != i->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const SBase *>(i)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (i->isSetId() 
       && (getListOfInputs()->get(i->getId())) != NULL)
  {
    // an object with this id already exists
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mOutputs.append(i);

    return LIBSBML_OPERATION_SUCCESS;
  }
}


  /**
   * Get the number of Output objects in this Transition.
   *
   * @return the number of Output objects in this Transition
   */
unsigned int 
Transition::getNumOutputs() const
{
  return mOutputs.size();
}


/**
 * Creates a new Output object, adds it to this Transitions
 * ListOfOutputs and returns the Output object created. 
 */
Output* 
Transition::createOutput()
{
  Output* o = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    o = new Output(qualns);
  }
  catch (...)
  {
    /* here we do not create a default object as the level/version must
     * match the parent object
     *
     * so do nothing
     */
  }
  
  if (o != NULL) mOutputs.appendAndOwn(o);

  return o;

}


/*
 * Returns the  "ListOfFunctionTerms" in this Transition object.
 */
const ListOfFunctionTerms*
Transition::getListOfFunctionTerms() const


{
  return &mFunctionTerms;
}


/*
 * Returns the  "ListOfFunctionTerms" in this Transition object.
 */
ListOfFunctionTerms*
Transition::getListOfFunctionTerms()
{
  return &mFunctionTerms;
}


/*
 * Removes the nth FunctionTerm from the ListOfFunctionTerms.
 */
FunctionTerm*
Transition::removeFunctionTerm(unsigned int n)
{
  return mFunctionTerms.remove(n);
}


/*
 * Removes the a FunctionTerm with given id from the ListOfFunctionTerms.
 */
FunctionTerm*
Transition::removeFunctionTerm(const std::string& sid)
{
  return mFunctionTerms.remove(sid);
}


/*
 * Return the nth FunctionTerm in the ListOfFunctionTerms within this Transition.
 */
FunctionTerm*
Transition::getFunctionTerm(unsigned int n)
{
  return mFunctionTerms.get(n);
}


/*
 * Return the nth FunctionTerm in the ListOfFunctionTerms within this Transition.
 */
const FunctionTerm*
Transition::getFunctionTerm(unsigned int n) const
{
  return mFunctionTerms.get(n);
}


/*
 * Return a FunctionTerm from the ListOfFunctionTerms by id.
 */
FunctionTerm*
Transition::getFunctionTerm(const std::string& sid)
{
  return mFunctionTerms.get(sid);
}


/*
 * Return a FunctionTerm from the ListOfFunctionTerms by id.
 */
const FunctionTerm*
Transition::getFunctionTerm(const std::string& sid) const
{
  return mFunctionTerms.get(sid);
}


/**
 * Adds a copy the given "FunctionTerm" to this Transition.
 */
int 
Transition::addFunctionTerm(const FunctionTerm* i)
{
  if (i == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (!(i->hasRequiredAttributes()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != i->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != i->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const SBase *>(i)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    mFunctionTerms.append(i);

    return LIBSBML_OPERATION_SUCCESS;
  }
}


  /**
   * Get the number of FunctionTerm objects in this Transition.
   *
   * @return the number of FunctionTerm objects in this Transition
   */
unsigned int 
Transition::getNumFunctionTerms() const
{
  return mFunctionTerms.size();
}


/**
 * Creates a new Output object, adds it to this Transitions
 * ListOfOutputs and returns the Output object created. 
 */
FunctionTerm* 
Transition::createFunctionTerm()
{
  FunctionTerm* ft = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    ft = new FunctionTerm(qualns);
  }
  catch (...)
  {
    /* here we do not create a default object as the level/version must
     * match the parent object
     *
     * so do nothing
     */
  }
  
  if (ft != NULL) mFunctionTerms.appendAndOwn(ft);

  return ft;

}


DefaultTerm* 
Transition::createDefaultTerm()
{
  DefaultTerm* dt = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    dt = new DefaultTerm(qualns);
  }
  catch (...)
  {
    /* here we do not create a default object as the level/version must
     * match the parent object
     *
     * so do nothing
     */
  }
  
  if (dt != NULL) 
  {
    mFunctionTerms.setDefaultTerm(dt);
    dt = mFunctionTerms.getDefaultTerm();
  }


  return dt;

}


int 
Transition::setDefaultTerm(const DefaultTerm* i)
{
  if (i == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (!(i->hasRequiredAttributes()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != i->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != i->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const SBase *>(i)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    mFunctionTerms.setDefaultTerm(i);

    return LIBSBML_OPERATION_SUCCESS;
  }
}


bool
Transition::isSetDefaultTerm() const
{
  return mFunctionTerms.isSetDefaultTerm();
}

DefaultTerm*
Transition::getDefaultTerm()
{
  return mFunctionTerms.getDefaultTerm();
}

const DefaultTerm*
Transition::getDefaultTerm() const 
{
  return const_cast<const DefaultTerm*>(mFunctionTerms.getDefaultTerm());
}


List*
Transition::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_LIST(ret, sublist, mInputs, filter);
  ADD_FILTERED_LIST(ret, sublist, mOutputs, filter);
  ADD_FILTERED_LIST(ret, sublist, mFunctionTerms, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}


/*
 * Returns the XML element name of this object
 */
const std::string&
Transition::getElementName () const
{
  static const string name = "transition";
  return name;
}


/*
 * Returns the libSBML type code for this SBML object.
 */
int
Transition::getTypeCode () const
{
  return SBML_QUAL_TRANSITION;
}


/*
 * check if all the required attributes are set
 */
bool
Transition::hasRequiredAttributes () const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * check if all the required attributes are set
 */
bool
Transition::hasRequiredElements () const
{
  bool allPresent = true;

  return allPresent;
}


  /** @cond doxygenLibsbmlInternal */

/*
 * write contained elements
 */
void
Transition::writeElements (XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (getNumInputs () > 0) 
  {
    mInputs.write(stream);
  }

  if (getNumOutputs () > 0) 
  {
    mOutputs.write(stream);
  }
  if (isSetDefaultTerm() == true || getNumFunctionTerms () > 0) 
  {
    mFunctionTerms.write(stream);
  }

  SBase::writeExtensionElements(stream);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor.
 */
bool
Transition::accept (SBMLVisitor& v) const
{
  v.visit(*this);

  mInputs.accept(v);
  mOutputs.accept(v);
  mFunctionTerms.accept(v);

  v.leave(*this);

  return true;
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument.
 */
void
Transition::setSBMLDocument (SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  mInputs.setSBMLDocument(d);
  mOutputs.setSBMLDocument(d);
  mFunctionTerms.setSBMLDocument(d);

}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * 
 */
void
Transition::connectToChild()
{
  SBase::connectToChild();
  mInputs.connectToParent(this);
  mOutputs.connectToParent(this);
  mFunctionTerms.connectToParent(this);
}


  /** @endcond */
  /** @cond doxygenLibsbmlInternal */

/*
 * Enables/Disables the given package with this element.
 */
void
Transition::enablePackageInternal(const std::string& pkgURI,
             const std::string& pkgPrefix, bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mInputs.enablePackageInternal(pkgURI,pkgPrefix,flag);
  mOutputs.enablePackageInternal(pkgURI,pkgPrefix,flag);
  mFunctionTerms.enablePackageInternal(pkgURI,pkgPrefix,flag);
}


  /** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * @return the SBML object corresponding to next XMLToken in the
 * XMLInputStream or @c NULL if the token was not recognized.
 */
SBase*
Transition::createObject (XMLInputStream& stream)
{
  const string& name   = stream.peek().getName();
  SBase*        object = NULL;


  if (name == "listOfInputs")
  {
    if (mInputs.size() != 0)
    {
      getErrorLog()->logPackageError("qual", QualTransitionLOElements, 
        getPackageVersion(), getLevel(), getVersion());
    }
      
    object = &mInputs;
  }
  else if (name == "listOfOutputs")
  {
    if (mOutputs.size() != 0)
    {
      getErrorLog()->logPackageError("qual", QualTransitionLOElements, 
        getPackageVersion(), getLevel(), getVersion());
    }
      
    object = &mOutputs;
  }
  else if (name == "listOfFunctionTerms")
  {
    object = &mFunctionTerms;
  }
  return object;
}

/** @endcond */


/** @cond doxygenLibsbmlInternal */

/*
 * Get the list of expected attributes for this element.
 */
void
Transition::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");
  attributes.add("name");
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Transition::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
  const unsigned int sbmlLevel   = getLevel  ();
  const unsigned int sbmlVersion = getVersion();

  unsigned int numErrs;

  /* look to see whether an unknown attribute error was logged
   * during the read of the listOfTransitions - which will have
   * happened immediately prior to this read
  */

  if (getErrorLog() != NULL && 
    static_cast<ListOfTransitions*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)      
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("qual", QualLOTransitionsAllowedAttributes,
          getPackageVersion(), sbmlLevel, sbmlVersion, details);
      } 
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("qual", QualLOTransitionsAllowedAttributes,
          getPackageVersion(), sbmlLevel, sbmlVersion, details);
      } 
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);

  // look to see whether an unknown attribute error was logged
  if (getErrorLog() != NULL)
  {
    numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("qual", QualTransitionAllowedAttributes,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("qual", QualTransitionAllowedCoreAttributes,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
    }
  }

  bool assigned = false;

  //
  // id SId  ( use = "optional" )
  //
  assigned = attributes.readInto("id", mId);

   if (assigned == true)
  {
    // check string is not empty and correct syntax

    if (mId.empty() == true)
    {
      logEmptyString(mId, getLevel(), getVersion(), "<Transition>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(InvalidIdSyntax);
    }
  }

  //
  // name string   ( use = "optional" )
  //
  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    // check string is not empty

    if (mName.empty() == true)
    {
      logEmptyString(mName, getLevel(), getVersion(), "<Transition>");
    }
  }

}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write values of XMLAttributes to the output stream.
 */
  void
Transition::writeAttributes (XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
    stream.writeAttribute("id", getPrefix(), mId);

  if (isSetName() == true)
    stream.writeAttribute("name", getPrefix(), mName);

  SBase::writeExtensionAttributes(stream);

}


  /** @endcond */


/*
 * Constructor 
 */
ListOfTransitions::ListOfTransitions(unsigned int level, 
                                     unsigned int version, 
                                     unsigned int pkgVersion)
 : ListOf(level, version)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion)); 
}


/*
 * Constructor 
 */
ListOfTransitions::ListOfTransitions(QualPkgNamespaces* qualns)
  : ListOf(qualns)
{
  setElementNamespace(qualns->getURI());
}


/*
 * Returns a deep copy of this ListOfTransitions 
 */
ListOfTransitions* 
ListOfTransitions::clone () const
 {
  return new ListOfTransitions(*this);
}


/*
 * Get a Transition from the ListOfTransitions by index.
*/
Transition*
ListOfTransitions::get(unsigned int n)
{
  return static_cast<Transition*>(ListOf::get(n));
}


/*
 * Get a Transition from the ListOfTransitions by index.
 */
const Transition*
ListOfTransitions::get(unsigned int n) const
{
  return static_cast<const Transition*>(ListOf::get(n));
}


/*
 * Get a Transition from the ListOfTransitions by id.
 */
Transition*
ListOfTransitions::get(const std::string& sid)
{
  return const_cast<Transition*>(
    static_cast<const ListOfTransitions&>(*this).get(sid));
}


/*
 * Get a Transition from the ListOfTransitions by id.
 */
const Transition*
ListOfTransitions::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq<Transition>(sid) );
  return (result == mItems.end()) ? 0 : static_cast <Transition*> (*result);
}


/*
 * Removes the nth Transition from this ListOfTransitions
 */
Transition*
ListOfTransitions::remove(unsigned int n)
{
  return static_cast<Transition*>(ListOf::remove(n));
}


/*
 * Removes the Transition from this ListOfTransitions with the given identifier
 */
Transition*
ListOfTransitions::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq<Transition>(sid) );

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <Transition*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
ListOfTransitions::getElementName () const
{
  static const string name = "listOfTransitions";
  return name;
}


/*
 * Returns the libSBML type code for the objects in this LIST_OF.
 */
int
ListOfTransitions::getItemTypeCode () const
{
  return SBML_QUAL_TRANSITION;
}


  /** @cond doxygenLibsbmlInternal */

/*
 * Creates a new Transition in this ListOfTransitions
 */
SBase*
ListOfTransitions::createObject(XMLInputStream& stream)
{
  const std::string& name   = stream.peek().getName();
  SBase* object = NULL;

  if (name == "transition")
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    object = new Transition(qualns);
    appendAndOwn(object);
  }

  return object;
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write the namespace for the Qual package.
 */
void
ListOfTransitions::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;

  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    if (getNamespaces()->hasURI(QualExtension::getXmlnsL3V1V1()))
    {
      xmlns.add(QualExtension::getXmlnsL3V1V1(),prefix);
    }
  }

  stream << xmlns;
}


  /** @endcond */


/**
 *
 */
LIBSBML_EXTERN
Transition_t *
Transition_create(unsigned int level, unsigned int version,
                  unsigned int pkgVersion)
{
  return new Transition(level, version, pkgVersion);
}


/**
 *
 */
LIBSBML_EXTERN
void
Transition_free(Transition_t * t)
{
  if (t != NULL)
    delete t;
}


/**
 *
 */
LIBSBML_EXTERN
Transition_t *
Transition_clone(Transition_t * t)
{
  if (t != NULL)
  {
    return static_cast<Transition_t*>(t->clone());
  }
  else
  {
    return NULL;
  }
}


/**
 *
 */
LIBSBML_EXTERN
char *
Transition_getId(Transition_t * t)
{
  if (t == NULL)
    return NULL;

  return t->getId().empty() ? NULL : safe_strdup(t->getId().c_str());
}


/**
 *
 */
LIBSBML_EXTERN
char *
Transition_getName(Transition_t * t)
{
  if (t == NULL)
    return NULL;

  return t->getName().empty() ? NULL : safe_strdup(t->getName().c_str());
}


/**
 *
 */
LIBSBML_EXTERN
int
Transition_isSetId(Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->isSetId()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
Transition_isSetName(Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->isSetName()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
Transition_setId(Transition_t * t, const char * id)
{
  return (t != NULL) ? t->setId(id) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
Transition_setName(Transition_t * t, const char * name)
{
  return (t != NULL) ? t->setName(name) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
Transition_unsetId(Transition_t * t)
{
  return (t != NULL) ? t->unsetId() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
Transition_unsetName(Transition_t * t)
{
  return (t != NULL) ? t->unsetName() : LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
int
Transition_addInput(Transition_t * t, Input_t * i)
{
  return (t != NULL) ? t->addInput(i) : LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
Input_t *
Transition_createInput(Transition_t * t)
{
  return (t != NULL) ? t->createInput() : NULL;
}


LIBSBML_EXTERN
ListOf_t *
Transition_getListOfInputs(Transition_t * t)
{
  return (t != NULL) ? t->getListOfInputs() : NULL;
}


LIBSBML_EXTERN
Input_t *
Transition_getInput(Transition_t * t, unsigned int n)
{
  return (t != NULL) ? t->getInput(n) : NULL;
}


LIBSBML_EXTERN
Input_t *
Transition_getInputById(Transition_t * t, const char * sid)
{
  return (t != NULL && sid != NULL) ? t->getInput(sid) : NULL;
}


LIBSBML_EXTERN
unsigned int
Transition_getNumInputs(Transition_t * t)
{
  return (t != NULL) ? t->getNumInputs() : SBML_INT_MAX;
}


LIBSBML_EXTERN
Input_t *
Transition_removeInput(Transition_t * t, unsigned int n)
{
  return (t != NULL) ? t->removeInput(n) : NULL;
}


LIBSBML_EXTERN
Input_t *
Transition_removeInputById(Transition_t * t, const char * sid)
{
  return (t != NULL && sid != NULL) ? t->removeInput(sid) : NULL;
}


LIBSBML_EXTERN
int
Transition_addOutput(Transition_t * t, Output_t * o)
{
  return (t != NULL) ? t->addOutput(0) : LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
Output_t *
Transition_createOutput(Transition_t * t)
{
  return (t != NULL) ? t->createOutput() : NULL;
}


LIBSBML_EXTERN
ListOf_t *
Transition_getListOfOutputs(Transition_t * t)
{
  return (t != NULL) ? t->getListOfOutputs() : NULL;
}


LIBSBML_EXTERN
Output_t *
Transition_getOutput(Transition_t * t, unsigned int n)
{
  return (t != NULL) ? t->getOutput(n) : NULL;
}


LIBSBML_EXTERN
Output_t *
Transition_getOutputById(Transition_t * t, const char * sid)
{
  return (t != NULL && sid != NULL) ? t->getOutput(sid) : NULL;
}


LIBSBML_EXTERN
unsigned int
Transition_getNumOutputs(Transition_t * t)
{
  return (t != NULL) ? t->getNumOutputs() : SBML_INT_MAX;
}


LIBSBML_EXTERN
Output_t *
Transition_removeOutput(Transition_t * t, unsigned int n)
{
  return (t != NULL) ? t->removeOutput(n) : NULL;
}


LIBSBML_EXTERN
Output_t *
Transition_removeOutputById(Transition_t * t, const char * sid)
{
  return (t != NULL && sid != NULL) ? t->removeOutput(sid) : NULL;
}


LIBSBML_EXTERN
int
Transition_addFunctionTerm(Transition_t * t, FunctionTerm_t * ft)
{
  return (t != NULL) ? t->addFunctionTerm(ft) : LIBSBML_INVALID_OBJECT;
}


LIBSBML_EXTERN
FunctionTerm_t *
Transition_createFunctionTerm(Transition_t * t)
{
  return (t != NULL) ? t->createFunctionTerm() : NULL;
}



LIBSBML_EXTERN
ListOf_t *
Transition_getListOfFunctionTerms(Transition_t * t)
{
  return (t != NULL) ? t->getListOfFunctionTerms() : NULL;
}


LIBSBML_EXTERN
FunctionTerm_t *
Transition_getFunctionTerm(Transition_t * t, unsigned int n)
{
  return (t != NULL) ? t->getFunctionTerm(n) : NULL;
}


LIBSBML_EXTERN
FunctionTerm_t *
Transition_getFunctionTermById(Transition_t * t, const char * sid)
{
  return (t != NULL && sid != NULL) ? t->getFunctionTerm(sid) : NULL;
}


LIBSBML_EXTERN
unsigned int
Transition_getNumFunctionTerms(Transition_t * t)
{
  return (t != NULL) ? t->getNumFunctionTerms() : SBML_INT_MAX;
}


LIBSBML_EXTERN
FunctionTerm_t *
Transition_removeFunctionTerm(Transition_t * t, unsigned int n)
{
  return (t != NULL) ? t->removeFunctionTerm(n) : NULL;
}


LIBSBML_EXTERN
FunctionTerm_t *
Transition_removeFunctionTermById(Transition_t * t, const char * sid)
{
  return (t != NULL && sid != NULL) ? t->removeFunctionTerm(sid) : NULL;
}


/**
 *
 */
LIBSBML_EXTERN
int
Transition_hasRequiredAttributes(Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->hasRequiredAttributes()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
Transition_t *
ListOfTransitions_getById(ListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <ListOfTransitions *>(lo)->get(sid) : NULL;
}


/**
 *
 */
LIBSBML_EXTERN
Transition_t *
ListOfTransitions_removeById(ListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <ListOfTransitions *>(lo)->remove(sid) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


