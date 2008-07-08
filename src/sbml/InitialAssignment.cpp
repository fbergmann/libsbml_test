/**
 * @file    InitialAssignment.cpp
 * @brief   Implementation of InitialAssignment and ListOfInitialAssignments.
 * @author  Ben Bornstein
 *
 * $Id$
 * $HeadURL$
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2007 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *----------------------------------------------------------------------- -->*/

#include <sbml/xml/XMLNode.h>
#include <sbml/xml/XMLAttributes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLOutputStream.h>

#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>

#include <sbml/SBO.h>
#include <sbml/SBMLVisitor.h>
#include <sbml/SBMLDocument.h>
#include <sbml/SBMLError.h>
#include <sbml/Model.h>
#include <sbml/InitialAssignment.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond doxygen-ignored */


/*
 * Creates a new InitialAssignment, optionally with its symbol attribute
 * set.
 */
InitialAssignment::InitialAssignment (const std::string& symbol) :
   SBase   ( symbol, "", -1 )
 , mMath   ( 0      )
{
}


/*
 * Destroys this InitialAssignment.
 */
InitialAssignment::~InitialAssignment ()
{
}


/*
 * Copy constructor. Creates a copy of this InitialAssignment.
 */
InitialAssignment::InitialAssignment (const InitialAssignment& orig) :
   SBase   ( orig )
 , mMath   ( 0    )
{
  if (orig.mMath) mMath = orig.mMath->deepCopy();
}


/*
 * Assignment operator
 */
InitialAssignment& InitialAssignment::operator=(const InitialAssignment& rhs)
{
  this->SBase::operator =(rhs);
  if (rhs.mMath) mMath = rhs.mMath->deepCopy();
  return *this;
}


/*
 * Accepts the given SBMLVisitor.
 *
 * @return the result of calling <code>v.visit()</code>, which indicates
 * whether or not the Visitor would like to visit the Model's next
 * InitialAssignment (if available).
 */
bool
InitialAssignment::accept (SBMLVisitor& v) const
{
  return v.visit(*this);
}


/*
 * @return a (deep) copy of this InitialAssignment.
 */
SBase*
InitialAssignment::clone () const
{
  return new InitialAssignment(*this);
}


/*
 * @return the symbol for this InitialAssignment.
 */
const string&
InitialAssignment::getSymbol () const
{
  return getId();
}


/*
 * @return the math for this InitialAssignment.
 */
const ASTNode*
InitialAssignment::getMath () const
{
  return mMath;
}


/*
 * @return true if the symbol of this InitialAssignment has been set,
 * false otherwise.
 */
bool
InitialAssignment::isSetSymbol () const
{
  return isSetId();
}


/*
 * @return true if the math for this InitialAssignment has been set,
 * false otherwise.
 */
bool
InitialAssignment::isSetMath () const
{
  return (mMath != 0);
}


/*
 * Sets the symbol of this InitialAssignment to a copy of sid.
 */
void
InitialAssignment::setSymbol (const std::string& sid)
{
  setId(sid);
}


/*
 * Sets the math of this InitialAssignment to a copy of the given
 * ASTNode.
 */
void
InitialAssignment::setMath (const ASTNode* math)
{
  if (mMath == math) return;


  delete mMath;
  mMath = (math != 0) ? math->deepCopy() : 0;
  if (mMath) mMath->setParentSBMLObject(this);
}


/*
  * Calculates and returns a UnitDefinition that expresses the units
  * returned by the math expression of this InitialAssignment.
  */
UnitDefinition * 
InitialAssignment::getDerivedUnitDefinition()
{
  if (!isSetMath())
    return NULL;
  if (!getSBMLDocument()->getModel()->isPopulatedListFormulaUnitsData())
  {
    getSBMLDocument()->getModel()->populateListFormulaUnitsData();
  }

  if (getSBMLDocument()->getModel()
    ->getFormulaUnitsData(getId(), getTypeCode()))
  {
    return getSBMLDocument()->getModel()
      ->getFormulaUnitsData(getId(), getTypeCode())
      ->getUnitDefinition();
  }
  else
  {
    return NULL;
  }
}

