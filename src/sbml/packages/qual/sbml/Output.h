/**
 * @file:   Output.h
 * @brief:  Implementation of the Output class
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
 *
 * @class Output
 * @ingroup qual
 * @brief @htmlinclude pkg-marker-qual.html
 * The Output class for the Qualitative Models package.
 * 
 * Each Output refers to a QualitativeSpecies that participates in (is affected by) the corresponding Transition. In Petri net models these are the output places of the transition. 
 *
 * In a logical model, a QualitativeSpecies should be referenced in at most one ListOfOutputs, (that of the Transition defining the evolution of this species). When a Transition has several outputs, it is because the referenced species share the same regulators and the same logical rules.
 */


#ifndef Output_H__
#define Output_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/qual/common/qualfwd.h>

LIBSBML_CPP_NAMESPACE_BEGIN

typedef enum
{
    OUTPUT_TRANSITION_EFFECT_PRODUCTION
  , OUTPUT_TRANSITION_EFFECT_ASSIGNMENT_LEVEL
  , OUTPUT_TRANSITION_EFFECT_UNKNOWN
} OutputTransitionEffect_t;

LIBSBML_CPP_NAMESPACE_END


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/ListOf.h>
#include <sbml/packages/qual/extension/QualExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Output : public SBase
{

protected:

  std::string   mId;
  std::string   mQualitativeSpecies;
  OutputTransitionEffect_t   mTransitionEffect;
  std::string   mName;
  int           mOutputLevel;
  bool          mIsSetOutputLevel;


public:

  /**
   * Creates a new Output with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Output
   *
   * @param version an unsigned int, the SBML Version to assign to this Output
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this Output
   */
  Output(unsigned int level      = QualExtension::getDefaultLevel(),
         unsigned int version    = QualExtension::getDefaultVersion(),
         unsigned int pkgVersion = QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new Output with the given QualPkgNamespaces object.
   *
   * @param qualns the QualPkgNamespaces object
   */
  Output(QualPkgNamespaces* qualns);


  /**
   * Copy constructor for Output.
   *
   * @param orig; the Output instance to copy.
   */
  Output(const Output& orig);


  /**
   * Assignment operator for Output.
   *
   * @param rhs; the object whose values are used as the basis
   * of the assignment
   */
  Output& operator=(const Output& rhs);


  /**
   * Creates and returns a deep copy of this Output object.
   *
   * @return a (deep) copy of this Output object.
   */
  virtual Output* clone () const;


  /**
   * Destructor for Output.
   */
  virtual ~Output();


  /**
   * Returns the value of the "id" attribute of this Output.
   *
   * @return the value of the "id" attribute of this Output as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "qualitativeSpecies" attribute of this Output.
   *
   * @return the value of the "qualitativeSpecies" attribute of this Output as a string.
   */
  virtual const std::string& getQualitativeSpecies() const;


  /**
   * Returns the value of the "transitionEffect" attribute of this Output.
   *
   * @return the value of the "transitionEffect" attribute of this Output as a string.
   */
  const OutputTransitionEffect_t getTransitionEffect() const;


  /**
   * Returns the value of the "name" attribute of this Output.
   *
   * @return the value of the "name" attribute of this Output as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Returns the value of the "outputLevel" attribute of this Output.
   *
   * @return the value of the "outputLevel" attribute of this Output as a integer.
   */
  virtual const int getOutputLevel() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Output's "id" attribute has been set.
   *
   * @return @c true if this Output's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Output's "qualitativeSpecies" attribute has been set.
   *
   * @return @c true if this Output's "qualitativeSpecies" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetQualitativeSpecies() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Output's "transitionEffect" attribute has been set.
   *
   * @return @c true if this Output's "transitionEffect" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTransitionEffect() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Output's "name" attribute has been set.
   *
   * @return @c true if this Output's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Output's "outputLevel" attribute has been set.
   *
   * @return @c true if this Output's "outputLevel" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetOutputLevel() const;


  /**
   * Sets the value of the "id" attribute of this Output.
   *
   * @param id; const std::string& value of the "id" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "qualitativeSpecies" attribute of this Output.
   *
   * @param qualitativeSpecies; const std::string& value of the "qualitativeSpecies" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setQualitativeSpecies(const std::string& qualitativeSpecies);


  /**
   * Sets the value of the "transitionEffect" attribute of this Output.
   *
   * @param transitionEffect; const std::string& value of the "transitionEffect" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  int setTransitionEffect(const OutputTransitionEffect_t transitionEffect);


  /**
   * Sets the value of the "name" attribute of this Output.
   *
   * @param name; const std::string& value of the "name" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setName(const std::string& name);


  /**
   * Sets the value of the "outputLevel" attribute of this Output.
   *
   * @param outputLevel; int value of the "outputLevel" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setOutputLevel(int outputLevel);


  /**
   * Unsets the value of the "id" attribute of this Output.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "qualitativeSpecies" attribute of this Output.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetQualitativeSpecies();


  /**
   * Unsets the value of the "transitionEffect" attribute of this Output.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  int unsetTransitionEffect();


  /**
   * Unsets the value of the "name" attribute of this Output.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetName();


  /**
   * Unsets the value of the "outputLevel" attribute of this Output.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   * @li LIBSBML_OPERATION_FAILED
   */
  virtual int unsetOutputLevel();


  /**
   * Renames all the @c SIdRef attributes on this element, including any
   * found in MathML content (if such exists).
   *
   * This method works by looking at all attributes and (if appropriate)
   * mathematical formulas, comparing the identifiers to the value of @p
   * oldid.  If any matches are found, the matching identifiers are replaced
   * with @p newid.  The method does @em not descend into child elements.
   *
   * @param oldid the old identifier
   * @param newid the new identifier
   */
   virtual void renameSIdRefs(const std::string& oldid, const std::string& newid);


	/**
   * Returns the XML element name of this object, which for Output, is
   * always @c "output".
   *
   * @return the name of this element, i.e. @c "output".
   */
  virtual const std::string& getElementName () const;


  /**
   * Returns the libSBML type code of this object instance.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @link SBMLQualTypeCode_t#SBML_QUAL_OUTPUT SBML_QUAL_OUTPUT@endlink
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode () const;


  /**
   * Predicate returning @c true if all the required attributes
   * for this Output object have been set.
   *
   * @note The required attributes for a Output object are:
   * @li "qualitativeSpecies"
   * @li "transitionEffect"
   *
   * @return a boolean value indicating whether all the required
   * attributes for this object have been defined.
   */
  virtual bool hasRequiredAttributes() const;


  /** @cond doxygenLibsbmlInternal */

  /**
   * Subclasses should override this method to write out their contained
   * SBML objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements (XMLOutputStream& stream) const;


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor.
   */
  virtual bool accept (SBMLVisitor& v) const;


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument.
   */
  virtual void setSBMLDocument (SBMLDocument* d);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/Disables the given package with this element.
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
               const std::string& pkgPrefix, bool flag);


  /** @endcond */


protected:

  /** @cond doxygenLibsbmlInternal */

  /**
   * Get the list of expected attributes for this element.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Read values from the given XMLAttributes set into their specific fields.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Write values of XMLAttributes to the output stream.
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;


  /** @endcond */



};

