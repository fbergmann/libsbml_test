/**
 * @file:   FunctionTerm.cpp
 * @brief:  Implementation of the FunctionTerm class
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


#include <sbml/packages/qual/sbml/FunctionTerm.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>
#include <sbml/math/MathML.h>


using namespace std;


LIBSBML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new FunctionTerm with the given level, version, and package version.
 */
FunctionTerm::FunctionTerm (unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
   ,mResultLevel (SBML_INT_MAX)
   ,mIsSetResultLevel (false)
   ,mMath (NULL)
{
  // set an SBMLNamespaces derived object of this package
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));

  // connect to child objects
  connectToChild();
}


/*
 * Creates a new FunctionTerm with the given QualPkgNamespaces object.
 */
FunctionTerm::FunctionTerm (QualPkgNamespaces* qualns)
  : SBase(qualns)
   ,mResultLevel (SBML_INT_MAX)
   ,mIsSetResultLevel (false)
   ,mMath (NULL)
{
  // set the element namespace of this object
  setElementNamespace(qualns->getURI());

  // load package extensions bound with this object (if any) 
  loadPlugins(qualns);
}


/*
 * Copy constructor for FunctionTerm.
 */
FunctionTerm::FunctionTerm (const FunctionTerm& orig)
  : SBase(orig)
{
  if (&orig == NULL)
  {
    throw SBMLConstructorException("Null argument to copy constructor");
  }
  else
  {
    mResultLevel  = orig.mResultLevel;
    mIsSetResultLevel  = orig.mIsSetResultLevel;
    if (orig.mMath != NULL)
    {
      mMath = orig.mMath->deepCopy();
    }
    else
    {
      mMath = NULL;
    }
  }
}


/*
 * Assignment for FunctionTerm.
 */
FunctionTerm&
FunctionTerm::operator=(const FunctionTerm& rhs)
{
  if (&rhs == NULL)
  {
    throw SBMLConstructorException("Null argument to assignment");
  }
  else if (&rhs != this)
  {
    SBase::operator=(rhs);
    mResultLevel  = rhs.mResultLevel;
    mIsSetResultLevel  = rhs.mIsSetResultLevel;
    if (rhs.mMath != NULL)
    {
      mMath = rhs.mMath->deepCopy();
    }
    else
    {
      mMath = NULL;
    }
  }
  return *this;
}


/*
 * Clone for FunctionTerm.
 */
FunctionTerm*
FunctionTerm::clone () const
{
  return new FunctionTerm(*this);
}


/*
 * Destructor for FunctionTerm.
 */
FunctionTerm::~FunctionTerm ()
{
  delete mMath;
}


/*
 * Returns the value of the "resultLevel" attribute of this FunctionTerm.
 */
const int
FunctionTerm::getResultLevel() const
{
  return mResultLevel;
}


/*
 * Returns the value of the "math" attribute of this FunctionTerm.
 */
const ASTNode*
FunctionTerm::getMath() const
{
  return mMath;
}


/*
 * Returns true/false if resultLevel is set.
 */
bool
FunctionTerm::isSetResultLevel() const
{
  return mIsSetResultLevel;
}


/*
 * Returns true/false if math is set.
 */
bool
FunctionTerm::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Sets resultLevel and returns value indicating success.
 */