/*
 * Predicate returning @c true or @c false depending on whether 
 * the math expression of this InitialAssignment contains
 * parameters/numbers with undeclared units that cannot be ignored.
 */
bool 
InitialAssignment::containsUndeclaredUnits()
{
  if (!isSetMath())
    return false;
  if (!getSBMLDocument()->getModel()->isPopulatedListFormulaUnitsData())
  {
    getSBMLDocument()->getModel()->populateListFormulaUnitsData();
  }

  if (getSBMLDocument()->getModel()
    ->getFormulaUnitsData(getId(), getTypeCode()))
  {
    return getSBMLDocument()->getModel()
      ->getFormulaUnitsData(getId(), getTypeCode())
      ->getContainsUndeclaredUnits();
  }
  else
  {
    return false;
  }
}


/*
 * @return the SBMLTypeCode_t of this SBML object or SBML_UNKNOWN
 * (default).
 *
 * @see getElementName()
 */
SBMLTypeCode_t
InitialAssignment::getTypeCode () const
{
  return SBML_INITIAL_ASSIGNMENT;
}


/*
 * @return the name of this element ie "initialAssignment".
 */
const string&
InitialAssignment::getElementName () const
{
  static const string name = "initialAssignment";
  return name;
}


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to write out their contained
 * SBML objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
InitialAssignment::writeElements (XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (mMath) writeMathML(mMath, stream);
}
/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
InitialAssignment::readOtherXML (XMLInputStream& stream)
{
  bool          read = false;
  const string& name = stream.peek().getName();

  if (name == "math")
  {
    // if this is level 1 there shouldnt be any math!!!
    if (getLevel() == 1) 
    {
      logError(NotSchemaConformant, getLevel(), getVersion(),
	       "SBML Level 1 does not support MathML.");
      delete mMath;
      return false;
    }

    /* check for MathML namespace 
     * this may be explicitly declared here
     * or implicitly declared on the whole document
     */
    const XMLToken elem = stream.peek();
    unsigned int match = 0;
    int n;
    if (elem.getNamespaces().getLength() != 0)
    {
      for (n = 0; n < elem.getNamespaces().getLength(); n++)
      {
        if (!strcmp(elem.getNamespaces().getURI(n).c_str(), "http://www.w3.org/1998/Math/MathML"))
        {
          match = 1;
          break;
        }
      }
    }
    if (match == 0)
    {
      if( mSBML->getNamespaces() != NULL)
      /* check for implicit declaration */
      {
        for (n = 0; n < mSBML->getNamespaces()->getLength(); n++)
        {
          if (!strcmp(mSBML->getNamespaces()->getURI(n).c_str(), 
                                                     "http://www.w3.org/1998/Math/MathML"))
          {
            match = 1;
            break;
          }
        }
      }
    }
    if (match == 0)
    {
      logError(InvalidMathElement);
    }

    delete mMath;
    mMath = readMathML(stream);
    if (mMath) mMath->setParentSBMLObject(this);
    read  = true;
  }

  return read;
}
/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
InitialAssignment::readAttributes (const XMLAttributes& attributes)
{
  SBase::readAttributes(attributes);

  const unsigned int level   = getLevel  ();
  const unsigned int version = getVersion();

  std::vector<std::string> expectedAttributes;
  expectedAttributes.clear();
  if (level == 2 && version > 1)
  {
    expectedAttributes.push_back("metaid");
    expectedAttributes.push_back("symbol");

    expectedAttributes.push_back("sboTerm");
  }

  // check that all attributes are expected
  for (int i = 0; i < attributes.getLength(); i++)
  {
    std::vector<std::string>::const_iterator end = expectedAttributes.end();
    std::vector<std::string>::const_iterator begin = expectedAttributes.begin();
    std::string name = attributes.getName(i);
    if (std::find(begin, end, name) == end)
    {
      logUnknownAttribute(name, level, version, "<initialAssignment>");
    }
  }

  //
  // symbol: SId  { use="required" }  (L2v2)
  //
  bool assigned = attributes.readInto("symbol", mId, getErrorLog(), true);
  if (assigned && mId.size() == 0)
  {
    logEmptyString("symbol", level, version, "<initialAssignment>");
  }
  SBase::checkIdSyntax();

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v2)
  //
  if (level == 2 && (version == 2 || version == 3)) 
    mSBOTerm = SBO::readTerm(attributes, this->getErrorLog());
}
/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to write their XML attributes
 * to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 */
