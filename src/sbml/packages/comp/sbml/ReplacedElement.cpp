/**
 * @file    ReplacedElement.cpp
 * @brief   Implementation of ReplacedElement, the SBaseRef derived class of replacedElements package.
 * @author  Lucian Smith
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2011 California Institute of Technology.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *------------------------------------------------------------------------- -->
 */

#include <iostream>

#include <sbml/SBMLVisitor.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLAttributes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLOutputStream.h>

#include <sbml/packages/comp/extension/CompExtension.h>
#include <sbml/packages/comp/extension/CompSBasePlugin.h>
#include <sbml/packages/comp/extension/CompModelPlugin.h>
#include <sbml/packages/comp/sbml/ReplacedElement.h>
#include <sbml/packages/comp/sbml/ListOfReplacedElements.h>
#include <sbml/packages/comp/validator/CompSBMLError.h>
#include <sbml/Model.h>

using namespace std;

LIBSBML_CPP_NAMESPACE_BEGIN

ReplacedElement::ReplacedElement (unsigned int level, unsigned int version, unsigned int pkgVersion) 
  : Replacing(level,version, pkgVersion)
  , mDeletion("")
{
  setSBMLNamespacesAndOwn(new CompPkgNamespaces(level,version,pkgVersion));  
}


ReplacedElement::ReplacedElement(CompPkgNamespaces* compns)
  : Replacing(compns)
  , mDeletion("")
{
  loadPlugins(compns);
}


ReplacedElement::ReplacedElement(const ReplacedElement& source) 
  : Replacing(source)
{
  mDeletion=source.mDeletion;
}

ReplacedElement& ReplacedElement::operator=(const ReplacedElement& source)
{
  if(&source!=this)
  {
    Replacing::operator=(source);
    mDeletion=source.mDeletion;
  }
  return *this;
}

ReplacedElement*
ReplacedElement::clone() const
{
  return new ReplacedElement(*this);
}

ReplacedElement::~ReplacedElement ()
{
}


/*
 * Sets the conversionFactor of this SBML object to a copy of conversionFactor.
 */