int
FunctionTerm::setResultLevel(int resultLevel)
{
  mResultLevel = resultLevel;
  mIsSetResultLevel = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets math and returns value indicating success.
 */
int
FunctionTerm::setMath(ASTNode* math)
{
  if (mMath == math)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (math == NULL)
  {
    delete mMath;
    mMath = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (!(math->isWellFormedASTNode()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else
  {
    delete mMath;
    mMath = (math != NULL) ?
      math->deepCopy() : NULL;
    if (mMath != NULL)
    {
      mMath->setParentSBMLObject(this);
    }
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets resultLevel and returns value indicating success.
 */
int
FunctionTerm::unsetResultLevel()
{
  mResultLevel = SBML_INT_MAX;
  mIsSetResultLevel = false;

  if (isSetResultLevel() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets math and returns value indicating success.
 */
int
FunctionTerm::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * rename attributes that are SIdRefs or instances in math
 */
void
FunctionTerm::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetMath() == true)
  {
    mMath->renameSIdRefs(oldid, newid);
  }

}


/*
 * Returns the XML element name of this object
 */
const std::string&
FunctionTerm::getElementName () const
{
  static const string name = "functionTerm";
  return name;
}


/*
 * Returns the libSBML type code for this SBML object.
 */
int
FunctionTerm::getTypeCode () const
{
  return SBML_QUAL_FUNCTION_TERM;
}


/*
 * check if all the required attributes are set
 */
bool
FunctionTerm::hasRequiredAttributes () const
{
  bool allPresent = true;

  if (isSetResultLevel() == false)
    allPresent = false;

  return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
FunctionTerm::hasRequiredElements () const
{
  bool allPresent = true;

  if (isSetMath() == false)
    allPresent = false;

  return allPresent;
}


  /** @cond doxygenLibsbmlInternal */

/*
 * write contained elements
 */
void
FunctionTerm::writeElements (XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetMath() == true)
  {
    writeMathML(getMath(), stream, getSBMLNamespaces());
  }

  SBase::writeExtensionElements(stream);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor.
 */
bool
FunctionTerm::accept (SBMLVisitor& v) const
{
  return v.visit(*this);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument.
 */
void
FunctionTerm::setSBMLDocument (SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Enables/Disables the given package with this element.
 */
void
FunctionTerm::enablePackageInternal(const std::string& pkgURI,
             const std::string& pkgPrefix, bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Get the list of expected attributes for this element.
 */
void
FunctionTerm::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("resultLevel");
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
FunctionTerm::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
  const unsigned int sbmlLevel   = getLevel  ();
  const unsigned int sbmlVersion = getVersion();

  unsigned int numErrs;

  /* look to see whether an unknown attribute error was logged
   * during the read of the listOfFunctionTerms - which will have
   * happened immediately prior to this read
  */
  if (getErrorLog() != NULL && 
    static_cast<ListOfFunctionTerms*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)      
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("qual", QualTransitionLOFuncTermAttributes,
          getPackageVersion(), sbmlLevel, sbmlVersion, details);
      } 
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("qual", QualTransitionLOFuncTermAttributes,
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
        getErrorLog()->logPackageError("qual", QualFuncTermAllowedAttributes,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("qual", QualFuncTermAllowedCoreAttributes,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
    }
  }

  //
  // resultLevel int   ( use = "required" )
  //
  numErrs = getErrorLog()->getNumErrors();
  mIsSetResultLevel = attributes.readInto("resultLevel", mResultLevel);

  if (mIsSetResultLevel == false)
  {
    if (getErrorLog() != NULL)
    {
      if (getErrorLog()->getNumErrors() == numErrs + 1 &&
              getErrorLog()->contains(XMLAttributeTypeMismatch))
      {
        getErrorLog()->remove(XMLAttributeTypeMismatch);
        getErrorLog()->logPackageError("qual", QualFuncTermResultMustBeInteger,
                     getPackageVersion(), sbmlLevel, sbmlVersion);
      }
      else
      {
        std::string message = "Qual attribute 'resultLevel' is missing.";
        getErrorLog()->logPackageError("qual", QualFuncTermAllowedAttributes,
                       getPackageVersion(), sbmlLevel, sbmlVersion, message);
      }
    }
  }
  else
  {
    if (mResultLevel < 0)
    {
      getErrorLog()->logPackageError("qual", QualFuncTermResultMustBeNonNeg,
                   getPackageVersion(), sbmlLevel, sbmlVersion);
    }
  }

}


  /** @endcond */


/** @cond doxygenLibsbmlInternal */
/*
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
FunctionTerm::readOtherXML (XMLInputStream& stream)
{
  bool          read = false;
  const string& name = stream.peek().getName();

  if (name == "math")
  {
    if (mMath != NULL)
    {
      getErrorLog()->logPackageError("qual", QualFuncTermOnlyOneMath,
                   getPackageVersion(), getLevel(), getVersion());
    }
    /* check for MathML namespace 
     * this may be explicitly declared here
     * or implicitly declared on the whole document
     */
    const XMLToken elem = stream.peek();
    const std::string prefix = checkMathMLNamespace(elem);

    // the following assumes that the SBML Namespaces object is valid
    if (stream.getSBMLNamespaces() == NULL)
    {
      stream.setSBMLNamespaces(new SBMLNamespaces(getLevel(), getVersion()));
    }

    delete mMath;
    mMath = readMathML(stream, prefix);
    if (mMath != NULL) mMath->setParentSBMLObject(this);
    read  = true;
  }

  /* ------------------------------
   *
   *   (EXTENSION)
   *
   * ------------------------------ */
  if ( SBase::readOtherXML(stream) )
    read = true;

  return read;
}
/** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write values of XMLAttributes to the output stream.
 */
  void
FunctionTerm::writeAttributes (XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetResultLevel() == true)
    stream.writeAttribute("resultLevel", getPrefix(), mResultLevel);

  SBase::writeExtensionAttributes(stream);

}


  /** @endcond */


/*
 * Constructor 
 */
ListOfFunctionTerms::ListOfFunctionTerms(unsigned int level, 
                      unsigned int version, 
                      unsigned int pkgVersion)
 : ListOf(level, version)
 , mDefaultTerm (NULL)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion)); 

  connectToChild();
}


/*
 * Constructor 
 */
ListOfFunctionTerms::ListOfFunctionTerms(QualPkgNamespaces* qualns)
  : ListOf(qualns)
  , mDefaultTerm (NULL)
{
  setElementNamespace(qualns->getURI());

  connectToChild();
}


/*
 * Returns a deep copy of this ListOfFunctionTerms 
 */
ListOfFunctionTerms* 
ListOfFunctionTerms::clone () const
{
  return new ListOfFunctionTerms(*this);
}


/*
 * Copy constructor for FunctionTerm.
 */
ListOfFunctionTerms::ListOfFunctionTerms (const ListOfFunctionTerms& orig)
  : ListOf(orig)
{
  if (&orig == NULL)
  {
    throw SBMLConstructorException("Null argument to copy constructor");
  }
  else
  {
    if (orig.mDefaultTerm != NULL)
    {
      mDefaultTerm = static_cast<DefaultTerm*>( orig.mDefaultTerm->clone() );
    }

    connectToChild();
  }
}


/*
 * Assignment for FunctionTerm.
 */
ListOfFunctionTerms&
ListOfFunctionTerms::operator=(const ListOfFunctionTerms& rhs)
{
  if (&rhs == NULL)
  {
    throw SBMLConstructorException("Null argument to assignment");
  }
  else if (&rhs != this)
  {
    ListOf::operator=(rhs);
    delete mDefaultTerm;
    if (rhs.mDefaultTerm != NULL)
    {
      mDefaultTerm = static_cast<DefaultTerm*>( rhs.mDefaultTerm->clone() );
    }
    else
    {
      mDefaultTerm = NULL;
    }

    connectToChild();
  }
  return *this;
}
/*
 * Get a FunctionTerm from the ListOfFunctionTerms by index.
*/
FunctionTerm*
ListOfFunctionTerms::get(unsigned int n)
{
  return static_cast<FunctionTerm*>(ListOf::get(n));
}


/*
 * Get a FunctionTerm from the ListOfFunctionTerms by index.
 */
const FunctionTerm*
ListOfFunctionTerms::get(unsigned int n) const
{
  return static_cast<const FunctionTerm*>(ListOf::get(n));
}


/*
 * Get a FunctionTerm from the ListOfFunctionTerms by id.
 */
FunctionTerm*
ListOfFunctionTerms::get(const std::string& sid)
{
  return const_cast<FunctionTerm*>(
    static_cast<const ListOfFunctionTerms&>(*this).get(sid));
}


/*
 * Get a FunctionTerm from the ListOfFunctionTerms by id.
 */
const FunctionTerm*
ListOfFunctionTerms::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq<FunctionTerm>(sid) );
  return (result == mItems.end()) ? 0 : static_cast <FunctionTerm*> (*result);
}


/*
 * Removes the nth FunctionTerm from this ListOfFunctionTerms
 */
FunctionTerm*
ListOfFunctionTerms::remove(unsigned int n)
{
  return static_cast<FunctionTerm*>(ListOf::remove(n));
}


/*
 * Removes the FunctionTerm from this ListOfFunctionTerms with the given identifier
 */
FunctionTerm*
ListOfFunctionTerms::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq<FunctionTerm>(sid) );

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <FunctionTerm*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
ListOfFunctionTerms::getElementName () const
{
  static const string name = "listOfFunctionTerms";
  return name;
}