void
InitialAssignment::writeAttributes (XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  const unsigned int level   = getLevel  ();
  const unsigned int version = getVersion();

  //
  // symbol: SId  { use="required" }  (L2v2)
  //
  stream.writeAttribute("symbol", mId);

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v2)
  //
  if (level == 2 && (version == 2 || version == 3)) 
    SBO::writeTerm(stream, mSBOTerm);
}
/** @endcond doxygen-libsbml-internal */


/*
 * @return a (deep) copy of this ListOfInitialAssignments.
 */
SBase*
ListOfInitialAssignments::clone () const
{
  return new ListOfInitialAssignments(*this);
}


/*
 * @return the SBMLTypeCode_t of SBML objects contained in this ListOf or
 * SBML_UNKNOWN (default).
 */
SBMLTypeCode_t
ListOfInitialAssignments::getItemTypeCode () const
{
  return SBML_INITIAL_ASSIGNMENT;
}


/*
 * @return the name of this element ie "listOfInitialAssignments".
 */
const string&
ListOfInitialAssignments::getElementName () const
{
  static const string name = "listOfInitialAssignments";
  return name;
}


/** @cond doxygen-libsbml-internal */
/*
 * @return the ordinal position of the element with respect to its siblings
 * or -1 (default) to indicate the position is not significant.
 */
int
ListOfInitialAssignments::getElementPosition () const
{
  return 8;
}
/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */
/*
 * @return the SBML object corresponding to next XMLToken in the
 * XMLInputStream or NULL if the token was not recognized.
 */
SBase*
ListOfInitialAssignments::createObject (XMLInputStream& stream)
{
  const string& name   = stream.peek().getName();
  SBase*        object = 0;


  if (name == "initialAssignment")
  {
    object = new InitialAssignment();
    mItems.push_back(object);
  }

  return object;
}
/** @endcond doxygen-libsbml-internal */



/** @cond doxygen-c-only */



/**
 * Creates a new, empty InitialAssignment_t structure and returns a pointer
 * to it.
 */
LIBSBML_EXTERN
InitialAssignment_t *
InitialAssignment_create ()
{
  return new(nothrow) InitialAssignment;
}


/**
 * Creates a new InitialAssignment_t structure, optionally with its "symbol"
 * attribute value set.
 *
 * @param symbol an identifier to assign as the value of the "symbol"
 * attribute of this InitialAssignment_t structure
 *
 * @return the newly-created InitialAssignment_t structure
 */
LIBSBML_EXTERN
InitialAssignment_t *
InitialAssignment_createWithSymbol (const char *symbol)
{
  return new(nothrow) InitialAssignment(symbol ? symbol : "");
}


/**
 * Frees the given InitialAssignment_t structure.
 *
 * @param ia the InitialAssignment_t structure to free.
 */
LIBSBML_EXTERN
void
InitialAssignment_free (InitialAssignment_t *ia)
{
  delete ia;
}


/**
 * Copy constructor; creates a copy of this InitialAssignment.
 *
 * @param ia the InitialAssignment_t structure
 *
 * @return a (deep) copy of the given InitialAssignment_t structure.
 */
LIBSBML_EXTERN
InitialAssignment_t *
InitialAssignment_clone (const InitialAssignment_t *ia)
{
  return static_cast<InitialAssignment*>( ia->clone() );
}


/**
 * Get the value of the "symbol" attribute of this InitialAssignment.
 *
 * @param ia the InitialAssignment_t structure
 * 
 * @return the identifier string stored as the "symbol" attribute value
 * in this InitialAssignment.
 */