/**
 * @class ListOfOutputs
 * @ingroup qual
 * @brief @htmlinclude pkg-marker-qual.html
 * Implementation of the %ListOfOutputs construct from the 'qual' package.
 * 
 * The ListOfOutputs is a container for the Output elements of a Transition.
 * 
 * @copydetails doc_what_is_listof
 *
 * @see Output
 */
class LIBSBML_EXTERN ListOfOutputs : public ListOf
{

public:

  /**
   * Creates a new ListOfOutputs with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ListOfOutputs
   *
   * @param version an unsigned int, the SBML Version to assign to this ListOfOutputs
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this ListOfOutputs
   */
  ListOfOutputs(unsigned int level      = QualExtension::getDefaultLevel(),
                unsigned int version    = QualExtension::getDefaultVersion(),
                unsigned int pkgVersion = QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfOutputs with the given QualPkgNamespaces object.
   *
   * @param qualns the QualPkgNamespaces object
   */
  ListOfOutputs(QualPkgNamespaces* qualns);


  /**
   * Creates and returns a deep copy of this ListOfOutputs object.
   *
   * @return a (deep) copy of this ListOfOutputs object.
   */
  virtual ListOfOutputs* clone () const;


  /**
   * Get a Output from the ListOfOutputs.
   *
   * @param n the index number of the Output to get.
   *
   * @return the nth Output in this ListOfOutputs.
   *
   * @see size()
   */
  virtual Output* get(unsigned int n);


  /**
   * Get a Output from the ListOfOutputs.
   *
   * @param n the index number of the Output to get.
   *
   * @return the nth Output in this ListOfOutputs.
   *
   * @see size()
   */
  virtual const Output* get(unsigned int n) const;


  /**
   * Get a Output from the ListOfOutputs
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Output to get.
   *
   * @return Output in this ListOfOutputs
   * with the given id or NULL if no such
   * Output exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual Output* get(const std::string& sid);


  /**
   * Get a Output from the ListOfOutputs
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Output to get.
   *
   * @return Output in this ListOfOutputs
   * with the given id or NULL if no such
   * Output exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual const Output* get(const std::string& sid) const;


  /**
   * Get a Output from the ListOfInputs
   * based on the qualitativeSpecies to which it refers.
   *
   * @param sid a string representing the qualitativeSpecies attribute
   * of the Output to get.
   *
   * @return the first Output in this ListOfInputs
   * with the given qualitativeSpecies or NULL if no such
   * Output exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  const Output* getBySpecies(const std::string& sid) const;


  /**
   * Get a Output from the ListOfInputs
   * based on the qualitativeSpecies to which it refers.
   *
   * @param sid a string representing the qualitativeSpecies attribute
   * of the Output to get.
   *
   * @return the first Output in this ListOfInputs
   * with the given qualitativeSpecies or NULL if no such
   * Output exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  Output* getBySpecies(const std::string& sid);


  /**
   * Removes the nth Input from this ListOfInputs
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the Output to remove.
   *
   * @see size()
   */
  virtual Output* remove(unsigned int n);


  /**
   * Removes the Output from this ListOfOutputs with the given identifier
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the Output to remove.
   *
   * @return the Output removed. As mentioned above, the caller owns the
   * returned item.
   */
  virtual Output* remove(const std::string& sid);


  /**
   * Returns the XML element name of this object, which for ListOfOutputs, is
   * always @c "listOfOutputs".
   *
   * @return the name of this element, i.e. @c "listOfOutputs".
   */
  virtual const std::string& getElementName () const;


  /**
   * Returns the libSBML type code for the SBML objects
   * contained in this ListOf object.
   * 
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for objects contained in this list:
   * @link SBMLTypeCode_t#SBML_QUAL_OUTPUT SBML_QUAL_OUTPUT@endlink (default).
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode () const;


protected:

  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new Output in this ListOfOutputs
   */
  virtual SBase* createObject(XMLInputStream& stream);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

  /**
   * Write the namespace for the Qual package.
   */
  virtual void writeXMLNS(XMLOutputStream& stream) const;


  /** @endcond */



};



LIBSBML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSBML_EXTERN
Output_t *
Output_create(unsigned int level, unsigned int version,
              unsigned int pkgVersion);


LIBSBML_EXTERN
void
Output_free(Output_t * o);


LIBSBML_EXTERN
Output_t *
Output_clone(Output_t * o);


LIBSBML_EXTERN
char *
Output_getId(Output_t * o);


LIBSBML_EXTERN
char *
Output_getQualitativeSpecies(Output_t * o);


LIBSBML_EXTERN
OutputTransitionEffect_t
Output_getTransitionEffect(Output_t * o);


LIBSBML_EXTERN
char *
Output_getName(Output_t * o);


LIBSBML_EXTERN
int
Output_getOutputLevel(Output_t * o);


LIBSBML_EXTERN
int
Output_isSetId(Output_t * o);


LIBSBML_EXTERN
int
Output_isSetQualitativeSpecies(Output_t * o);


LIBSBML_EXTERN
int
Output_isSetTransitionEffect(Output_t * o);


LIBSBML_EXTERN
int
Output_isSetName(Output_t * o);


LIBSBML_EXTERN
int
Output_isSetOutputLevel(Output_t * o);


LIBSBML_EXTERN
int
Output_setId(Output_t * o, const char * id);


LIBSBML_EXTERN
int
Output_setQualitativeSpecies(Output_t * o, const char * qualitativeSpecies);


LIBSBML_EXTERN
int
Output_setTransitionEffect(Output_t * o, const char * transitionEffect);


LIBSBML_EXTERN
int
Output_setName(Output_t * o, const char * name);


LIBSBML_EXTERN
int
Output_setOutputLevel(Output_t * o, int outputLevel);


LIBSBML_EXTERN
int
Output_unsetId(Output_t * o);


LIBSBML_EXTERN
int
Output_unsetQualitativeSpecies(Output_t * o);


LIBSBML_EXTERN
int
Output_unsetTransitionEffect(Output_t * o);


LIBSBML_EXTERN
int
Output_unsetName(Output_t * o);


LIBSBML_EXTERN
int
Output_unsetOutputLevel(Output_t * o);


LIBSBML_EXTERN
int
Output_hasRequiredAttributes(Output_t * o);


LIBSBML_EXTERN
Output_t *
ListOfOutputs_getById(ListOf_t * lo, const char * sid);


LIBSBML_EXTERN
Output_t *
ListOfOutputs_removeById(ListOf_t * lo, const char * sid);


LIBSBML_EXTERN
const char* 
OutputTransitionEffect_toString(OutputTransitionEffect_t effect);


LIBSBML_EXTERN
OutputTransitionEffect_t 
OutputTransitionEffect_fromString(const char* s);


LIBSBML_EXTERN
int 
OutputTransitionEffect_isValidOutputTransitionEffect(OutputTransitionEffect_t effect);


LIBSBML_EXTERN
int 
OutputTransitionEffect_isValidOutputTransitionEffectString(const char* s);


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Output_H__  */