/*
 * Returns the libSBML type code for the objects in this LIST_OF.
 */
int
ListOfFunctionTerms::getItemTypeCode () const
{
  return SBML_QUAL_FUNCTION_TERM;
}


DefaultTerm * 
ListOfFunctionTerms::getDefaultTerm()
{
  return mDefaultTerm;
}


const DefaultTerm * ListOfFunctionTerms::getDefaultTerm() const
{
  return const_cast<const DefaultTerm*>(mDefaultTerm);
}


int 
ListOfFunctionTerms::setDefaultTerm(const DefaultTerm* dt)
{
  if (mDefaultTerm == dt)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (dt == NULL)
  {
    delete mDefaultTerm;
    mDefaultTerm = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (getLevel() != dt->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != dt->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else
  {
    delete mDefaultTerm;
    mDefaultTerm = static_cast<DefaultTerm*>( dt->clone() );

    if (mDefaultTerm != NULL) mDefaultTerm->connectToParent(this);
    
    return LIBSBML_OPERATION_SUCCESS;
  }
}


bool 
ListOfFunctionTerms::isSetDefaultTerm() const
{
  return mDefaultTerm != NULL;
}


List*
ListOfFunctionTerms::getAllElements(ElementFilter *filter)
{
  List* ret = new List();
  List* sublist = NULL;
  for (unsigned int i = 0; i < size(); i++) {
    SBase* obj = get(i);
    if (filter == NULL || filter->filter(obj))
      ret->add(obj);
    sublist = obj->getAllElements(filter);
    ret->transferFrom(sublist);
    delete sublist;
  }

  ADD_FILTERED_POINTER(ret, sublist, mDefaultTerm, filter);  


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}

  /** @cond doxygenLibsbmlInternal */

/*
 * Creates a new FunctionTerm in this ListOfFunctionTerms
 */
SBase*
ListOfFunctionTerms::createObject(XMLInputStream& stream)
{
  const std::string& name   = stream.peek().getName();
  SBase* object = NULL;
    
  QUAL_CREATE_NS(qualns, getSBMLNamespaces());

  if (name == "functionTerm")
  {
    object = new FunctionTerm(qualns);
    appendAndOwn(object);
  }
  else if (name == "defaultTerm")
  {
    object = new DefaultTerm(qualns);
    setDefaultTerm(static_cast<DefaultTerm*>(object));

    /* teh setFunction clones the object and so need to reassign the pointer
     * or subsequent read of the term is to the wrong object
     */
    object = getDefaultTerm();
  }

  return object;
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write the namespace for the Qual package.
 */
void
ListOfFunctionTerms::writeXMLNS(XMLOutputStream& stream) const
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


  /** @cond doxygenLibsbmlInternal */

/*
 * Write the namespace for the Qual package.
 */
void
ListOfFunctionTerms::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (mDefaultTerm != NULL) mDefaultTerm->write(stream);
  
  ListOf::writeElements(stream);

  //
  // (EXTENSION)
  //
  SBase::writeExtensionElements(stream);
}


  /** @endcond */
  /** @cond doxygenLibsbmlInternal */

/*
 * 
 */
void
ListOfFunctionTerms::connectToChild()
{
  ListOf::connectToChild();
  if (mDefaultTerm != NULL)
  {
    mDefaultTerm->connectToParent(this);
  }
}
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * 
 */
void
ListOfFunctionTerms::setSBMLDocument(SBMLDocument* d)
{
  ListOf::setSBMLDocument(d);
  if (mDefaultTerm != NULL)
  {
    mDefaultTerm->setSBMLDocument(d);
  }
}
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * 
 */
bool
ListOfFunctionTerms::accept(SBMLVisitor& v) const
{
  bool result = v.visit(*this);

  if (mDefaultTerm != NULL)
  {
    mDefaultTerm->accept(v);
  }

  for (unsigned int i = 0; i < size(); i++)
  {
    get(i)->accept(v);
  }

  v.leave(*this);

  return result;
}
  /** @endcond */


/**
 *
 */
LIBSBML_EXTERN
FunctionTerm_t *
FunctionTerm_create(unsigned int level, unsigned int version,
                    unsigned int pkgVersion)
{
  return new FunctionTerm(level, version, pkgVersion);
}


/**
 *
 */
LIBSBML_EXTERN
void
FunctionTerm_free(FunctionTerm_t * ft)
{
  if (ft != NULL)
    delete ft;
}


/**
 *
 */
LIBSBML_EXTERN
FunctionTerm_t *
FunctionTerm_clone(FunctionTerm_t * ft)
{
  if (ft != NULL)
  {
    return static_cast<FunctionTerm_t*>(ft->clone());
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
int
FunctionTerm_getResultLevel(FunctionTerm_t * ft)
{
  return (ft != NULL) ? ft->getResultLevel() : SBML_INT_MAX;
}


/**
 *
 */
LIBSBML_EXTERN
int
FunctionTerm_isSetResultLevel(FunctionTerm_t * ft)
{
  return (ft != NULL) ? static_cast<int>(ft->isSetResultLevel()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
FunctionTerm_setResultLevel(FunctionTerm_t * ft, int resultLevel)
{
  return (ft != NULL) ? ft->setResultLevel(resultLevel) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
FunctionTerm_unsetResultLevel(FunctionTerm_t * ft)
{
  return (ft != NULL) ? ft->unsetResultLevel() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
FunctionTerm_hasRequiredAttributes(FunctionTerm_t * ft)
{
  return (ft != NULL) ? static_cast<int>(ft->hasRequiredAttributes()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
FunctionTerm_t *
ListOfFunctionTerms_getById(ListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <ListOfFunctionTerms *>(lo)->get(sid) : NULL;
}


/**
 *
 */
LIBSBML_EXTERN
FunctionTerm_t *
ListOfFunctionTerms_removeById(ListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <ListOfFunctionTerms *>(lo)->remove(sid) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