LIBSBML_EXTERN
const char *
InitialAssignment_getSymbol (const InitialAssignment_t *ia)
{
  return ia->isSetSymbol() ? ia->getSymbol().c_str() : NULL;
}


/**
 * Get the mathematical formula of this InitialAssignment.
 *
 * @param ia the InitialAssignment_t structure
 *
 * @return an ASTNode, the value of the "math" subelement of this
 * InitialAssignment
 */
LIBSBML_EXTERN
const ASTNode_t *
InitialAssignment_getMath (const InitialAssignment_t *ia)
{
  return ia->getMath();
}


/**
 * Predicate returning @c true or @c false depending on whether this
 * InitialAssignment's "symbol" attribute has been set.
 *
 * @param ia the InitialAssignment_t structure
 * 
 * @return nonzero if the "symbol" attribute of this InitialAssignment
 * has been set, zero (0) otherwise.
 */
LIBSBML_EXTERN
int
InitialAssignment_isSetSymbol (const InitialAssignment_t *ia)
{
  return static_cast<int>( ia->isSetSymbol() );
}


/**
 * Predicate returning @c true or @c false depending on whether this
 * InitialAssignment's "math" subelement contains a value.
 *
 * @param ia the InitialAssignment_t structure
 * 
 * @return nonzero if the "math" for this InitialAssignment has been set,
 * zero (0) otherwise.
 */
LIBSBML_EXTERN
int
InitialAssignment_isSetMath (const InitialAssignment_t *ia)
{
  return static_cast<int>( ia->isSetMath() );
}


/**
 * Sets the "symbol" attribute value of this InitialAssignment
 *
 * @param ia the InitialAssignment_t structure
 *
 * @param sid, the identifier of a Species, Compartment or Parameter
 * object defined elsewhere in this Model.
 */
LIBSBML_EXTERN
void
InitialAssignment_setSymbol (InitialAssignment_t *ia, const char *sid)
{
  ia->setSymbol(sid ? sid : "");
}


/**
 * Sets the "math" subelement of this InitialAssignment
 *
 * The ASTNode tree passed in @p math is copied.
 *
 * @param ia the InitialAssignment_t structure
 *
 * @param math an ASTNode tree containing the mathematical expression to
 * be used as the formula for this InitialAssignment.
 */
LIBSBML_EXTERN
void
InitialAssignment_setMath (InitialAssignment_t *ia, const ASTNode_t *math)
{
  ia->setMath(math);
}

/**
  * Calculates and returns a UnitDefinition_t that expresses the units
  * returned by the math expression of this InitialAssignment_t.
  *
  * @return a UnitDefinition_t that expresses the units of the math 
  * expression of this InitialAssignment_t.
  *
  * @note The units are calculated by applying the mathematics 
  * from the expression to the units of the <ci> elements used 
  * within the expression. Where there are parameters/numbers
  * with undeclared units the UnitDefinition_t returned by this
  * function may not accurately represent the units of the expression.
  * 
  * @see InitialAssignment_containsUndeclaredUnits()
  */
LIBSBML_EXTERN
UnitDefinition_t * 
InitialAssignment_getDerivedUnitDefinition(InitialAssignment_t *ia)
{
  return ia->getDerivedUnitDefinition();
}


/**
  * Predicate returning @c true or @c false depending on whether 
  * the math expression of this InitialAssignment_t contains
  * parameters/numbers with undeclared units.
  * 
  * @return @c true if the math expression of this InitialAssignment_t
  * includes parameters/numbers 
  * with undeclared units, @c false otherwise.
  *
  * @note a return value of @c true indicates that the UnitDefinition_t
  * returned by the getDerivedUnitDefinition function may not 
  * accurately represent the units of the expression.
  *
  * @see InitialAssignment_getDerivedUnitDefinition()
  */
LIBSBML_EXTERN
int 
InitialAssignment_containsUndeclaredUnits(InitialAssignment_t *ia)
{
  return static_cast<int>(ia->containsUndeclaredUnits());
}


/** @endcond doxygen-c-only */