int
ReplacedElement::setConversionFactor (const std::string& conversionFactor)
{
  if (!SyntaxChecker::isValidSBMLSId(conversionFactor)) 
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  mConversionFactor = conversionFactor;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @return the conversionFactor of this SBML object.
 */
const string&
ReplacedElement::getConversionFactor () const
{
  return mConversionFactor;
}


/*
 * @return true if the conversionFactor of this SBML object has been set, false
 * otherwise.
 */
bool
ReplacedElement::isSetConversionFactor () const
{
  return (mConversionFactor.empty() == false);
}


/*
 * Unsets the conversionFactor of this SBML object.
 */
int
ReplacedElement::unsetConversionFactor ()
{
  mConversionFactor.erase();

  if (mConversionFactor.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Sets the deletion of this SBML object to a copy of deletion.
 */
int
ReplacedElement::setDeletion (const std::string& deletion)
{
  //Only set the deletion if we don't refer to anything already, or if we only
  // refer to the deletion.
  if (!(getNumReferents() == 0 || 
        (getNumReferents()==1 && isSetDeletion()))) {
    //LS DEBUG return something else
    return LIBSBML_OPERATION_FAILED;
  }
  if (!SyntaxChecker::isValidSBMLSId(deletion)) 
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  mDeletion = deletion;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @return the deletion of this SBML object.
 */
const string&
ReplacedElement::getDeletion () const
{
  return mDeletion;
}


/*
 * @return true if the deletion of this SBML object has been set, false
 * otherwise.
 */
bool
ReplacedElement::isSetDeletion () const
{
  return (mDeletion.empty() == false);
}


/*
 * Unsets the deletion of this SBML object.
 */
int
ReplacedElement::unsetDeletion ()
{
  mDeletion.erase();

  if (mDeletion.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}

const std::string&
ReplacedElement::getElementName () const
{
  static const std::string name = "replacedElement";
  return name;
}


int 
ReplacedElement::getNumReferents() const
{
  int retval = SBaseRef::getNumReferents();
  if (isSetDeletion()) retval++;
  return retval;
}

/** @cond doxygen-libsbml-internal */
void
ReplacedElement::addExpectedAttributes(ExpectedAttributes& attributes)
{
  Replacing::addExpectedAttributes(attributes);
  attributes.add("deletion");
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void
ReplacedElement::readAttributes (const XMLAttributes& attributes,
                                 const ExpectedAttributes& expectedAttributes)
{
  const unsigned int sbmlLevel   = getLevel  ();
  const unsigned int sbmlVersion = getVersion();

  // look to see whether an unknown attribute error was logged
  // during the read of the ListOfReplacedElements - which will have
  // happened immediately prior to this read
  if (getErrorLog() != NULL && 
    static_cast<ListOfReplacedElements*>(getParentSBMLObject())->size() < 2)
  {
    unsigned int numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)      
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("comp", CompLOReplacedElementsAllowedAttribs,
          getPackageVersion(), sbmlLevel, sbmlVersion, details);
      } 
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("comp", CompLOReplacedElementsAllowedAttribs,
          getPackageVersion(), sbmlLevel, sbmlVersion, details);
      } 
    }
  }


  XMLTriple tripleDeletion("deletion", mURI, getPrefix());
  if (attributes.readInto(tripleDeletion, mDeletion, getErrorLog(), false, getLine(), getColumn())) {
    if (!SyntaxChecker::isValidSBMLSId(mDeletion)) {
      logInvalidId("comp:deletion", mDeletion);
    }
  }
  XMLTriple tripleConversionFactor("conversionFactor", mURI, getPrefix());
  if(attributes.readInto(tripleConversionFactor, mConversionFactor, getErrorLog(), false, getLine(), getColumn())) {
    if (!SyntaxChecker::isValidSBMLSId(mConversionFactor)) {
      logInvalidId("comp:conversionFactor", mConversionFactor);
    }
  }

  //We call the base class version here because of the error checking for having set exactly one of the mutually-exclusive attributes, and two of them (deletion and conversionFactor) only exist for ReplacedElements, not SBaseRef.
  Replacing::readAttributes(attributes,expectedAttributes);
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void
ReplacedElement::writeAttributes (XMLOutputStream& stream) const
{
  Replacing::writeAttributes(stream);

  if (isSetDeletion()) {
    stream.writeAttribute("deletion", getPrefix(), mDeletion);
  }
  if (isSetConversionFactor()) {
    stream.writeAttribute("conversionFactor", getPrefix(), mConversionFactor);
  }

  Replacing::writeExtensionAttributes(stream);
}
/** @endcond */

/** @cond doxygen-libsbml-internal */
void
ReplacedElement::writeElements (XMLOutputStream& stream) const
{
  Replacing::writeElements(stream);

  Replacing::writeExtensionElements(stream);
}
/** @endcond */


int
ReplacedElement::getTypeCode () const
{
  return SBML_COMP_REPLACEDELEMENT;
}

void
ReplacedElement::renameSIdRefs(std::string oldid, std::string newid)
{
  if (mDeletion==oldid) mDeletion=newid;
  Replacing::renameSIdRefs(oldid, newid);
}


int ReplacedElement::performReplacement()
{
  if (isSetDeletion()) {
    //Deletions don't need to be replaced.
    return LIBSBML_OPERATION_SUCCESS;
  }
  //Find the various objects and plugin objects we need for this to work.
  SBase* lore = getParentSBMLObject();
  if (lore == NULL) return LIBSBML_INVALID_OBJECT;
  if (lore->getTypeCode() != SBML_LIST_OF) return LIBSBML_INVALID_OBJECT;
  SBase* parent = lore->getParentSBMLObject();
  if (parent==NULL) return LIBSBML_INVALID_OBJECT;
  SBase* ref = getReferencedElement();
  if (ref==NULL) return LIBSBML_INVALID_OBJECT;
  CompSBasePlugin* refplug = static_cast<CompSBasePlugin*>(ref->getPlugin(getPrefix()));
  if (refplug==NULL) return LIBSBML_INVALID_OBJECT;

  //Update the IDs.
  int ret = updateIDs(ref, parent);
  if (ret != LIBSBML_OPERATION_SUCCESS) return ret;

  //Perform any conversions on references in the submodel.
  ASTNode* blank = NULL;
  ret = performConversions(parent, blank);
  if (ret != LIBSBML_OPERATION_SUCCESS) return ret;

  //Now recurse down the 'replace*' tree, renaming IDs and deleting things as we go.
  for (unsigned int re=0; re<refplug->getNumReplacedElements(); re++) {
    refplug->getReplacedElement(re)->replaceWithAndMaybeDelete(parent, true, blank);
  }
  if (refplug->isSetReplacedBy()) {
    //Even if the subelement used to be replaced by something further down, it is now being replaced by the parent.  It just can't catch a break, it seems.
    refplug->getReplacedBy()->replaceWithAndMaybeDelete(parent, true, blank);
  }

  //And finally, delete the referenced object.
  return CompBase::removeFromParentAndPorts(ref);
}

SBase* 
ReplacedElement::getReferencedElementFrom(Model* model)
{
  if (!hasRequiredAttributes()) {
    return NULL;
  }
  SBase* referent = Replacing::getReferencedElementFrom(model);
  if (referent != NULL) return referent;
  if (isSetDeletion()) {
    //The deletion is not actually in the passed-in Model, but in our own Model.
    model = getParentModel(this);
    if (model==NULL) return NULL;
    if (!isSetSubmodelRef()) return NULL;
    CompModelPlugin* mplugin = static_cast<CompModelPlugin*>(model->getPlugin(getPrefix()));
    if (mplugin==NULL) return NULL;
    Submodel* submod = mplugin->getSubmodel(getSubmodelRef());
    if (submod==NULL) return NULL;
    return submod->getDeletion(getDeletion());
  }
  return NULL;
}

/** @cond doxygen-libsbml-internal */

bool
ReplacedElement::accept (SBMLVisitor& v) const
{
  v.visit(*this);

  if (isSetSBaseRef() == true)
  {
    getSBaseRef()->accept(v);
  }

  return true;
}

/** @endcond */


/**
 * 
 */
LIBSBML_EXTERN
ReplacedElement_t *
ReplacedElement_create(unsigned int level, unsigned int version,
                       unsigned int pkgVersion)
{
	return new ReplacedElement(level, version, pkgVersion);
}


/**
 * 
 */
LIBSBML_EXTERN
void
ReplacedElement_free(ReplacedElement_t * re)
{
	if (re != NULL)
		delete re;
}


/**
 * 
 */
LIBSBML_EXTERN
ReplacedElement_t *
ReplacedElement_clone(ReplacedElement_t * re)
{
	if (re != NULL)
	{
		return static_cast<ReplacedElement_t*>(re->clone());
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
ReplacedElement_getSubmodelRef(ReplacedElement_t * re)
{
	if (re == NULL)
		return NULL;

	return re->getSubmodelRef().empty() ? NULL : safe_strdup(re->getSubmodelRef().c_str());
}


/**
 * 
 */
LIBSBML_EXTERN
char *
ReplacedElement_getDeletion(ReplacedElement_t * re)
{
	if (re == NULL)
		return NULL;

	return re->getDeletion().empty() ? NULL : safe_strdup(re->getDeletion().c_str());
}


/**
 * 
 */
LIBSBML_EXTERN
char *
ReplacedElement_getConversionFactor(ReplacedElement_t * re)
{
	if (re == NULL)
		return NULL;

	return re->getConversionFactor().empty() ? NULL : safe_strdup(re->getConversionFactor().c_str());
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_isSetSubmodelRef(ReplacedElement_t * re)
{
	return (re != NULL) ? static_cast<int>(re->isSetSubmodelRef()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_isSetDeletion(ReplacedElement_t * re)
{
	return (re != NULL) ? static_cast<int>(re->isSetDeletion()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_isSetConversionFactor(ReplacedElement_t * re)
{
	return (re != NULL) ? static_cast<int>(re->isSetConversionFactor()) : 0;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_setSubmodelRef(ReplacedElement_t * re, const char * submodelRef)
{
	return (re != NULL) ? re->setSubmodelRef(submodelRef) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_setDeletion(ReplacedElement_t * re, const char * deletion)
{
	return (re != NULL) ? re->setDeletion(deletion) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_setConversionFactor(ReplacedElement_t * re, const char * conversionFactor)
{
	return (re != NULL) ? re->setConversionFactor(conversionFactor) : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_unsetSubmodelRef(ReplacedElement_t * re)
{
	return (re != NULL) ? re->unsetSubmodelRef() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_unsetDeletion(ReplacedElement_t * re)
{
	return (re != NULL) ? re->unsetDeletion() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_unsetConversionFactor(ReplacedElement_t * re)
{
	return (re != NULL) ? re->unsetConversionFactor() : LIBSBML_INVALID_OBJECT;
}


/**
 * 
 */
LIBSBML_EXTERN
int
ReplacedElement_hasRequiredAttributes(ReplacedElement_t * re)
{
	return (re != NULL) ? static_cast<int>(re->hasRequiredAttributes()) : 0;
}


LIBSBML_CPP_NAMESPACE_END

